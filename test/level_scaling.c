#include "global.h"
#include "test/test.h"
#include "data.h"
#include "level_scaling.h"
#include "malloc.h"
#include "pokemon.h"
#include "random.h"
#include "trainer_pools.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/trainers.h"

#if B_LEVEL_SCALING_ENABLED

// Tier tables live in src/data/*_progression_tiers.h and are pulled in by
// src/level_scaling.c. Declared here so the gate tests can be driven by the
// real data instead of hardcoding a move/item that may be re-tiered later.
extern const u8 gMoveProgressionTier[];
extern const u8 gItemProgressionTier[];

// TEST builds replace gTrainers with the small table generated from
// test/battle/trainer_control.party (see the !TESTING guard in src/data.c), so
// real trainer ids have a NULL party here. Trainer 1 is defined there and is
// absent from gTrainerLevelScalingRules, so it resolves to the global default
// scaling config. gTrainerLevelScalingRules itself is real in both builds, so
// tests that only need a *config* can still name a real trainer.
#define TRAINER_WITH_TEST_PARTY 1

// How many samples the variation tests draw. Variation is random, so these
// tests assert on the observed range rather than a single value.
#define VARIATION_SAMPLES 100

static void SetUpPlayerParty(const u8 *levels, u32 count)
{
    u32 i;

    ZeroPlayerPartyMons();
    for (i = 0; i < count; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];

        CreateMon(mon, SPECIES_WOBBUFFET, levels[i], 0, OTID_STRUCT_PLAYER_ID);
        CalculateMonStats(mon);   // CreateMon does not fill in stats/current HP
    }
    CalculatePlayerPartyCount();
    InvalidatePartyLevelCache();
}

static void FaintPartyMon(u32 index)
{
    u32 hp = 0;
    SetMonData(&gParties[B_TRAINER_PLAYER][index], MON_DATA_HP, &hp);
    InvalidatePartyLevelCache();
}

// ============================================================================
// Party base level derivation
// ============================================================================

TEST("(Level Scaling) PARTY_AVG/HIGHEST/LOWEST derive the base level from the player's party")
{
    u8 mode, expected;
    static const u8 levels[] = {10, 20, 30, 40, 50, 60};   // avg 35

    PARAMETRIZE { mode = LEVEL_SCALING_PARTY_AVG;     expected = 35; }
    PARAMETRIZE { mode = LEVEL_SCALING_PARTY_HIGHEST; expected = 60; }
    PARAMETRIZE { mode = LEVEL_SCALING_PARTY_LOWEST;  expected = 10; }

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    EXPECT_EQ(CalculatePlayerPartyBaseLevel(mode, FALSE), expected);
}

TEST("(Level Scaling) PARTY_AVG truncates rather than rounds")
{
    static const u8 levels[] = {10, 11};   // 10.5 -> 10

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_AVG, FALSE), 10);
}

TEST("(Level Scaling) excludeFainted omits fainted party members from the base level")
{
    u8 mode, expected;
    static const u8 levels[] = {10, 50};

    PARAMETRIZE { mode = LEVEL_SCALING_PARTY_AVG;     expected = 10; }
    PARAMETRIZE { mode = LEVEL_SCALING_PARTY_HIGHEST; expected = 10; }
    PARAMETRIZE { mode = LEVEL_SCALING_PARTY_LOWEST;  expected = 10; }

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));
    FaintPartyMon(1);   // the level 50 mon

    EXPECT_EQ(CalculatePlayerPartyBaseLevel(mode, TRUE), expected);
}

TEST("(Level Scaling) fainted party members still count when excludeFainted is FALSE")
{
    static const u8 levels[] = {10, 50};

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));
    FaintPartyMon(1);

    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_HIGHEST, FALSE), 50);
}

TEST("(Level Scaling) both excludeFainted variants read correctly from a warm cache")
{
    static const u8 levels[] = {10, 50};

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));
    FaintPartyMon(1);

    // The two variants disagree, so they cannot share one cache slot.
    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_HIGHEST, TRUE), 10);
    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_HIGHEST, FALSE), 50);
}

TEST("(Level Scaling) an empty party falls back to base level 1")
{
    u8 mode;

    PARAMETRIZE { mode = LEVEL_SCALING_PARTY_AVG; }
    PARAMETRIZE { mode = LEVEL_SCALING_PARTY_HIGHEST; }
    PARAMETRIZE { mode = LEVEL_SCALING_PARTY_LOWEST; }

    SetUpPlayerParty(NULL, 0);

    EXPECT_EQ(CalculatePlayerPartyBaseLevel(mode, FALSE), 1);
}

TEST("(Level Scaling) LEVEL_SCALING_NONE reports base level 0 as the 'do not scale' sentinel")
{
    static const u8 levels[] = {50};

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_NONE, FALSE), 0);
}

TEST("(Level Scaling) the party level cache is refreshed by InvalidatePartyLevelCache")
{
    static const u8 before[] = {10};
    static const u8 after[] = {50};

    SetUpPlayerParty(before, ARRAY_COUNT(before));
    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_HIGHEST, FALSE), 10);

    SetUpPlayerParty(after, ARRAY_COUNT(after));
    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_HIGHEST, FALSE), 50);
}

TEST("(Level Scaling) every mode reads correctly from a warm cache")
{
    static const u8 levels[] = {10, 50};   // avg 30, highest 50, lowest 10

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    // Warm the cache on one mode, then query the others without invalidating —
    // a double battle can resolve two trainers with different modes back to back.
    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_HIGHEST, FALSE), 50);
    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_AVG, FALSE), 30);
    EXPECT_EQ(CalculatePlayerPartyBaseLevel(LEVEL_SCALING_PARTY_LOWEST, FALSE), 10);
}

// ============================================================================
// CalculateScaledLevel — augment, variation, clamping
// ============================================================================

TEST("(Level Scaling) levelAugmentAdd shifts the base level")
{
    s8 augment;
    u8 expected;
    static const u8 levels[] = {50};
    struct LevelScalingConfig config = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelVariationPct = 0,
    };

    PARAMETRIZE { augment =   0; expected = 50; }
    PARAMETRIZE { augment =   5; expected = 55; }
    PARAMETRIZE { augment =  -8; expected = 42; }

    config.levelAugmentAdd = augment;
    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    EXPECT_EQ(CalculateScaledLevel(&config, 5), expected);
}

TEST("(Level Scaling) a negative augment cannot push the scaled level below 1")
{
    static const u8 levels[] = {5};
    struct LevelScalingConfig config = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelAugmentAdd = -50,
        .levelVariationPct = 0,
    };

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    EXPECT_EQ(CalculateScaledLevel(&config, 20), 1);
}

TEST("(Level Scaling) levelVariationPct only ever reduces the level, never raises it")
{
    u32 i;
    u8 highest = 0;
    static const u8 levels[] = {50};
    struct LevelScalingConfig config = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelAugmentAdd = 0,
        .levelVariationPct = 10,
    };

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    for (i = 0; i < VARIATION_SAMPLES; i++)
    {
        u8 level = CalculateScaledLevel(&config, 5);
        if (level > highest)
            highest = level;
    }

    // Variation is a downward-only percentage reduction, so the augmented base
    // (50 + 0) is the ceiling — it is not a +/- spread around the base.
    EXPECT_EQ(highest, 50);
}

TEST("(Level Scaling) levelVariationPct reduces by at most that percentage of the base")
{
    u32 i;
    u8 lowest = MAX_LEVEL;
    u8 highest = 0;
    static const u8 levels[] = {50};
    struct LevelScalingConfig config = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelAugmentAdd = 0,
        .levelVariationPct = 10,
    };

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    for (i = 0; i < VARIATION_SAMPLES; i++)
    {
        u8 level = CalculateScaledLevel(&config, 5);
        if (level < lowest)
            lowest = level;
        if (level > highest)
            highest = level;
    }

    EXPECT_GE(lowest, 45);       // 10% of 50 = 5 levels of headroom
    EXPECT_LE(highest, 50);
    EXPECT_LT(lowest, highest);  // and the spread is actually used
}

TEST("(Level Scaling) levelVariationPct of 0 produces no variation at all")
{
    u32 i;
    static const u8 levels[] = {50};
    struct LevelScalingConfig config = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelAugmentAdd = 2,
        .levelVariationPct = 0,
    };

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    for (i = 0; i < VARIATION_SAMPLES; i++)
        EXPECT_EQ(CalculateScaledLevel(&config, 5), 52);
}

TEST("(Level Scaling) a non-zero levelVariationPct always gives at least 1 level of spread")
{
    u32 i;
    u8 lowest = MAX_LEVEL;
    u8 highest = 0;
    static const u8 levels[] = {5};
    struct LevelScalingConfig config = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelAugmentAdd = 0,
        .levelVariationPct = 10,     // 10% of 5 truncates to 0
    };

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    for (i = 0; i < VARIATION_SAMPLES; i++)
    {
        u8 level = CalculateScaledLevel(&config, 20);
        if (level < lowest)
            lowest = level;
        if (level > highest)
            highest = level;
    }

    EXPECT_EQ(highest, 5);
    EXPECT_EQ(lowest, 4);
}

TEST("(Level Scaling) minLevel and maxLevel clamp the scaled level")
{
    u8 partyLevel, expected;
    struct LevelScalingConfig config = {
        .mode = LEVEL_SCALING_PARTY_HIGHEST,
        .levelAugmentAdd = 0,
        .levelVariationPct = 0,
        .minLevel = 25,
        .maxLevel = 50,
    };

    PARAMETRIZE { partyLevel = 10; expected = 25; }
    PARAMETRIZE { partyLevel = 35; expected = 35; }
    PARAMETRIZE { partyLevel = 80; expected = 50; }

    SetUpPlayerParty(&partyLevel, 1);

    EXPECT_EQ(CalculateScaledLevel(&config, 5), expected);
}

TEST("(Level Scaling) a LEVEL_SCALING_NONE config returns the trainer's original level")
{
    static const u8 levels[] = {50};
    struct LevelScalingConfig config = {
        .mode = LEVEL_SCALING_NONE,
        .levelAugmentAdd = 10,
        .levelVariationPct = 50,
    };

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    EXPECT_EQ(CalculateScaledLevel(&config, 17), 17);
}

// ============================================================================
// Evolution management
// ============================================================================

TEST("(Level Scaling) manageEvolutions devolves a species that cannot exist at the scaled level")
{
    ASSUME(P_FAMILY_BULBASAUR == TRUE);

    // Ivysaur evolves at 16, Venusaur at 32.
    EXPECT_EQ(ValidateSpeciesForLevel(SPECIES_VENUSAUR, 5,  TRUE), SPECIES_BULBASAUR);
    EXPECT_EQ(ValidateSpeciesForLevel(SPECIES_VENUSAUR, 20, TRUE), SPECIES_IVYSAUR);
    EXPECT_EQ(ValidateSpeciesForLevel(SPECIES_IVYSAUR,  5,  TRUE), SPECIES_BULBASAUR);
}

TEST("(Level Scaling) manageEvolutions leaves a species that is legal at the scaled level")
{
    ASSUME(P_FAMILY_BULBASAUR == TRUE);

    EXPECT_EQ(ValidateSpeciesForLevel(SPECIES_VENUSAUR,  40, TRUE), SPECIES_VENUSAUR);
    EXPECT_EQ(ValidateSpeciesForLevel(SPECIES_BULBASAUR, 1,  TRUE), SPECIES_BULBASAUR);
}

TEST("(Level Scaling) manageEvolutions FALSE leaves the species untouched")
{
    ASSUME(P_FAMILY_BULBASAUR == TRUE);

    EXPECT_EQ(ValidateSpeciesForLevel(SPECIES_VENUSAUR, 5, FALSE), SPECIES_VENUSAUR);
}

TEST("(Level Scaling) evolution overrides gate species that do not evolve by level")
{
    const struct EvolutionOverride *override;

    ASSUME(B_SCALING_USE_OVERRIDES == TRUE);
    ASSUME(P_FAMILY_GASTLY == TRUE);

    // Gengar is a trade evolution, so it has no level requirement of its own.
    override = GetEvolutionOverride(SPECIES_GENGAR);
    ASSUME(override != NULL);

    EXPECT_NE(ValidateSpeciesForLevel(SPECIES_GENGAR, override->minimumLevel - 1, TRUE), SPECIES_GENGAR);
    EXPECT_EQ(ValidateSpeciesForLevel(SPECIES_GENGAR, override->minimumLevel, TRUE), SPECIES_GENGAR);
}

TEST("(Level Scaling) species without an override are not gated")
{
    EXPECT(GetEvolutionOverride(SPECIES_WOBBUFFET) == NULL);
}

// ============================================================================
// Move and held item progression gates
// ============================================================================

static u16 FindMoveWithTier(u8 tier)
{
    u32 i;

    for (i = 1; i < MOVES_COUNT; i++)
    {
        if (gMoveProgressionTier[i] == tier)
            return i;
    }
    return MOVE_NONE;
}

static u16 FindItemWithTier(u8 tier)
{
    u32 i;

    for (i = 1; i < ITEMS_COUNT; i++)
    {
        if (gItemProgressionTier[i] == tier)
            return i;
    }
    return ITEM_NONE;
}

TEST("(Level Scaling) IsMovePermittedAtLevel gates moves by progression tier")
{
    u8 tier, minLevel;
    u16 move;

    // MOVE_TIER_ENDGAME is omitted: no move currently carries it in
    // src/data/move_progression_tiers.h.
    PARAMETRIZE { tier = MOVE_TIER_MID;  minLevel = B_SCALING_TIER_MID_MIN_LEVEL; }
    PARAMETRIZE { tier = MOVE_TIER_LATE; minLevel = B_SCALING_TIER_LATE_MIN_LEVEL; }

    move = FindMoveWithTier(tier);
    ASSUME(move != MOVE_NONE);

    EXPECT(!IsMovePermittedAtLevel(move, minLevel - 1));
    EXPECT(IsMovePermittedAtLevel(move, minLevel));
    EXPECT(IsMovePermittedAtLevel(move, MAX_LEVEL));
}

TEST("(Level Scaling) untiered moves are permitted at any level")
{
    u16 move = FindMoveWithTier(MOVE_TIER_DEFAULT);

    ASSUME(move != MOVE_NONE);

    EXPECT(IsMovePermittedAtLevel(move, 1));
    EXPECT(IsMovePermittedAtLevel(MOVE_NONE, 1));
}

TEST("(Level Scaling) IsItemPermittedAtLevel gates held items by progression tier")
{
    u8 tier, minLevel;
    u16 item;

    // ITEM_TIER_ENDGAME is omitted: no item currently carries it in
    // src/data/item_progression_tiers.h.
    PARAMETRIZE { tier = ITEM_TIER_MID;  minLevel = B_SCALING_TIER_MID_MIN_LEVEL; }
    PARAMETRIZE { tier = ITEM_TIER_LATE; minLevel = B_SCALING_TIER_LATE_MIN_LEVEL; }

    item = FindItemWithTier(tier);
    ASSUME(item != ITEM_NONE);

    EXPECT(!IsItemPermittedAtLevel(item, minLevel - 1));
    EXPECT(IsItemPermittedAtLevel(item, minLevel));
    EXPECT(IsItemPermittedAtLevel(item, MAX_LEVEL));
}

TEST("(Level Scaling) untiered held items are permitted at any level")
{
    u16 item = FindItemWithTier(ITEM_TIER_DEFAULT);

    ASSUME(item != ITEM_NONE);

    EXPECT(IsItemPermittedAtLevel(item, 1));
    EXPECT(IsItemPermittedAtLevel(ITEM_NONE, 1));
}

// ============================================================================
// EV scaling
// ============================================================================

// EVs in struct TrainerMon are in Showdown order: HP, Atk, Def, SpAtk, SpDef, Speed.
static u32 GetMonEVTotal(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_HP_EV, NULL)
         + GetMonData(mon, MON_DATA_ATK_EV, NULL)
         + GetMonData(mon, MON_DATA_DEF_EV, NULL)
         + GetMonData(mon, MON_DATA_SPATK_EV, NULL)
         + GetMonData(mon, MON_DATA_SPDEF_EV, NULL)
         + GetMonData(mon, MON_DATA_SPEED_EV, NULL);
}

TEST("(Level Scaling) scaled EVs are held to a budget of 10 per level")
{
    struct Pokemon *mon = Alloc(sizeof(struct Pokemon));
    static const u8 baseEVs[6] = {252, 252, 0, 0, 0, 4};   // 508 total

    ASSUME(GetTrainerLevelScalingConfig(TRAINER_FLANNERY_1)->scaleEVs == TRUE);

    CreateMon(mon, SPECIES_WOBBUFFET, 15, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT(TryApplyScaledTrainerEVs(mon, baseEVs, TRAINER_FLANNERY_1, 15));

    // Budget at level 15 is 150; truncation only ever loses EVs.
    EXPECT_LE(GetMonEVTotal(mon), 150);
    EXPECT_GT(GetMonEVTotal(mon), 0);
    EXPECT_LT(GetMonData(mon, MON_DATA_HP_EV, NULL), 252);

    Free(mon);
}

TEST("(Level Scaling) EV totals already within the level budget are left alone")
{
    struct Pokemon *mon = Alloc(sizeof(struct Pokemon));
    static const u8 baseEVs[6] = {4, 4, 0, 0, 0, 4};   // 12 total

    ASSUME(GetTrainerLevelScalingConfig(TRAINER_FLANNERY_1)->scaleEVs == TRUE);

    CreateMon(mon, SPECIES_WOBBUFFET, 15, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT(TryApplyScaledTrainerEVs(mon, baseEVs, TRAINER_FLANNERY_1, 15));

    EXPECT_EQ(GetMonData(mon, MON_DATA_HP_EV, NULL), 4);
    EXPECT_EQ(GetMonData(mon, MON_DATA_ATK_EV, NULL), 4);
    EXPECT_EQ(GetMonData(mon, MON_DATA_SPEED_EV, NULL), 4);

    Free(mon);
}

TEST("(Level Scaling) the EV budget never exceeds 510 at high levels")
{
    struct Pokemon *mon = Alloc(sizeof(struct Pokemon));
    static const u8 baseEVs[6] = {252, 252, 0, 0, 0, 4};

    ASSUME(GetTrainerLevelScalingConfig(TRAINER_FLANNERY_1)->scaleEVs == TRUE);

    CreateMon(mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT(TryApplyScaledTrainerEVs(mon, baseEVs, TRAINER_FLANNERY_1, 100));

    EXPECT_LE(GetMonEVTotal(mon), 510);

    Free(mon);
}

TEST("(Level Scaling) EV scaling is skipped for trainers that have not opted in")
{
    struct Pokemon *mon = Alloc(sizeof(struct Pokemon));
    static const u8 baseEVs[6] = {252, 252, 0, 0, 0, 4};

    ASSUME(GetTrainerLevelScalingConfig(TRAINER_WATTSON_1)->scaleEVs == FALSE);

    CreateMon(mon, SPECIES_WOBBUFFET, 15, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT(!TryApplyScaledTrainerEVs(mon, baseEVs, TRAINER_WATTSON_1, 15));

    Free(mon);
}

// ============================================================================
// Party selection — BST ceiling and the never-empty floor
// ============================================================================

TEST("(Level Scaling) SelectScaledTrainerParty drops non-ace mons above the level's BST ceiling")
{
    const struct Trainer *trainer = GetTrainerStructFromId(TRAINER_WITH_TEST_PARTY);
    u32 monIndices[3] = {0, 0, 0};
    u8 scaledLevels[3] = {5, 5, 5};
    u16 scaledSpecies[3] = {SPECIES_CATERPIE, SPECIES_MEWTWO, SPECIES_CATERPIE};
    u8 kept;

    ASSUME(P_FAMILY_CATERPIE == TRUE);
    ASSUME(P_FAMILY_MEWTWO == TRUE);
    ASSUME(trainer->partySize >= 1);
    ASSUME((trainer->party[0].tags & MON_POOL_TAG_ACE) == 0);
    ASSUME(GetTrainerLevelScalingConfig(TRAINER_WITH_TEST_PARTY)->mode != LEVEL_SCALING_NONE);
    // Below B_SCALING_TIER_MID_MIN_LEVEL the ceiling is B_SCALING_BST_BELOW_MID.
    ASSUME(5 < B_SCALING_TIER_MID_MIN_LEVEL);
    ASSUME(B_SCALING_BST_BELOW_MID < 680);   // Mewtwo's BST
    ASSUME(GetScaledTrainerPartySize(TRAINER_WITH_TEST_PARTY, 3) == 3);

    kept = SelectScaledTrainerParty(trainer, TRAINER_WITH_TEST_PARTY, monIndices, scaledLevels, scaledSpecies, 3);

    EXPECT_EQ(kept, 2);
    EXPECT_EQ(scaledSpecies[0], SPECIES_CATERPIE);
    EXPECT_EQ(scaledSpecies[1], SPECIES_CATERPIE);
}

TEST("(Level Scaling) SelectScaledTrainerParty keeps mons within the BST ceiling")
{
    const struct Trainer *trainer = GetTrainerStructFromId(TRAINER_WITH_TEST_PARTY);
    u32 monIndices[2] = {0, 0};
    u8 scaledLevels[2] = {50, 50};
    u16 scaledSpecies[2] = {SPECIES_MEWTWO, SPECIES_CATERPIE};
    u8 kept;

    ASSUME(P_FAMILY_CATERPIE == TRUE);
    ASSUME(P_FAMILY_MEWTWO == TRUE);
    ASSUME(trainer->partySize >= 1);
    ASSUME((trainer->party[0].tags & MON_POOL_TAG_ACE) == 0);
    ASSUME(GetTrainerLevelScalingConfig(TRAINER_WITH_TEST_PARTY)->mode != LEVEL_SCALING_NONE);
    // At level 50 the ceiling is B_SCALING_BST_LATE, which is unlimited by default.
    ASSUME(B_SCALING_BST_LATE >= 680);
    ASSUME(GetScaledTrainerPartySize(TRAINER_WITH_TEST_PARTY, 2) == 2);

    kept = SelectScaledTrainerParty(trainer, TRAINER_WITH_TEST_PARTY, monIndices, scaledLevels, scaledSpecies, 2);

    EXPECT_EQ(kept, 2);
    EXPECT_EQ(scaledSpecies[0], SPECIES_MEWTWO);
    EXPECT_EQ(scaledSpecies[1], SPECIES_CATERPIE);
}

TEST("(Level Scaling) SelectScaledTrainerParty always fields at least one mon")
{
    const struct Trainer *trainer = GetTrainerStructFromId(TRAINER_WITH_TEST_PARTY);
    u32 monIndices[2] = {0, 0};
    u8 scaledLevels[2] = {5, 5};
    u16 scaledSpecies[2] = {SPECIES_MEWTWO, SPECIES_MEWTWO};
    u8 kept;

    ASSUME(P_FAMILY_MEWTWO == TRUE);
    ASSUME(trainer->partySize >= 1);
    ASSUME((trainer->party[0].tags & MON_POOL_TAG_ACE) == 0);
    ASSUME(GetTrainerLevelScalingConfig(TRAINER_WITH_TEST_PARTY)->mode != LEVEL_SCALING_NONE);
    ASSUME(5 < B_SCALING_TIER_MID_MIN_LEVEL);
    ASSUME(B_SCALING_BST_BELOW_MID < 680);

    // Every mon is over the ceiling, so the lowest-BST mon is kept as a floor.
    kept = SelectScaledTrainerParty(trainer, TRAINER_WITH_TEST_PARTY, monIndices, scaledLevels, scaledSpecies, 2);

    EXPECT_EQ(kept, 1);
    EXPECT_EQ(scaledSpecies[0], SPECIES_MEWTWO);
}

// ============================================================================
// Wild encounters
// ============================================================================

TEST("(Level Scaling) wild variation only ever reduces the level")
{
    u32 i;
    u8 highest = 0;
    u8 base, ceiling;
    s16 augmented;
    static const u8 levels[] = {50};

    ASSUME(B_WILD_SCALING_ENABLED == TRUE);

    SetUpPlayerParty(levels, ARRAY_COUNT(levels));

    base = CalculatePlayerPartyBaseLevel(B_WILD_SCALING_DEFAULT_MODE, B_WILD_SCALING_EXCLUDE_FAINTED);
    ASSUME(base > 0);
    augmented = (s16)base + B_WILD_SCALING_LEVEL_AUGMENT;
    if (augmented < 1)
        augmented = 1;
    ceiling = (u8)augmented;
    if (B_WILD_SCALING_MAX_LEVEL > 0 && ceiling > B_WILD_SCALING_MAX_LEVEL)
        ceiling = B_WILD_SCALING_MAX_LEVEL;
    if (B_WILD_SCALING_MIN_LEVEL > ceiling)
        ceiling = B_WILD_SCALING_MIN_LEVEL;

    for (i = 0; i < VARIATION_SAMPLES; i++)
    {
        u8 level = CalculateWildScaledLevel(SPECIES_WOBBUFFET, 5);
        if (level > highest)
            highest = level;
    }

    EXPECT_LE(highest, ceiling);
}

TEST("(Level Scaling) wild species are devolved to match their scaled level")
{
    ASSUME(B_WILD_SCALING_ENABLED == TRUE);
    ASSUME(B_WILD_SCALING_MANAGE_EVOLUTIONS == TRUE);
    ASSUME(P_FAMILY_BULBASAUR == TRUE);

    EXPECT_EQ(CalculateWildScaledSpecies(SPECIES_VENUSAUR, 5), SPECIES_BULBASAUR);
    EXPECT_EQ(CalculateWildScaledSpecies(SPECIES_VENUSAUR, 40), SPECIES_VENUSAUR);
}


#endif // B_LEVEL_SCALING_ENABLED

TEST("(Level Scaling) a devolved species keeps the trainer's ability slot")
{
    enum Species original, scaled;
    enum Ability ability, expected;

    // Both pairs crashed SetCorrectAbilityNum before GetScaledTrainerAbility existed.
    PARAMETRIZE { original = SPECIES_GALLADE;  scaled = SPECIES_RALTS;   ability = ABILITY_SHARPNESS; expected = ABILITY_TRACE; }
    PARAMETRIZE { original = SPECIES_PELIPPER; scaled = SPECIES_WINGULL; ability = ABILITY_DRIZZLE;   expected = ABILITY_HYDRATION; }

    ASSUME(P_FAMILY_RALTS == TRUE);
    ASSUME(P_FAMILY_WINGULL == TRUE);

    EXPECT_EQ(GetScaledTrainerAbility(original, scaled, ability), expected);
}

TEST("(Level Scaling) an ability the devolved species still has is left alone")
{
    ASSUME(P_FAMILY_WINGULL == TRUE);

    // Rain Dish sits on both Pelipper and Wingull, so it survives devolution.
    EXPECT_EQ(GetScaledTrainerAbility(SPECIES_PELIPPER, SPECIES_WINGULL, ABILITY_RAIN_DISH), ABILITY_RAIN_DISH);
}

TEST("(Level Scaling) an unscaled species keeps its ability untouched")
{
    ASSUME(P_FAMILY_RALTS == TRUE);

    EXPECT_EQ(GetScaledTrainerAbility(SPECIES_GALLADE, SPECIES_GALLADE, ABILITY_SHARPNESS), ABILITY_SHARPNESS);
    EXPECT_EQ(GetScaledTrainerAbility(SPECIES_GALLADE, SPECIES_RALTS, ABILITY_NONE), ABILITY_NONE);
}
