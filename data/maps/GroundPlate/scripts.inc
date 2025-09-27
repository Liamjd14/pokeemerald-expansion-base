GroundPlate_MapScripts::
# 2 "data/maps/GroundPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GroundPlate_OnLoad
	.byte 0


GroundPlate_OnLoad::
# 6 "data/maps/GroundPlate/scripts.pory"
	call GroundPlate_IsGemCollected
# 7 "data/maps/GroundPlate/scripts.pory"
	call GroundPlate_ConditionCheck
# 8 "data/maps/GroundPlate/scripts.pory"
	call_if_unset FLAG_GROUND_PC, GroundPlate_Entrance
	end


GroundPlate_Entrance::
# 13 "data/maps/GroundPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/GroundPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/GroundPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/GroundPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


GroundPlate_Battle::
# 23 "data/maps/GroundPlate/scripts.pory"
	lockall
# 24 "data/maps/GroundPlate/scripts.pory"
	playmoncry SPECIES_URSALUNA, CRY_MODE_ENCOUNTER
# 25 "data/maps/GroundPlate/scripts.pory"
	delay 40
# 26 "data/maps/GroundPlate/scripts.pory"
	waitmoncry
# 28 "data/maps/GroundPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_URSALUNA, 50, [ ITEM_GROUND_GEM ], , NATURE_JOLLY, 0, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_FACADE ], [ MOVE_HEADLONG_RUSH ], [ MOVE_FIRE_PUNCH ], [ MOVE_ICE_PUNCH ]
# 29 "data/maps/GroundPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 30 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/GroundPlate/scripts.pory"
	dowildbattle
# 35 "data/maps/GroundPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GroundPlate_Battle_2
# 39 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GroundPlate_Battle_3
# 42 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq GroundPlate_Battle_4
# 45 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq GroundPlate_Battle_5
GroundPlate_Battle_1:
# 48 "data/maps/GroundPlate/scripts.pory"
	waitmessage
# 49 "data/maps/GroundPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/GroundPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/GroundPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_GROUND_PC1
# 53 "data/maps/GroundPlate/scripts.pory"
	releaseall
	return

GroundPlate_Battle_2:
# 37 "data/maps/GroundPlate/scripts.pory"
	call GroundPlateWonCatch
	goto GroundPlate_Battle_1

GroundPlate_Battle_3:
# 40 "data/maps/GroundPlate/scripts.pory"
	call GroundPlateWonCatch
	goto GroundPlate_Battle_1

GroundPlate_Battle_4:
# 43 "data/maps/GroundPlate/scripts.pory"
	call GroundPlateRun
	goto GroundPlate_Battle_1

GroundPlate_Battle_5:
# 46 "data/maps/GroundPlate/scripts.pory"
	call GroundPlateRun
	goto GroundPlate_Battle_1


GroundPlateWonCatch::
# 57 "data/maps/GroundPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/GroundPlate/scripts.pory"
	removeobject 1
# 59 "data/maps/GroundPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/GroundPlate/scripts.pory"
	giveitem ITEM_EARTH_PLATE
# 62 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


GroundPlateRun::
# 68 "data/maps/GroundPlate/scripts.pory"
	playmoncry SPECIES_URSALUNA, CRY_MODE_ENCOUNTER
# 69 "data/maps/GroundPlate/scripts.pory"
	waitmoncry
	return


GroundPlate_IsGemCollected::
# 74 "data/maps/GroundPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GROUND_GEM, GroundPlate_IsGemCollected_2
# 78 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
GroundPlate_IsGemCollected_1:
	return

GroundPlate_IsGemCollected_2:
# 75 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto GroundPlate_IsGemCollected_1


GroundPlate_CollectGem::
# 84 "data/maps/GroundPlate/scripts.pory"
	lockall
# 85 "data/maps/GroundPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GROUND_GEM, GroundPlate_CollectGem_2
# 89 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GroundPlate_CollectGem_5
GroundPlate_CollectGem_1:
# 99 "data/maps/GroundPlate/scripts.pory"
	releaseall
	return

GroundPlate_CollectGem_2:
# 86 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto GroundPlate_CollectGem_1

GroundPlate_CollectGem_5:
# 91 "data/maps/GroundPlate/scripts.pory"
	giveitem ITEM_GROUND_GEM
# 92 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_GROUND_GEM
# 93 "data/maps/GroundPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/GroundPlate/scripts.pory"
	warp MAP_GROUND_PLATE, 7, 20
# 95 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/GroundPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto GroundPlate_CollectGem_1


GroundPlate_ConditionCheck::
# 103 "data/maps/GroundPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, GroundPlate_ConditionCheck_2
GroundPlate_ConditionCheck_1:
	return

GroundPlate_ConditionCheck_2:
# 104 "data/maps/GroundPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, GroundPlate_ConditionCheck_4
	goto GroundPlate_ConditionCheck_1

GroundPlate_ConditionCheck_4:
# 105 "data/maps/GroundPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, GroundPlate_ConditionCheck_6
	goto GroundPlate_ConditionCheck_1

GroundPlate_ConditionCheck_6:
# 106 "data/maps/GroundPlate/scripts.pory"
	checkitem ITEM_GROUND_GEM, 1
# 107 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq GroundPlate_ConditionCheck_8
	goto GroundPlate_ConditionCheck_1

GroundPlate_ConditionCheck_8:
# 108 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_GROUND_PC
	goto GroundPlate_ConditionCheck_1


GroundPlateWonCatch_Text_0:
# 60 "data/maps/GroundPlate/scripts.pory"
	.string "The Ursaluna dissapeared in to th\ncave.$"

GroundPlateWonCatch_Text_1:
# 62 "data/maps/GroundPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

GroundPlateWonCatch_Text_2:
# 63 "data/maps/GroundPlate/scripts.pory"
	.string "When the universe was created, it's\nshards became this Plate.$"

GroundPlate_CollectGem_Text_0:
# 86 "data/maps/GroundPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

GroundPlate_CollectGem_Text_1:
# 89 "data/maps/GroundPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
