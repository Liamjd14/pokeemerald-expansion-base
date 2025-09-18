DarkPlate_MapScripts::
# 2 "data/maps/DarkPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DarkPlate_OnLoad
	.byte 0


DarkPlate_OnLoad::
# 6 "data/maps/DarkPlate/scripts.pory"
	call_if_unset FLAG_DARK_PC, DarkPlate_Entrance
# 7 "data/maps/DarkPlate/scripts.pory"
	call DarkPlate_IsGemCollected
	end


DarkPlate_Entrance::
# 12 "data/maps/DarkPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/DarkPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/DarkPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/DarkPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/DarkPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/DarkPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


DarkPlate_Battle::
# 22 "data/maps/DarkPlate/scripts.pory"
	lockall
# 23 "data/maps/DarkPlate/scripts.pory"
	playmoncry SPECIES_OVERQWIL, CRY_MODE_ENCOUNTER
# 24 "data/maps/DarkPlate/scripts.pory"
	delay 40
# 25 "data/maps/DarkPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/DarkPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_OVERQWIL, 50, [ ITEM_DARK_GEM ], , NATURE_JOLLY, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_AQUA_JET ], [ MOVE_CRUNCH ], [ MOVE_GUNK_SHOT ], [ MOVE_LIQUIDATION ]
# 28 "data/maps/DarkPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/DarkPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/DarkPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/DarkPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/DarkPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/DarkPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/DarkPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DarkPlate_Battle_2
# 38 "data/maps/DarkPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DarkPlate_Battle_3
# 41 "data/maps/DarkPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq DarkPlate_Battle_4
# 44 "data/maps/DarkPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq DarkPlate_Battle_5
DarkPlate_Battle_1:
# 47 "data/maps/DarkPlate/scripts.pory"
	waitmessage
# 48 "data/maps/DarkPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/DarkPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/DarkPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/DarkPlate/scripts.pory"
	setflag FLAG_DARK_PC1
# 52 "data/maps/DarkPlate/scripts.pory"
	releaseall
	return

DarkPlate_Battle_2:
# 36 "data/maps/DarkPlate/scripts.pory"
	call DarkPlateWonCatch
	goto DarkPlate_Battle_1

DarkPlate_Battle_3:
# 39 "data/maps/DarkPlate/scripts.pory"
	call DarkPlateWonCatch
	goto DarkPlate_Battle_1

DarkPlate_Battle_4:
# 42 "data/maps/DarkPlate/scripts.pory"
	call DarkPlateRun
	goto DarkPlate_Battle_1

DarkPlate_Battle_5:
# 45 "data/maps/DarkPlate/scripts.pory"
	call DarkPlateRun
	goto DarkPlate_Battle_1


DarkPlateWonCatch::
# 56 "data/maps/DarkPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/DarkPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/DarkPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/DarkPlate/scripts.pory"
	msgbox DarkPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/DarkPlate/scripts.pory"
	giveitem ITEM_DREAD_PLATE
# 61 "data/maps/DarkPlate/scripts.pory"
	msgbox DarkPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/DarkPlate/scripts.pory"
	msgbox DarkPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


DarkPlateRun::
# 67 "data/maps/DarkPlate/scripts.pory"
	playmoncry SPECIES_OVERQWIL, CRY_MODE_ENCOUNTER
# 68 "data/maps/DarkPlate/scripts.pory"
	waitmoncry
	return


DarkPlate_IsGemCollected::
# 73 "data/maps/DarkPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_DARK_GEM, DarkPlate_IsGemCollected_2
# 77 "data/maps/DarkPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
DarkPlate_IsGemCollected_1:
	return

DarkPlate_IsGemCollected_2:
# 74 "data/maps/DarkPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto DarkPlate_IsGemCollected_1


DarkPlate_CollectGem::
# 83 "data/maps/DarkPlate/scripts.pory"
	lockall
# 84 "data/maps/DarkPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_DARK_GEM, DarkPlate_CollectGem_2
# 88 "data/maps/DarkPlate/scripts.pory"
	msgbox DarkPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/DarkPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DarkPlate_CollectGem_5
DarkPlate_CollectGem_1:
# 98 "data/maps/DarkPlate/scripts.pory"
	releaseall
	return

DarkPlate_CollectGem_2:
# 85 "data/maps/DarkPlate/scripts.pory"
	msgbox DarkPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto DarkPlate_CollectGem_1

DarkPlate_CollectGem_5:
# 90 "data/maps/DarkPlate/scripts.pory"
	giveitem ITEM_DARK_GEM
# 91 "data/maps/DarkPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_DARK_GEM
# 92 "data/maps/DarkPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/DarkPlate/scripts.pory"
	warp MAP_DARK_PLATE, 7, 20
# 94 "data/maps/DarkPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/DarkPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto DarkPlate_CollectGem_1


DarkPlateWonCatch_Text_0:
# 59 "data/maps/DarkPlate/scripts.pory"
	.string "The Overqwil dissapeared in to the cave.$"

DarkPlateWonCatch_Text_1:
# 61 "data/maps/DarkPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

DarkPlateWonCatch_Text_2:
# 62 "data/maps/DarkPlate/scripts.pory"
	.string "Two make matter, and three make spirit,\nshaping the world.$"

DarkPlate_CollectGem_Text_0:
# 85 "data/maps/DarkPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

DarkPlate_CollectGem_Text_1:
# 88 "data/maps/DarkPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
