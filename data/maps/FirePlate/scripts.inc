FirePlate_MapScripts::
# 2 "data/maps/FirePlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FirePlate_OnLoad
	.byte 0


FirePlate_OnLoad::
# 6 "data/maps/FirePlate/scripts.pory"
	call_if_unset FLAG_FIRE_PC, FirePlate_Entrance
# 7 "data/maps/FirePlate/scripts.pory"
	call FirePlate_IsGemCollected
	end


FirePlate_Entrance::
# 12 "data/maps/FirePlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/FirePlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/FirePlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/FirePlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


FirePlate_Battle::
# 22 "data/maps/FirePlate/scripts.pory"
	lockall
# 23 "data/maps/FirePlate/scripts.pory"
	playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_ENCOUNTER
# 24 "data/maps/FirePlate/scripts.pory"
	delay 40
# 25 "data/maps/FirePlate/scripts.pory"
	waitmoncry
# 27 "data/maps/FirePlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_ARCANINE_HISUI, 50, [ ITEM_FIRE_GEM ], , NATURE_JOLLY, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_DOUBLE_EDGE ], [ MOVE_WILD_CHARGE ], [ MOVE_HEAD_SMASH ], [ MOVE_FLARE_BLITZ ]
# 28 "data/maps/FirePlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/FirePlate/scripts.pory"
	dowildbattle
# 34 "data/maps/FirePlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FirePlate_Battle_2
# 38 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FirePlate_Battle_3
# 41 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FirePlate_Battle_4
# 44 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FirePlate_Battle_5
FirePlate_Battle_1:
# 47 "data/maps/FirePlate/scripts.pory"
	waitmessage
# 48 "data/maps/FirePlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/FirePlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/FirePlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_FIRE_PC1
# 52 "data/maps/FirePlate/scripts.pory"
	releaseall
	return

FirePlate_Battle_2:
# 36 "data/maps/FirePlate/scripts.pory"
	call FirePlateWonCatch
	goto FirePlate_Battle_1

FirePlate_Battle_3:
# 39 "data/maps/FirePlate/scripts.pory"
	call FirePlateWonCatch
	goto FirePlate_Battle_1

FirePlate_Battle_4:
# 42 "data/maps/FirePlate/scripts.pory"
	call FirePlateRun
	goto FirePlate_Battle_1

FirePlate_Battle_5:
# 45 "data/maps/FirePlate/scripts.pory"
	call FirePlateRun
	goto FirePlate_Battle_1


FirePlateWonCatch::
# 56 "data/maps/FirePlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/FirePlate/scripts.pory"
	removeobject 1
# 58 "data/maps/FirePlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/FirePlate/scripts.pory"
	giveitem ITEM_FLAME_PLATE
# 61 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


FirePlateRun::
# 67 "data/maps/FirePlate/scripts.pory"
	playmoncry SPECIES_ARCANINE_HISUI, CRY_MODE_ENCOUNTER
# 68 "data/maps/FirePlate/scripts.pory"
	waitmoncry
	return


FirePlate_IsGemCollected::
# 73 "data/maps/FirePlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FIRE_GEM, FirePlate_IsGemCollected_2
# 77 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
FirePlate_IsGemCollected_1:
	return

FirePlate_IsGemCollected_2:
# 74 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto FirePlate_IsGemCollected_1


FirePlate_CollectGem::
# 83 "data/maps/FirePlate/scripts.pory"
	lockall
# 84 "data/maps/FirePlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FIRE_GEM, FirePlate_CollectGem_2
# 88 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/FirePlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FirePlate_CollectGem_5
FirePlate_CollectGem_1:
# 98 "data/maps/FirePlate/scripts.pory"
	releaseall
	return

FirePlate_CollectGem_2:
# 85 "data/maps/FirePlate/scripts.pory"
	msgbox FirePlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto FirePlate_CollectGem_1

FirePlate_CollectGem_5:
# 90 "data/maps/FirePlate/scripts.pory"
	giveitem ITEM_FIRE_GEM
# 91 "data/maps/FirePlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_FIRE_GEM
# 92 "data/maps/FirePlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/FirePlate/scripts.pory"
	warp MAP_FIRE_PLATE, 7, 20
# 94 "data/maps/FirePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/FirePlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto FirePlate_CollectGem_1


FirePlateWonCatch_Text_0:
# 59 "data/maps/FirePlate/scripts.pory"
	.string "The Arcanine dissapeared in to the\ncave.$"

FirePlateWonCatch_Text_1:
# 61 "data/maps/FirePlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

FirePlateWonCatch_Text_2:
# 62 "data/maps/FirePlate/scripts.pory"
	.string "The power of defeated giants infuses\nthis Plate.$"

FirePlate_CollectGem_Text_0:
# 85 "data/maps/FirePlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

FirePlate_CollectGem_Text_1:
# 88 "data/maps/FirePlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
