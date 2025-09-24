EletricPlate_MapScripts::
# 2 "data/maps/EletricPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EletricPlate_OnLoad
	.byte 0


EletricPlate_OnLoad::
# 6 "data/maps/EletricPlate/scripts.pory"
	call_if_unset FLAG_ELECTRIC_PC, EletricPlate_Entrance
# 7 "data/maps/EletricPlate/scripts.pory"
	call EletricPlate_IsGemCollected
# 8 "data/maps/EletricPlate/scripts.pory"
	call EletricPlate_ConditionCheck
	end


EletricPlate_Entrance::
# 13 "data/maps/EletricPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/EletricPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/EletricPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/EletricPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


EletricPlate_Battle::
# 23 "data/maps/EletricPlate/scripts.pory"
	lockall
# 24 "data/maps/EletricPlate/scripts.pory"
	playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_ENCOUNTER
# 25 "data/maps/EletricPlate/scripts.pory"
	delay 40
# 26 "data/maps/EletricPlate/scripts.pory"
	waitmoncry
# 28 "data/maps/EletricPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_ELECTRODE_HISUI, 50, [ ITEM_ELECTRIC_GEM ], , NATURE_TIMID, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_TAUNT ], [ MOVE_LEAF_STORM ], [ MOVE_THUNDERBOLT ], [ MOVE_VOLT_SWITCH ]
# 29 "data/maps/EletricPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 30 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/EletricPlate/scripts.pory"
	dowildbattle
# 35 "data/maps/EletricPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EletricPlate_Battle_2
# 39 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EletricPlate_Battle_3
# 42 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EletricPlate_Battle_4
# 45 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EletricPlate_Battle_5
EletricPlate_Battle_1:
# 48 "data/maps/EletricPlate/scripts.pory"
	waitmessage
# 49 "data/maps/EletricPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/EletricPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/EletricPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_ELECTRIC_PC1
# 53 "data/maps/EletricPlate/scripts.pory"
	releaseall
	return

EletricPlate_Battle_2:
# 37 "data/maps/EletricPlate/scripts.pory"
	call EletricPlateWonCatch
	goto EletricPlate_Battle_1

EletricPlate_Battle_3:
# 40 "data/maps/EletricPlate/scripts.pory"
	call EletricPlateWonCatch
	goto EletricPlate_Battle_1

EletricPlate_Battle_4:
# 43 "data/maps/EletricPlate/scripts.pory"
	call EletricPlateRun
	goto EletricPlate_Battle_1

EletricPlate_Battle_5:
# 46 "data/maps/EletricPlate/scripts.pory"
	call EletricPlateRun
	goto EletricPlate_Battle_1


EletricPlateWonCatch::
# 57 "data/maps/EletricPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/EletricPlate/scripts.pory"
	removeobject 1
# 59 "data/maps/EletricPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/EletricPlate/scripts.pory"
	giveitem ITEM_ZAP_PLATE
# 62 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


EletricPlateRun::
# 68 "data/maps/EletricPlate/scripts.pory"
	playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_ENCOUNTER
# 69 "data/maps/EletricPlate/scripts.pory"
	waitmoncry
	return


EletricPlate_IsGemCollected::
# 74 "data/maps/EletricPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ELETRIC_GEM, EletricPlate_IsGemCollected_2
# 78 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
EletricPlate_IsGemCollected_1:
	return

EletricPlate_IsGemCollected_2:
# 75 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto EletricPlate_IsGemCollected_1


EletricPlate_CollectGem::
# 84 "data/maps/EletricPlate/scripts.pory"
	lockall
# 85 "data/maps/EletricPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ELETRIC_GEM, EletricPlate_CollectGem_2
# 89 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EletricPlate_CollectGem_5
EletricPlate_CollectGem_1:
# 99 "data/maps/EletricPlate/scripts.pory"
	releaseall
	return

EletricPlate_CollectGem_2:
# 86 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto EletricPlate_CollectGem_1

EletricPlate_CollectGem_5:
# 91 "data/maps/EletricPlate/scripts.pory"
	giveitem ITEM_ELECTRIC_GEM
# 92 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_ELETRIC_GEM
# 93 "data/maps/EletricPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/EletricPlate/scripts.pory"
	warp MAP_ELETRIC_PLATE, 7, 20
# 95 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/EletricPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto EletricPlate_CollectGem_1


EletricPlate_ConditionCheck::
# 103 "data/maps/EletricPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, EletricPlate_ConditionCheck_2
EletricPlate_ConditionCheck_1:
	return

EletricPlate_ConditionCheck_2:
# 104 "data/maps/EletricPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, EletricPlate_ConditionCheck_4
	goto EletricPlate_ConditionCheck_1

EletricPlate_ConditionCheck_4:
# 105 "data/maps/EletricPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, EletricPlate_ConditionCheck_6
	goto EletricPlate_ConditionCheck_1

EletricPlate_ConditionCheck_6:
# 106 "data/maps/EletricPlate/scripts.pory"
	checkitem ITEM_ELECTRIC_GEM, 1
# 107 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EletricPlate_ConditionCheck_8
	goto EletricPlate_ConditionCheck_1

EletricPlate_ConditionCheck_8:
# 108 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_ELECTRIC_PC
	goto EletricPlate_ConditionCheck_1


EletricPlateWonCatch_Text_0:
# 60 "data/maps/EletricPlate/scripts.pory"
	.string "The Electrode dissapeared in to the\ncave.$"

EletricPlateWonCatch_Text_1:
# 62 "data/maps/EletricPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

EletricPlateWonCatch_Text_2:
# 63 "data/maps/EletricPlate/scripts.pory"
	.string "The third being raged, raining down\nbolts of anger.$"

EletricPlate_CollectGem_Text_0:
# 86 "data/maps/EletricPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

EletricPlate_CollectGem_Text_1:
# 89 "data/maps/EletricPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
