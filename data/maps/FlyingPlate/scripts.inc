FlyingPlate_MapScripts::
# 2 "data/maps/FlyingPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FlyingPlate_OnLoad
	.byte 0


FlyingPlate_OnLoad::
# 6 "data/maps/FlyingPlate/scripts.pory"
	call FlyingPlate_IsGemCollected
# 7 "data/maps/FlyingPlate/scripts.pory"
	call FlyingPlate_ConditionCheck
# 8 "data/maps/FlyingPlate/scripts.pory"
	call_if_unset FLAG_FLYING_PC, FlyingPlate_Entrance
	end


FlyingPlate_Entrance::
# 13 "data/maps/FlyingPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/FlyingPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/FlyingPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/FlyingPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/FlyingPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/FlyingPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


FlyingPlate_Battle::
# 23 "data/maps/FlyingPlate/scripts.pory"
	lockall
# 24 "data/maps/FlyingPlate/scripts.pory"
	playmoncry SPECIES_BRAVIARY_HISUI, CRY_MODE_ENCOUNTER
# 25 "data/maps/FlyingPlate/scripts.pory"
	delay 40
# 26 "data/maps/FlyingPlate/scripts.pory"
	waitmoncry
# 28 "data/maps/FlyingPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_BRAVIARY_HISUI, 50, [ ITEM_FLYING_GEM ], , NATURE_TIMID, 1, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_HEAT_WAVE ], [ MOVE_ROOST ], [ MOVE_PSYCHIC ], [ MOVE_HURRICANE ]
# 29 "data/maps/FlyingPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 30 "data/maps/FlyingPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/FlyingPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/FlyingPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/FlyingPlate/scripts.pory"
	dowildbattle
# 35 "data/maps/FlyingPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/FlyingPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FlyingPlate_Battle_2
# 39 "data/maps/FlyingPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FlyingPlate_Battle_3
# 42 "data/maps/FlyingPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FlyingPlate_Battle_4
# 45 "data/maps/FlyingPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FlyingPlate_Battle_5
FlyingPlate_Battle_1:
# 48 "data/maps/FlyingPlate/scripts.pory"
	waitmessage
# 49 "data/maps/FlyingPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/FlyingPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/FlyingPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/FlyingPlate/scripts.pory"
	setflag FLAG_FLYING_PC1
# 53 "data/maps/FlyingPlate/scripts.pory"
	releaseall
	return

FlyingPlate_Battle_2:
# 37 "data/maps/FlyingPlate/scripts.pory"
	call FlyingPlateWonCatch
	goto FlyingPlate_Battle_1

FlyingPlate_Battle_3:
# 40 "data/maps/FlyingPlate/scripts.pory"
	call FlyingPlateWonCatch
	goto FlyingPlate_Battle_1

FlyingPlate_Battle_4:
# 43 "data/maps/FlyingPlate/scripts.pory"
	call FlyingPlateRun
	goto FlyingPlate_Battle_1

FlyingPlate_Battle_5:
# 46 "data/maps/FlyingPlate/scripts.pory"
	call FlyingPlateRun
	goto FlyingPlate_Battle_1


FlyingPlateWonCatch::
# 57 "data/maps/FlyingPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/FlyingPlate/scripts.pory"
	removeobject 1
# 59 "data/maps/FlyingPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/FlyingPlate/scripts.pory"
	msgbox FlyingPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/FlyingPlate/scripts.pory"
	giveitem ITEM_SKY_PLATE
# 62 "data/maps/FlyingPlate/scripts.pory"
	msgbox FlyingPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/FlyingPlate/scripts.pory"
	msgbox FlyingPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


FlyingPlateRun::
# 68 "data/maps/FlyingPlate/scripts.pory"
	playmoncry SPECIES_BRAVIARY_HISUI, CRY_MODE_ENCOUNTER
# 69 "data/maps/FlyingPlate/scripts.pory"
	waitmoncry
	return


FlyingPlate_IsGemCollected::
# 74 "data/maps/FlyingPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FLYING_GEM, FlyingPlate_IsGemCollected_2
# 78 "data/maps/FlyingPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
FlyingPlate_IsGemCollected_1:
	return

FlyingPlate_IsGemCollected_2:
# 75 "data/maps/FlyingPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto FlyingPlate_IsGemCollected_1


FlyingPlate_CollectGem::
# 84 "data/maps/FlyingPlate/scripts.pory"
	lockall
# 85 "data/maps/FlyingPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FLYING_GEM, FlyingPlate_CollectGem_2
# 89 "data/maps/FlyingPlate/scripts.pory"
	msgbox FlyingPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/FlyingPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FlyingPlate_CollectGem_5
FlyingPlate_CollectGem_1:
# 99 "data/maps/FlyingPlate/scripts.pory"
	releaseall
	return

FlyingPlate_CollectGem_2:
# 86 "data/maps/FlyingPlate/scripts.pory"
	msgbox FlyingPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto FlyingPlate_CollectGem_1

FlyingPlate_CollectGem_5:
# 91 "data/maps/FlyingPlate/scripts.pory"
	giveitem ITEM_FLYING_GEM
# 92 "data/maps/FlyingPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_FLYING_GEM
# 93 "data/maps/FlyingPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/FlyingPlate/scripts.pory"
	warp MAP_FLYING_PLATE, 7, 20
# 95 "data/maps/FlyingPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/FlyingPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto FlyingPlate_CollectGem_1


FlyingPlate_ConditionCheck::
# 103 "data/maps/FlyingPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, FlyingPlate_ConditionCheck_2
FlyingPlate_ConditionCheck_1:
	return

FlyingPlate_ConditionCheck_2:
# 104 "data/maps/FlyingPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, FlyingPlate_ConditionCheck_4
	goto FlyingPlate_ConditionCheck_1

FlyingPlate_ConditionCheck_4:
# 105 "data/maps/FlyingPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, FlyingPlate_ConditionCheck_6
	goto FlyingPlate_ConditionCheck_1

FlyingPlate_ConditionCheck_6:
# 106 "data/maps/FlyingPlate/scripts.pory"
	checkitem ITEM_FLYING_GEM, 1
# 107 "data/maps/FlyingPlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FlyingPlate_ConditionCheck_8
	goto FlyingPlate_ConditionCheck_1

FlyingPlate_ConditionCheck_8:
# 108 "data/maps/FlyingPlate/scripts.pory"
	setflag FLAG_FLYING_PC
	goto FlyingPlate_ConditionCheck_1


FlyingPlateWonCatch_Text_0:
# 60 "data/maps/FlyingPlate/scripts.pory"
	.string "The Braviary dissapeared in to the cave.$"

FlyingPlateWonCatch_Text_1:
# 62 "data/maps/FlyingPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

FlyingPlateWonCatch_Text_2:
# 63 "data/maps/FlyingPlate/scripts.pory"
	.string "The being poured the remains of its\npower into stone and buried it deep.$"

FlyingPlate_CollectGem_Text_0:
# 86 "data/maps/FlyingPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

FlyingPlate_CollectGem_Text_1:
# 89 "data/maps/FlyingPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
