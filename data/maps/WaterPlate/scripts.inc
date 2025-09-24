WaterPlate_MapScripts::
# 2 "data/maps/WaterPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, WaterPlate_OnLoad
	.byte 0


WaterPlate_OnLoad::
# 6 "data/maps/WaterPlate/scripts.pory"
	call_if_unset FLAG_WATER_PC, WaterPlate_Entrance
# 7 "data/maps/WaterPlate/scripts.pory"
	call WaterPlate_IsGemCollected
# 8 "data/maps/WaterPlate/scripts.pory"
	call WaterPlate_ConditionCheck
	end


WaterPlate_Entrance::
# 13 "data/maps/WaterPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/WaterPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/WaterPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/WaterPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


WaterPlate_Battle::
# 23 "data/maps/WaterPlate/scripts.pory"
	lockall
# 24 "data/maps/WaterPlate/scripts.pory"
	playmoncry SPECIES_BASCULEGION, CRY_MODE_ENCOUNTER
# 25 "data/maps/WaterPlate/scripts.pory"
	delay 40
# 26 "data/maps/WaterPlate/scripts.pory"
	waitmoncry
# 28 "data/maps/WaterPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_BASCULEGION, 50, [ ITEM_WATER_GEM ], , NATURE_JOLLY, 0, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_PSYCHIC_FANGS ], [ MOVE_LAST_RESPECTS ], [ MOVE_LIQUIDATION ], [ MOVE_FLIP_TURN ]
# 29 "data/maps/WaterPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 30 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/WaterPlate/scripts.pory"
	dowildbattle
# 35 "data/maps/WaterPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq WaterPlate_Battle_2
# 39 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq WaterPlate_Battle_3
# 42 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq WaterPlate_Battle_4
# 45 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq WaterPlate_Battle_5
WaterPlate_Battle_1:
# 48 "data/maps/WaterPlate/scripts.pory"
	waitmessage
# 49 "data/maps/WaterPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/WaterPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/WaterPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_WATER_PC1
# 53 "data/maps/WaterPlate/scripts.pory"
	releaseall
	return

WaterPlate_Battle_2:
# 37 "data/maps/WaterPlate/scripts.pory"
	call WaterPlateWonCatch
	goto WaterPlate_Battle_1

WaterPlate_Battle_3:
# 40 "data/maps/WaterPlate/scripts.pory"
	call WaterPlateWonCatch
	goto WaterPlate_Battle_1

WaterPlate_Battle_4:
# 43 "data/maps/WaterPlate/scripts.pory"
	call WaterPlateRun
	goto WaterPlate_Battle_1

WaterPlate_Battle_5:
# 46 "data/maps/WaterPlate/scripts.pory"
	call WaterPlateRun
	goto WaterPlate_Battle_1


WaterPlateWonCatch::
# 57 "data/maps/WaterPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/WaterPlate/scripts.pory"
	removeobject 1
# 59 "data/maps/WaterPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/WaterPlate/scripts.pory"
	giveitem ITEM_SPLASH_PLATE
# 62 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


WaterPlateRun::
# 68 "data/maps/WaterPlate/scripts.pory"
	playmoncry SPECIES_BASCULEGION, CRY_MODE_ENCOUNTER
# 69 "data/maps/WaterPlate/scripts.pory"
	waitmoncry
	return


WaterPlate_IsGemCollected::
# 74 "data/maps/WaterPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_WATER_GEM, WaterPlate_IsGemCollected_2
# 78 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
WaterPlate_IsGemCollected_1:
	return

WaterPlate_IsGemCollected_2:
# 75 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto WaterPlate_IsGemCollected_1


WaterPlate_CollectGem::
# 84 "data/maps/WaterPlate/scripts.pory"
	lockall
# 85 "data/maps/WaterPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_WATER_GEM, WaterPlate_CollectGem_2
# 89 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WaterPlate_CollectGem_5
WaterPlate_CollectGem_1:
# 99 "data/maps/WaterPlate/scripts.pory"
	releaseall
	return

WaterPlate_CollectGem_2:
# 86 "data/maps/WaterPlate/scripts.pory"
	msgbox WaterPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto WaterPlate_CollectGem_1

WaterPlate_CollectGem_5:
# 91 "data/maps/WaterPlate/scripts.pory"
	giveitem ITEM_WATER_GEM
# 92 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_WATER_GEM
# 93 "data/maps/WaterPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/WaterPlate/scripts.pory"
	warp MAP_WATER_PLATE, 7, 20
# 95 "data/maps/WaterPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/WaterPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto WaterPlate_CollectGem_1


WaterPlate_ConditionCheck::
# 103 "data/maps/WaterPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, WaterPlate_ConditionCheck_2
WaterPlate_ConditionCheck_1:
	return

WaterPlate_ConditionCheck_2:
# 104 "data/maps/WaterPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, WaterPlate_ConditionCheck_4
	goto WaterPlate_ConditionCheck_1

WaterPlate_ConditionCheck_4:
# 105 "data/maps/WaterPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, WaterPlate_ConditionCheck_6
	goto WaterPlate_ConditionCheck_1

WaterPlate_ConditionCheck_6:
# 106 "data/maps/WaterPlate/scripts.pory"
	checkitem ITEM_WATER_GEM, 1
# 107 "data/maps/WaterPlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq WaterPlate_ConditionCheck_8
	goto WaterPlate_ConditionCheck_1

WaterPlate_ConditionCheck_8:
# 108 "data/maps/WaterPlate/scripts.pory"
	setflag FLAG_WATER_PC
	goto WaterPlate_ConditionCheck_1


WaterPlateWonCatch_Text_0:
# 60 "data/maps/WaterPlate/scripts.pory"
	.string "The Basculegion dissapeared in to the\ncave.$"

WaterPlateWonCatch_Text_1:
# 62 "data/maps/WaterPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

WaterPlateWonCatch_Text_2:
# 63 "data/maps/WaterPlate/scripts.pory"
	.string "The rightful bearer of a Plate draws\nfrom the Plate it holds.$"

WaterPlate_CollectGem_Text_0:
# 86 "data/maps/WaterPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

WaterPlate_CollectGem_Text_1:
# 89 "data/maps/WaterPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
