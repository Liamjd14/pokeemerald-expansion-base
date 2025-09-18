EletricPlate_MapScripts::
# 2 "data/maps/EletricPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EletricPlate_OnLoad
	.byte 0


EletricPlate_OnLoad::
# 6 "data/maps/EletricPlate/scripts.pory"
	call_if_unset FLAG_ELECTRIC_PC, EletricPlate_Entrance
# 7 "data/maps/EletricPlate/scripts.pory"
	call EletricPlate_IsGemCollected
	end


EletricPlate_Entrance::
# 12 "data/maps/EletricPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/EletricPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/EletricPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/EletricPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


EletricPlate_Battle::
# 22 "data/maps/EletricPlate/scripts.pory"
	lockall
# 23 "data/maps/EletricPlate/scripts.pory"
	playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_ENCOUNTER
# 24 "data/maps/EletricPlate/scripts.pory"
	delay 40
# 25 "data/maps/EletricPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/EletricPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_ELECTRODE_HISUI, 50, [ ITEM_ELECTRIC_GEM ], , NATURE_TIMID, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_TAUNT ], [ MOVE_LEAF_STORM ], [ MOVE_THUNDERBOLT ], [ MOVE_VOLT_SWITCH ]
# 28 "data/maps/EletricPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 29 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/EletricPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/EletricPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EletricPlate_Battle_2
# 38 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EletricPlate_Battle_3
# 41 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EletricPlate_Battle_4
# 44 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EletricPlate_Battle_5
EletricPlate_Battle_1:
# 47 "data/maps/EletricPlate/scripts.pory"
	waitmessage
# 48 "data/maps/EletricPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/EletricPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/EletricPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_ELECTRIC_PC1
# 52 "data/maps/EletricPlate/scripts.pory"
	releaseall
	return

EletricPlate_Battle_2:
# 36 "data/maps/EletricPlate/scripts.pory"
	call EletricPlateWonCatch
	goto EletricPlate_Battle_1

EletricPlate_Battle_3:
# 39 "data/maps/EletricPlate/scripts.pory"
	call EletricPlateWonCatch
	goto EletricPlate_Battle_1

EletricPlate_Battle_4:
# 42 "data/maps/EletricPlate/scripts.pory"
	call EletricPlateRun
	goto EletricPlate_Battle_1

EletricPlate_Battle_5:
# 45 "data/maps/EletricPlate/scripts.pory"
	call EletricPlateRun
	goto EletricPlate_Battle_1


EletricPlateWonCatch::
# 56 "data/maps/EletricPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/EletricPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/EletricPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/EletricPlate/scripts.pory"
	giveitem ITEM_ZAP_PLATE
# 61 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


EletricPlateRun::
# 67 "data/maps/EletricPlate/scripts.pory"
	playmoncry SPECIES_ELECTRODE_HISUI, CRY_MODE_ENCOUNTER
# 68 "data/maps/EletricPlate/scripts.pory"
	waitmoncry
	return


EletricPlate_IsGemCollected::
# 73 "data/maps/EletricPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ELETRIC_GEM, EletricPlate_IsGemCollected_2
# 77 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
EletricPlate_IsGemCollected_1:
	return

EletricPlate_IsGemCollected_2:
# 74 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto EletricPlate_IsGemCollected_1


EletricPlate_CollectGem::
# 83 "data/maps/EletricPlate/scripts.pory"
	lockall
# 84 "data/maps/EletricPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ELETRIC_GEM, EletricPlate_CollectGem_2
# 88 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/EletricPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EletricPlate_CollectGem_5
EletricPlate_CollectGem_1:
# 98 "data/maps/EletricPlate/scripts.pory"
	releaseall
	return

EletricPlate_CollectGem_2:
# 85 "data/maps/EletricPlate/scripts.pory"
	msgbox EletricPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto EletricPlate_CollectGem_1

EletricPlate_CollectGem_5:
# 90 "data/maps/EletricPlate/scripts.pory"
	giveitem ITEM_ELECTRIC_GEM
# 91 "data/maps/EletricPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_ELETRIC_GEM
# 92 "data/maps/EletricPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/EletricPlate/scripts.pory"
	warp MAP_ELETRIC_PLATE, 7, 20
# 94 "data/maps/EletricPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/EletricPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto EletricPlate_CollectGem_1


EletricPlateWonCatch_Text_0:
# 59 "data/maps/EletricPlate/scripts.pory"
	.string "The Electrode dissapeared in to the\ncave.$"

EletricPlateWonCatch_Text_1:
# 61 "data/maps/EletricPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

EletricPlateWonCatch_Text_2:
# 62 "data/maps/EletricPlate/scripts.pory"
	.string "The third being raged, raining down\nbolts of anger.$"

EletricPlate_CollectGem_Text_0:
# 85 "data/maps/EletricPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

EletricPlate_CollectGem_Text_1:
# 88 "data/maps/EletricPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
