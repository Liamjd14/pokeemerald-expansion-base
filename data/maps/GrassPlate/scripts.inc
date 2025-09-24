GrassPlate_MapScripts::
# 2 "data/maps/GrassPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GrassPlate_OnLoad
	.byte 0


GrassPlate_OnLoad::
# 6 "data/maps/GrassPlate/scripts.pory"
	call_if_unset FLAG_GRASS_PC, GrassPlate_Entrance
# 7 "data/maps/GrassPlate/scripts.pory"
	call BugPlate_IsGemCollected
# 8 "data/maps/GrassPlate/scripts.pory"
	call GrassPlate_ConditionCheck
	end


GrassPlate_Entrance::
# 13 "data/maps/GrassPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/GrassPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/GrassPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/GrassPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


GrassPlate_Battle::
# 23 "data/maps/GrassPlate/scripts.pory"
	lockall
# 24 "data/maps/GrassPlate/scripts.pory"
	playmoncry SPECIES_LILLIGANT_HISUI, CRY_MODE_ENCOUNTER
# 25 "data/maps/GrassPlate/scripts.pory"
	delay 40
# 26 "data/maps/GrassPlate/scripts.pory"
	waitmoncry
# 28 "data/maps/GrassPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_LILLIGANT_HISUI, 50, [ ITEM_GRASS_GEM ], , NATURE_ADAMANT, 0, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_ACROBATICS ], [ MOVE_LEAF_BLADE ], [ MOVE_CLOSE_COMBAT ], [ MOVE_ICE_SPINNER ]
# 29 "data/maps/GrassPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 30 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/GrassPlate/scripts.pory"
	dowildbattle
# 35 "data/maps/GrassPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GrassPlate_Battle_2
# 39 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GrassPlate_Battle_3
# 42 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq GrassPlate_Battle_4
# 45 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq GrassPlate_Battle_5
GrassPlate_Battle_1:
# 48 "data/maps/GrassPlate/scripts.pory"
	waitmessage
# 49 "data/maps/GrassPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/GrassPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/GrassPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_GRASS_PC1
# 53 "data/maps/GrassPlate/scripts.pory"
	releaseall
	return

GrassPlate_Battle_2:
# 37 "data/maps/GrassPlate/scripts.pory"
	call GrassPlateWonCatch
	goto GrassPlate_Battle_1

GrassPlate_Battle_3:
# 40 "data/maps/GrassPlate/scripts.pory"
	call GrassPlateWonCatch
	goto GrassPlate_Battle_1

GrassPlate_Battle_4:
# 43 "data/maps/GrassPlate/scripts.pory"
	call GrassPlateRun
	goto GrassPlate_Battle_1

GrassPlate_Battle_5:
# 46 "data/maps/GrassPlate/scripts.pory"
	call GrassPlateRun
	goto GrassPlate_Battle_1


GrassPlateWonCatch::
# 57 "data/maps/GrassPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/GrassPlate/scripts.pory"
	removeobject 1
# 59 "data/maps/GrassPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/GrassPlate/scripts.pory"
	giveitem ITEM_MEADOW_PLATE
# 62 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


GrassPlateRun::
# 68 "data/maps/GrassPlate/scripts.pory"
	playmoncry SPECIES_LILLIGANT_HISUI, CRY_MODE_ENCOUNTER
# 69 "data/maps/GrassPlate/scripts.pory"
	waitmoncry
	return


GrassPlate_IsGemCollected::
# 74 "data/maps/GrassPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GRASS_GEM, GrassPlate_IsGemCollected_2
# 78 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
GrassPlate_IsGemCollected_1:
	return

GrassPlate_IsGemCollected_2:
# 75 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto GrassPlate_IsGemCollected_1


GrassPlate_CollectGem::
# 84 "data/maps/GrassPlate/scripts.pory"
	lockall
# 85 "data/maps/GrassPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GRASS_GEM, GrassPlate_CollectGem_2
# 89 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GrassPlate_CollectGem_5
GrassPlate_CollectGem_1:
# 99 "data/maps/GrassPlate/scripts.pory"
	releaseall
	return

GrassPlate_CollectGem_2:
# 86 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto GrassPlate_CollectGem_1

GrassPlate_CollectGem_5:
# 91 "data/maps/GrassPlate/scripts.pory"
	giveitem ITEM_GRASS_GEM
# 92 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_GRASS_GEM
# 93 "data/maps/GrassPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/GrassPlate/scripts.pory"
	warp MAP_GRASS_PLATE, 7, 20
# 95 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/GrassPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto GrassPlate_CollectGem_1


GrassPlate_ConditionCheck::
# 103 "data/maps/GrassPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, GrassPlate_ConditionCheck_2
GrassPlate_ConditionCheck_1:
	return

GrassPlate_ConditionCheck_2:
# 104 "data/maps/GrassPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, GrassPlate_ConditionCheck_4
	goto GrassPlate_ConditionCheck_1

GrassPlate_ConditionCheck_4:
# 105 "data/maps/GrassPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, GrassPlate_ConditionCheck_6
	goto GrassPlate_ConditionCheck_1

GrassPlate_ConditionCheck_6:
# 106 "data/maps/GrassPlate/scripts.pory"
	checkitem ITEM_GRASS_GEM, 1
# 107 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq GrassPlate_ConditionCheck_8
	goto GrassPlate_ConditionCheck_1

GrassPlate_ConditionCheck_8:
# 108 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_GRASS_PC
	goto GrassPlate_ConditionCheck_1


GrassPlateWonCatch_Text_0:
# 60 "data/maps/GrassPlate/scripts.pory"
	.string "The Lilligant dissapeared in to the\ncave.$"

GrassPlateWonCatch_Text_1:
# 62 "data/maps/GrassPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

GrassPlateWonCatch_Text_2:
# 63 "data/maps/GrassPlate/scripts.pory"
	.string "The powers of Plates are shared among\nPokémon.$"

GrassPlate_CollectGem_Text_0:
# 86 "data/maps/GrassPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

GrassPlate_CollectGem_Text_1:
# 89 "data/maps/GrassPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
