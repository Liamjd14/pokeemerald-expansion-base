IcePlate_MapScripts::
# 2 "data/maps/IcePlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, IcePlate_OnLoad
	.byte 0


IcePlate_OnLoad::
# 6 "data/maps/IcePlate/scripts.pory"
	call_if_unset FLAG_ICE_PC, IcePlate_Entrance
# 7 "data/maps/IcePlate/scripts.pory"
	call IcePlate_IsGemCollected
# 8 "data/maps/IcePlate/scripts.pory"
	call IcePlate_ConditionCheck
	end


IcePlate_Entrance::
# 13 "data/maps/IcePlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/IcePlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/IcePlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/IcePlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


IcePlate_Battle::
# 23 "data/maps/IcePlate/scripts.pory"
	lockall
# 24 "data/maps/IcePlate/scripts.pory"
	playmoncry SPECIES_AVALUGG_HISUI, CRY_MODE_ENCOUNTER
# 25 "data/maps/IcePlate/scripts.pory"
	delay 40
# 26 "data/maps/IcePlate/scripts.pory"
	waitmoncry
# 28 "data/maps/IcePlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_AVALUGG_HISUI, 50, [ ITEM_ICE_GEM ], , NATURE_ADAMANT, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_STEALTH_ROCK ], [ MOVE_MOUNTAIN_GALE ], [ MOVE_BODY_PRESS ], [ MOVE_IRON_DEFENSE ]
# 29 "data/maps/IcePlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 30 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/IcePlate/scripts.pory"
	dowildbattle
# 35 "data/maps/IcePlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq IcePlate_Battle_2
# 39 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq IcePlate_Battle_3
# 42 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq IcePlate_Battle_4
# 45 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq IcePlate_Battle_5
IcePlate_Battle_1:
# 48 "data/maps/IcePlate/scripts.pory"
	waitmessage
# 49 "data/maps/IcePlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/IcePlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/IcePlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_ICE_PC1
# 53 "data/maps/IcePlate/scripts.pory"
	releaseall
	return

IcePlate_Battle_2:
# 37 "data/maps/IcePlate/scripts.pory"
	call IcePlateWonCatch
	goto IcePlate_Battle_1

IcePlate_Battle_3:
# 40 "data/maps/IcePlate/scripts.pory"
	call IcePlateWonCatch
	goto IcePlate_Battle_1

IcePlate_Battle_4:
# 43 "data/maps/IcePlate/scripts.pory"
	call IcePlateRun
	goto IcePlate_Battle_1

IcePlate_Battle_5:
# 46 "data/maps/IcePlate/scripts.pory"
	call IcePlateRun
	goto IcePlate_Battle_1


IcePlateWonCatch::
# 57 "data/maps/IcePlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/IcePlate/scripts.pory"
	removeobject 1
# 59 "data/maps/IcePlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/IcePlate/scripts.pory"
	giveitem ITEM_ICICLE_PLATE
# 62 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


IcePlateRun::
# 68 "data/maps/IcePlate/scripts.pory"
	playmoncry SPECIES_AVALUGG_HISUI, CRY_MODE_ENCOUNTER
# 69 "data/maps/IcePlate/scripts.pory"
	waitmoncry
	return


IcePlate_IsGemCollected::
# 74 "data/maps/IcePlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ICE_GEM, IcePlate_IsGemCollected_2
# 78 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
IcePlate_IsGemCollected_1:
	return

IcePlate_IsGemCollected_2:
# 75 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto IcePlate_IsGemCollected_1


IcePlate_CollectGem::
# 84 "data/maps/IcePlate/scripts.pory"
	lockall
# 85 "data/maps/IcePlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ICE_GEM, IcePlate_CollectGem_2
# 89 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq IcePlate_CollectGem_5
IcePlate_CollectGem_1:
# 99 "data/maps/IcePlate/scripts.pory"
	releaseall
	return

IcePlate_CollectGem_2:
# 86 "data/maps/IcePlate/scripts.pory"
	msgbox IcePlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto IcePlate_CollectGem_1

IcePlate_CollectGem_5:
# 91 "data/maps/IcePlate/scripts.pory"
	giveitem ITEM_ICE_GEM
# 92 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_ICE_GEM
# 93 "data/maps/IcePlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/IcePlate/scripts.pory"
	warp MAP_ICE_PLATE, 7, 20
# 95 "data/maps/IcePlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/IcePlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto IcePlate_CollectGem_1


IcePlate_ConditionCheck::
# 103 "data/maps/IcePlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, IcePlate_ConditionCheck_2
IcePlate_ConditionCheck_1:
	return

IcePlate_ConditionCheck_2:
# 104 "data/maps/IcePlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, IcePlate_ConditionCheck_4
	goto IcePlate_ConditionCheck_1

IcePlate_ConditionCheck_4:
# 105 "data/maps/IcePlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, IcePlate_ConditionCheck_6
	goto IcePlate_ConditionCheck_1

IcePlate_ConditionCheck_6:
# 106 "data/maps/IcePlate/scripts.pory"
	checkitem ITEM_ICE_GEM, 1
# 107 "data/maps/IcePlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq IcePlate_ConditionCheck_8
	goto IcePlate_ConditionCheck_1

IcePlate_ConditionCheck_8:
# 108 "data/maps/IcePlate/scripts.pory"
	setflag FLAG_ICE_PC
	goto IcePlate_ConditionCheck_1


IcePlateWonCatch_Text_0:
# 60 "data/maps/IcePlate/scripts.pory"
	.string "The Avalugg dissapeared in to the cave.$"

IcePlateWonCatch_Text_1:
# 62 "data/maps/IcePlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

IcePlateWonCatch_Text_2:
# 63 "data/maps/IcePlate/scripts.pory"
	.string "Two beings of time and space set free\nfrom the Original One.$"

IcePlate_CollectGem_Text_0:
# 86 "data/maps/IcePlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

IcePlate_CollectGem_Text_1:
# 89 "data/maps/IcePlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
