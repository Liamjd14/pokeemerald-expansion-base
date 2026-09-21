#include "game_corner_gacha.h"
#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "bg.h"
#include "coins.h"
#include "caps.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "field_message_box.h"
#include "international_string_util.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "naming_screen.h"
#include "new_game.h"
#include "overworld.h"
#include "palette.h"
#include "palette_util.h"
#include "pokemon.h"
#include "pokedex.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trade.h"
#include "trainer_pokemon_sprites.h"
#include "tv.h"
#include "window.h"
#include "constants/coins.h"
#include "constants/flags.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/vars.h"
#include "scanline_effect.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "field_specials.h"

enum
{
    GACHA_STATE_INIT,
    GACHA_STATE_PROCESS_INPUT,
    GACHA_STATE_START_EXIT,
    GACHA_STATE_EXIT,
    STATE_INIT_A,
    STATE_TIMER_1,
    STATE_TWIST,
    STATE_TIMER_2,
    STATE_INIT_GIVE,
    STATE_SHAKE_1,
    STATE_TIMER_3,
    STATE_INIT_SHAKE_2,
    STATE_SHAKE_2,
    STATE_TIMER_4,
    STATE_INIT_SHAKE_3,
    STATE_TIMER_5,
    STATE_GIVE,
    STATE_FADE,
    STATE_POKEBALL_INIT,
    STATE_POKEBALL_PROCESS,
    STATE_POKEBALL_ARRIVE,
    STATE_FADE_POKEBALL_TO_NORMAL,
    STATE_POKEBALL_ARRIVE_WAIT,
    STATE_SHOW_NEW_MON,
    STATE_NEW_MON_MSG,
    NEW_1,
    NEW_2,
    STATE_SET_EXIT,
};

enum {
    SPR_CREDIT_DIG_1,
    SPR_CREDIT_DIG_10,
    SPR_CREDIT_DIG_100,
    SPR_CREDIT_DIG_1000,
};

enum {
    GACHA_BASIC = 1,
    GACHA_GREAT,
    GACHA_ULTRA,
    GACHA_MASTER,
};

enum {
    RARITY_COMMON,
    RARITY_UNCOMMON,
    RARITY_RARE,
    RARITY_ULTRA_RARE,
};

enum {
    SPR_PLAYER_DIG_1,
    SPR_PLAYER_DIG_10,
    SPR_PLAYER_DIG_100,
    SPR_PLAYER_DIG_1000,
};

#define RARITY_COMMON_ODDS 40
#define RARITY_UNCOMMON_ODDS 30
#define RARITY_RARE_ODDS 20
#define RARITY_ULTRA_RARE_ODDS 10

#define GACHA_BASIC_MIN_WAGER 50
#define GACHA_GREAT_MIN_WAGER 100
#define GACHA_ULTRA_MIN_WAGER 250
#define GACHA_MASTER_MIN_WAGER 1000

#define SPR_CREDIT_DIGITS SPR_CREDIT_DIG_1
#define SPR_PLAYER_DIGITS SPR_PLAYER_DIG_1

#define MAX_SPRITES_CREDIT 4
#define MAX_SPRITES_PLAYER 4

struct Gacha {
    u8 state;
    u8 GachaId;
    u8 KnobSpriteId;
    u8 DigitalTextSpriteId;
    u8 LotteryJPNspriteId;
    u8 CreditSpriteIds[MAX_SPRITES_CREDIT];
    u8 PlayerSpriteIds[MAX_SPRITES_PLAYER];
    u8 CreditMenu1Id;
    u8 CreditMenu2Id;
    u8 PokemonOneSpriteId;
    u8 PokemonTwoSpriteId;
    u8 PokemonThreeSpriteId;
    u8 newMonOdds;
    u8 ArrowsSpriteId;
    u8 CTAspriteId;
    u8 cursorPosition;
    bool8 canBetWager;
    u8 Rarity; // 0 = Common, 1 = Uncommon, 2 = Rare, 3 = Ultra Rare
    u8 ownedCommon;
    u8 ownedUncommon;
    u8 ownedRare;
    u8 ownedUltraRare;
    u8 bouncingPokeballSpriteId;
    u8 timer;
    u8 monSpriteId;
    u16 CalculatedSpecies;
    u16 wager;
    u32 waitTimer;
};    

static const u8 sText_FromGacha[] = _("You got {STR_VAR_1}!");

static const s8 sTradeBallVerticalVelocityTable[] =
{
     0,  0,  1,  0,  1,  0,  1,  1,  1,
     1,  2,  2,  2,  2,  3,  3,  3,  3,
     4,  4,  4,  4, -4, -4, -4, -3, -3,
    -3, -3, -2, -2, -2, -2, -1, -1, -1,
    -1,  0, -1,  0, -1,  0,  0,  0,  0,
     0,  1,  0,  1,  0,  1,  1,  1,  1,
     2,  2,  2,  2,  3,  3,  3,  3,  4,
     4,  4,  4, -4, -3, -3, -2, -2, -1,
    -1, -1,  0, -1,  0,  0,  0,  0,  0,
     0,  1,  0,  1,  1,  1,  2,  2,  3,
     3,  4, -4, -3, -2, -1, -1, -1,  0,
     0,  0,  0,  1,  0,  1,  1,  2,  3
};

static EWRAM_DATA struct Gacha *sGacha = NULL;
static EWRAM_DATA u8 sTextWindowId = 0;

static void FadeToGachaScreen(u8 taskId);
static void InitGachaScreen(void);
static void GachaVBlankCallback(void);
static void SpriteCB_BouncingPokeball(struct Sprite *);
static void SpriteCB_BouncingPokeballArrive(struct Sprite *);

static const u8 sMessageText[] = _("NEW POKéMON : {STR_VAR_1}%");

static void SpriteCB_Null(struct Sprite *sprite)
{
}

// BG Images/Tilemaps

// Main, no shake
static const u32 Gacha_BG_Main[] = INCBIN_U32("graphics/gacha/bg_middle.4bpp.smol");
static const u8 Gacha_BG_Main_Tilemap[] = INCBIN_U8("graphics/gacha/bg_middle.bin.smolTM");
// Left shake
static const u32 Gacha_BG_Left[] = INCBIN_U32("graphics/gacha/bg_left.4bpp.smol");
static const u8 Gacha_BG_Left_Tilemap[] = INCBIN_U8("graphics/gacha/bg_left.bin.smolTM");
// Right shake
static const u32 Gacha_BG_Right[] = INCBIN_U32("graphics/gacha/bg_right.4bpp.smol");
static const u8 Gacha_BG_Right_Tilemap[] = INCBIN_U8("graphics/gacha/bg_right.bin.smolTM");

// Trade
static const u32 Gacha_BG_Red[] = INCBIN_U32("graphics/gacha/bg_mon.4bpp.smol");
static const u8 Gacha_BG_Red_Tilemap[] = INCBIN_U8("graphics/gacha/bg_mon.bin.smolTM");

// BG Palettes

// Basic
static const u16 Gacha_BG_Basic_Pal[] = INCBIN_U16("graphics/gacha/bg_basic.gbapal");
// Great
static const u16 Gacha_BG_Great_Pal[] = INCBIN_U16("graphics/gacha/bg_great.gbapal");
// Ultra
static const u16 Gacha_BG_Ultra_Pal[] = INCBIN_U16("graphics/gacha/bg_ultra.gbapal");
// Master
static const u16 Gacha_BG_Master_Pal[] = INCBIN_U16("graphics/gacha/bg_master.gbapal");

static const u16 Gacha_BG_Red_Pal[] = INCBIN_U16("graphics/gacha/bg_mon.gbapal");

// Knob Sprite Image
static const u32 Gacha_Knob[] = INCBIN_U32("graphics/gacha/knob.4bpp.smol");

// Knob Sprite Palettes

static const u16 Gacha_Knob_Pal[] = INCBIN_U16("graphics/gacha/knob.gbapal");
static const u16 Gacha_Digital_Text_Pal[] = INCBIN_U16("graphics/gacha/digital_text.gbapal");
static const u16 Gacha_Lottery_Pal[] = INCBIN_U16("graphics/gacha/lottery.gbapal");
static const u16 Gacha_press_a_Pal[] = INCBIN_U16("graphics/gacha/press_a.gbapal");

// Digital Text
static const u32 Gacha_Digital_Text[] = INCBIN_U32("graphics/gacha/digital_text.4bpp.smol");

// Title, Japanese
static const u32 Gacha_Lottery_JPN[] = INCBIN_U32("graphics/gacha/lottery_japan.4bpp.smol");

//Numbers

static const u32 gCredits_Gfx[] = INCBIN_U32("graphics/gacha/numbers.4bpp.smol");
static const u16 sCredit_Pal[] = INCBIN_U16("graphics/gacha/numbers.gbapal");

static const u32 gPlayer_Gfx[] = INCBIN_U32("graphics/gacha/input_numbers.4bpp.smol");
static const u16 sPlayer_Pal[] = INCBIN_U16("graphics/gacha/input_numbers.gbapal");

// Credits Menu

// Images

static const u32 Gacha_Menu_1[] = INCBIN_U32("graphics/gacha/menu_1.4bpp.smol");
static const u32 Gacha_Menu_2[] = INCBIN_U32("graphics/gacha/menu_2.4bpp.smol");

// Palettes

// Basic
static const u16 Gacha_Menu_Basic_Pal[] = INCBIN_U16("graphics/gacha/menu_basic.gbapal");
// Great
static const u16 Gacha_Menu_Great_Pal[] = INCBIN_U16("graphics/gacha/menu_great.gbapal");
// Ultra
static const u16 Gacha_Menu_Ultra_Pal[] = INCBIN_U16("graphics/gacha/menu_ultra.gbapal");
// Master
static const u16 Gacha_Menu_Master_Pal[] = INCBIN_U16("graphics/gacha/menu_master.gbapal");

// Basic
static const u16 Gacha_Menu2_Basic_Pal[] = INCBIN_U16("graphics/gacha/menu2_basic.gbapal");
// Great
static const u16 Gacha_Menu2_Great_Pal[] = INCBIN_U16("graphics/gacha/menu2_great.gbapal");
// Ultra
static const u16 Gacha_Menu2_Ultra_Pal[] = INCBIN_U16("graphics/gacha/menu2_ultra.gbapal");
// Master
static const u16 Gacha_Menu2_Master_Pal[] = INCBIN_U16("graphics/gacha/menu2_master.gbapal");

// Pokemon

// Belossom
static const u32 BelossomGFX[] = INCBIN_U32("graphics/gacha/belossom.4bpp.smol");
static const u16 BelossomPAL[] = INCBIN_U16("graphics/gacha/belossom.gbapal");

// Phanpy
static const u32 PhanpyGFX[] = INCBIN_U32("graphics/gacha/phanpy.4bpp.smol");
static const u16 PhanpyPal[] = INCBIN_U16("graphics/gacha/phanpy.gbapal");

// Teddiursa
static const u32 TeddiursaGFX[] = INCBIN_U32("graphics/gacha/teddiursa.4bpp.smol");
static const u16 TeddiursaPAL[] = INCBIN_U16("graphics/gacha/teddiursa.gbapal");

// Elekid
static const u32 ElekidGFX[] = INCBIN_U32("graphics/gacha/elekid.4bpp.smol");
static const u16 ElekidPAL[] = INCBIN_U16("graphics/gacha/elekid.gbapal");

// Hoppip
static const u32 HoppipGFX[] = INCBIN_U32("graphics/gacha/hoppip.4bpp.smol");
static const u16 HoppipPAL[] = INCBIN_U16("graphics/gacha/hoppip.gbapal");

// Arrows

static const u32 Gacha_Arrows_GFX[] = INCBIN_U32("graphics/gacha/arrows.4bpp.smol");

// Press "A"

static const u32 Gacha_Press_A_GFX[] = INCBIN_U32("graphics/gacha/pressA.4bpp.smol");

static const u16 sPokeball_Pal[] = INCBIN_U16("graphics/trade/pokeball.gbapal");
static const u8 sPokeball_Gfx[] = INCBIN_U8("graphics/trade/pokeball.4bpp");

const u16 gTrade_Tilemap[] = INCBIN_U16("graphics/trade/platform.bin");

#define GACHA_BG_BASE 1
#define GACHA_MENUS 2

static const struct BgTemplate sGachaBGtemplates[] = {
    {
       .bg = GACHA_BG_BASE,
       .charBaseIndex = 2,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 3,
       .baseTile = 0
   },
   {
        .bg = GACHA_MENUS,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x17,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

static const struct WindowTemplate sGachaWinTemplates[] = {
    {
        .bg = GACHA_MENUS,
        .tilemapLeft = 16,
        .tilemapTop = 9,
        .width = 14,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x194,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sWinTemplates_EggHatch[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 64
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sYesNoWinTemplate =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 424
};

#define BG_MIDDLE_GFX 1
#define BG_LEFT_GFX 2
#define BG_RIGHT_GFX 3
#define KNOB_GFX 4
#define DIGITAL_TEXT_GFX 5
#define LOTTERY_JPN_GFX 6
#define GFXTAG_CREDIT_DIGIT 7
#define GFXTAG_PLAYER_DIGIT 8
#define GFXTAG_MENU_1 9
#define GFXTAG_MENU_2 10
#define GFXTAG_MASCOT 11
#define GFXTAG_ARROWS 12
#define GFXTAG_PRESS_A 13

#define GFXTAG_POKEBALL        5557

#define PALTAG_KNOB 1
#define DIGITAL_TEXT_PAL 2
#define LOTTERY_JPN_PAL 3
#define PALTAG_INTERFACE 4
#define PALTAG_INTERFACEPLAYER 5
#define PALTAG_MENU_ID 6

#define PALTAG_MASCOT 7
#define PALTAG_ARROWS 8
#define PALTAG_PRESS_A 9

#define PALTAG_POKEBALL  5558

static const struct SpritePalette sSpritePalettesBasic[] =
{
    { .data = Gacha_press_a_Pal,       .tag = PALTAG_PRESS_A },
    { .data = Gacha_Knob_Pal,          .tag = PALTAG_KNOB },
    { .data = Gacha_Digital_Text_Pal,  .tag = DIGITAL_TEXT_PAL },
    { .data = sCredit_Pal,             .tag = PALTAG_INTERFACE },
    { .data = sPlayer_Pal,             .tag = PALTAG_INTERFACEPLAYER },
    { .data = Gacha_Lottery_Pal,       .tag = LOTTERY_JPN_PAL },
    { .data = Gacha_Menu_Basic_Pal,    .tag = PALTAG_MENU_ID },
    { .data = HoppipPAL,               .tag = PALTAG_MASCOT },
    { .data = sCredit_Pal,             .tag = PALTAG_ARROWS },
    {}
};

static const struct SpritePalette sSpritePalettesGreat[] =
{
    { .data = Gacha_press_a_Pal,       .tag = PALTAG_PRESS_A },
    { .data = Gacha_Knob_Pal,          .tag = PALTAG_KNOB },
    { .data = Gacha_Digital_Text_Pal,  .tag = DIGITAL_TEXT_PAL },
    { .data = sCredit_Pal,             .tag = PALTAG_INTERFACE },
    { .data = sPlayer_Pal,             .tag = PALTAG_INTERFACEPLAYER },
    { .data = Gacha_Lottery_Pal,       .tag = LOTTERY_JPN_PAL },
    { .data = Gacha_Menu_Great_Pal,    .tag = PALTAG_MENU_ID },
    { .data = PhanpyPal,               .tag = PALTAG_MASCOT },
    { .data = sCredit_Pal,             .tag = PALTAG_ARROWS },
    {}
};

static const struct SpritePalette sSpritePalettesUltra[] =
{
    { .data = Gacha_press_a_Pal,       .tag = PALTAG_PRESS_A },
    { .data = Gacha_Knob_Pal,          .tag = PALTAG_KNOB },
    { .data = Gacha_Digital_Text_Pal,  .tag = DIGITAL_TEXT_PAL },
    { .data = sCredit_Pal,             .tag = PALTAG_INTERFACE },
    { .data = sPlayer_Pal,             .tag = PALTAG_INTERFACEPLAYER },
    { .data = Gacha_Lottery_Pal,       .tag = LOTTERY_JPN_PAL },
    { .data = Gacha_Menu_Ultra_Pal,    .tag = PALTAG_MENU_ID },
    { .data = TeddiursaPAL,            .tag = PALTAG_MASCOT },
    { .data = sCredit_Pal,             .tag = PALTAG_ARROWS },
    {}
};

static const struct SpritePalette sSpritePalettesMaster[] =
{
    { .data = Gacha_press_a_Pal,       .tag = PALTAG_PRESS_A },
    { .data = Gacha_Knob_Pal,          .tag = PALTAG_KNOB },
    { .data = Gacha_Digital_Text_Pal,  .tag = DIGITAL_TEXT_PAL },
    { .data = sCredit_Pal,             .tag = PALTAG_INTERFACE },
    { .data = sPlayer_Pal,             .tag = PALTAG_INTERFACEPLAYER },
    { .data = Gacha_Lottery_Pal,       .tag = LOTTERY_JPN_PAL },
    { .data = Gacha_Menu_Master_Pal,   .tag = PALTAG_MENU_ID },
    { .data = BelossomPAL,             .tag = PALTAG_MASCOT },
    { .data = sCredit_Pal,             .tag = PALTAG_ARROWS },
    {}
};

static const struct CompressedSpriteSheet sSpriteSheet_Press_A =
{
    .data = Gacha_Press_A_GFX,
    .size = 0xC00,
    .tag = GFXTAG_PRESS_A,
};

static const struct CompressedSpriteSheet sSpriteSheet_Arrows =
{
    .data = Gacha_Arrows_GFX,
    .size = 0x200,
    .tag = GFXTAG_ARROWS,
};

static const struct CompressedSpriteSheet sSpriteSheet_Hoppip =
{
    .data = HoppipGFX,
    .size = 0x800,
    .tag = GFXTAG_MASCOT,
};

static const struct CompressedSpriteSheet sSpriteSheet_Elekid =
{
    .data = ElekidGFX,
    .size = 0x800,
    .tag = GFXTAG_MASCOT,
};

static const struct CompressedSpriteSheet sSpriteSheet_Teddiursa =
{
    .data = TeddiursaGFX,
    .size = 0x800,
    .tag = GFXTAG_MASCOT,
};

static const struct CompressedSpriteSheet sSpriteSheet_Phanpy =
{
    .data = PhanpyGFX,
    .size = 0x800,
    .tag = GFXTAG_MASCOT,
};

static const struct CompressedSpriteSheet sSpriteSheet_Belossom =
{
    .data = BelossomGFX,
    .size = 0x800,
    .tag = GFXTAG_MASCOT,
};

static const struct CompressedSpriteSheet sSpriteSheet_Menu_1 =
{
    .data = Gacha_Menu_1,
    .size = 0x800,
    .tag = GFXTAG_MENU_1,
};

static const struct CompressedSpriteSheet sSpriteSheet_Menu_2 =
{
    .data = Gacha_Menu_2,
    .size = 0x1000,
    .tag = GFXTAG_MENU_2,
};

static const struct CompressedSpriteSheet sSpriteSheets_Interface[] =
{
    {
        .data = gCredits_Gfx,
        .size = 0x280,
        .tag = GFXTAG_CREDIT_DIGIT,
    },
    {}
};

static const struct CompressedSpriteSheet sSpriteSheets_PlayerInterface[] =
{
    {
        .data = gPlayer_Gfx,
        .size = 0x280,
        .tag = GFXTAG_PLAYER_DIGIT
    },
    {}
};

static const struct CompressedSpriteSheet sSpriteSheet_Lottery_JPN =
{
    .data = Gacha_Lottery_JPN,
    .size = 0x800,
    .tag = LOTTERY_JPN_GFX,
};

static const struct CompressedSpriteSheet sSpriteSheet_Digital_Text =
{
    .data = Gacha_Digital_Text,
    .size = 0x1000,
    .tag = DIGITAL_TEXT_GFX,
};

static const struct CompressedSpriteSheet sSpriteSheet_Knob =
{
    .data = Gacha_Knob,
    .size = 0x800,
    .tag = KNOB_GFX,
};

static const struct OamData sOamData_Press_A =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Arrows =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(8x32),
    .size = SPRITE_SIZE(8x32),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Hoppip =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Elekid =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Teddiursa =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Phanpy =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Belossom =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Menu =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Menu_2 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Lottery_JPN =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Digital_Text =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOamData_Knob =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
};

static const struct OamData sOam_CreditDigit =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(8x16),
    .size = SPRITE_SIZE(8x16),
    .priority = 2,
};

static const struct OamData sOamData_Pokeball =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16)
};

static const union AnimCmd sAnim_Pokeball_SpinOnce[] =
{
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_FRAME( 4, 3),
    ANIMCMD_FRAME( 8, 3),
    ANIMCMD_FRAME(12, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(20, 3),
    ANIMCMD_FRAME(24, 3),
    ANIMCMD_FRAME(28, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(36, 3),
    ANIMCMD_FRAME(40, 3),
    ANIMCMD_FRAME(44, 3),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pokeball_SpinTwice[] =
{
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_FRAME( 4, 3),
    ANIMCMD_FRAME( 8, 3),
    ANIMCMD_FRAME(12, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(20, 3),
    ANIMCMD_FRAME(24, 3),
    ANIMCMD_FRAME(28, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(36, 3),
    ANIMCMD_FRAME(40, 3),
    ANIMCMD_FRAME(44, 3),
    ANIMCMD_LOOP(2),
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Pokeball[] =
{
    sAnim_Pokeball_SpinOnce,
    sAnim_Pokeball_SpinTwice
};

static const union AffineAnimCmd sAffineAnim_Pokeball_Normal[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Pokeball_Squish[] =
{
    AFFINEANIMCMD_FRAME(-8, 0, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Pokeball_Unsquish[] =
{
    AFFINEANIMCMD_FRAME(0x60, 0x100, 0,  0),
    AFFINEANIMCMD_FRAME(   0,     0, 0,  5),
    AFFINEANIMCMD_FRAME(   8,     0, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_Pokeball[] =
{
    sAffineAnim_Pokeball_Normal,
    sAffineAnim_Pokeball_Squish,
    sAffineAnim_Pokeball_Unsquish
};

static const struct SpriteSheet sPokeBallSpriteSheet =
{
    .data = sPokeball_Gfx,
    .size = sizeof(sPokeball_Gfx),
    .tag = GFXTAG_POKEBALL
};

static const struct SpritePalette sPokeBallSpritePalette =
{
    .data = sPokeball_Pal,
    .tag = PALTAG_POKEBALL
};

static const struct SpriteTemplate sSpriteTemplate_Pokeball =
{
    .tileTag = GFXTAG_POKEBALL,
    .paletteTag = PALTAG_POKEBALL,
    .oam = &sOamData_Pokeball,
    .anims = sAnims_Pokeball,
    .images = NULL,
    .affineAnims = sAffineAnims_Pokeball,
    .callback = SpriteCB_BouncingPokeball
};

static const union AnimCmd sPressAAnimCmd_1[] = 
{
    ANIMCMD_FRAME(32, 10),
    ANIMCMD_FRAME(64, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sPressAAnimCmd_0[] = 
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sPressAAnimCmds[] = {
    sPressAAnimCmd_0, // Gray
    sPressAAnimCmd_1, // Highlight
};

static const struct SpriteTemplate sSpriteTemplate_Press_A =
{
    .tileTag = GFXTAG_PRESS_A,
    .paletteTag = PALTAG_PRESS_A,
    .oam = &sOamData_Press_A,
    .anims = sPressAAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sArrowAnimCmd_1[] = 
{
    ANIMCMD_FRAME(8, 20),
    ANIMCMD_FRAME(12, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sArrowAnimCmd_0[] = 
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sArrowsAnimCmds[] = {
    sArrowAnimCmd_0, // Up and Down
    sArrowAnimCmd_1, // Up
};

static const struct SpriteTemplate sSpriteTemplate_Arrows =
{
    .tileTag = GFXTAG_ARROWS,
    .paletteTag = PALTAG_ARROWS,
    .oam = &sOamData_Arrows,
    .anims = sArrowsAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sMenu2AnimCmd_0[] = 
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(64, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sMenu2AnimCmds[] = {
    sMenu2AnimCmd_0,  // Looping animation
};

static const union AnimCmd sHoppipAnimCmd_0[] = 
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(48, 15),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sHoppipAnimCmds[] = {
    sHoppipAnimCmd_0,  // Looping animation
};

static const struct SpriteTemplate sSpriteTemplate_Hoppip =
{
    .tileTag = GFXTAG_MASCOT,
    .paletteTag = PALTAG_MASCOT,
    .oam = &sOamData_Hoppip,
    .anims = sHoppipAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sElekidAnimCmd_0[] = 
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(32, 15),
    //ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(48, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sElekidAnimCmds[] = {
    sElekidAnimCmd_0,  // Looping animation
};

static const struct SpriteTemplate sSpriteTemplate_Elekid =
{
    .tileTag = GFXTAG_MASCOT,
    .paletteTag = PALTAG_MASCOT,
    .oam = &sOamData_Elekid,
    .anims = sElekidAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sTeddiursaAnimCmd_0[] = 
{
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(48, 30),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sTeddiursaAnimCmds[] = {
    sTeddiursaAnimCmd_0,  // Looping animation
};

static const struct SpriteTemplate sSpriteTemplate_Teddiursa =
{
    .tileTag = GFXTAG_MASCOT,
    .paletteTag = PALTAG_MASCOT,
    .oam = &sOamData_Teddiursa,
    .anims = sTeddiursaAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sPhanpyAnimCmd_0[] = 
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(48, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(48, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sPhanpyAnimCmds[] = {
    sPhanpyAnimCmd_0,  // Looping animation
};

static const struct SpriteTemplate sSpriteTemplate_Phanpy =
{
    .tileTag = GFXTAG_MASCOT,
    .paletteTag = PALTAG_MASCOT,
    .oam = &sOamData_Phanpy,
    .anims = sPhanpyAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sBelossomAnimCmd_0[] = 
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(48, 30),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sBelossomAnimCmds[] = {
    sBelossomAnimCmd_0,  // Looping animation
};

static const struct SpriteTemplate sSpriteTemplate_Belossom =
{
    .tileTag = GFXTAG_MASCOT,
    .paletteTag = PALTAG_MASCOT,
    .oam = &sOamData_Belossom,
    .anims = sBelossomAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Menu_1_Master =
{
    .tileTag = GFXTAG_MENU_1,
    .paletteTag = PALTAG_MENU_ID,
    .oam = &sOamData_Menu,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Menu_2_Master =
{
    .tileTag = GFXTAG_MENU_2,
    .paletteTag = PALTAG_MENU_ID,
    .oam = &sOamData_Menu_2,
    .anims = sMenu2AnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Menu_1_Ultra =
{
    .tileTag = GFXTAG_MENU_1,
    .paletteTag = PALTAG_MENU_ID,
    .oam = &sOamData_Menu,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Menu_2_Ultra =
{
    .tileTag = GFXTAG_MENU_2,
    .paletteTag = PALTAG_MENU_ID,
    .oam = &sOamData_Menu_2,
    .anims = sMenu2AnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Menu_1_Great =
{
    .tileTag = GFXTAG_MENU_1,
    .paletteTag = PALTAG_MENU_ID,
    .oam = &sOamData_Menu,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Menu_2_Great =
{
    .tileTag = GFXTAG_MENU_2,
    .paletteTag = PALTAG_MENU_ID,
    .oam = &sOamData_Menu_2,
    .anims = sMenu2AnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Menu_1_Basic =
{
    .tileTag = GFXTAG_MENU_1,
    .paletteTag = PALTAG_MENU_ID,
    .oam = &sOamData_Menu,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Menu_2_Basic =
{
    .tileTag = GFXTAG_MENU_2,
    .paletteTag = PALTAG_MENU_ID,
    .oam = &sOamData_Menu_2,
    .anims = sMenu2AnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_CreditDigit =
{
    .tileTag = GFXTAG_CREDIT_DIGIT,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_CreditDigit,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PlayerDigit =
{
    .tileTag = GFXTAG_PLAYER_DIGIT,
    .paletteTag = PALTAG_INTERFACEPLAYER,
    .oam = &sOam_CreditDigit,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const union AnimCmd sDigitalTextAnimCmd_0[] = 
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_FRAME(96, 30),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sDigitalTextAnimCmds[] = {
    sDigitalTextAnimCmd_0,  // Looping animation
};

static const struct SpriteTemplate sSpriteTemplate_Digital_Text =
{
    .tileTag = DIGITAL_TEXT_GFX,
    .paletteTag = DIGITAL_TEXT_PAL,
    .oam = &sOamData_Digital_Text,
    .anims = sDigitalTextAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Lottery_JPN =
{
    .tileTag = LOTTERY_JPN_GFX,
    .paletteTag = LOTTERY_JPN_PAL,
    .oam = &sOamData_Lottery_JPN,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sKnobAnimCmd_1[] = 
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 20),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sKnobAnimCmd_0[] = 
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd *const sKnobAnimCmds[] = {
    sKnobAnimCmd_0, // Still
    sKnobAnimCmd_1, // Rotate
};

static const struct SpriteTemplate sSpriteTemplate_Knob =
{
    .tileTag = KNOB_GFX,
    .paletteTag = PALTAG_KNOB,
    .oam = &sOamData_Knob,
    .anims = sKnobAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

void StartGacha(void)
{
    sGacha = AllocZeroed(sizeof(struct Gacha));
    CreateTask(FadeToGachaScreen, 0);
}

static void SpriteCB_BouncingPokeball(struct Sprite *sprite)
{
    sprite->y += sprite->data[0] / 10;
    sprite->data[5] += sprite->data[1];
    sprite->x = sprite->data[5] / 10;
    if (sprite->y > 0x4c)
    {
        sprite->y = 0x4c;
        sprite->data[0] = -(sprite->data[0] * sprite->data[2]) / 100;
        sprite->data[3] ++;
    }
    if (sprite->x == 0x78)
        sprite->data[1] = 0;
    sprite->data[0] += sprite->data[4];
    if (sprite->data[3] == 4)
    {
        sprite->data[7] = 1;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_BouncingPokeballArrive(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        if ((sprite->y += 4) > sprite->data[3])
        {
            sprite->data[2] ++;
            sprite->data[0] = 0x16;
            PlaySE(SE_BALL_BOUNCE_1);
        }
    }
    else
    {
        if (sprite->data[0] == 0x42)
            PlaySE(SE_BALL_BOUNCE_2);
        if (sprite->data[0] == 0x5c)
            PlaySE(SE_BALL_BOUNCE_3);
        if (sprite->data[0] == 0x6b)
            PlaySE(SE_BALL_BOUNCE_4);
        sprite->y2 += sTradeBallVerticalVelocityTable[sprite->data[0]];
        if (++sprite->data[0] == 0x6c)
            sprite->callback = SpriteCallbackDummy;
    }
}

static void FadeToGachaScreen(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(InitGachaScreen);
            DestroyTask(taskId);
        }
        break;
    }
}

static void BGSetup(void)
{
    u16 size = 0x1480;

    InitBgsFromTemplates(0, sGachaBGtemplates, ARRAY_COUNT(sGachaBGtemplates));
    SetBgTilemapBuffer(GACHA_BG_BASE, AllocZeroed(BG_SCREEN_SIZE));
    DecompressAndLoadBgGfxUsingHeap(GACHA_BG_BASE, Gacha_BG_Main, size, 0, 0);
    CopyToBgTilemapBuffer(GACHA_BG_BASE, Gacha_BG_Main_Tilemap, 0, 0);
    ResetPaletteFade();

    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        LoadPalette(Gacha_BG_Basic_Pal, 0, PLTT_SIZE_4BPP);
        break;
    case GACHA_GREAT:
        LoadPalette(Gacha_BG_Great_Pal, 0, PLTT_SIZE_4BPP);
        break;
    case GACHA_ULTRA:
        LoadPalette(Gacha_BG_Ultra_Pal, 0, PLTT_SIZE_4BPP);
        break;
    case GACHA_MASTER:
        LoadPalette(Gacha_BG_Master_Pal, 0, PLTT_SIZE_4BPP);
        break;
    }
}

static void BGRed(void)
{
    u16 size = 0x1480;

    InitBgsFromTemplates(0, sGachaBGtemplates, ARRAY_COUNT(sGachaBGtemplates));
    SetBgTilemapBuffer(GACHA_BG_BASE, AllocZeroed(BG_SCREEN_SIZE));
    DecompressAndLoadBgGfxUsingHeap(GACHA_BG_BASE, Gacha_BG_Red, size, 0, 0);
    CopyToBgTilemapBuffer(GACHA_BG_BASE, Gacha_BG_Red_Tilemap, 0, 0);
    ResetPaletteFade();
    LoadPalette(Gacha_BG_Red_Pal, 0, PLTT_SIZE_4BPP);
}

static void Shake1(void)
{
    u16 size = 0x1480;

    InitBgsFromTemplates(0, sGachaBGtemplates, ARRAY_COUNT(sGachaBGtemplates));
    SetBgTilemapBuffer(GACHA_BG_BASE, AllocZeroed(BG_SCREEN_SIZE));
    DecompressAndLoadBgGfxUsingHeap(GACHA_BG_BASE, Gacha_BG_Left, size, 0, 0);
    CopyToBgTilemapBuffer(GACHA_BG_BASE, Gacha_BG_Left_Tilemap, 0, 0);
    ResetPaletteFade();

    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        LoadPalette(Gacha_BG_Basic_Pal, 0, PLTT_SIZE_4BPP);
        break;
    case GACHA_GREAT:
        LoadPalette(Gacha_BG_Great_Pal, 0, PLTT_SIZE_4BPP);
        break;
    case GACHA_ULTRA:
        LoadPalette(Gacha_BG_Ultra_Pal, 0, PLTT_SIZE_4BPP);
        break;
    case GACHA_MASTER:
        LoadPalette(Gacha_BG_Master_Pal, 0, PLTT_SIZE_4BPP);
        break;
    }
}

static void Shake2(void)
{
    u16 size = 0x1480;

    InitBgsFromTemplates(0, sGachaBGtemplates, ARRAY_COUNT(sGachaBGtemplates));
    SetBgTilemapBuffer(GACHA_BG_BASE, AllocZeroed(BG_SCREEN_SIZE));
    DecompressAndLoadBgGfxUsingHeap(GACHA_BG_BASE, Gacha_BG_Right, size, 0, 0);
    CopyToBgTilemapBuffer(GACHA_BG_BASE, Gacha_BG_Right_Tilemap, 0, 0);
    ResetPaletteFade();

    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        LoadPalette(Gacha_BG_Basic_Pal, 0, PLTT_SIZE_4BPP);
        break;
    case GACHA_GREAT:
        LoadPalette(Gacha_BG_Great_Pal, 0, PLTT_SIZE_4BPP);
        break;
    case GACHA_ULTRA:
        LoadPalette(Gacha_BG_Ultra_Pal, 0, PLTT_SIZE_4BPP);
        break;
    case GACHA_MASTER:
        LoadPalette(Gacha_BG_Master_Pal, 0, PLTT_SIZE_4BPP);
        break;
    }
}

static void GachaVBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void GachaMainCallback(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void SetCreditDigits(u16 num)
{
    u8 i;
    u16 d = 1000;

    for (i = 0; i < 4; i++)
    {
        u8 digit = num / d;

        gSprites[sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS]].invisible = FALSE;

        gSprites[sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS]].oam.tileNum =
            gSprites[sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS]].sheetTileStart + (digit * 2);

        gSprites[sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS]].oam.priority = 0;

        num = num % d;
        d = d / 10;
    }

    for (i = 0; i < 4; i++) {
        if (gSprites[sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS]].invisible == FALSE) {

        } else {
            gSprites[sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS]].invisible = FALSE;
        }
    }

    BuildOamBuffer();
}

static void SetPlayerDigits(u16 num)
{
    u8 i;
    u16 d = 1000;  // Start with the thousands place

    for (i = 0; i < 4; i++)  // Always show 4 digits
    {
        u8 digit = num / d;

        // Show the digit (all digits are visible)
        gSprites[sGacha->PlayerSpriteIds[i + SPR_PLAYER_DIGITS]].invisible = FALSE;

        // If it's a smaller number, show 0 for the higher place values
        if (i == 0 && num < 1000) {
            digit = 0;  // Force 0 for the thousands place if the number is less than 1000
        }

        // Set the tileNum based on the current digit
        gSprites[sGacha->PlayerSpriteIds[i + SPR_PLAYER_DIGITS]].oam.tileNum =
            gSprites[sGacha->PlayerSpriteIds[i + SPR_PLAYER_DIGITS]].sheetTileStart + (digit * 2);

        gSprites[sGacha->PlayerSpriteIds[i + SPR_PLAYER_DIGITS]].oam.priority = 0;

        // Reduce num for the next digit
        num = num % d;
        d = d / 10;
    }

    BuildOamBuffer();
}

static void CreateCreditSprites(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sSpriteSheets_Interface) - 1; i++)  
    {
        LoadCompressedSpriteSheet(&sSpriteSheets_Interface[i]);
    }

    for (i = 0; i < MAX_COIN_DIGITS; i++)
    {
        if (i == 0)
        {
            sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS] = CreateSprite(&sSpriteTemplate_CreditDigit, 207, 140, 2);
            gSprites[sGacha->PlayerSpriteIds[i + SPR_CREDIT_DIGITS]].oam.priority = 0;
        }
        if (i == 1)
        {
            sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS] = CreateSprite(&sSpriteTemplate_CreditDigit, 8 + 207, 140, 2);
            gSprites[sGacha->PlayerSpriteIds[i + SPR_CREDIT_DIGITS]].oam.priority = 0;
        }
        if (i == 2)
        {
            sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS] = CreateSprite(&sSpriteTemplate_CreditDigit, 16 + 207, 140, 2);
            gSprites[sGacha->PlayerSpriteIds[i + SPR_CREDIT_DIGITS]].oam.priority = 0;
        }
        if (i == 3)
        {
            sGacha->CreditSpriteIds[i + SPR_CREDIT_DIGITS] = CreateSprite(&sSpriteTemplate_CreditDigit, 24 + 207, 140, 2);
            gSprites[sGacha->PlayerSpriteIds[i + SPR_CREDIT_DIGITS]].oam.priority = 0;
        }
    }
}

static void CreatePlayerSprites(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sSpriteSheets_PlayerInterface) - 1; i++)  
    {
        LoadCompressedSpriteSheet(&sSpriteSheets_PlayerInterface[i]);
    }

    for (i = 0; i < 4; i++)
    {
        sGacha->PlayerSpriteIds[i + SPR_PLAYER_DIGITS] = CreateSprite(&sSpriteTemplate_PlayerDigit, i * 8 + 207, 118, 2);
        gSprites[sGacha->PlayerSpriteIds[i + SPR_PLAYER_DIGITS]].oam.priority = 0;
    }
}

static void CreateCTA(void)
{
    LoadCompressedSpriteSheet(&sSpriteSheet_Press_A);
    sGacha->CTAspriteId = CreateSprite(&sSpriteTemplate_Press_A, 152, 116, 0);
    gSprites[sGacha->CTAspriteId].animNum = 0; // Off
}

static void CreateArrows(void)
{
    LoadCompressedSpriteSheet(&sSpriteSheet_Arrows);
    sGacha->ArrowsSpriteId = CreateSprite(&sSpriteTemplate_Arrows, 207 + 24, 120, 0);
    gSprites[sGacha->ArrowsSpriteId].animNum = 1; // Only Up
}

static void CreateLotteryJPN(void)
{
    LoadCompressedSpriteSheet(&sSpriteSheet_Lottery_JPN);
    sGacha->LotteryJPNspriteId = CreateSprite(&sSpriteTemplate_Lottery_JPN, 176, 32, 0);
}

static void CreateHoppip(void)
{
    s16 x = 142;
    s16 y = 56;
    s16 x2 = x + 34;
    s16 x3 = x + 68;

    LoadCompressedSpriteSheet(&sSpriteSheet_Hoppip);
    sGacha->PokemonOneSpriteId = CreateSprite(&sSpriteTemplate_Hoppip, x, y, 0);
    sGacha->PokemonTwoSpriteId = CreateSprite(&sSpriteTemplate_Hoppip, x2, y, 0);    
    sGacha->PokemonThreeSpriteId = CreateSprite(&sSpriteTemplate_Hoppip, x3, y, 0);    
}

static UNUSED void CreateElekid(void)
{
    s16 x = 142;
    s16 y = 56 + 2;
    s16 x2 = x + 34;
    s16 x3 = x + 68;

    LoadCompressedSpriteSheet(&sSpriteSheet_Elekid);
    sGacha->PokemonOneSpriteId = CreateSprite(&sSpriteTemplate_Elekid, x, y, 0);
    sGacha->PokemonTwoSpriteId = CreateSprite(&sSpriteTemplate_Elekid, x2, y, 0);
    sGacha->PokemonThreeSpriteId = CreateSprite(&sSpriteTemplate_Elekid, x3, y, 0);    
}

static void CreateTeddiursa(void)
{
    s16 x = 142;
    s16 y = 56;
    s16 x2 = x + 34;
    s16 x3 = x + 68;

    LoadCompressedSpriteSheet(&sSpriteSheet_Teddiursa);
    sGacha->PokemonOneSpriteId = CreateSprite(&sSpriteTemplate_Teddiursa, x, y, 0);
    sGacha->PokemonTwoSpriteId = CreateSprite(&sSpriteTemplate_Teddiursa, x2, y, 0);    
    sGacha->PokemonThreeSpriteId = CreateSprite(&sSpriteTemplate_Teddiursa, x3, y, 0);
}

static void CreatePhanpy(void)
{
    s16 x = 142;
    s16 y = 56;
    s16 x2 = x + 34;
    s16 x3 = x + 68;

    LoadCompressedSpriteSheet(&sSpriteSheet_Phanpy);
    sGacha->PokemonOneSpriteId = CreateSprite(&sSpriteTemplate_Phanpy, x, y, 0);
    sGacha->PokemonTwoSpriteId = CreateSprite(&sSpriteTemplate_Phanpy, x2, y, 0);
    sGacha->PokemonThreeSpriteId = CreateSprite(&sSpriteTemplate_Phanpy, x3, y, 0);
}

static void CreateBelossom(void)
{
    s16 x = 142;
    s16 y = 56;
    s16 x2 = x + 34;
    s16 x3 = x + 68;

    LoadCompressedSpriteSheet(&sSpriteSheet_Belossom);
    sGacha->PokemonOneSpriteId = CreateSprite(&sSpriteTemplate_Belossom, x, y, 0);
    sGacha->PokemonTwoSpriteId = CreateSprite(&sSpriteTemplate_Belossom, x2, y, 0);    
    sGacha->PokemonThreeSpriteId = CreateSprite(&sSpriteTemplate_Belossom, x3, y, 0);

}

static void CreateDigitalText(void)
{
    LoadCompressedSpriteSheet(&sSpriteSheet_Digital_Text);
    sGacha->DigitalTextSpriteId = CreateSprite(&sSpriteTemplate_Digital_Text, 64, 25, 0);
}

static void CreateCreditMenu(void)
{
    s16 x = 144;
    s16 y = 128;
    u8 priority = 1;

    LoadCompressedSpriteSheet(&sSpriteSheet_Menu_1);

    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        sGacha->CreditMenu1Id = CreateSprite(&sSpriteTemplate_Menu_1_Basic, x, y, priority);
        break;
    case GACHA_GREAT:
        sGacha->CreditMenu1Id = CreateSprite(&sSpriteTemplate_Menu_1_Great, x, y, priority);
        break;
    case GACHA_ULTRA:
        sGacha->CreditMenu1Id = CreateSprite(&sSpriteTemplate_Menu_1_Ultra, x, y, priority);
        break;
    case GACHA_MASTER:
        sGacha->CreditMenu1Id = CreateSprite(&sSpriteTemplate_Menu_1_Master, x, y, priority);
        break;
    }
    gSprites[sGacha->CreditMenu1Id].oam.priority = 1;
}

static void CreatePlayerMenu(void)
{
    s16 x = 144;
    s16 y = 128;
    s16 x2 = x + 64;
    u8 priority = 1;

    LoadCompressedSpriteSheet(&sSpriteSheet_Menu_2);

    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        sGacha->CreditMenu2Id = CreateSprite(&sSpriteTemplate_Menu_2_Basic, x2, y, priority);
        break;
    case GACHA_GREAT:
        sGacha->CreditMenu2Id = CreateSprite(&sSpriteTemplate_Menu_2_Great, x2, y, priority);
        break;
    case GACHA_ULTRA:
        sGacha->CreditMenu2Id = CreateSprite(&sSpriteTemplate_Menu_2_Ultra, x2, y, priority);
        break;
    case GACHA_MASTER:
        sGacha->CreditMenu2Id = CreateSprite(&sSpriteTemplate_Menu_2_Master, x2, y, priority);
        break;
    }
    gSprites[sGacha->CreditMenu2Id].oam.priority = 1;
}

static void CreateKnob(void)
{
    LoadCompressedSpriteSheet(&sSpriteSheet_Knob);
    sGacha->KnobSpriteId = CreateSprite(&sSpriteTemplate_Knob, 76, 128, 0);
    gSprites[sGacha->KnobSpriteId].animNum = 0; // No Rotation
}

static const u16 sGachaBasicSpeciesCommon[] = {
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PIDGEY,
    SPECIES_RATTATA,
    SPECIES_SPEAROW,
    SPECIES_SENTRET,
    SPECIES_HOOTHOOT,
    SPECIES_LEDYBA,
    SPECIES_SPINARAK,
    SPECIES_POOCHYENA,
    SPECIES_ZIGZAGOON,
    SPECIES_WURMPLE,
    SPECIES_TAILLOW,
    SPECIES_STARLY,
    SPECIES_BIDOOF,
    SPECIES_KRICKETOT,
    SPECIES_SHINX,
    SPECIES_BURMY_PLANT,
    SPECIES_BURMY_SANDY,
    SPECIES_BURMY_TRASH,
    SPECIES_PATRAT,
    SPECIES_LILLIPUP,
    SPECIES_PURRLOIN,
    SPECIES_PIDOVE,
    SPECIES_SEWADDLE,
    SPECIES_VENIPEDE,
    SPECIES_BUNNELBY,
    SPECIES_FLETCHLING,
    SPECIES_SCATTERBUG_ICY_SNOW,
    SPECIES_SCATTERBUG_POLAR,
    SPECIES_SCATTERBUG_TUNDRA,
    SPECIES_SCATTERBUG_CONTINENTAL,
    SPECIES_SCATTERBUG_GARDEN,
    SPECIES_SCATTERBUG_ELEGANT,
    SPECIES_SCATTERBUG_MEADOW,
    SPECIES_SCATTERBUG_MODERN,
    SPECIES_SCATTERBUG_MARINE,
    SPECIES_SCATTERBUG_ARCHIPELAGO,
    SPECIES_SCATTERBUG_HIGH_PLAINS,
    SPECIES_SCATTERBUG_SANDSTORM,
    SPECIES_SCATTERBUG_RIVER,
    SPECIES_SCATTERBUG_MONSOON,
    SPECIES_SCATTERBUG_SAVANNA,
    SPECIES_SCATTERBUG_SUN,
    SPECIES_SCATTERBUG_OCEAN,
    SPECIES_SCATTERBUG_JUNGLE,
    SPECIES_SCATTERBUG_FANCY,
    SPECIES_SCATTERBUG_POKEBALL,
    SPECIES_LITLEO,
    SPECIES_FLABEBE_RED,
    SPECIES_FLABEBE_YELLOW,
    SPECIES_FLABEBE_ORANGE,
    SPECIES_FLABEBE_BLUE,
    SPECIES_FLABEBE_WHITE,
    SPECIES_PIKIPEK,
    SPECIES_YUNGOOS,
    SPECIES_GRUBBIN,
    SPECIES_SKWOVET,
    SPECIES_ROOKIDEE,
    SPECIES_BLIPBUG,
    SPECIES_NICKIT,
    SPECIES_LECHONK,
    SPECIES_TAROUNTULA,
    SPECIES_NYMBLE,
    SPECIES_PAWMI,
    SPECIES_WATTREL
};

static const u16 sGachaBasicSpeciesUncommon[] = {
    SPECIES_METAPOD,
    SPECIES_KAKUNA,
    SPECIES_PIDGEOTTO,
    SPECIES_SILCOON,
    SPECIES_CASCOON,
    SPECIES_STARAVIA,
    SPECIES_LUXIO,
    SPECIES_HERDIER,
    SPECIES_TRANQUILL,
    SPECIES_SWADLOON,
    SPECIES_WHIRLIPEDE,
    SPECIES_FLETCHINDER,
    SPECIES_SPEWPA_ICY_SNOW,
    SPECIES_SPEWPA_POLAR,
    SPECIES_SPEWPA_TUNDRA,
    SPECIES_SPEWPA_CONTINENTAL,
    SPECIES_SPEWPA_GARDEN,
    SPECIES_SPEWPA_ELEGANT,
    SPECIES_SPEWPA_MEADOW,
    SPECIES_SPEWPA_MODERN,
    SPECIES_SPEWPA_MARINE,
    SPECIES_SPEWPA_ARCHIPELAGO,
    SPECIES_SPEWPA_HIGH_PLAINS,
    SPECIES_SPEWPA_SANDSTORM,
    SPECIES_SPEWPA_RIVER,
    SPECIES_SPEWPA_MONSOON,
    SPECIES_SPEWPA_SAVANNA,
    SPECIES_SPEWPA_SUN,
    SPECIES_SPEWPA_OCEAN,
    SPECIES_SPEWPA_JUNGLE,
    SPECIES_SPEWPA_FANCY,
    SPECIES_SPEWPA_POKEBALL,
    SPECIES_FLOETTE_RED,
    SPECIES_FLOETTE_YELLOW,
    SPECIES_FLOETTE_ORANGE,
    SPECIES_FLOETTE_BLUE,
    SPECIES_FLOETTE_WHITE,
    SPECIES_TRUMBEAK,
    SPECIES_CHARJABUG,
    SPECIES_CORVISQUIRE,
    SPECIES_DOTTLER,
    SPECIES_PAWMO
};

static const u16 sGachaBasicSpeciesRare[] = {
    SPECIES_BUTTERFREE,
    SPECIES_BEEDRILL,
    SPECIES_PIDGEOT,
    SPECIES_RATICATE,
    SPECIES_FEAROW,
    SPECIES_FURRET,
    SPECIES_NOCTOWL,
    SPECIES_LEDIAN,
    SPECIES_ARIADOS,
    SPECIES_MIGHTYENA,
    SPECIES_LINOONE,
    SPECIES_BEAUTIFLY,
    SPECIES_DUSTOX,
    SPECIES_SWELLOW,
    SPECIES_STARAPTOR,
    SPECIES_BIBAREL,
    SPECIES_KRICKETUNE,
    SPECIES_LUXRAY,
    SPECIES_WORMADAM_PLANT,
    SPECIES_WORMADAM_SANDY,
    SPECIES_WORMADAM_TRASH,
    SPECIES_MOTHIM_PLANT,
    SPECIES_WATCHOG,
    SPECIES_STOUTLAND,
    SPECIES_LIEPARD,
    SPECIES_UNFEZANT,
    SPECIES_LEAVANNY,
    SPECIES_SCOLIPEDE,
    SPECIES_DIGGERSBY,
    SPECIES_TALONFLAME,
    SPECIES_VIVILLON_ICY_SNOW,
    SPECIES_VIVILLON_POLAR,
    SPECIES_VIVILLON_TUNDRA,
    SPECIES_VIVILLON_CONTINENTAL,
    SPECIES_VIVILLON_GARDEN,
    SPECIES_VIVILLON_ELEGANT,
    SPECIES_VIVILLON_MEADOW,
    SPECIES_VIVILLON_MODERN,
    SPECIES_VIVILLON_MARINE,
    SPECIES_VIVILLON_ARCHIPELAGO,
    SPECIES_VIVILLON_HIGH_PLAINS,
    SPECIES_VIVILLON_SANDSTORM,
    SPECIES_VIVILLON_RIVER,
    SPECIES_VIVILLON_MONSOON,
    SPECIES_VIVILLON_SAVANNA,
    SPECIES_VIVILLON_SUN,
    SPECIES_VIVILLON_OCEAN,
    SPECIES_VIVILLON_JUNGLE,
    SPECIES_VIVILLON_FANCY,
    SPECIES_VIVILLON_POKEBALL,
    SPECIES_PYROAR,
    SPECIES_FLORGES_RED,
    SPECIES_FLORGES_YELLOW,
    SPECIES_FLORGES_ORANGE,
    SPECIES_FLORGES_BLUE,
    SPECIES_FLORGES_WHITE,
    SPECIES_TOUCANNON,
    SPECIES_GUMSHOOS,
    SPECIES_VIKAVOLT,
    SPECIES_GREEDENT,
    SPECIES_CORVIKNIGHT,
    SPECIES_ORBEETLE,
    SPECIES_THIEVUL,
    SPECIES_OINKOLOGNE_M,
    SPECIES_OINKOLOGNE_F,
    SPECIES_SPIDOPS,
    SPECIES_LOKIX,
    SPECIES_PAWMOT,
    SPECIES_KILOWATTREL
};

static const u16 sGachaBasicSpeciesUltraRare[] = {
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_CHIKORITA,
    SPECIES_CYNDAQUIL,
    SPECIES_TOTODILE,
    SPECIES_TREECKO,
    SPECIES_MUDKIP,
    SPECIES_TORCHIC,
    SPECIES_TURTWIG,
    SPECIES_CHIMCHAR,
    SPECIES_PIPLUP,
    SPECIES_SNIVY,
    SPECIES_TEPIG,
    SPECIES_PIGNITE,
    SPECIES_CHESPIN,
    SPECIES_FENNEKIN,
    SPECIES_FROAKIE,
    SPECIES_ROWLET,
    SPECIES_LITTEN,
    SPECIES_POPPLIO,
    SPECIES_GROOKEY,
    SPECIES_SCORBUNNY,
    SPECIES_SOBBLE,
    SPECIES_SPRIGATITO,
    SPECIES_FUECOCO,
    SPECIES_QUAXLY
};

static const u16 sGachaGreatSpeciesCommon[] = {
    SPECIES_EKANS,
    SPECIES_SANDSHREW,
    SPECIES_NIDORAN_F,
    SPECIES_NIDORAN_M,
    SPECIES_VULPIX,
    SPECIES_ZUBAT,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_VENONAT,
    SPECIES_DIGLETT,
    SPECIES_MEOWTH,
    SPECIES_PSYDUCK,
    SPECIES_MANKEY,
    SPECIES_GROWLITHE,
    SPECIES_POLIWAG,
    SPECIES_ABRA,
    SPECIES_MACHOP,
    SPECIES_BELLSPROUT,
    SPECIES_TENTACOOL,
    SPECIES_GEODUDE,
    SPECIES_PONYTA,
    SPECIES_SLOWPOKE,
    SPECIES_MAGNEMITE,
    SPECIES_DODUO,
    SPECIES_SEEL,
    SPECIES_GRIMER,
    SPECIES_SHELLDER,
    SPECIES_GASTLY,
    SPECIES_DROWZEE,
    SPECIES_KRABBY,
    SPECIES_VOLTORB,
    SPECIES_EXEGGCUTE,
    SPECIES_CUBONE,
    SPECIES_KOFFING,
    SPECIES_RHYHORN,
    SPECIES_TANGELA,
    SPECIES_HORSEA,
    SPECIES_GOLDEEN,
    SPECIES_STARYU,
    SPECIES_MAGIKARP,
    SPECIES_CHINCHOU,
    SPECIES_PICHU,
    SPECIES_CLEFFA,
    SPECIES_IGGLYBUFF,
    SPECIES_NATU,
    SPECIES_MAREEP,
    SPECIES_HOPPIP,
    SPECIES_AIPOM,
    SPECIES_SUNKERN,
    SPECIES_YANMA,
    SPECIES_WOOPER,
    SPECIES_UNOWN,
    SPECIES_UNOWN_B,
    SPECIES_UNOWN_C,
    SPECIES_UNOWN_D,
    SPECIES_UNOWN_E,
    SPECIES_UNOWN_F,
    SPECIES_UNOWN_G,
    SPECIES_UNOWN_H,
    SPECIES_UNOWN_I,
    SPECIES_UNOWN_J,
    SPECIES_UNOWN_K,
    SPECIES_UNOWN_L,
    SPECIES_UNOWN_M,
    SPECIES_UNOWN_N,
    SPECIES_UNOWN_O,
    SPECIES_UNOWN_P,
    SPECIES_UNOWN_Q,
    SPECIES_UNOWN_R,
    SPECIES_UNOWN_S,
    SPECIES_UNOWN_T,
    SPECIES_UNOWN_U,
    SPECIES_UNOWN_V,
    SPECIES_UNOWN_W,
    SPECIES_UNOWN_X,
    SPECIES_UNOWN_Y,
    SPECIES_UNOWN_Z,
    SPECIES_UNOWN_EXCLAMATION,
    SPECIES_UNOWN_QUESTION,
    SPECIES_PINECO,
    SPECIES_SNUBBULL,
    SPECIES_TEDDIURSA,
    SPECIES_SLUGMA,
    SPECIES_SWINUB,
    SPECIES_REMORAID,
    SPECIES_HOUNDOUR,
    SPECIES_PHANPY,
    SPECIES_SMOOCHUM,
    SPECIES_ELEKID,
    SPECIES_MAGBY,
    SPECIES_LOTAD,
    SPECIES_SEEDOT,
    SPECIES_WINGULL,
    SPECIES_SURSKIT,
    SPECIES_SHROOMISH,
    SPECIES_NINCADA,
    SPECIES_WHISMUR,
    SPECIES_MAKUHITA,
    SPECIES_AZURILL,
    SPECIES_NOSEPASS,
    SPECIES_SKITTY,
    SPECIES_DELCATTY,
    SPECIES_MEDITITE,
    SPECIES_ELECTRIKE,
    SPECIES_PLUSLE,
    SPECIES_MINUN,
    SPECIES_VOLBEAT,
    SPECIES_ILLUMISE,
    SPECIES_GULPIN,
    SPECIES_CARVANHA,
    SPECIES_NUMEL,
    SPECIES_TORKOAL,
    SPECIES_SPOINK,
    SPECIES_TRAPINCH,
    SPECIES_CACNEA,
    SPECIES_SWABLU,
    SPECIES_BARBOACH,
    SPECIES_CORPHISH,
    SPECIES_BALTOY,
    SPECIES_SHUPPET,
    SPECIES_DUSKULL,
    SPECIES_TROPIUS,
    SPECIES_SNORUNT,
    SPECIES_SPHEAL,
    SPECIES_BUDEW,
    SPECIES_COMBEE,
    SPECIES_PACHIRISU,
    SPECIES_BUIZEL,
    SPECIES_CHERUBI,
    SPECIES_SHELLOS_WEST,
    SPECIES_SHELLOS_EAST,
    SPECIES_AMBIPOM,
    SPECIES_DRIFLOON,
    SPECIES_BUNEARY,
    SPECIES_HONCHKROW,
    SPECIES_GLAMEOW,
    SPECIES_CHINGLING,
    SPECIES_STUNKY,
    SPECIES_BRONZOR,
    SPECIES_BONSLY,
    SPECIES_MUNCHLAX,
    SPECIES_MIME_JR,
    SPECIES_HAPPINY,
    SPECIES_CHATOT,
    SPECIES_SPIRITOMB,
    SPECIES_RIOLU,
    SPECIES_HIPPOPOTAS,
    SPECIES_SKORUPI,
    SPECIES_CROAGUNK,
    SPECIES_TOXICROAK,
    SPECIES_CARNIVINE,
    SPECIES_FINNEON,
    SPECIES_MANTYKE,
    SPECIES_SNOVER,
    SPECIES_PANSAGE,
    SPECIES_PANSEAR,
    SPECIES_PANPOUR,
    SPECIES_MUNNA,
    SPECIES_BLITZLE,
    SPECIES_ROGGENROLA,
    SPECIES_WOOBAT,
    SPECIES_DRILBUR,
    SPECIES_AUDINO,
    SPECIES_TIMBURR,
    SPECIES_TYMPOLE,
    SPECIES_COTTONEE,
    SPECIES_PETILIL,
    SPECIES_BASCULIN_RED_STRIPED,
    SPECIES_BASCULIN_BLUE_STRIPED,
    SPECIES_BASCULIN_WHITE_STRIPED,
    SPECIES_SANDILE,
    SPECIES_DARUMAKA,
    SPECIES_DWEBBLE,
    SPECIES_SCRAGGY,
    SPECIES_SIGILYPH,
    SPECIES_TRUBBISH,
    SPECIES_ZORUA,
    SPECIES_MINCCINO,
    SPECIES_GOTHITA,
    SPECIES_SOLOSIS,
    SPECIES_DUCKLETT,
    SPECIES_SWANNA,
    SPECIES_VANILLITE,
    SPECIES_DEERLING_SPRING,
    SPECIES_DEERLING_SUMMER,
    SPECIES_DEERLING_AUTUMN,
    SPECIES_DEERLING_WINTER,
    SPECIES_KARRABLAST,
    SPECIES_FOONGUS,
    SPECIES_FRILLISH,
    SPECIES_JOLTIK,
    SPECIES_FERROSEED,
    SPECIES_KLINK,
    SPECIES_TYNAMO,
    SPECIES_ELGYEM,
    SPECIES_LITWICK,
    SPECIES_CUBCHOO,
    SPECIES_SHELMET,
    SPECIES_STUNFISK,
    SPECIES_MIENFOO,
    SPECIES_GOLETT,
    SPECIES_PAWNIARD,
    SPECIES_RUFFLET,
    SPECIES_VULLABY,
    SPECIES_FURFROU_NATURAL,
    SPECIES_FURFROU_HEART,
    SPECIES_FURFROU_STAR,
    SPECIES_FURFROU_DIAMOND,
    SPECIES_FURFROU_DEBUTANTE,
    SPECIES_FURFROU_MATRON,
    SPECIES_FURFROU_DANDY,
    SPECIES_FURFROU_LA_REINE,
    SPECIES_FURFROU_KABUKI,
    SPECIES_FURFROU_PHARAOH,
    SPECIES_SKIDDO,
    SPECIES_PANCHAM,
    SPECIES_ESPURR,
    SPECIES_HONEDGE,
    SPECIES_SPRITZEE,
    SPECIES_SWIRLIX,
    SPECIES_INKAY,
    SPECIES_BINACLE,
    SPECIES_SKRELP,
    SPECIES_CLAUNCHER,
    SPECIES_HELIOPTILE,
    SPECIES_CARBINK,
    SPECIES_PHANTUMP,
    SPECIES_PUMPKABOO_SMALL,
    SPECIES_PUMPKABOO_LARGE,
    SPECIES_PUMPKABOO_SUPER,
    SPECIES_PUMPKABOO_AVERAGE,
    SPECIES_BERGMITE,
    SPECIES_NOIBAT,
    SPECIES_CRABRAWLER,
    SPECIES_CUTIEFLY,
    SPECIES_ORICORIO_BAILE,
    SPECIES_ORICORIO_POM_POM,
    SPECIES_ORICORIO_PAU,
    SPECIES_ORICORIO_SENSU,
    SPECIES_ROCKRUFF_OWN_TEMPO,
    SPECIES_ROCKRUFF,
    SPECIES_MAREANIE,
    SPECIES_MUDBRAY,
    SPECIES_DEWPIDER,
    SPECIES_FOMANTIS,
    SPECIES_MORELULL,
    SPECIES_SALANDIT,
    SPECIES_STUFFUL,
    SPECIES_BOUNSWEET,
    SPECIES_COMFEY,
    SPECIES_WIMPOD,
    SPECIES_SANDYGAST,
    SPECIES_PYUKUMUKU,
    SPECIES_MINIOR_RED,
    SPECIES_MINIOR_METEOR_ORANGE,
    SPECIES_MINIOR_METEOR_YELLOW,
    SPECIES_MINIOR_METEOR_GREEN,
    SPECIES_MINIOR_METEOR_BLUE,
    SPECIES_MINIOR_METEOR_INDIGO,
    SPECIES_MINIOR_METEOR_VIOLET,
    SPECIES_KOMALA,
    SPECIES_BRUXISH,
    SPECIES_GOSSIFLEUR,
    SPECIES_WOOLOO,
    SPECIES_CHEWTLE,
    SPECIES_YAMPER,
    SPECIES_ROLYCOLY,
    SPECIES_APPLIN,
    SPECIES_SILICOBRA,
    SPECIES_CRAMORANT,
    SPECIES_ARROKUDA,
    SPECIES_TOXEL,
    SPECIES_SIZZLIPEDE,
    SPECIES_CLOBBOPUS,
    SPECIES_HATENNA,
    SPECIES_IMPIDIMP,
    SPECIES_MILCERY,
    SPECIES_PINCURCHIN,
    SPECIES_SNOM,
    SPECIES_CUFANT,
    SPECIES_TANDEMAUS,
    SPECIES_FIDOUGH,
    SPECIES_SMOLIV,
    SPECIES_SQUAWKABILLY_GREEN,
    SPECIES_SQUAWKABILLY_BLUE,
    SPECIES_SQUAWKABILLY_YELLOW,
    SPECIES_SQUAWKABILLY_WHITE,
    SPECIES_NACLI,
    SPECIES_CHARCADET,
    SPECIES_TADBULB,
    SPECIES_MASCHIFF,
    SPECIES_SHROODLE,
    SPECIES_BRAMBLIN,
    SPECIES_TOEDSCOOL,
    SPECIES_CAPSAKID,
    SPECIES_RELLOR,
    SPECIES_FLITTLE,
    SPECIES_TINKATINK,
    SPECIES_WIGLETT,
    SPECIES_VAROOM,
    SPECIES_GLIMMET,
    SPECIES_GREAVARD,
    SPECIES_CETODDLE,
    SPECIES_RATTATA_ALOLA,
    SPECIES_SANDSHREW_ALOLA,
    SPECIES_VULPIX_ALOLA,
    SPECIES_DIGLETT_ALOLA,
    SPECIES_MEOWTH_ALOLA,
    SPECIES_MEOWTH_GALAR,
    SPECIES_GEODUDE_ALOLA,
    SPECIES_GRIMER_ALOLA,
    SPECIES_EXEGGUTOR_ALOLA,
    SPECIES_PONYTA_GALAR,
    SPECIES_SLOWPOKE_GALAR,
    SPECIES_FARFETCHD_GALAR,
    SPECIES_ZIGZAGOON_GALAR,
    SPECIES_DARUMAKA_GALAR,
    SPECIES_VOLTORB_HISUI,
    SPECIES_SNEASEL_HISUI,
    SPECIES_ZORUA_HISUI,
    SPECIES_QWILFISH_HISUI,
    SPECIES_YAMASK_GALAR,
    SPECIES_GROWLITHE_HISUI,
    SPECIES_WOOPER_PALDEA
};

static const u16 sGachaGreatSpeciesUncommon[] = {
    SPECIES_MR_MIME,
    SPECIES_JYNX,
    SPECIES_ELECTABUZZ,
    SPECIES_MAGMAR,
    SPECIES_VAPOREON,
    SPECIES_JOLTEON,
    SPECIES_FLAREON,
    SPECIES_TAUROS  ,
    SPECIES_LAPRAS,
    SPECIES_FARFETCHD,
    SPECIES_ONIX,
    SPECIES_LICKITUNG,
    SPECIES_KANGASKHAN,
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
    SPECIES_DITTO,
    SPECIES_EEVEE,
    SPECIES_PORYGON,
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
    SPECIES_ARBOK,
    SPECIES_PIKACHU,
    SPECIES_SANDSLASH,
    SPECIES_NIDORINA,
    SPECIES_NIDORINO,
    SPECIES_CLEFAIRY,
    SPECIES_NINETALES,
    SPECIES_JIGGLYPUFF,
    SPECIES_GOLBAT,
    SPECIES_GLOOM,
    SPECIES_PARASECT,
    SPECIES_VENOMOTH,
    SPECIES_DUGTRIO,
    SPECIES_PERSIAN,
    SPECIES_GOLDUCK,
    SPECIES_PRIMEAPE,
    SPECIES_ARCANINE,
    SPECIES_POLIWHIRL,
    SPECIES_KADABRA,
    SPECIES_MACHOKE,
    SPECIES_WEEPINBELL,
    SPECIES_TENTACRUEL,
    SPECIES_GRAVELER,
    SPECIES_RAPIDASH,
    SPECIES_SLOWBRO,
    SPECIES_MAGNETON,
    SPECIES_DODRIO,
    SPECIES_MUK,
    SPECIES_DEWGONG,
    SPECIES_CLOYSTER,
    SPECIES_HAUNTER,
    SPECIES_HYPNO,
    SPECIES_KINGLER,
    SPECIES_ELECTRODE,
    SPECIES_EXEGGUTOR,
    SPECIES_MAROWAK,
    SPECIES_HITMONLEE,
    SPECIES_HITMONCHAN,
    SPECIES_WEEZING,
    SPECIES_RHYDON,
    SPECIES_CHANSEY,
    SPECIES_SEADRA,
    SPECIES_SEAKING,
    SPECIES_STARMIE,
    SPECIES_GYARADOS,
    SPECIES_GIRAFARIG,
    SPECIES_DUNSPARCE,
    SPECIES_TYROGUE,
    SPECIES_SMEARGLE,
    SPECIES_DELIBIRD,
    SPECIES_MILTANK,
    SPECIES_GLIGAR,
    SPECIES_QWILFISH,
    SPECIES_SHUCKLE,
    SPECIES_STANTLER,
    SPECIES_HERACROSS,
    SPECIES_CORSOLA,
    SPECIES_SNEASEL,
    SPECIES_SKARMORY,
    SPECIES_TOGEPI,
    SPECIES_MISDREAVUS,
    SPECIES_MURKROW,
    SPECIES_LANTURN,
    SPECIES_TOGETIC,
    SPECIES_XATU,
    SPECIES_FLAAFFY,
    SPECIES_MARILL,
    SPECIES_SUDOWOODO,
    SPECIES_SKIPLOOM,
    SPECIES_SUNFLORA,
    SPECIES_QUAGSIRE,
    SPECIES_ESPEON,
    SPECIES_UMBREON,
    SPECIES_SLOWKING,
    SPECIES_WOBBUFFET,
    SPECIES_FORRETRESS,
    SPECIES_STEELIX,
    SPECIES_SCIZOR,
    SPECIES_GRANBULL,
    SPECIES_URSARING,
    SPECIES_MAGCARGO,
    SPECIES_PILOSWINE,
    SPECIES_OCTILLERY,
    SPECIES_MANTINE,
    SPECIES_HOUNDOOM,
    SPECIES_DONPHAN,
    SPECIES_PORYGON2,
    SPECIES_HITMONTOP,
    SPECIES_RALTS,
    SPECIES_SLAKOTH,
    SPECIES_SABLEYE,
    SPECIES_MAWILE,
    SPECIES_ARON,
    SPECIES_SPINDA,
    SPECIES_ZANGOOSE,
    SPECIES_SEVIPER,
    SPECIES_LUNATONE,
    SPECIES_SOLROCK,
    SPECIES_LILEEP,
    SPECIES_ANORITH,
    SPECIES_FEEBAS,
    SPECIES_CASTFORM_NORMAL,
    SPECIES_CASTFORM_SUNNY,
    SPECIES_CASTFORM_RAINY,
    SPECIES_CASTFORM_SNOWY,
    SPECIES_KECLEON,
    SPECIES_ABSOL,
    SPECIES_WYNAUT,
    SPECIES_CLAMPERL,
    SPECIES_RELICANTH,
    SPECIES_LUVDISC,
    SPECIES_LOMBRE,
    SPECIES_NUZLEAF,
    SPECIES_PELIPPER,
    SPECIES_KIRLIA,
    SPECIES_MASQUERAIN,
    SPECIES_BRELOOM,
    SPECIES_VIGOROTH,
    SPECIES_NINJASK,
    SPECIES_SHEDINJA,
    SPECIES_LOUDRED,
    SPECIES_HARIYAMA,
    SPECIES_LAIRON,
    SPECIES_MEDICHAM,
    SPECIES_MANECTRIC,
    SPECIES_ROSELIA,
    SPECIES_SWALOT,
    SPECIES_WAILMER,
    SPECIES_WAILORD,
    SPECIES_CAMERUPT,
    SPECIES_SHARPEDO,
    SPECIES_GRUMPIG,
    SPECIES_VIBRAVA,
    SPECIES_CACTURNE,
    SPECIES_ALTARIA,
    SPECIES_WHISCASH,
    SPECIES_CRAWDAUNT,
    SPECIES_CLAYDOL,
    SPECIES_CRADILY,
    SPECIES_ARMALDO,
    SPECIES_MILOTIC,
    SPECIES_BANETTE,
    SPECIES_DUSCLOPS,
    SPECIES_CHIMECHO,
    SPECIES_SEALEO,
    SPECIES_GLALIE,
    SPECIES_HUNTAIL,
    SPECIES_GOREBYSS,
    SPECIES_CRANIDOS,
    SPECIES_SHIELDON,
    SPECIES_VESPIQUEN,
    SPECIES_FLOATZEL,
    SPECIES_CHERRIM,
    SPECIES_GASTRODON_WEST,
    SPECIES_GASTRODON_EAST,
    SPECIES_DRIFBLIM,
    SPECIES_MISMAGIUS,
    SPECIES_LOPUNNY,
    SPECIES_PURUGLY,
    SPECIES_SKUNTANK,
    SPECIES_BRONZONG,
    SPECIES_LUCARIO,
    SPECIES_HIPPOWDON,
    SPECIES_DRAPION,
    SPECIES_LUMINEON,
    SPECIES_ABOMASNOW,
    SPECIES_WEAVILE,
    SPECIES_LICKILICKY,
    SPECIES_TANGROWTH,
    SPECIES_YANMEGA,
    SPECIES_LEAFEON,
    SPECIES_GLACEON,
    SPECIES_GLISCOR,
    SPECIES_PROBOPASS,
    SPECIES_FROSLASS,
    SPECIES_THROH,
    SPECIES_SAWK,
    SPECIES_YAMASK,
    SPECIES_TIRTOUGA,
    SPECIES_ARCHEN,
    SPECIES_MARACTUS,
    SPECIES_EMOLGA,
    SPECIES_ALOMOMOLA,
    SPECIES_AXEW,
    SPECIES_CRYOGONAL,
    SPECIES_DRUDDIGON,
    SPECIES_BOUFFALANT,
    SPECIES_HEATMOR,
    SPECIES_DURANT,
    SPECIES_LARVESTA,
    SPECIES_SIMISAGE,
    SPECIES_SIMISEAR,
    SPECIES_SIMIPOUR,
    SPECIES_MUSHARNA,
    SPECIES_ZEBSTRIKA,
    SPECIES_BOLDORE,
    SPECIES_SWOOBAT,
    SPECIES_EXCADRILL,
    SPECIES_GURDURR,
    SPECIES_PALPITOAD,
    SPECIES_WHIMSICOTT,
    SPECIES_KROKOROK,
    SPECIES_CRUSTLE,
    SPECIES_SCRAFTY,
    SPECIES_COFAGRIGUS,
    SPECIES_CARRACOSTA,
    SPECIES_ARCHEOPS,
    SPECIES_GARBODOR,
    SPECIES_ZOROARK,
    SPECIES_CINCCINO,
    SPECIES_GOTHORITA,
    SPECIES_DUOSION,
    SPECIES_VANILLISH,
    SPECIES_SAWSBUCK_SPRING,
    SPECIES_SAWSBUCK_SUMMER,
    SPECIES_SAWSBUCK_AUTUMN,
    SPECIES_SAWSBUCK_WINTER,
    SPECIES_ESCAVALIER,
    SPECIES_AMOONGUSS,
    SPECIES_JELLICENT,
    SPECIES_GALVANTULA,
    SPECIES_FERROTHORN,
    SPECIES_KLANG,
    SPECIES_EELEKTRIK,
    SPECIES_LAMPENT,
    SPECIES_FRAXURE,
    SPECIES_BEARTIC,
    SPECIES_ACCELGOR,
    SPECIES_MIENSHAO,
    SPECIES_GOLURK,
    SPECIES_BISHARP,
    SPECIES_TYRUNT,
    SPECIES_AMAURA,
    SPECIES_HAWLUCHA,
    SPECIES_DEDENNE,
    SPECIES_KLEFKI,
    SPECIES_GOGOAT,
    SPECIES_PANGORO,
    SPECIES_MEOWSTIC_M,
    SPECIES_MEOWSTIC_F,
    SPECIES_DOUBLADE,
    SPECIES_AROMATISSE,
    SPECIES_SLURPUFF,
    SPECIES_MALAMAR,
    SPECIES_DRAGALGE,
    SPECIES_BARBARACLE,
    SPECIES_CLAWITZER,
    SPECIES_HELIOLISK,
    SPECIES_SYLVEON,
    SPECIES_TREVENANT,
    SPECIES_GOURGEIST_SMALL,
    SPECIES_GOURGEIST_LARGE,
    SPECIES_GOURGEIST_SUPER,
    SPECIES_GOURGEIST_AVERAGE,
    SPECIES_AVALUGG,
    SPECIES_WISHIWASHI,
    SPECIES_ORANGURU,
    SPECIES_PASSIMIAN,
    SPECIES_TURTONATOR,
    SPECIES_TOGEDEMARU,
    SPECIES_MIMIKYU,
    SPECIES_DRAMPA,
    SPECIES_DHELMISE,
    SPECIES_CRABOMINABLE,
    SPECIES_RIBOMBEE,
    SPECIES_LYCANROC_MIDNIGHT,
    SPECIES_LYCANROC_DUSK,
    SPECIES_LYCANROC_MIDDAY,
    SPECIES_TOXAPEX,
    SPECIES_MUDSDALE,
    SPECIES_ARAQUANID,
    SPECIES_LURANTIS,
    SPECIES_SHIINOTIC,
    SPECIES_SALAZZLE,
    SPECIES_BEWEAR,
    SPECIES_STEENEE,
    SPECIES_GOLISOPOD,
    SPECIES_PALOSSAND,
    SPECIES_FALINKS,
    SPECIES_STONJOURNER,
    SPECIES_EISCUE,
    SPECIES_MORPEKO,
    SPECIES_ELDEGOSS,
    SPECIES_DUBWOOL,
    SPECIES_DREDNAW,
    SPECIES_BOLTUND,
    SPECIES_CARKOL,
    SPECIES_FLAPPLE,
    SPECIES_APPLETUN,
    SPECIES_SANDACONDA,
    SPECIES_BARRASKEWDA,
    SPECIES_CENTISKORCH,
    SPECIES_GRAPPLOCT,
    SPECIES_HATTREM,
    SPECIES_MORGREM,
    SPECIES_CURSOLA,
    SPECIES_PERRSERKER,
    SPECIES_RUNERIGUS,
    SPECIES_ALCREMIE,
    SPECIES_RATICATE_ALOLA,
    SPECIES_RAICHU_ALOLA,
    SPECIES_SANDSLASH_ALOLA,
    SPECIES_NINETALES_ALOLA,
    SPECIES_DUGTRIO_ALOLA,
    SPECIES_PERSIAN_ALOLA,
    SPECIES_GRAVELER_ALOLA,
    SPECIES_MUK_ALOLA,
    SPECIES_MAROWAK_ALOLA,
    SPECIES_RAPIDASH_GALAR,
    SPECIES_SLOWBRO_GALAR,
    SPECIES_WEEZING_GALAR,
    SPECIES_MR_MIME_GALAR,
    SPECIES_SLOWKING_GALAR,
    SPECIES_TAUROS_PALDEA_COMBAT,
    SPECIES_TAUROS_PALDEA_BLAZE,
    SPECIES_TAUROS_PALDEA_AQUA,
    SPECIES_CORSOLA_GALAR,
    SPECIES_LINOONE_GALAR,
    SPECIES_DARMANITAN_GALAR,
    SPECIES_STUNFISK_GALAR,
    SPECIES_ARCANINE_HISUI,
    SPECIES_ELECTRODE_HISUI,
    SPECIES_LILLIGANT_HISUI,
    SPECIES_ZOROARK_HISUI,
    SPECIES_BRAVIARY_HISUI,
    SPECIES_SLIGGOO_HISUI,
    SPECIES_AVALUGG_HISUI,
    SPECIES_GOLEM_ALOLA,
    SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL,
    SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_BERRY_VANILLA_CREAM,
    SPECIES_ALCREMIE_BERRY_RUBY_CREAM,
    SPECIES_ALCREMIE_BERRY_MATCHA_CREAM,
    SPECIES_ALCREMIE_BERRY_MINT_CREAM,
    SPECIES_ALCREMIE_BERRY_LEMON_CREAM,
    SPECIES_ALCREMIE_BERRY_SALTED_CREAM,
    SPECIES_ALCREMIE_BERRY_RUBY_SWIRL,
    SPECIES_ALCREMIE_BERRY_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_BERRY_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_LOVE_VANILLA_CREAM,
    SPECIES_ALCREMIE_LOVE_RUBY_CREAM,
    SPECIES_ALCREMIE_LOVE_MATCHA_CREAM,
    SPECIES_ALCREMIE_LOVE_MINT_CREAM,
    SPECIES_ALCREMIE_LOVE_LEMON_CREAM,
    SPECIES_ALCREMIE_LOVE_SALTED_CREAM,
    SPECIES_ALCREMIE_LOVE_RUBY_SWIRL,
    SPECIES_ALCREMIE_LOVE_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_LOVE_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_STAR_VANILLA_CREAM,
    SPECIES_ALCREMIE_STAR_RUBY_CREAM,
    SPECIES_ALCREMIE_STAR_MATCHA_CREAM,
    SPECIES_ALCREMIE_STAR_MINT_CREAM,
    SPECIES_ALCREMIE_STAR_LEMON_CREAM,
    SPECIES_ALCREMIE_STAR_SALTED_CREAM,
    SPECIES_ALCREMIE_STAR_RUBY_SWIRL,
    SPECIES_ALCREMIE_STAR_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_STAR_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_CLOVER_VANILLA_CREAM,
    SPECIES_ALCREMIE_CLOVER_RUBY_CREAM,
    SPECIES_ALCREMIE_CLOVER_MATCHA_CREAM,
    SPECIES_ALCREMIE_CLOVER_MINT_CREAM,
    SPECIES_ALCREMIE_CLOVER_LEMON_CREAM,
    SPECIES_ALCREMIE_CLOVER_SALTED_CREAM,
    SPECIES_ALCREMIE_CLOVER_RUBY_SWIRL,
    SPECIES_ALCREMIE_CLOVER_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_CLOVER_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_FLOWER_VANILLA_CREAM,
    SPECIES_ALCREMIE_FLOWER_RUBY_CREAM,
    SPECIES_ALCREMIE_FLOWER_MATCHA_CREAM,
    SPECIES_ALCREMIE_FLOWER_MINT_CREAM,
    SPECIES_ALCREMIE_FLOWER_LEMON_CREAM,
    SPECIES_ALCREMIE_FLOWER_SALTED_CREAM,
    SPECIES_ALCREMIE_FLOWER_RUBY_SWIRL,
    SPECIES_ALCREMIE_FLOWER_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_FLOWER_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_RIBBON_VANILLA_CREAM,
    SPECIES_ALCREMIE_RIBBON_RUBY_CREAM,
    SPECIES_ALCREMIE_RIBBON_MATCHA_CREAM,
    SPECIES_ALCREMIE_RIBBON_MINT_CREAM,
    SPECIES_ALCREMIE_RIBBON_LEMON_CREAM,
    SPECIES_ALCREMIE_RIBBON_SALTED_CREAM,
    SPECIES_ALCREMIE_RIBBON_RUBY_SWIRL,
    SPECIES_ALCREMIE_RIBBON_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL,
    SPECIES_SIRFETCHD,
    SPECIES_FROSMOTH,
    SPECIES_COPPERAJAH,
    SPECIES_SINISTEA_ANTIQUE,
    SPECIES_SINISTEA,
    SPECIES_GIMMIGHOUL_CHEST,
    SPECIES_POLTCHAGEIST_COUNTERFEIT,
    SPECIES_POLTCHAGEIST_ARTISAN,
    SPECIES_FINIZEN,
    SPECIES_TOXTRICITY_AMPED,
    SPECIES_TOXTRICITY_LOW_KEY,
    SPECIES_POLTEAGEIST,
    SPECIES_POLTEAGEIST_ANTIQUE,
    SPECIES_WYRDEER,
    SPECIES_KLEAVOR,
    SPECIES_BASCULEGION_M,
    SPECIES_BASCULEGION_F,
    SPECIES_SNEASLER,
    SPECIES_OVERQWIL,
    SPECIES_MAUSHOLD_THREE,
    SPECIES_MAUSHOLD_FOUR,
    SPECIES_DACHSBUN,
    SPECIES_DOLLIV,
    SPECIES_NACLSTACK,
    SPECIES_ARMAROUGE,
    SPECIES_CERULEDGE,
    SPECIES_BELLIBOLT,
    SPECIES_MABOSSTIFF,
    SPECIES_GRAFAIAI,
    SPECIES_BRAMBLEGHAST,
    SPECIES_TOEDSCRUEL,
    SPECIES_KLAWF,
    SPECIES_SCOVILLAIN,
    SPECIES_RABSCA,
    SPECIES_ESPATHRA,
    SPECIES_TINKATUFF,
    SPECIES_WUGTRIO,
    SPECIES_BOMBIRDIER,
    SPECIES_REVAVROOM,
    SPECIES_CYCLIZAR,
    SPECIES_ORTHWORM,
    SPECIES_GLIMMORA,
    SPECIES_HOUNDSTONE,
    SPECIES_FLAMIGO,
    SPECIES_CETITAN,
    SPECIES_VELUZA,
    SPECIES_DONDOZO,
    SPECIES_TATSUGIRI_CURLY,
    SPECIES_TATSUGIRI_DROOPY,
    SPECIES_TATSUGIRI_STRETCHY,
    SPECIES_CLODSIRE,
    SPECIES_FARIGIRAF,
    SPECIES_DUDUNSPARCE_TWO_SEGMENT,
    SPECIES_DUDUNSPARCE_THREE_SEGMENT,
    SPECIES_DIPPLIN,
    SPECIES_SINISTCHA_UNREMARKABLE,
    SPECIES_SINISTCHA_MASTERPIECE
};

static const u16 sGachaGreatSpeciesRare[] = {
    SPECIES_AERODACTYL,
    SPECIES_SNORLAX,
    SPECIES_OMASTAR,
    SPECIES_KABUTOPS,
    SPECIES_RAICHU,
    SPECIES_NIDOQUEEN,
    SPECIES_NIDOKING,
    SPECIES_CLEFABLE,
    SPECIES_WIGGLYTUFF,
    SPECIES_VILEPLUME,
    SPECIES_POLIWRATH,
    SPECIES_ALAKAZAM,
    SPECIES_MACHAMP,
    SPECIES_VICTREEBEL,
    SPECIES_GOLEM,
    SPECIES_GENGAR,
    SPECIES_CROBAT,
    SPECIES_AMPHAROS,
    SPECIES_BELLOSSOM,
    SPECIES_AZUMARILL,
    SPECIES_POLITOED,
    SPECIES_JUMPLUFF,
    SPECIES_KINGDRA,
    SPECIES_BLISSEY,
    SPECIES_LUDICOLO,
    SPECIES_SHIFTRY,
    SPECIES_GARDEVOIR,
    SPECIES_SLAKING,
    SPECIES_EXPLOUD,
    SPECIES_AGGRON,
    SPECIES_FLYGON,
    SPECIES_WALREIN,
    SPECIES_RAMPARDOS,
    SPECIES_BASTIODON,
    SPECIES_ROSERADE,
    SPECIES_MAGNEZONE,
    SPECIES_RHYPERIOR,
    SPECIES_ELECTIVIRE,
    SPECIES_MAGMORTAR,
    SPECIES_TOGEKISS,
    SPECIES_PORYGON_Z,
    SPECIES_MAMOSWINE,
    SPECIES_GALLADE,
    SPECIES_DUSKNOIR,
    SPECIES_BRAVIARY,
    SPECIES_MANDIBUZZ,
    SPECIES_VOLCARONA,
    SPECIES_GIGALITH,
    SPECIES_CONKELDURR,
    SPECIES_SEISMITOAD,
    SPECIES_LILLIGANT,
    SPECIES_KROOKODILE,
    SPECIES_DARMANITAN,
    SPECIES_GOTHITELLE,
    SPECIES_REUNICLUS,
    SPECIES_VANILLUXE,
    SPECIES_KLINKLANG,
    SPECIES_EELEKTROSS,
    SPECIES_BEHEEYEM,
    SPECIES_CHANDELURE,
    SPECIES_HAXORUS,
    SPECIES_TYRANTRUM,
    SPECIES_AURORUS,
    SPECIES_NOIVERN,
    SPECIES_AEGISLASH,
    SPECIES_TSAREENA,
    SPECIES_DURALUDON,
    SPECIES_DRACOZOLT,
    SPECIES_ARCTOZOLT,
    SPECIES_DRACOVISH,
    SPECIES_ARCTOVISH,
    SPECIES_COALOSSAL,
    SPECIES_HATTERENE,
    SPECIES_GRIMMSNARL,
    SPECIES_OBSTAGOON,
    SPECIES_MR_RIME,
    SPECIES_INDEEDEE_M,
    SPECIES_INDEEDEE_F,
    SPECIES_URSALUNA,
    SPECIES_ARBOLIVA,
    SPECIES_GARGANACL,
    SPECIES_PALAFIN_ZERO,
    SPECIES_TINKATON,
    SPECIES_ANNIHILAPE,
    SPECIES_KINGAMBIT,
    SPECIES_GHOLDENGO,
    SPECIES_URSALUNA_BLOODMOON,
    SPECIES_ARCHALUDON,
    SPECIES_HYDRAPPLE
};

static const u16 sGachaGreatSpeciesUltraRare[] = {
    SPECIES_IVYSAUR,
    SPECIES_CHARMELEON,
    SPECIES_WARTORTLE,
    SPECIES_BAYLEEF,
    SPECIES_QUILAVA,
    SPECIES_CROCONAW,
    SPECIES_GROVYLE,
    SPECIES_COMBUSKEN,
    SPECIES_MARSHTOMP,
    SPECIES_GROTLE,
    SPECIES_MONFERNO,
    SPECIES_PRINPLUP,
    SPECIES_SERVINE,
    SPECIES_OSHAWOTT,
    SPECIES_DEWOTT,
    SPECIES_QUILLADIN,
    SPECIES_BRAIXEN,
    SPECIES_FROGADIER,
    SPECIES_DARTRIX,
    SPECIES_TORRACAT,
    SPECIES_BRIONNE,
    SPECIES_THWACKEY,
    SPECIES_RABOOT,
    SPECIES_DRIZZILE,
    SPECIES_FLORAGATO,
    SPECIES_CROCALOR,
    SPECIES_QUAXWELL
};

static const u16 sGachaUltraSpeciesCommon[] = {
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_CHIKORITA,
    SPECIES_CYNDAQUIL,
    SPECIES_TOTODILE,
    SPECIES_TREECKO,
    SPECIES_MUDKIP,
    SPECIES_TORCHIC,
    SPECIES_TURTWIG,
    SPECIES_CHIMCHAR,
    SPECIES_PIPLUP,
    SPECIES_SNIVY,
    SPECIES_TEPIG,
    SPECIES_PIGNITE,
    SPECIES_CHESPIN,
    SPECIES_FENNEKIN,
    SPECIES_FROAKIE,
    SPECIES_ROWLET,
    SPECIES_LITTEN,
    SPECIES_POPPLIO,
    SPECIES_GROOKEY,
    SPECIES_SCORBUNNY,
    SPECIES_SOBBLE,
    SPECIES_SPRIGATITO,
    SPECIES_FUECOCO,
    SPECIES_QUAXLY,
    SPECIES_DRATINI,
    SPECIES_LARVITAR,
    SPECIES_BAGON,
    SPECIES_BELDUM,
    SPECIES_GIBLE,
    SPECIES_DEINO,
    SPECIES_GOOMY,
    SPECIES_JANGMO_O,
    SPECIES_DREEPY,
    SPECIES_FRIGIBAX
};

static const u16 sGachaUltraSpeciesUncommon[] = {
    SPECIES_IVYSAUR,
    SPECIES_CHARMELEON,
    SPECIES_WARTORTLE,
    SPECIES_BAYLEEF,
    SPECIES_QUILAVA,
    SPECIES_CROCONAW,
    SPECIES_GROVYLE,
    SPECIES_COMBUSKEN,
    SPECIES_MARSHTOMP,
    SPECIES_GROTLE,
    SPECIES_MONFERNO,
    SPECIES_PRINPLUP,
    SPECIES_SERVINE,
    SPECIES_OSHAWOTT,
    SPECIES_DEWOTT,
    SPECIES_QUILLADIN,
    SPECIES_BRAIXEN,
    SPECIES_FROGADIER,
    SPECIES_DARTRIX,
    SPECIES_TORRACAT,
    SPECIES_BRIONNE,
    SPECIES_THWACKEY,
    SPECIES_RABOOT,
    SPECIES_DRIZZILE,
    SPECIES_FLORAGATO,
    SPECIES_CROCALOR,
    SPECIES_QUAXWELL,
    SPECIES_DRAGONAIR,
    SPECIES_PUPITAR,
    SPECIES_SHELGON,
    SPECIES_METANG,
    SPECIES_GABITE,
    SPECIES_ZWEILOUS,
    SPECIES_SLIGGOO,
    SPECIES_HAKAMO_O,
    SPECIES_DRAKLOAK,
    SPECIES_ARCTIBAX
};

static const u16 sGachaUltraSpeciesRare[] = {
    SPECIES_VENUSAUR,
    SPECIES_CHARIZARD,
    SPECIES_BLASTOISE,
    SPECIES_MEGANIUM,
    SPECIES_TYPHLOSION,
    SPECIES_FERALIGATR,
    SPECIES_SCEPTILE,
    SPECIES_BLAZIKEN,
    SPECIES_SWAMPERT,
    SPECIES_TORTERRA,
    SPECIES_INFERNAPE,
    SPECIES_EMPOLEON,
    SPECIES_SERPERIOR,
    SPECIES_EMBOAR,
    SPECIES_SAMUROTT,
    SPECIES_CHESNAUGHT,
    SPECIES_DELPHOX,
    SPECIES_GRENINJA,
    SPECIES_DECIDUEYE,
    SPECIES_INCINEROAR,
    SPECIES_PRIMARINA,
    SPECIES_RILLABOOM,
    SPECIES_CINDERACE,
    SPECIES_INTELEON,
    SPECIES_MEOWSCARADA,
    SPECIES_SKELEDIRGE,
    SPECIES_QUAQUAVAL,
    SPECIES_TYPHLOSION_HISUI,
    SPECIES_SAMUROTT_HISUI,
    SPECIES_DECIDUEYE_HISUI,
    SPECIES_DRAGONITE,
    SPECIES_TYRANITAR,
    SPECIES_SALAMENCE,
    SPECIES_METAGROSS,
    SPECIES_GARCHOMP,
    SPECIES_HYDREIGON,
    SPECIES_GOODRA,
    SPECIES_KOMMO_O,
    SPECIES_DRAGAPULT,
    SPECIES_BAXCALIBUR,
    SPECIES_GOODRA_HISUI
};

static const u16 sGachaUltraSpeciesUltraRare[] = {
    SPECIES_ROTOM,
    SPECIES_ROTOM_HEAT,
    SPECIES_ROTOM_WASH,
    SPECIES_ROTOM_FROST,
    SPECIES_ROTOM_FAN,
    SPECIES_ROTOM_MOW,
    SPECIES_FLOETTE_ETERNAL,
    SPECIES_GRENINJA_BOND,
    SPECIES_TYPE_NULL,
    SPECIES_COSMOG,
    SPECIES_COSMOEM,
    SPECIES_NIHILEGO,
    SPECIES_BUZZWOLE,
    SPECIES_PHEROMOSA,
    SPECIES_XURKITREE,
    SPECIES_CELESTEELA,
    SPECIES_KARTANA,
    SPECIES_GUZZLORD,
    SPECIES_POIPOLE,
    SPECIES_NAGANADEL,
    SPECIES_STAKATAKA,
    SPECIES_BLACEPHALON,
    SPECIES_KUBFU,
    SPECIES_GREAT_TUSK,
    SPECIES_SCREAM_TAIL,
    SPECIES_BRUTE_BONNET,
    SPECIES_FLUTTER_MANE,
    SPECIES_SLITHER_WING,
    SPECIES_SANDY_SHOCKS,
    SPECIES_IRON_TREADS,
    SPECIES_IRON_BUNDLE,
    SPECIES_IRON_HANDS,
    SPECIES_IRON_JUGULIS,
    SPECIES_IRON_MOTH,
    SPECIES_IRON_THORNS,
    SPECIES_ROARING_MOON,
    SPECIES_IRON_VALIANT
};

static const u16 sGachaMasterSpeciesCommon[] = {
    SPECIES_ROTOM,
    SPECIES_ROTOM_HEAT,
    SPECIES_ROTOM_WASH,
    SPECIES_ROTOM_FROST,
    SPECIES_ROTOM_FAN,
    SPECIES_ROTOM_MOW,
    SPECIES_FLOETTE_ETERNAL,
    SPECIES_GRENINJA_BOND,
    SPECIES_TYPE_NULL,
    SPECIES_COSMOG,
    SPECIES_COSMOEM,
    SPECIES_NIHILEGO,
    SPECIES_BUZZWOLE,
    SPECIES_PHEROMOSA,
    SPECIES_XURKITREE,
    SPECIES_CELESTEELA,
    SPECIES_KARTANA,
    SPECIES_GUZZLORD,
    SPECIES_POIPOLE,
    SPECIES_NAGANADEL,
    SPECIES_STAKATAKA,
    SPECIES_BLACEPHALON,
    SPECIES_KUBFU,
    SPECIES_GREAT_TUSK,
    SPECIES_SCREAM_TAIL,
    SPECIES_BRUTE_BONNET,
    SPECIES_FLUTTER_MANE,
    SPECIES_SLITHER_WING,
    SPECIES_SANDY_SHOCKS,
    SPECIES_IRON_TREADS,
    SPECIES_IRON_BUNDLE,
    SPECIES_IRON_HANDS,
    SPECIES_IRON_JUGULIS,
    SPECIES_IRON_MOTH,
    SPECIES_IRON_THORNS,
    SPECIES_ROARING_MOON,
    SPECIES_IRON_VALIANT
};

static const u16 sGachaMasterSpeciesUncommon[] = {
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_ARTICUNO_GALAR,
    SPECIES_ZAPDOS_GALAR,
    SPECIES_MOLTRES_GALAR,
    SPECIES_RAIKOU,
    SPECIES_ENTEI,
    SPECIES_SUICUNE,
    SPECIES_REGIROCK,
    SPECIES_REGICE,
    SPECIES_REGISTEEL,
    SPECIES_LATIAS,
    SPECIES_LATIOS,
    SPECIES_UXIE,
    SPECIES_MESPRIT,
    SPECIES_AZELF,
    SPECIES_HEATRAN,
    SPECIES_COBALION,
    SPECIES_TERRAKION,
    SPECIES_VIRIZION,
    SPECIES_TORNADUS,
    SPECIES_THUNDURUS,
    SPECIES_TORNADUS_THERIAN,
    SPECIES_THUNDURUS_THERIAN,
    SPECIES_LANDORUS_THERIAN,
    SPECIES_SILVALLY,
    SPECIES_TAPU_KOKO,
    SPECIES_TAPU_LELE,
    SPECIES_TAPU_BULU,
    SPECIES_TAPU_FINI,
    SPECIES_REGIELEKI,
    SPECIES_REGIDRAGO,
    SPECIES_URSHIFU_SINGLE_STRIKE,
    SPECIES_URSHIFU_RAPID_STRIKE,
    SPECIES_ENAMORUS_INCARNATE,
    SPECIES_ENAMORUS_THERIAN,
    SPECIES_WALKING_WAKE,
    SPECIES_IRON_LEAVES,
    SPECIES_GOUGING_FIRE,
    SPECIES_RAGING_BOLT,
    SPECIES_IRON_BOULDER,
    SPECIES_IRON_CROWN,
    SPECIES_WO_CHIEN,
    SPECIES_CHIEN_PAO,
    SPECIES_TING_LU,
    SPECIES_CHI_YU,
    SPECIES_OKIDOGI,
    SPECIES_MUNKIDORI,
    SPECIES_FEZANDIPITI
};

static const u16 sGachaMasterSpeciesRare[] = {
    SPECIES_MEWTWO,
    SPECIES_LUGIA,
    SPECIES_HO_OH,
    SPECIES_KYOGRE,
    SPECIES_GROUDON,
    SPECIES_RAYQUAZA,
    SPECIES_REGIGIGAS,
    SPECIES_DIALGA,
    SPECIES_PALKIA,
    SPECIES_GIRATINA,
    SPECIES_CRESSELIA,
    SPECIES_RESHIRAM,
    SPECIES_ZEKROM,
    SPECIES_LANDORUS,
    SPECIES_KYUREM,
    SPECIES_XERNEAS,
    SPECIES_YVELTAL,
    SPECIES_ZYGARDE,
    SPECIES_SOLGALEO,
    SPECIES_LUNALA,
    SPECIES_NECROZMA,
    SPECIES_ZAMAZENTA,
    SPECIES_ZACIAN,
    SPECIES_ETERNATUS,
    SPECIES_GLASTRIER,
    SPECIES_SPECTRIER,
    SPECIES_CALYREX,
    SPECIES_KORAIDON,
    SPECIES_MIRAIDON,
    SPECIES_OGERPON,
    SPECIES_TERAPAGOS
};

static const u16 sGachaMasterSpeciesUltraRare[] = {
    SPECIES_MEW,
    SPECIES_CELEBI,
    SPECIES_JIRACHI,
    SPECIES_DEOXYS,
    SPECIES_PHIONE,
    SPECIES_MANAPHY,
    SPECIES_DARKRAI,
    SPECIES_SHAYMIN,
    SPECIES_ARCEUS,
    SPECIES_VICTINI,
    SPECIES_KELDEO,
    SPECIES_MELOETTA,
    SPECIES_GENESECT,
    SPECIES_DIANCIE,
    SPECIES_HOOPA_CONFINED,
    SPECIES_VOLCANION,
    SPECIES_HOOPA_UNBOUND,
    SPECIES_MAGEARNA_ORIGINAL,
    SPECIES_MAGEARNA,
    SPECIES_MARSHADOW,
    SPECIES_ZERAORA,
    SPECIES_MELTAN,
    SPECIES_MELMETAL,
    SPECIES_ZARUDE,
    SPECIES_ZARUDE_DADA,
    SPECIES_PECHARUNT
};

static void ShowMessage(void)
{
    u16 bet;
    struct WindowTemplate template;

    SetWindowTemplateFields(&template, GACHA_MENUS, 17, 10, 10, 2, 0xF, 0x194);
    
    sTextWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sTextWindowId, PIXEL_FILL(0));
    PutWindowTilemap(sTextWindowId);
    LoadUserWindowBorderGfx(sTextWindowId, 0x214, BG_PLTT_ID(14));
    DrawStdWindowFrame(sTextWindowId, FALSE); 
    bet = sGacha->newMonOdds;
    ConvertUIntToDecimalStringN(gStringVar1, bet, STR_CONV_MODE_LEADING_ZEROS, 3);
    //gStringVar4[0] = '\0';
    StringExpandPlaceholders(gStringVar4, sMessageText);
    AddTextPrinterParameterized(sTextWindowId, FONT_NARROW, gStringVar4, 0, 1, 0, 0);
    CopyWindowToVram(sTextWindowId, 3);
}

static void ResetMessage(void)
{
    ClearStdWindowAndFrame(sTextWindowId, TRUE);
    RemoveWindow(sTextWindowId);
}

static void StartExitGacha(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    sGacha->state = GACHA_STATE_EXIT;
}

static void StartTradeScreen(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    sGacha->state = STATE_FADE;
}

static u16 GetMaxAvailableGachaRaritySpecies(u32 gachaId, u32 rarity)
{
    // Get the number of available Pokémon based on rarity
    switch (gachaId)
    {
    default:
    case GACHA_BASIC:
        switch (rarity)
        {
        default:
        case RARITY_COMMON:
            return ARRAY_COUNT(sGachaBasicSpeciesCommon);
        case RARITY_UNCOMMON:
            return ARRAY_COUNT(sGachaBasicSpeciesUncommon);
        case RARITY_RARE:
            return ARRAY_COUNT(sGachaBasicSpeciesRare);
        case RARITY_ULTRA_RARE:
            return ARRAY_COUNT(sGachaBasicSpeciesUltraRare);
        }
    case GACHA_GREAT:
        switch (rarity)
        {
        default:
        case RARITY_COMMON:
            return ARRAY_COUNT(sGachaGreatSpeciesCommon);
        case RARITY_UNCOMMON:
            return ARRAY_COUNT(sGachaGreatSpeciesUncommon);
        case RARITY_RARE:
            return ARRAY_COUNT(sGachaGreatSpeciesRare);
        case RARITY_ULTRA_RARE:
            return ARRAY_COUNT(sGachaGreatSpeciesUltraRare);
        }
    case GACHA_ULTRA:
        switch (rarity)
        {
        default:
        case RARITY_COMMON:
            return ARRAY_COUNT(sGachaUltraSpeciesCommon);
        case RARITY_UNCOMMON:
            return ARRAY_COUNT(sGachaUltraSpeciesUncommon);
        case RARITY_RARE:
            return ARRAY_COUNT(sGachaUltraSpeciesRare);
        case RARITY_ULTRA_RARE:
            return ARRAY_COUNT(sGachaUltraSpeciesUltraRare);
        }
    case GACHA_MASTER:
        switch (rarity)
        {
        default:
        case RARITY_COMMON:
            return ARRAY_COUNT(sGachaMasterSpeciesCommon);
        case RARITY_UNCOMMON:
            return ARRAY_COUNT(sGachaMasterSpeciesUncommon);
        case RARITY_RARE:
            return ARRAY_COUNT(sGachaMasterSpeciesRare);
        case RARITY_ULTRA_RARE:
            return ARRAY_COUNT(sGachaMasterSpeciesUltraRare);
        }
    }
    return 0; // failsafe
}

static inline u16 GetGachaBasicSpecies(u16 randNum)
{
    u16 totalMax;

    // Use the pre-defined totalMax values based on the rarity
    totalMax = GetMaxAvailableGachaRaritySpecies(GACHA_BASIC, sGacha->Rarity);

    // Check if the provided Number is valid
    if (randNum >= totalMax)
        return -1;  // Return -1 if the Number is out of range for the list

    // Now, search for the Pokémon based on its customNumber
    switch (sGacha->Rarity)
    {
    default:
    case RARITY_COMMON:
        return sGachaBasicSpeciesCommon[randNum];
    case RARITY_UNCOMMON:
        return sGachaBasicSpeciesUncommon[randNum];
    case RARITY_RARE:
        return sGachaBasicSpeciesRare[randNum];
    case RARITY_ULTRA_RARE:
        return sGachaBasicSpeciesUltraRare[randNum];
    }

    return -1; // Return -1 if customNumber is not found
}

static inline u16 GetGachaGreatSpecies(u16 randNum)
{
    u16 totalMax = 0;

    // Determine the totalMax based on rarity
    totalMax = GetMaxAvailableGachaRaritySpecies(GACHA_GREAT, sGacha->Rarity);

    // Check if the provided Number is within the range
    if (randNum >= totalMax)
        return -1;  // Return -1 if out of range

    // Loop through the correct array based on rarity
    switch (sGacha->Rarity)
    {
    default:
    case RARITY_COMMON:
        return sGachaGreatSpeciesCommon[randNum];
    case RARITY_UNCOMMON:
        return sGachaGreatSpeciesUncommon[randNum];
    case RARITY_RARE:
        return sGachaGreatSpeciesRare[randNum];
    case RARITY_ULTRA_RARE:
        return sGachaGreatSpeciesUltraRare[randNum];
    }

    return -1; // Return -1 if customNumber is not found
}

static inline u16 GetGachaUltraSpecies(u16 randNum)
{
    u16 totalMax = 0;

    // Determine the totalMax based on rarity
    totalMax = GetMaxAvailableGachaRaritySpecies(GACHA_ULTRA, sGacha->Rarity);

    // Check if the provided Number is within the range
    if (randNum >= totalMax)
        return -1;  // Return -1 if out of range

    // Loop through the correct array based on rarity
    switch (sGacha->Rarity)
    {
    default:
    case RARITY_COMMON:
        return sGachaUltraSpeciesCommon[randNum];
    case RARITY_UNCOMMON:
        return sGachaUltraSpeciesUncommon[randNum];
    case RARITY_RARE:
        return sGachaUltraSpeciesRare[randNum];
    case RARITY_ULTRA_RARE:
        return sGachaUltraSpeciesUltraRare[randNum];
    }

    return -1; // Return -1 if customNumber is not found
}

static inline u16 GetGachaMasterSpecies(u16 randNum)
{
    u16 totalMax = 0;

    totalMax = GetMaxAvailableGachaRaritySpecies(GACHA_MASTER, sGacha->Rarity);

    // Check if the provided Number is within the range
    if (randNum >= totalMax)
        return -1;  // Return -1 if out of range

    switch (sGacha->Rarity)
    {
    default:
    case RARITY_COMMON:
        return sGachaMasterSpeciesCommon[randNum];
    case RARITY_UNCOMMON:
        return sGachaMasterSpeciesUncommon[randNum];
    case RARITY_RARE:
        return sGachaMasterSpeciesRare[randNum];
    case RARITY_ULTRA_RARE:
        return sGachaMasterSpeciesUltraRare[randNum];
    }

    return -1; // Return -1 if customNumber is not found
}

static u16 GetGachaMon(u16 randNum)
{
    u32 species;

    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        species = GetGachaBasicSpecies(randNum);
        break;
    case GACHA_GREAT:
        species = GetGachaGreatSpecies(randNum);
        break;
    case GACHA_ULTRA:
        species = GetGachaUltraSpecies(randNum);
        break;
    case GACHA_MASTER:
        species = GetGachaMasterSpecies(randNum);
        break;
    }

    if (species >= SPECIES_EGG)
        return SPECIES_NONE;  // Or another default value indicating not found.
    return species;
}

static inline bool32 CheckIfOwned(u16 species)
{
    u16 nationalDexNo;
    nationalDexNo = SpeciesToNationalPokedexNum(species);
    return GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT);
}

static inline bool32 IsNotValidOwnedSpecies(u16 species)
{
    if (species == SPECIES_NONE)
        return TRUE;
    return !CheckIfOwned(species);
}

static inline bool32 IsNotValidUnownedSpecies(u16 species)
{
    if (species == SPECIES_NONE)
        return TRUE;
    return CheckIfOwned(species);
}

static void GetPokemonOwned(void)
{
    u16 species;
    int nationalDexNo;
    int i;

    sGacha->ownedCommon = 0;
    sGacha->ownedUncommon = 0;
    sGacha->ownedRare = 0;
    sGacha->ownedUltraRare = 0;

    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        for (i = 0; i < ARRAY_COUNT(sGachaBasicSpeciesCommon); i++)
        {
            species = sGachaBasicSpeciesCommon[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedCommon = (sGacha->ownedCommon + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaBasicSpeciesUncommon); i++)
        {
            species = sGachaBasicSpeciesUncommon[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedUncommon = (sGacha->ownedUncommon + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaBasicSpeciesRare); i++)
        {
            species = sGachaBasicSpeciesRare[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedRare = (sGacha->ownedRare + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaBasicSpeciesUltraRare); i++)
        {
            species = sGachaBasicSpeciesUltraRare[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedUltraRare = (sGacha->ownedUltraRare + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        break;
    case GACHA_GREAT:
        for (i = 0; i < ARRAY_COUNT(sGachaGreatSpeciesCommon); i++)
        {
            species = sGachaGreatSpeciesCommon[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedCommon = (sGacha->ownedCommon + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaGreatSpeciesUncommon); i++)
        {
            species = sGachaGreatSpeciesUncommon[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedUncommon = (sGacha->ownedUncommon + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaGreatSpeciesRare); i++)
        {
            species = sGachaGreatSpeciesRare[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedRare = (sGacha->ownedRare + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaGreatSpeciesUltraRare); i++)
        {
            species = sGachaGreatSpeciesUltraRare[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedUltraRare = (sGacha->ownedUltraRare + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        break;
    case GACHA_ULTRA:
        for (i = 0; i < ARRAY_COUNT(sGachaUltraSpeciesCommon); i++)
        {
            species = sGachaUltraSpeciesCommon[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedCommon = (sGacha->ownedCommon + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaUltraSpeciesUncommon); i++)
        {
            species = sGachaUltraSpeciesUncommon[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedUncommon = (sGacha->ownedUncommon + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaUltraSpeciesRare); i++)
        {
            species = sGachaUltraSpeciesRare[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedRare = (sGacha->ownedRare + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaUltraSpeciesUltraRare); i++)
        {
            species = sGachaUltraSpeciesUltraRare[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedUltraRare = (sGacha->ownedUltraRare + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        break;
    case GACHA_MASTER:
        for (i = 0; i < ARRAY_COUNT(sGachaMasterSpeciesCommon); i++)
        {
            species = sGachaMasterSpeciesCommon[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedCommon = (sGacha->ownedCommon + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaMasterSpeciesUncommon); i++)
        {
            species = sGachaMasterSpeciesUncommon[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedUncommon = (sGacha->ownedUncommon + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaMasterSpeciesRare); i++)
        {
            species = sGachaMasterSpeciesRare[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedRare = (sGacha->ownedRare + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        for (i = 0; i < ARRAY_COUNT(sGachaMasterSpeciesUltraRare); i++)
        {
            species = sGachaMasterSpeciesUltraRare[i];
            nationalDexNo = SpeciesToNationalPokedexNum(species);
            sGacha->ownedUltraRare = (sGacha->ownedUltraRare + GetSetPokedexFlag(nationalDexNo, FLAG_GET_CAUGHT));
        }
        break;
    }
}

u8 CalculateChanceForCategory(u16 owned, u16 available, u8 baseChance, u16 wager)
{
    u8 newChance;
    u8 ownedPercentage;
    u8 wagerMultiplier;
    u8 boostedChance;
    u16 minWager;

    // Determine minimum wager based on sGacha->GachaId
    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        minWager = GACHA_BASIC_MIN_WAGER;
        break;
    case GACHA_GREAT:
        minWager = GACHA_GREAT_MIN_WAGER;
        break;
    case GACHA_ULTRA:
        minWager = GACHA_ULTRA_MIN_WAGER;
        break;
    case GACHA_MASTER:
        minWager = GACHA_MASTER_MIN_WAGER;
        break;
    }

    // If available Pokémon is 0, there is no chance
    if (available == 0)
        return 0;

    // Calculate the reduction in chance based on the proportion of owned Pokémon
    ownedPercentage = (owned * 100) / available;
    newChance = baseChance * (100 - ownedPercentage) / 100;

    // Ensure the wager is within the valid range
    if (wager >= minWager && owned < available)
    {
        // Normalize wager to a 0-100 range where [minWager - 9999] -> [0 - 100]
        wagerMultiplier = ((wager - minWager) * 100) / (9999 - minWager);

        // Boost the chance based on the wager multiplier, but cap it by baseChance
        boostedChance = newChance + ((baseChance - newChance) * wagerMultiplier) / 100;

        // Ensure the chance doesn't exceed baseChance
        newChance = (boostedChance > baseChance) ? baseChance : boostedChance;
    }

    return newChance;
}

// Function to determine if the player gets a new Pokémon, and the rarity
void DeterminePokemonRarityAndNewStatus(void)
{
    u16 species;
    u16 totalNotOwned;
    u8 totalOwned;
    u16 totalMax;
    u16 newPokemonChance;
    u16 randomValue;
    u32 attempts = 1000;

    while (TRUE)
    {
        randomValue = (Random() % 100);  // Generate random value between 0 and 100

        // Determine Rarity based on the chances
        if (randomValue < RARITY_COMMON_ODDS)
            sGacha->Rarity = RARITY_COMMON; // Common
        else if (randomValue < (RARITY_COMMON_ODDS + RARITY_UNCOMMON_ODDS))
            sGacha->Rarity = RARITY_UNCOMMON; // Uncommon
        else if (randomValue < (RARITY_COMMON_ODDS + RARITY_UNCOMMON_ODDS + RARITY_RARE_ODDS))
            sGacha->Rarity = RARITY_RARE; // Rare
        else
            sGacha->Rarity = RARITY_ULTRA_RARE; // Ultra Rare

        // Get the number of available and owned Pokémon based on rarity
        totalMax = GetMaxAvailableGachaRaritySpecies(sGacha->GachaId, sGacha->Rarity);
        switch (sGacha->Rarity)
        {
        default:
        case RARITY_COMMON:
            totalOwned = sGacha->ownedCommon;
            break;
        case RARITY_UNCOMMON:
            totalOwned = sGacha->ownedUncommon;
            break;
        case RARITY_RARE:
            totalOwned = sGacha->ownedRare;
            break;
        case RARITY_ULTRA_RARE:
            totalOwned = sGacha->ownedUltraRare;
            break;
        }

        // Calculate the total number of Pokémon the player doesn't own
        totalNotOwned = totalMax - totalOwned;

        if (totalNotOwned <= 0)
        {
            // If all Pokémon of the selected rarity are owned, restart the process (reroll)
            continue;  // This will make the loop restart from the beginning
        }

        // Generate a random value for the chances
        randomValue = Random() % 100;  // Generate random value between 0-99

        // Check if we should get a new Pokémon based on the odds
        if (sGacha->newMonOdds >= randomValue)
        {
            // Loop until a new (not owned) Pokémon is found
            do {
                newPokemonChance = (Random() % totalMax);  // Random pull from the available pool
                species = GetGachaMon(newPokemonChance);  // Get the Pokémon species based on the random value
                attempts--;
                if (attempts < 1)
                {
                    attempts = 1000;
                    randomValue = (Random() % 100);  // Generate random value between 0 and 100

                    // Determine Rarity based on the chances
                    if (randomValue < RARITY_COMMON_ODDS)
                        sGacha->Rarity = RARITY_COMMON;
                    else if (randomValue < (RARITY_COMMON_ODDS + RARITY_UNCOMMON_ODDS))
                        sGacha->Rarity = RARITY_UNCOMMON;
                    else if (randomValue < (RARITY_COMMON_ODDS + RARITY_UNCOMMON_ODDS + RARITY_RARE_ODDS))
                        sGacha->Rarity = RARITY_RARE;
                    else
                        sGacha->Rarity = RARITY_ULTRA_RARE;
                }
                // If the Pokémon is not owned, we found a new Pokémon
            } while (IsNotValidUnownedSpecies(species));  // Continue if owned (IsNotValidUnownedSpecies returns TRUE)

            // If we've broken out of the loop, we have a new Pokémon
            sGacha->CalculatedSpecies = species;  // Store the species of the new Pokémon
            break;  // Exit the loop after finding a new Pokémon
        }
        else
        {
            // Loop until an owned Pokémon is found
            do {
                newPokemonChance = (Random() % totalMax);  // Random pull from the available pool
                species = GetGachaMon(newPokemonChance);  // Get the Pokémon species based on the random value
                attempts--;
                if (attempts < 1)
                {
                    attempts = 1000;
                    randomValue = (Random() % 100);  // Generate random value between 0 and 100

                    // Determine Rarity based on the chances
                    if (randomValue < RARITY_COMMON_ODDS)
                        sGacha->Rarity = RARITY_COMMON;
                    else if (randomValue < (RARITY_COMMON_ODDS + RARITY_UNCOMMON_ODDS))
                        sGacha->Rarity = RARITY_UNCOMMON;
                    else if (randomValue < (RARITY_COMMON_ODDS + RARITY_UNCOMMON_ODDS + RARITY_RARE_ODDS))
                        sGacha->Rarity = RARITY_RARE;
                    else
                        sGacha->Rarity = RARITY_ULTRA_RARE;
                }

                // If the Pokémon is owned, we have an owned Pokémon
            } while (IsNotValidOwnedSpecies(species));  // Continue if not owned

            // If we've broken out of the loop, we have an owned Pokémon
            sGacha->CalculatedSpecies = species;  // Store the species of the owned Pokémon
            break;  // Exit the loop after finding an owned Pokémon
        }
    }
}

static void CalculatePullOdds(void)
{
    u16 totalCommonAvailable;
    u16 totalUncommonAvailable;
    u16 totalRareAvailable;
    u16 totalUltraRareAvailable;
    u16 wager;
    u8 totalChance;

    totalCommonAvailable = GetMaxAvailableGachaRaritySpecies(sGacha->GachaId, RARITY_COMMON);
    totalUncommonAvailable = GetMaxAvailableGachaRaritySpecies(sGacha->GachaId, RARITY_UNCOMMON);
    totalRareAvailable = GetMaxAvailableGachaRaritySpecies(sGacha->GachaId, RARITY_RARE);
    totalUltraRareAvailable = GetMaxAvailableGachaRaritySpecies(sGacha->GachaId, RARITY_ULTRA_RARE);

    wager = sGacha->wager;  // Player's wager (0-9999)

    // Add up the chances from each rarity
    totalChance = CalculateChanceForCategory(sGacha->ownedCommon, totalCommonAvailable, RARITY_COMMON_ODDS, wager);
    totalChance += CalculateChanceForCategory(sGacha->ownedUncommon, totalUncommonAvailable, RARITY_UNCOMMON_ODDS, wager);
    totalChance += CalculateChanceForCategory(sGacha->ownedRare, totalRareAvailable, RARITY_RARE_ODDS, wager);
    totalChance += CalculateChanceForCategory(sGacha->ownedUltraRare, totalUltraRareAvailable, RARITY_ULTRA_RARE_ODDS, wager);

    if (totalChance <= 100)
        sGacha->newMonOdds = totalChance;
    else
        sGacha->newMonOdds = 100;
}

static void AButton(void)
{
    if (sGacha->canBetWager)
    {
        sGacha->state = STATE_INIT_A;
    }
    else
    {
        PlaySE(SE_FAILURE);
    }
}

static void UpdateCursorPosition(s16 x)
{
    // Update cursor position based on X coordinate
    if (x == 231)
        sGacha->cursorPosition = 3; // Ones
    else if (x == 223)
        sGacha->cursorPosition = 2; // Tens
    else if (x == 215)
        sGacha->cursorPosition = 1; // Hundreds
    else
        sGacha->cursorPosition = 0; // Thousands
}

static void UpdateWagerDigit(int direction)
{
    u8 place;
    u16 oldWager;
    u8 wagerDigits[4];
    u16 newWager;
    u16 d;
    int i;
    u16 maxWager;
    u16 minWager;

    place = sGacha->cursorPosition;
    d = 1000;
    oldWager = sGacha->wager;
    
    for (i = 0; i < 4; i++)
    {
        if (oldWager >= d)
            wagerDigits[i] = oldWager / d;
        else
            wagerDigits[i] = 0;

        oldWager = oldWager % d;
        d = d / 10;
    }
    maxWager = GetCoins();  // Maximum wager is the current coins
    
    // wagerDigits[0] = Thousands place
    // wagerDigits[1] = Hundreds place
    // wagerDigits[2] = Tens place
    // wagerDigits[3] = Ones place

    if (direction == 0) // Up
    {
        if (wagerDigits[place] == 9)
        {
            // Set the current digit to 0
            wagerDigits[place] = 0;
            if (place > 0)
                place--;  // Move to the next digit on the left
        }

        // Otherwise, simply increase the digit by 1
        wagerDigits[place]++;
        PlaySE(SE_SELECT);
                
        // Ensure the new wager doesn't exceed max available coins
        newWager = (wagerDigits[0] * 1000) + (wagerDigits[1] * 100) + (wagerDigits[2] * 10) + wagerDigits[3];
        if (newWager > maxWager) // If the new wager exceeds available coins, revert back
            newWager = maxWager;
        // Update the wager if it's within the limit
        sGacha->wager = newWager;
    }
    else if (direction == 2) // Down
    {
        if (wagerDigits[place] > 0)
        {
            // Decrease the digit by 1
            wagerDigits[place]--;
            sGacha->wager = (wagerDigits[0] * 1000) + (wagerDigits[1] * 100) + (wagerDigits[2] * 10) + wagerDigits[3];
            PlaySE(SE_SELECT);
        }
    }

    // Update sprite animation based on the new value
    gSprites[sGacha->ArrowsSpriteId].animNum = (wagerDigits[place] == 0) ? 1 : 0;
    SetPlayerDigits(sGacha->wager);  // Update the displayed wager

    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        minWager = GACHA_BASIC_MIN_WAGER;
        break;
    case GACHA_GREAT:
        minWager = GACHA_GREAT_MIN_WAGER;
        break;
    case GACHA_ULTRA:
        minWager = GACHA_ULTRA_MIN_WAGER;
        break;
    case GACHA_MASTER:
        minWager = GACHA_MASTER_MIN_WAGER;
        break;
    }

    if (sGacha->wager >= minWager)
    {
        ResetMessage();
        CalculatePullOdds();
        sGacha->canBetWager = TRUE;
        gSprites[sGacha->CTAspriteId].animNum = 1; // On
        ShowMessage();
    }
    else
    {
        ResetMessage();
        //CalculatePullOdds();
        sGacha->newMonOdds = 0;
        sGacha->canBetWager = FALSE;        
        gSprites[sGacha->CTAspriteId].animNum = 0; // Off
        ShowMessage();
    }
}

static void MoveCursor(int direction)
{
    struct Sprite *cursorSprite = &gSprites[sGacha->ArrowsSpriteId];
    int curX = cursorSprite->x;
    int destX = curX;
    
    // Move cursor left or right (X axis)
    if (direction == 1 || direction == 3)// Right or Left
    {
        if (direction == 1 && curX < 231)
        {
            destX = curX + 8;
            PlaySE(SE_SELECT);
        }
        else if (direction == 3 && curX > 207)
        {
            destX = curX - 8;
            PlaySE(SE_SELECT);
        }
        
        cursorSprite->x = destX;
        UpdateCursorPosition(gSprites[sGacha->ArrowsSpriteId].x);  // Update cursor position based on X coordinate
    }
    
    // Move cursor up or down (change wager digit)
    else if (direction == 0 || direction == 2) // Up or Down
    {
        UpdateWagerDigit(direction); // Update the corresponding digit
    }
}

static void ExitGacha(void)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        FREE_AND_SET_NULL(sGacha);
    }
}

static void HandleInput(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        AButton();
    }
    else if (JOY_NEW(B_BUTTON))
    {
        sGacha->state = GACHA_STATE_START_EXIT;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        MoveCursor(0);
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        MoveCursor(1);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        MoveCursor(2);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        MoveCursor(3);
    }
}

static void RemoveGarbage(void)
{
    DestroySpriteAndFreeResources(&gSprites[sGacha->CreditSpriteIds[0]]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->CreditSpriteIds[1]]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->CreditSpriteIds[2]]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->CreditSpriteIds[3]]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->PlayerSpriteIds[0]]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->PlayerSpriteIds[1]]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->PlayerSpriteIds[2]]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->PlayerSpriteIds[3]]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->KnobSpriteId]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->DigitalTextSpriteId]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->LotteryJPNspriteId]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->CreditMenu1Id]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->CreditMenu2Id]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->PokemonOneSpriteId]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->PokemonTwoSpriteId]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->PokemonThreeSpriteId]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->ArrowsSpriteId]);
    DestroySpriteAndFreeResources(&gSprites[sGacha->CTAspriteId]);
    ResetMessage();
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                 BGCNT_CHARBASE(1) |
                                 BGCNT_16COLOR |
                                 BGCNT_SCREENBASE(18) |
                                 BGCNT_TXT512x256);
    LoadPalette(gTradeGba2_Pal, BG_PLTT_ID(1), 3 * PLTT_SIZE_4BPP);
    DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(1), 0x1420, 0x1000);
    DmaCopy16Defvars(3, gTrade_Tilemap, (void *) BG_SCREEN_ADDR(18), 0x1000);    
    
    gPaletteFade.bufferTransferDisabled = TRUE;
    gPaletteFade.bufferTransferDisabled = FALSE;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetVBlankCallback(GachaVBlankCallback);
}

void ShowFinalMessage(void)
{
    struct WindowTemplate template;

    SetWindowTemplateFields(&template, 1, 2, 15, 26, 4, 0xF, 0x194);
    
    sTextWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sTextWindowId, PIXEL_FILL(0));
    PutWindowTilemap(sTextWindowId);
    LoadUserWindowBorderGfx(sTextWindowId, 0x214, BG_PLTT_ID(14));
    DrawStdWindowFrame(sTextWindowId, FALSE); 
    StringCopy(gStringVar1, GetSpeciesName(sGacha->CalculatedSpecies));
    StringExpandPlaceholders(gStringVar4, sText_FromGacha);
    AddTextPrinterParameterized(sTextWindowId, FONT_NORMAL, gStringVar4, 0, 1, 0, 0);
    CopyWindowToVram(sTextWindowId, 3);
}

static u8 GetSpeciesGachaLevel(void)
{
    u32 level, levelCap, minLevel, addedLevelRange, i;
    static const u32 sLevelGachaFlagMap[][3] =
    {
        {FLAG_BADGE01_GET, 5, 6},
        {FLAG_BADGE02_GET, 7, 5},
        {FLAG_BADGE03_GET, 13, 7},
        {FLAG_BADGE04_GET, 18, 5},
        {FLAG_BADGE05_GET, 19, 9},
        {FLAG_BADGE06_GET, 21, 9},
        {FLAG_BADGE07_GET, 28, 8},
        {FLAG_BADGE08_GET, 36, 14},
        {FLAG_IS_CHAMPION, 40, 29},
    };

    minLevel = 2;
    addedLevelRange = 4;

    for (i = 0; i < ARRAY_COUNT(sLevelGachaFlagMap); i++)
    {
        if (FlagGet(sLevelGachaFlagMap[i][0]))
        {
            minLevel = sLevelGachaFlagMap[i][1];
            addedLevelRange = sLevelGachaFlagMap[i][2];
        }
    }

    addedLevelRange += 1;

    level = (Random() % addedLevelRange) + minLevel;

    levelCap = GetCurrentLevelCap();

    if (level > levelCap)
        level = levelCap;

    if (level < 1)
        level = 1;

    return level;
}

static void GachaMain(u8 taskId)
{
    switch (sGacha->state)
    {
    case GACHA_STATE_INIT:
        if (!gPaletteFade.active) {
            sGacha->state = GACHA_STATE_PROCESS_INPUT;
        }
        break;
    case GACHA_STATE_PROCESS_INPUT:
        HandleInput();
        break;
    case GACHA_STATE_START_EXIT:
        StartExitGacha();
        break;
    case GACHA_STATE_EXIT:
        ExitGacha();
        break;
    case STATE_INIT_A: // Initial state
        DeterminePokemonRarityAndNewStatus();
        PlaySE(SE_SHOP);
        RemoveCoins(sGacha->wager);
        sGacha->wager = 0;
        ResetMessage();
        gSprites[sGacha->CTAspriteId].animNum = 0;
        gSprites[sGacha->ArrowsSpriteId].invisible = TRUE;
        SetCreditDigits(GetCoins());
        SetPlayerDigits(sGacha->wager);
        sGacha->waitTimer = 30;  // Set the timer
        sGacha->state = STATE_TIMER_1;  // Move to next state
        break;
    case STATE_TIMER_1: // Waiting for timer to expire
        if (sGacha->waitTimer > 0)
            sGacha->waitTimer--;  // Decrease timer
        else
            sGacha->state = STATE_TWIST;  // Transition to next state when the timer is done
        break;
    case STATE_TWIST: // After timer expires, proceed with animation
        PlaySE(SE_VEND);
        gSprites[sGacha->KnobSpriteId].animNum = 1;
        sGacha->state = STATE_TIMER_2;  // Move to the next state after animation starts
        break;
    case STATE_TIMER_2: // Handle the next part of the delay or action
        // (You can add another waiting period if needed)
        sGacha->waitTimer = 50;  // Set the next timer
        sGacha->state = STATE_INIT_GIVE;  // Move to next state
        break;
    case STATE_INIT_GIVE: // Final state
        if (sGacha->waitTimer > 0)
            sGacha->waitTimer--;  // Decrease timer
        else
            sGacha->state = STATE_SHAKE_1;  // Final action after timer
        break;
    case STATE_SHAKE_1: // After timer expires, proceed with animation
        PlaySE(SE_BREAKABLE_DOOR);
        Shake1();
        sGacha->state = STATE_TIMER_3;  // Move to the next state after animation starts
        break;
    case STATE_TIMER_3: // Handle the next part of the delay or action
        // (You can add another waiting period if needed)
        sGacha->waitTimer = 3;  // Set the next timer
        sGacha->state = STATE_INIT_SHAKE_2;  // Move to next state
        break;
    case STATE_INIT_SHAKE_2: // Final state
        if (sGacha->waitTimer > 0)
            sGacha->waitTimer--;  // Decrease timer
        else
            sGacha->state = STATE_SHAKE_2;  // Final action after timer
        break;    
    case STATE_SHAKE_2: // After timer expires, proceed with animation
        //PlaySE(SE_BREAKABLE_DOOR);
        Shake2();
        sGacha->state = STATE_TIMER_4;  // Move to the next state after animation starts
        break;
    case STATE_TIMER_4: // Handle the next part of the delay or action
        // (You can add another waiting period if needed)
        sGacha->waitTimer = 3;  // Set the next timer
        sGacha->state = STATE_INIT_SHAKE_3;  // Move to next state
        break;
    case STATE_INIT_SHAKE_3: // Final state
        if (sGacha->waitTimer > 0)
        {
            sGacha->waitTimer--;  // Decrease timer
        }
        else 
        {
            BGSetup();
            sGacha->waitTimer = 20;
            sGacha->state = STATE_TIMER_5;  // Final action after timer
        }
        break;
    case STATE_TIMER_5: // After timer expires, proceed with animation
        if (sGacha->waitTimer > 0)
            sGacha->waitTimer--;  // Decrease timer
        else
            sGacha->state = STATE_GIVE;  // Move to the next state after animation starts
        break;
    case STATE_GIVE:
        StartTradeScreen();
        break;
    case STATE_FADE:
        if (!gPaletteFade.active)
        {
            BGRed();
            sGacha->state = STATE_POKEBALL_INIT;
        }
        break;
    case STATE_POKEBALL_INIT:
        RemoveGarbage();
        sGacha->state++;
        break;    
    case STATE_POKEBALL_PROCESS:
        if (!gPaletteFade.active)
            sGacha->state = STATE_POKEBALL_ARRIVE;
        break;
    case STATE_POKEBALL_ARRIVE:    
        LoadSpriteSheet(&sPokeBallSpriteSheet);
        LoadSpritePalette(&sPokeBallSpritePalette);
        sGacha->bouncingPokeballSpriteId = CreateSprite(&sSpriteTemplate_Pokeball, 120, -8, 0);
        gSprites[sGacha->bouncingPokeballSpriteId].data[3] = 74;
        gSprites[sGacha->bouncingPokeballSpriteId].callback = SpriteCB_BouncingPokeballArrive;
        StartSpriteAnim(&gSprites[sGacha->bouncingPokeballSpriteId], 1);
        StartSpriteAffineAnim(&gSprites[sGacha->bouncingPokeballSpriteId], 2);
        BlendPalettes(1 << (16 + gSprites[sGacha->bouncingPokeballSpriteId].oam.paletteNum), 16, RGB_WHITEALPHA);
        sGacha->state++;
        sGacha->timer = 0;
        break;
    case STATE_FADE_POKEBALL_TO_NORMAL:
        BeginNormalPaletteFade(1 << (16 + gSprites[sGacha->bouncingPokeballSpriteId].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
        sGacha->state++;
        break;
    case STATE_POKEBALL_ARRIVE_WAIT:        
        if (gSprites[sGacha->bouncingPokeballSpriteId].callback == SpriteCallbackDummy)
        {
            CreateRandomMon(&gParties[B_TRAINER_OPPONENT_A][0], sGacha->CalculatedSpecies, GetSpeciesGachaLevel());
            
            //CreateMon(&gParties[B_TRAINER_OPPONENT_A][0], sGacha->CalculatedSpecies, GetSpeciesGachaLevel(), USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
            CopyMonToPC(&gParties[B_TRAINER_OPPONENT_A][0]);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(sGacha->CalculatedSpecies), FLAG_SET_SEEN);
            HandleSetPokedexFlag(SpeciesToNationalPokedexNum(sGacha->CalculatedSpecies), FLAG_SET_CAUGHT, GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_PERSONALITY));
            LoadPalette(GetMonFrontSpritePal(&gParties[B_TRAINER_OPPONENT_A][0]), OBJ_PLTT_ID(2), PLTT_SIZE_4BPP);
            SetMultiuseSpriteTemplateToPokemon(sGacha->CalculatedSpecies, B_POSITION_OPPONENT_RIGHT);
            sGacha->monSpriteId = CreateMonPicSprite_Affine(sGacha->CalculatedSpecies, GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_IS_SHINY), GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_PERSONALITY), MON_PIC_AFFINE_FRONT, 120, 60, 14, TAG_NONE);
            gSprites[sGacha->monSpriteId].callback = SpriteCB_Null;
            gSprites[sGacha->monSpriteId].oam.priority = 0;
            gSprites[sGacha->monSpriteId].invisible = TRUE;
            HandleLoadSpecialPokePic(TRUE,
                                        gMonSpritesGfxPtr->spritesGfx[B_POSITION_OPPONENT_RIGHT],
                                        sGacha->CalculatedSpecies,
                                        GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_PERSONALITY));
            sGacha->state++;
        }
        break;
    case STATE_SHOW_NEW_MON:
        gSprites[sGacha->monSpriteId].x = 120;
        gSprites[sGacha->monSpriteId].y = gSpeciesInfo[sGacha->CalculatedSpecies].frontPicYOffset + 56;
        gSprites[sGacha->monSpriteId].x2 = 0;
        gSprites[sGacha->monSpriteId].y2 = 0;
        StartSpriteAnim(&gSprites[sGacha->monSpriteId], 0);
        CreatePokeballSpriteToReleaseMon(sGacha->monSpriteId, gSprites[sGacha->monSpriteId].oam.paletteNum, 120, 84, 2, 1, 20, PALETTES_BG | (0xF << 16), sGacha->CalculatedSpecies);
        FreeSpriteOamMatrix(&gSprites[sGacha->bouncingPokeballSpriteId]);
        DestroySprite(&gSprites[sGacha->bouncingPokeballSpriteId]);
        sGacha->state++;
        break;
    case STATE_NEW_MON_MSG:
        // Wait for Pokémon's front sprite animation
        if (gSprites[sGacha->monSpriteId].callback == SpriteCallbackDummy)
            sGacha->state++;
        break;
    case NEW_1:
        // "{mon} hatched from egg" message/fanfare
        ShowFinalMessage();
        PlayFanfare(MUS_EVOLVED);
        sGacha->state++;
        //PutWindowTilemap(0);
        //CopyWindowToVram(0, COPYWIN_FULL);
        break;
    case NEW_2:
        if (IsFanfareTaskInactive())
            sGacha->state++;
        break;
    case STATE_SET_EXIT:
        // Ready the nickname prompt
        if (FlagGet(FLAG_SYS_POKEMON_GET) == FALSE)
        {
            FlagSet(FLAG_SYS_POKEMON_GET);
        }
        sGacha->state = GACHA_STATE_START_EXIT;
        break;
    }
}

static void InitGachaScreen(void)
{    
    sGacha->GachaId = gSpecialVar_0x8004;

    SetVBlankCallback(NULL);
    ResetAllBgsCoordinates();
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    ResetTempTileDataBuffers();

    BGSetup();

    ResetSpriteData();
    FreeAllSpritePalettes();

    switch (sGacha->GachaId)
    {
    default:
    case GACHA_BASIC:
        LoadSpritePalettes(sSpritePalettesBasic);
        CreateHoppip();
        break;
    case GACHA_GREAT:
        LoadSpritePalettes(sSpritePalettesGreat);
        CreatePhanpy();
        break;
    case GACHA_ULTRA:
        LoadSpritePalettes(sSpritePalettesUltra);
        CreateTeddiursa();
        break;
    case GACHA_MASTER:
        LoadSpritePalettes(sSpritePalettesMaster);
        CreateBelossom();
        break;
    }
    CreateArrows();
    CreateCTA();
    CreateDigitalText();    
    CreateKnob();
    CreateCreditSprites();
    CreatePlayerSprites();
    SetCreditDigits(GetCoins());
    SetPlayerDigits(0);    
    CreateCreditMenu();    
    CreatePlayerMenu();
    CreateLotteryJPN();
    
    sGacha->newMonOdds = 0;
    InitWindows(sGachaWinTemplates);
    LoadPalette(GetTextWindowPalette(2), 11 * 16, 32);
    ShowMessage();

    UpdateCursorPosition(gSprites[sGacha->ArrowsSpriteId].x);
    sGacha->waitTimer = 0;
    GetPokemonOwned();
    
    CopyBgTilemapBufferToVram(GACHA_BG_BASE);
    CopyBgTilemapBufferToVram(GACHA_MENUS);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_BG2_ON);
    ShowBg(GACHA_BG_BASE);
    ShowBg(GACHA_MENUS);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    SetVBlankCallback(GachaVBlankCallback);
    SetMainCallback2(GachaMainCallback);
    CreateTask(GachaMain, 1);
}

