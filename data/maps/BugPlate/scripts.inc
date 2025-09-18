BugPlate_MapScripts::
# 2 "data/maps/BugPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BugPlate_OnLoad
	.byte 0


BugPlate_OnLoad::
# 6 "data/maps/BugPlate/scripts.pory"
	call_if_unset FLAG_BUG_PC, BugPlate_Entrance
# 7 "data/maps/BugPlate/scripts.pory"
	call BugPlate_IsGemCollected
	end


BugPlate_Entrance::
# 12 "data/maps/BugPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/BugPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/BugPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/BugPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


BugPlate_Battle::
# 22 "data/maps/BugPlate/scripts.pory"
	lockall
# 23 "data/maps/BugPlate/scripts.pory"
	playmoncry SPECIES_KLEAVOR, CRY_MODE_ENCOUNTER
# 24 "data/maps/BugPlate/scripts.pory"
	delay 40
# 25 "data/maps/BugPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/BugPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_KLEAVOR, 50, [ ITEM_BUG_GEM ], , NATURE_JOLLY, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_STONE_AXE ], [ MOVE_CLOSE_COMBAT ], [ MOVE_SWORDS_DANCE ], [ MOVE_X_SCISSOR ]
# 28 "data/maps/BugPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/BugPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/BugPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq BugPlate_Battle_2
# 38 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BugPlate_Battle_3
# 41 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq BugPlate_Battle_4
# 44 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq BugPlate_Battle_5
BugPlate_Battle_1:
# 47 "data/maps/BugPlate/scripts.pory"
	waitmessage
# 48 "data/maps/BugPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/BugPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/BugPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_BUG_PC1
# 52 "data/maps/BugPlate/scripts.pory"
	releaseall
	return

BugPlate_Battle_2:
# 36 "data/maps/BugPlate/scripts.pory"
	call BugPlateWonCatch
	goto BugPlate_Battle_1

BugPlate_Battle_3:
# 39 "data/maps/BugPlate/scripts.pory"
	call BugPlateWonCatch
	goto BugPlate_Battle_1

BugPlate_Battle_4:
# 42 "data/maps/BugPlate/scripts.pory"
	call BugPlateRun
	goto BugPlate_Battle_1

BugPlate_Battle_5:
# 45 "data/maps/BugPlate/scripts.pory"
	call BugPlateRun
	goto BugPlate_Battle_1


BugPlateWonCatch::
# 56 "data/maps/BugPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/BugPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/BugPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/BugPlate/scripts.pory"
	giveitem ITEM_INSECT_PLATE
# 61 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


BugPlateRun::
# 67 "data/maps/BugPlate/scripts.pory"
	playmoncry SPECIES_KLEAVOR, CRY_MODE_ENCOUNTER
# 68 "data/maps/BugPlate/scripts.pory"
	waitmoncry
	return


BugPlate_IsGemCollected::
# 73 "data/maps/BugPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_BUG_GEM, BugPlate_IsGemCollected_2
# 77 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
BugPlate_IsGemCollected_1:
	return

BugPlate_IsGemCollected_2:
# 74 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto BugPlate_IsGemCollected_1


BugPlate_CollectGem::
# 83 "data/maps/BugPlate/scripts.pory"
	lockall
# 84 "data/maps/BugPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_BUG_GEM, BugPlate_CollectGem_2
# 88 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/BugPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq BugPlate_CollectGem_5
BugPlate_CollectGem_1:
# 98 "data/maps/BugPlate/scripts.pory"
	releaseall
	return

BugPlate_CollectGem_2:
# 85 "data/maps/BugPlate/scripts.pory"
	msgbox BugPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto BugPlate_CollectGem_1

BugPlate_CollectGem_5:
# 90 "data/maps/BugPlate/scripts.pory"
	giveitem ITEM_BUG_GEM
# 91 "data/maps/BugPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_BUG_GEM
# 92 "data/maps/BugPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/BugPlate/scripts.pory"
	warp MAP_BUG_PLATE, 7, 20
# 94 "data/maps/BugPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/BugPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto BugPlate_CollectGem_1


BugPlateWonCatch_Text_0:
# 59 "data/maps/BugPlate/scripts.pory"
	.string "The Kleavor dissapeared in to the cave.$"

BugPlateWonCatch_Text_1:
# 61 "data/maps/BugPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

BugPlateWonCatch_Text_2:
# 62 "data/maps/BugPlate/scripts.pory"
	.string "Where all creation was born, that is the\nbeing's place of origin.$"

BugPlate_CollectGem_Text_0:
# 85 "data/maps/BugPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

BugPlate_CollectGem_Text_1:
# 88 "data/maps/BugPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
