IcePlate_MapScripts::
# 2 "data/maps/IcePlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, IcePlate_OnLoad
	.byte 0


IcePlate_OnLoad::
# 6 "data/maps/IcePlate/scripts.pory"
	call_if_unset FLAG_ICE_PC, IcePlate_Entrance
# 7 "data/maps/IcePlate/scripts.pory"
	call IcePlate_IsGemCollected
	end


IcePlate_Entrance::
# 12 "data/maps/IcePlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/IcePlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/IcePlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/IcePlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


IcePlate_Battle::
# 22 "data/maps/IcePlate/scripts.pory"
	lockall
# 23 "data/maps/IcePlate/scripts.pory"
	playmoncry SPECIES_AVALUGG_HISUI, CRY_MODE_ENCOUNTER
# 24 "data/maps/IcePlate/scripts.pory"
	delay 40
# 25 "data/maps/IcePlate/scripts.pory"
	waitmoncry
# 27 "data/maps/IcePlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_AVALUGG_HISUI, 50, [ ITEM_ICE_GEM ], , NATURE_ADAMANT, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_STEALTH_ROCK ], [ MOVE_MOUNTAIN_GALE ], [ MOVE_BODY_PRESS ], [ MOVE_IRON_DEFENSE ]
# 28 "data/maps/IcePlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/IcePlate/scripts.pory"
	dowildbattle
# 34 "data/maps/IcePlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq IcePlate_Battle_2
# 38 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq IcePlate_Battle_3
# 41 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq IcePlate_Battle_4
# 44 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq IcePlate_Battle_5
IcePlate_Battle_1:
# 47 "data/maps/IcePlate/scripts.pory"
	waitmessage
# 48 "data/maps/IcePlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/IcePlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/IcePlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_ICE_PC1
# 52 "data/maps/IcePlate/scripts.pory"
	releaseall
	return

IcePlate_Battle_2:
# 36 "data/maps/IcePlate/scripts.pory"
	call IcePlateWonCatch
	goto IcePlate_Battle_1

IcePlate_Battle_3:
# 39 "data/maps/IcePlate/scripts.pory"
	call IcePlateWonCatch
	goto IcePlate_Battle_1

IcePlate_Battle_4:
# 42 "data/maps/IcePlate/scripts.pory"
	call IcePlateRun
	goto IcePlate_Battle_1

IcePlate_Battle_5:
# 45 "data/maps/IcePlate/scripts.pory"
	call IcePlateRun
	goto IcePlate_Battle_1


IcePlateWonCatch::
# 56 "data/maps/IcePlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/IcePlate/scripts.pory"
	removeobject 1
# 58 "data/maps/IcePlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/IcePlate/scripts.pory"
	giveitem ITEM_ICICLE_PLATE
# 61 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


IcePlateRun::
# 67 "data/maps/IcePlate/scripts.pory"
	playmoncry SPECIES_AVALUGG_HISUI, CRY_MODE_ENCOUNTER
# 68 "data/maps/IcePlate/scripts.pory"
	waitmoncry
	return


IcePlate_IsGemCollected::
# 73 "data/maps/IcePlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ICE_GEM, IcePlate_IsGemCollected_2
# 77 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
IcePlate_IsGemCollected_1:
	return

IcePlate_IsGemCollected_2:
# 74 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto IcePlate_IsGemCollected_1


IcePlate_CollectGem::
# 83 "data/maps/IcePlate/scripts.pory"
	lockall
# 84 "data/maps/IcePlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ICE_GEM, IcePlate_CollectGem_2
# 88 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq IcePlate_CollectGem_5
IcePlate_CollectGem_1:
# 98 "data/maps/IcePlate/scripts.pory"
	releaseall
	return

IcePlate_CollectGem_2:
# 85 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto IcePlate_CollectGem_1

IcePlate_CollectGem_5:
# 90 "data/maps/IcePlate/scripts.pory"
	giveitem ITEM_ICE_GEM
# 91 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_ICE_GEM
# 92 "data/maps/IcePlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/IcePlate/scripts.pory"
	warp MAP_ICE_PLATE, 7, 20
# 94 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/IcePlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto IcePlate_CollectGem_1


IcePlateWonCatch_Text_0:
# 59 "data/maps/IcePlate/scripts.pory"
	.string "The Avalugg dissapeared in to the cave.$"

IcePlateWonCatch_Text_1:
# 61 "data/maps/IcePlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

IcePlateWonCatch_Text_2:
# 62 "data/maps/IcePlate/scripts.pory"
	.string "Two beings of time and space set free\nfrom the Original One.$"

IcePlate_CollectGem_Text_0:
# 85 "data/maps/IcePlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

IcePlate_CollectGem_Text_1:
# 88 "data/maps/IcePlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
