BugPlate_MapScripts::
# 2 "data/maps/BugPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BugPlate_OnLoad
	.byte 0


BugPlate_OnLoad::
# 6 "data/maps/BugPlate/scripts.pory"
	call_if_unset FLAG_BUG_PC, BugPlate_Entrance
# 7 "data/maps/BugPlate/scripts.pory"
	call BugPlate_IsGemCollected
# 8 "data/maps/BugPlate/scripts.pory"
	call BugPlate_ConditionCheck
	end


BugPlate_Entrance::
# 13 "data/maps/BugPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/BugPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/BugPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/BugPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


BugPlate_Battle::
# 23 "data/maps/BugPlate/scripts.pory"
	lockall
# 24 "data/maps/BugPlate/scripts.pory"
	playmoncry SPECIES_KLEAVOR, CRY_MODE_ENCOUNTER
# 25 "data/maps/BugPlate/scripts.pory"
	delay 40
# 26 "data/maps/BugPlate/scripts.pory"
	waitmoncry
# 28 "data/maps/BugPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_KLEAVOR, 50, [ ITEM_BUG_GEM ], , NATURE_JOLLY, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_STONE_AXE ], [ MOVE_CLOSE_COMBAT ], [ MOVE_SWORDS_DANCE ], [ MOVE_X_SCISSOR ]
# 29 "data/maps/BugPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 30 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/BugPlate/scripts.pory"
	dowildbattle
# 35 "data/maps/BugPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq BugPlate_Battle_2
# 39 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BugPlate_Battle_3
# 42 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq BugPlate_Battle_4
# 45 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq BugPlate_Battle_5
BugPlate_Battle_1:
# 48 "data/maps/BugPlate/scripts.pory"
	waitmessage
# 49 "data/maps/BugPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/BugPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/BugPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_BUG_PC1
# 53 "data/maps/BugPlate/scripts.pory"
	releaseall
	return

BugPlate_Battle_2:
# 37 "data/maps/BugPlate/scripts.pory"
	call BugPlateWonCatch
	goto BugPlate_Battle_1

BugPlate_Battle_3:
# 40 "data/maps/BugPlate/scripts.pory"
	call BugPlateWonCatch
	goto BugPlate_Battle_1

BugPlate_Battle_4:
# 43 "data/maps/BugPlate/scripts.pory"
	call BugPlateRun
	goto BugPlate_Battle_1

BugPlate_Battle_5:
# 46 "data/maps/BugPlate/scripts.pory"
	call BugPlateRun
	goto BugPlate_Battle_1


BugPlateWonCatch::
# 57 "data/maps/BugPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/BugPlate/scripts.pory"
	removeobject 1
# 59 "data/maps/BugPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/BugPlate/scripts.pory"
	giveitem ITEM_INSECT_PLATE
# 62 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


BugPlateRun::
# 68 "data/maps/BugPlate/scripts.pory"
	playmoncry SPECIES_KLEAVOR, CRY_MODE_ENCOUNTER
# 69 "data/maps/BugPlate/scripts.pory"
	waitmoncry
	return


BugPlate_IsGemCollected::
# 74 "data/maps/BugPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_BUG_GEM, BugPlate_IsGemCollected_2
# 78 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
BugPlate_IsGemCollected_1:
	return

BugPlate_IsGemCollected_2:
# 75 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto BugPlate_IsGemCollected_1


BugPlate_CollectGem::
# 84 "data/maps/BugPlate/scripts.pory"
	lockall
# 85 "data/maps/BugPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_BUG_GEM, BugPlate_CollectGem_2
# 89 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq BugPlate_CollectGem_5
BugPlate_CollectGem_1:
# 99 "data/maps/BugPlate/scripts.pory"
	releaseall
	return

BugPlate_CollectGem_2:
# 86 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto BugPlate_CollectGem_1

BugPlate_CollectGem_5:
# 91 "data/maps/BugPlate/scripts.pory"
	giveitem ITEM_BUG_GEM
# 92 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_BUG_GEM
# 93 "data/maps/BugPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/BugPlate/scripts.pory"
	warp MAP_BUG_PLATE, 7, 20
# 95 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/BugPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto BugPlate_CollectGem_1


BugPlate_ConditionCheck::
# 103 "data/maps/BugPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, BugPlate_ConditionCheck_2
BugPlate_ConditionCheck_1:
	return

BugPlate_ConditionCheck_2:
# 104 "data/maps/BugPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, BugPlate_ConditionCheck_4
	goto BugPlate_ConditionCheck_1

BugPlate_ConditionCheck_4:
# 105 "data/maps/BugPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, BugPlate_ConditionCheck_6
	goto BugPlate_ConditionCheck_1

BugPlate_ConditionCheck_6:
# 106 "data/maps/BugPlate/scripts.pory"
	checkitem ITEM_BUG_GEM, 1
# 107 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BugPlate_ConditionCheck_8
	goto BugPlate_ConditionCheck_1

BugPlate_ConditionCheck_8:
# 108 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_BUG_PC
	goto BugPlate_ConditionCheck_1


BugPlateWonCatch_Text_0:
# 60 "data/maps/BugPlate/scripts.pory"
	.string "The Kleavor dissapeared in to the cave.$"

BugPlateWonCatch_Text_1:
# 62 "data/maps/BugPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

BugPlateWonCatch_Text_2:
# 63 "data/maps/BugPlate/scripts.pory"
	.string "Where all creation was born, that is the\nbeing's place of origin.$"

BugPlate_CollectGem_Text_0:
# 86 "data/maps/BugPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

BugPlate_CollectGem_Text_1:
# 89 "data/maps/BugPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
