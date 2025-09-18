GhostPlare_MapScripts::
# 2 "data/maps/GhostPlare/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GhostPlate_OnLoad
	.byte 0


GhostPlate_OnLoad::
# 6 "data/maps/GhostPlare/scripts.pory"
	call_if_unset FLAG_ROCK_PC, GhostPlate_Entrance
# 7 "data/maps/GhostPlare/scripts.pory"
	call GhostPlate_IsGemCollected
	end


GhostPlate_Entrance::
# 12 "data/maps/GhostPlare/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/GhostPlare/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/GhostPlare/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/GhostPlare/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


GhostPlate_Battle::
# 22 "data/maps/GhostPlare/scripts.pory"
	lockall
# 23 "data/maps/GhostPlare/scripts.pory"
	playmoncry SPECIES_SPIRITOMB, CRY_MODE_ENCOUNTER
# 24 "data/maps/GhostPlare/scripts.pory"
	delay 40
# 25 "data/maps/GhostPlare/scripts.pory"
	waitmoncry
# 27 "data/maps/GhostPlare/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_SPIRITOMB, 50, [ ITEM_GHOST_GEM ], , NATURE_QUIET, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_TRICK_ROOM ], [ MOVE_PSYSHOCK ], [ MOVE_DARK_PULSE ], [ MOVE_SHADOW_BALL ]
# 28 "data/maps/GhostPlare/scripts.pory"
	settotemboost B_BATTLER_1, 0, 1, 0, 2, 1, 1, 0
# 29 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/GhostPlare/scripts.pory"
	dowildbattle
# 34 "data/maps/GhostPlare/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GhostPlate_Battle_2
# 38 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GhostPlate_Battle_3
# 41 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq GhostPlate_Battle_4
# 44 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq GhostPlate_Battle_5
GhostPlate_Battle_1:
# 47 "data/maps/GhostPlare/scripts.pory"
	waitmessage
# 48 "data/maps/GhostPlare/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/GhostPlare/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/GhostPlare/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_ROCK_PC1
# 52 "data/maps/GhostPlare/scripts.pory"
	releaseall
	return

GhostPlate_Battle_2:
# 36 "data/maps/GhostPlare/scripts.pory"
	call GhostPlateWonCatch
	goto GhostPlate_Battle_1

GhostPlate_Battle_3:
# 39 "data/maps/GhostPlare/scripts.pory"
	call GhostPlateWonCatch
	goto GhostPlate_Battle_1

GhostPlate_Battle_4:
# 42 "data/maps/GhostPlare/scripts.pory"
	call GhostPlateRun
	goto GhostPlate_Battle_1

GhostPlate_Battle_5:
# 45 "data/maps/GhostPlare/scripts.pory"
	call GhostPlateRun
	goto GhostPlate_Battle_1


GhostPlateWonCatch::
# 56 "data/maps/GhostPlare/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/GhostPlare/scripts.pory"
	removeobject 1
# 58 "data/maps/GhostPlare/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/GhostPlare/scripts.pory"
	giveitem ITEM_SPOOKY_PLATE
# 61 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


GhostPlateRun::
# 67 "data/maps/GhostPlare/scripts.pory"
	playmoncry SPECIES_SPIRITOMB, CRY_MODE_ENCOUNTER
# 68 "data/maps/GhostPlare/scripts.pory"
	waitmoncry
	return


GhostPlate_IsGemCollected::
# 73 "data/maps/GhostPlare/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GHOST_GEM, GhostPlate_IsGemCollected_2
# 77 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
GhostPlate_IsGemCollected_1:
	return

GhostPlate_IsGemCollected_2:
# 74 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto GhostPlate_IsGemCollected_1


GhostPlate_CollectGem::
# 83 "data/maps/GhostPlare/scripts.pory"
	lockall
# 84 "data/maps/GhostPlare/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GHOST_GEM, GhostPlate_CollectGem_2
# 88 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GhostPlate_CollectGem_5
GhostPlate_CollectGem_1:
# 98 "data/maps/GhostPlare/scripts.pory"
	releaseall
	return

GhostPlate_CollectGem_2:
# 85 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto GhostPlate_CollectGem_1

GhostPlate_CollectGem_5:
# 90 "data/maps/GhostPlare/scripts.pory"
	giveitem ITEM_GHOST_GEM
# 91 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_GHOST_GEM
# 92 "data/maps/GhostPlare/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/GhostPlare/scripts.pory"
	warp MAP_GHOST_PLARE, 7, 20
# 94 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/GhostPlare/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto GhostPlate_CollectGem_1


GhostPlateWonCatch_Text_0:
# 59 "data/maps/GhostPlare/scripts.pory"
	.string "The Spiritomb dissapeared in to the cave.$"

GhostPlateWonCatch_Text_1:
# 61 "data/maps/GhostPlare/scripts.pory"
	.string "There is an engraving on the Plate.$"

GhostPlateWonCatch_Text_2:
# 62 "data/maps/GhostPlare/scripts.pory"
	.string "The other side of this world was given\nby the Original One to its raging third.$"

GhostPlate_CollectGem_Text_0:
# 85 "data/maps/GhostPlare/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

GhostPlate_CollectGem_Text_1:
# 88 "data/maps/GhostPlare/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
