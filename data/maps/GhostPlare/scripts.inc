GhostPlare_MapScripts::
# 2 "data/maps/GhostPlare/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GhostPlate_OnLoad
	.byte 0


GhostPlate_OnLoad::
# 6 "data/maps/GhostPlare/scripts.pory"
	call GhostPlate_IsGemCollected
# 7 "data/maps/GhostPlare/scripts.pory"
	call GhostPlate_ConditionCheck
# 8 "data/maps/GhostPlare/scripts.pory"
	call_if_unset FLAG_ROCK_PC, GhostPlate_Entrance
	end


GhostPlate_Entrance::
# 13 "data/maps/GhostPlare/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/GhostPlare/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/GhostPlare/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/GhostPlare/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


GhostPlate_Battle::
# 23 "data/maps/GhostPlare/scripts.pory"
	lockall
# 24 "data/maps/GhostPlare/scripts.pory"
	playmoncry SPECIES_SPIRITOMB, CRY_MODE_ENCOUNTER
# 25 "data/maps/GhostPlare/scripts.pory"
	delay 40
# 26 "data/maps/GhostPlare/scripts.pory"
	waitmoncry
# 28 "data/maps/GhostPlare/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_SPIRITOMB, 50, [ ITEM_GHOST_GEM ], , NATURE_QUIET, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_TRICK_ROOM ], [ MOVE_PSYSHOCK ], [ MOVE_DARK_PULSE ], [ MOVE_SHADOW_BALL ]
# 29 "data/maps/GhostPlare/scripts.pory"
	settotemboost B_BATTLER_1, 0, 1, 0, 2, 1, 1, 0
# 30 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/GhostPlare/scripts.pory"
	dowildbattle
# 35 "data/maps/GhostPlare/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GhostPlate_Battle_2
# 39 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GhostPlate_Battle_3
# 42 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq GhostPlate_Battle_4
# 45 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq GhostPlate_Battle_5
GhostPlate_Battle_1:
# 48 "data/maps/GhostPlare/scripts.pory"
	waitmessage
# 49 "data/maps/GhostPlare/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/GhostPlare/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/GhostPlare/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_ROCK_PC1
# 53 "data/maps/GhostPlare/scripts.pory"
	releaseall
	return

GhostPlate_Battle_2:
# 37 "data/maps/GhostPlare/scripts.pory"
	call GhostPlateWonCatch
	goto GhostPlate_Battle_1

GhostPlate_Battle_3:
# 40 "data/maps/GhostPlare/scripts.pory"
	call GhostPlateWonCatch
	goto GhostPlate_Battle_1

GhostPlate_Battle_4:
# 43 "data/maps/GhostPlare/scripts.pory"
	call GhostPlateRun
	goto GhostPlate_Battle_1

GhostPlate_Battle_5:
# 46 "data/maps/GhostPlare/scripts.pory"
	call GhostPlateRun
	goto GhostPlate_Battle_1


GhostPlateWonCatch::
# 57 "data/maps/GhostPlare/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/GhostPlare/scripts.pory"
	removeobject 1
# 59 "data/maps/GhostPlare/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/GhostPlare/scripts.pory"
	giveitem ITEM_SPOOKY_PLATE
# 62 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


GhostPlateRun::
# 68 "data/maps/GhostPlare/scripts.pory"
	playmoncry SPECIES_SPIRITOMB, CRY_MODE_ENCOUNTER
# 69 "data/maps/GhostPlare/scripts.pory"
	waitmoncry
	return


GhostPlate_IsGemCollected::
# 74 "data/maps/GhostPlare/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GHOST_GEM, GhostPlate_IsGemCollected_2
# 78 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
GhostPlate_IsGemCollected_1:
	return

GhostPlate_IsGemCollected_2:
# 75 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto GhostPlate_IsGemCollected_1


GhostPlate_CollectGem::
# 84 "data/maps/GhostPlare/scripts.pory"
	lockall
# 85 "data/maps/GhostPlare/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GHOST_GEM, GhostPlate_CollectGem_2
# 89 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GhostPlate_CollectGem_5
GhostPlate_CollectGem_1:
# 99 "data/maps/GhostPlare/scripts.pory"
	releaseall
	return

GhostPlate_CollectGem_2:
# 86 "data/maps/GhostPlare/scripts.pory"
	msgbox GhostPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto GhostPlate_CollectGem_1

GhostPlate_CollectGem_5:
# 91 "data/maps/GhostPlare/scripts.pory"
	giveitem ITEM_GHOST_GEM
# 92 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_GHOST_GEM
# 93 "data/maps/GhostPlare/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/GhostPlare/scripts.pory"
	warp MAP_GHOST_PLARE, 7, 20
# 95 "data/maps/GhostPlare/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/GhostPlare/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto GhostPlate_CollectGem_1


GhostPlate_ConditionCheck::
# 103 "data/maps/GhostPlare/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, GhostPlate_ConditionCheck_2
GhostPlate_ConditionCheck_1:
	return

GhostPlate_ConditionCheck_2:
# 104 "data/maps/GhostPlare/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, GhostPlate_ConditionCheck_4
	goto GhostPlate_ConditionCheck_1

GhostPlate_ConditionCheck_4:
# 105 "data/maps/GhostPlare/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, GhostPlate_ConditionCheck_6
	goto GhostPlate_ConditionCheck_1

GhostPlate_ConditionCheck_6:
# 106 "data/maps/GhostPlare/scripts.pory"
	checkitem ITEM_GHOST_GEM, 1
# 107 "data/maps/GhostPlare/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq GhostPlate_ConditionCheck_8
	goto GhostPlate_ConditionCheck_1

GhostPlate_ConditionCheck_8:
# 108 "data/maps/GhostPlare/scripts.pory"
	setflag FLAG_GHOST_PC
	goto GhostPlate_ConditionCheck_1


GhostPlateWonCatch_Text_0:
# 60 "data/maps/GhostPlare/scripts.pory"
	.string "The Spiritomb dissapeared in to the cave.$"

GhostPlateWonCatch_Text_1:
# 62 "data/maps/GhostPlare/scripts.pory"
	.string "There is an engraving on the Plate.$"

GhostPlateWonCatch_Text_2:
# 63 "data/maps/GhostPlare/scripts.pory"
	.string "The other side of this world was given\nby the Original One to its raging third.$"

GhostPlate_CollectGem_Text_0:
# 86 "data/maps/GhostPlare/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

GhostPlate_CollectGem_Text_1:
# 89 "data/maps/GhostPlare/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
