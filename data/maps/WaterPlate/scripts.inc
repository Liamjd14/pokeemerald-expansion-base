WaterPlate_MapScripts::
# 2 "data/maps/WaterPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, WaterPlate_OnLoad
	.byte 0


WaterPlate_OnLoad::
# 6 "data/maps/WaterPlate/scripts.pory"
	call_if_unset FLAG_WATER_PC, WaterPlate_Entrance
# 7 "data/maps/WaterPlate/scripts.pory"
	call WaterPlate_IsGemCollected
	end


WaterPlate_Entrance::
# 12 "data/maps/WaterPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/WaterPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/WaterPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/WaterPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


WaterPlate_Battle::
# 22 "data/maps/WaterPlate/scripts.pory"
	lockall
# 23 "data/maps/WaterPlate/scripts.pory"
	playmoncry SPECIES_BASCULEGION, CRY_MODE_ENCOUNTER
# 24 "data/maps/WaterPlate/scripts.pory"
	delay 40
# 25 "data/maps/WaterPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/WaterPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_BASCULEGION, 50, [ ITEM_WATER_GEM ], , NATURE_JOLLY, 0, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_PSYCHIC_FANGS ], [ MOVE_LAST_RESPECTS ], [ MOVE_LIQUIDATION ], [ MOVE_FLIP_TURN ]
# 28 "data/maps/WaterPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/WaterPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/WaterPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq WaterPlate_Battle_2
# 38 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq WaterPlate_Battle_3
# 41 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq WaterPlate_Battle_4
# 44 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq WaterPlate_Battle_5
WaterPlate_Battle_1:
# 47 "data/maps/WaterPlate/scripts.pory"
	waitmessage
# 48 "data/maps/WaterPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/WaterPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/WaterPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_WATER_PC1
# 52 "data/maps/WaterPlate/scripts.pory"
	releaseall
	return

WaterPlate_Battle_2:
# 36 "data/maps/WaterPlate/scripts.pory"
	call WaterPlateWonCatch
	goto WaterPlate_Battle_1

WaterPlate_Battle_3:
# 39 "data/maps/WaterPlate/scripts.pory"
	call WaterPlateWonCatch
	goto WaterPlate_Battle_1

WaterPlate_Battle_4:
# 42 "data/maps/WaterPlate/scripts.pory"
	call WaterPlateRun
	goto WaterPlate_Battle_1

WaterPlate_Battle_5:
# 45 "data/maps/WaterPlate/scripts.pory"
	call WaterPlateRun
	goto WaterPlate_Battle_1


WaterPlateWonCatch::
# 56 "data/maps/WaterPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/WaterPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/WaterPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/WaterPlate/scripts.pory"
	giveitem ITEM_SPLASH_PLATE
# 61 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


WaterPlateRun::
# 67 "data/maps/WaterPlate/scripts.pory"
	playmoncry SPECIES_BASCULEGION, CRY_MODE_ENCOUNTER
# 68 "data/maps/WaterPlate/scripts.pory"
	waitmoncry
	return


WaterPlate_IsGemCollected::
# 73 "data/maps/WaterPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_WATER_GEM, WaterPlate_IsGemCollected_2
# 77 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
WaterPlate_IsGemCollected_1:
	return

WaterPlate_IsGemCollected_2:
# 74 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto WaterPlate_IsGemCollected_1


WaterPlate_CollectGem::
# 83 "data/maps/WaterPlate/scripts.pory"
	lockall
# 84 "data/maps/WaterPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_WATER_GEM, WaterPlate_CollectGem_2
# 88 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WaterPlate_CollectGem_5
WaterPlate_CollectGem_1:
# 98 "data/maps/WaterPlate/scripts.pory"
	releaseall
	return

WaterPlate_CollectGem_2:
# 85 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto WaterPlate_CollectGem_1

WaterPlate_CollectGem_5:
# 90 "data/maps/WaterPlate/scripts.pory"
	giveitem ITEM_WATER_GEM
# 91 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_WATER_GEM
# 92 "data/maps/WaterPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/WaterPlate/scripts.pory"
	warp MAP_WATER_PLATE, 7, 20
# 94 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/WaterPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto WaterPlate_CollectGem_1


WaterPlateWonCatch_Text_0:
# 59 "data/maps/WaterPlate/scripts.pory"
	.string "The Basculegion dissapeared in to the\ncave.$"

WaterPlateWonCatch_Text_1:
# 61 "data/maps/WaterPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

WaterPlateWonCatch_Text_2:
# 62 "data/maps/WaterPlate/scripts.pory"
	.string "The rightful bearer of a Plate draws\nfrom the Plate it holds.$"

WaterPlate_CollectGem_Text_0:
# 85 "data/maps/WaterPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

WaterPlate_CollectGem_Text_1:
# 88 "data/maps/WaterPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
