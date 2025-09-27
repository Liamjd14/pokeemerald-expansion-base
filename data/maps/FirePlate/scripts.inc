FirePlate_MapScripts::
# 2 "data/maps/FirePlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FirePlate_OnLoad
	.byte 0


FirePlate_OnLoad::
# 6 "data/maps/FirePlate/scripts.pory"
	call FirePlate_IsGemCollected
# 7 "data/maps/FirePlate/scripts.pory"
	call FirePlate_ConditionCheck
# 8 "data/maps/FirePlate/scripts.pory"
	call_if_unset FLAG_FIRE_PC, FirePlate_Entrance
	end


FirePlate_Entrance::
# 13 "data/maps/FirePlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/FirePlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/FirePlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/FirePlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


FirePlate_Battle::
# 23 "data/maps/FirePlate/scripts.pory"
	lockall
# 24 "data/maps/FirePlate/scripts.pory"
	playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_ENCOUNTER
# 25 "data/maps/FirePlate/scripts.pory"
	delay 40
# 26 "data/maps/FirePlate/scripts.pory"
	waitmoncry
# 28 "data/maps/FirePlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_ARCANINE_HISUI, 50, [ ITEM_FIRE_GEM ], , NATURE_JOLLY, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_DOUBLE_EDGE ], [ MOVE_WILD_CHARGE ], [ MOVE_HEAD_SMASH ], [ MOVE_FLARE_BLITZ ]
# 29 "data/maps/FirePlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 30 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/FirePlate/scripts.pory"
	dowildbattle
# 35 "data/maps/FirePlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FirePlate_Battle_2
# 39 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FirePlate_Battle_3
# 42 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FirePlate_Battle_4
# 45 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FirePlate_Battle_5
FirePlate_Battle_1:
# 48 "data/maps/FirePlate/scripts.pory"
	waitmessage
# 49 "data/maps/FirePlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/FirePlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/FirePlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_FIRE_PC1
# 53 "data/maps/FirePlate/scripts.pory"
	releaseall
	return

FirePlate_Battle_2:
# 37 "data/maps/FirePlate/scripts.pory"
	call FirePlateWonCatch
	goto FirePlate_Battle_1

FirePlate_Battle_3:
# 40 "data/maps/FirePlate/scripts.pory"
	call FirePlateWonCatch
	goto FirePlate_Battle_1

FirePlate_Battle_4:
# 43 "data/maps/FirePlate/scripts.pory"
	call FirePlateRun
	goto FirePlate_Battle_1

FirePlate_Battle_5:
# 46 "data/maps/FirePlate/scripts.pory"
	call FirePlateRun
	goto FirePlate_Battle_1


FirePlateWonCatch::
# 57 "data/maps/FirePlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/FirePlate/scripts.pory"
	removeobject 1
# 59 "data/maps/FirePlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/FirePlate/scripts.pory"
	giveitem ITEM_FLAME_PLATE
# 62 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


FirePlateRun::
# 68 "data/maps/FirePlate/scripts.pory"
	playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_ENCOUNTER
# 69 "data/maps/FirePlate/scripts.pory"
	waitmoncry
	return


FirePlate_IsGemCollected::
# 74 "data/maps/FirePlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FIRE_GEM, FirePlate_IsGemCollected_2
# 78 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
FirePlate_IsGemCollected_1:
	return

FirePlate_IsGemCollected_2:
# 75 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto FirePlate_IsGemCollected_1


FirePlate_CollectGem::
# 84 "data/maps/FirePlate/scripts.pory"
	lockall
# 85 "data/maps/FirePlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FIRE_GEM, FirePlate_CollectGem_2
# 89 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FirePlate_CollectGem_5
FirePlate_CollectGem_1:
# 99 "data/maps/FirePlate/scripts.pory"
	releaseall
	return

FirePlate_CollectGem_2:
# 86 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto FirePlate_CollectGem_1

FirePlate_CollectGem_5:
# 91 "data/maps/FirePlate/scripts.pory"
	giveitem ITEM_FIRE_GEM
# 92 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_FIRE_GEM
# 93 "data/maps/FirePlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/FirePlate/scripts.pory"
	warp MAP_FIRE_PLATE, 7, 20
# 95 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/FirePlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto FirePlate_CollectGem_1


FirePlate_ConditionCheck::
# 103 "data/maps/FirePlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, FirePlate_ConditionCheck_2
FirePlate_ConditionCheck_1:
	return

FirePlate_ConditionCheck_2:
# 104 "data/maps/FirePlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, FirePlate_ConditionCheck_4
	goto FirePlate_ConditionCheck_1

FirePlate_ConditionCheck_4:
# 105 "data/maps/FirePlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, FirePlate_ConditionCheck_6
	goto FirePlate_ConditionCheck_1

FirePlate_ConditionCheck_6:
# 106 "data/maps/FirePlate/scripts.pory"
	checkitem ITEM_FIRE_GEM, 1
# 107 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FirePlate_ConditionCheck_8
	goto FirePlate_ConditionCheck_1

FirePlate_ConditionCheck_8:
# 108 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_FIRE_PC
	goto FirePlate_ConditionCheck_1


FirePlateWonCatch_Text_0:
# 60 "data/maps/FirePlate/scripts.pory"
	.string "The Arcanine dissapeared in to the\ncave.$"

FirePlateWonCatch_Text_1:
# 62 "data/maps/FirePlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

FirePlateWonCatch_Text_2:
# 63 "data/maps/FirePlate/scripts.pory"
	.string "The power of defeated giants infuses\nthis Plate.$"

FirePlate_CollectGem_Text_0:
# 86 "data/maps/FirePlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

FirePlate_CollectGem_Text_1:
# 89 "data/maps/FirePlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
