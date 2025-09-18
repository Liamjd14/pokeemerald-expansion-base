GrassPlate_MapScripts::
# 2 "data/maps/GrassPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GrassPlate_OnLoad
	.byte 0


GrassPlate_OnLoad::
# 6 "data/maps/GrassPlate/scripts.pory"
	call_if_unset FLAG_GRASS_PC, GrassPlate_Entrance
# 7 "data/maps/GrassPlate/scripts.pory"
	call BugPlate_IsGemCollected
	end


GrassPlate_Entrance::
# 12 "data/maps/GrassPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/GrassPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/GrassPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/GrassPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


GrassPlate_Battle::
# 22 "data/maps/GrassPlate/scripts.pory"
	lockall
# 23 "data/maps/GrassPlate/scripts.pory"
	playmoncry SPECIES_LILLIGANT_HISUI, CRY_MODE_ENCOUNTER
# 24 "data/maps/GrassPlate/scripts.pory"
	delay 40
# 25 "data/maps/GrassPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/GrassPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_LILLIGANT_HISUI, 50, [ ITEM_GRASS_GEM ], , NATURE_ADAMANT, 0, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_ACROBATICS ], [ MOVE_LEAF_BLADE ], [ MOVE_CLOSE_COMBAT ], [ MOVE_ICE_SPINNER ]
# 28 "data/maps/GrassPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/GrassPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/GrassPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GrassPlate_Battle_2
# 38 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GrassPlate_Battle_3
# 41 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq GrassPlate_Battle_4
# 44 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq GrassPlate_Battle_5
GrassPlate_Battle_1:
# 47 "data/maps/GrassPlate/scripts.pory"
	waitmessage
# 48 "data/maps/GrassPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/GrassPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/GrassPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_GRASS_PC1
# 52 "data/maps/GrassPlate/scripts.pory"
	releaseall
	return

GrassPlate_Battle_2:
# 36 "data/maps/GrassPlate/scripts.pory"
	call GrassPlateWonCatch
	goto GrassPlate_Battle_1

GrassPlate_Battle_3:
# 39 "data/maps/GrassPlate/scripts.pory"
	call GrassPlateWonCatch
	goto GrassPlate_Battle_1

GrassPlate_Battle_4:
# 42 "data/maps/GrassPlate/scripts.pory"
	call GrassPlateRun
	goto GrassPlate_Battle_1

GrassPlate_Battle_5:
# 45 "data/maps/GrassPlate/scripts.pory"
	call GrassPlateRun
	goto GrassPlate_Battle_1


GrassPlateWonCatch::
# 56 "data/maps/GrassPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/GrassPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/GrassPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/GrassPlate/scripts.pory"
	giveitem ITEM_MEADOW_PLATE
# 61 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


GrassPlateRun::
# 67 "data/maps/GrassPlate/scripts.pory"
	playmoncry SPECIES_LILLIGANT_HISUI, CRY_MODE_ENCOUNTER
# 68 "data/maps/GrassPlate/scripts.pory"
	waitmoncry
	return


GrassPlate_IsGemCollected::
# 73 "data/maps/GrassPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GRASS_GEM, GrassPlate_IsGemCollected_2
# 77 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
GrassPlate_IsGemCollected_1:
	return

GrassPlate_IsGemCollected_2:
# 74 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto GrassPlate_IsGemCollected_1


GrassPlate_CollectGem::
# 83 "data/maps/GrassPlate/scripts.pory"
	lockall
# 84 "data/maps/GrassPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GRASS_GEM, GrassPlate_CollectGem_2
# 88 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/GrassPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GrassPlate_CollectGem_5
GrassPlate_CollectGem_1:
# 98 "data/maps/GrassPlate/scripts.pory"
	releaseall
	return

GrassPlate_CollectGem_2:
# 85 "data/maps/GrassPlate/scripts.pory"
	msgbox GrassPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto GrassPlate_CollectGem_1

GrassPlate_CollectGem_5:
# 90 "data/maps/GrassPlate/scripts.pory"
	giveitem ITEM_GRASS_GEM
# 91 "data/maps/GrassPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_GRASS_GEM
# 92 "data/maps/GrassPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/GrassPlate/scripts.pory"
	warp MAP_GRASS_PLATE, 7, 20
# 94 "data/maps/GrassPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/GrassPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto GrassPlate_CollectGem_1


GrassPlateWonCatch_Text_0:
# 59 "data/maps/GrassPlate/scripts.pory"
	.string "The Lilligant dissapeared in to the\ncave.$"

GrassPlateWonCatch_Text_1:
# 61 "data/maps/GrassPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

GrassPlateWonCatch_Text_2:
# 62 "data/maps/GrassPlate/scripts.pory"
	.string "The powers of Plates are shared among\nPokémon.$"

GrassPlate_CollectGem_Text_0:
# 85 "data/maps/GrassPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

GrassPlate_CollectGem_Text_1:
# 88 "data/maps/GrassPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
