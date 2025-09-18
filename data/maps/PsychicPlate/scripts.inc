PsychicPlate_MapScripts::
# 2 "data/maps/PsychicPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PsychicPlate_OnLoad
	.byte 0


PsychicPlate_OnLoad::
# 6 "data/maps/PsychicPlate/scripts.pory"
	call_if_unset FLAG_PSYCHIC_PC, PsychicPlate_Entrance
# 7 "data/maps/PsychicPlate/scripts.pory"
	call PsychicPlate_IsGemCollected
	end


PsychicPlate_Entrance::
# 12 "data/maps/PsychicPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/PsychicPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/PsychicPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/PsychicPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/PsychicPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/PsychicPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


PsychicPlate_Battle::
# 22 "data/maps/PsychicPlate/scripts.pory"
	lockall
# 23 "data/maps/PsychicPlate/scripts.pory"
	playmoncry SPECIES_GALLADE, CRY_MODE_ENCOUNTER
# 24 "data/maps/PsychicPlate/scripts.pory"
	delay 40
# 25 "data/maps/PsychicPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/PsychicPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_GALLADE, 50, [ ITEM_PSYCHIC_GEM ], , NATURE_JOLLY, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_SACRED_SWORD ], [ MOVE_LEAF_BLADE ], [ MOVE_PSYCHO_CUT ], [ MOVE_KNOCK_OFF ]
# 28 "data/maps/PsychicPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/PsychicPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/PsychicPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/PsychicPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 32 "data/maps/PsychicPlate/scripts.pory"
	setvar VAR_B_VAR_STARTING_STATUS, 5, TRUE
# 33 "data/maps/PsychicPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/PsychicPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/PsychicPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq PsychicPlate_Battle_2
# 38 "data/maps/PsychicPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PsychicPlate_Battle_3
# 41 "data/maps/PsychicPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq PsychicPlate_Battle_4
# 44 "data/maps/PsychicPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq PsychicPlate_Battle_5
PsychicPlate_Battle_1:
# 47 "data/maps/PsychicPlate/scripts.pory"
	waitmessage
# 48 "data/maps/PsychicPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/PsychicPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/PsychicPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/PsychicPlate/scripts.pory"
	setflag FLAG_PSYCHIC_PC1
# 52 "data/maps/PsychicPlate/scripts.pory"
	releaseall
	return

PsychicPlate_Battle_2:
# 36 "data/maps/PsychicPlate/scripts.pory"
	call PsychicPlateWonCatch
	goto PsychicPlate_Battle_1

PsychicPlate_Battle_3:
# 39 "data/maps/PsychicPlate/scripts.pory"
	call PsychicPlateWonCatch
	goto PsychicPlate_Battle_1

PsychicPlate_Battle_4:
# 42 "data/maps/PsychicPlate/scripts.pory"
	call PsychicPlateRun
	goto PsychicPlate_Battle_1

PsychicPlate_Battle_5:
# 45 "data/maps/PsychicPlate/scripts.pory"
	call PsychicPlateRun
	goto PsychicPlate_Battle_1


PsychicPlateWonCatch::
# 56 "data/maps/PsychicPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/PsychicPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/PsychicPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/PsychicPlate/scripts.pory"
	msgbox PsychicPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/PsychicPlate/scripts.pory"
	giveitem ITEM_MIND_PLATE
# 61 "data/maps/PsychicPlate/scripts.pory"
	msgbox PsychicPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/PsychicPlate/scripts.pory"
	msgbox PsychicPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


PsychicPlateRun::
# 67 "data/maps/PsychicPlate/scripts.pory"
	playmoncry SPECIES_GALLADE, CRY_MODE_ENCOUNTER
# 68 "data/maps/PsychicPlate/scripts.pory"
	waitmoncry
	return


PsychicPlate_IsGemCollected::
# 73 "data/maps/PsychicPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_PSYCHIC_GEM, PsychicPlate_IsGemCollected_2
# 77 "data/maps/PsychicPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
PsychicPlate_IsGemCollected_1:
	return

PsychicPlate_IsGemCollected_2:
# 74 "data/maps/PsychicPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto PsychicPlate_IsGemCollected_1


PsychicPlate_CollectGem::
# 83 "data/maps/PsychicPlate/scripts.pory"
	lockall
# 84 "data/maps/PsychicPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_PSYCHIC_GEM, PsychicPlate_CollectGem_2
# 88 "data/maps/PsychicPlate/scripts.pory"
	msgbox PsychicPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/PsychicPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PsychicPlate_CollectGem_5
PsychicPlate_CollectGem_1:
# 98 "data/maps/PsychicPlate/scripts.pory"
	releaseall
	return

PsychicPlate_CollectGem_2:
# 85 "data/maps/PsychicPlate/scripts.pory"
	msgbox PsychicPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto PsychicPlate_CollectGem_1

PsychicPlate_CollectGem_5:
# 90 "data/maps/PsychicPlate/scripts.pory"
	giveitem ITEM_PSYCHIC_GEM
# 91 "data/maps/PsychicPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_PSYCHIC_GEM
# 92 "data/maps/PsychicPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/PsychicPlate/scripts.pory"
	warp MAP_PSYCHIC_PLATE, 7, 20
# 94 "data/maps/PsychicPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/PsychicPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto PsychicPlate_CollectGem_1


PsychicPlateWonCatch_Text_0:
# 59 "data/maps/PsychicPlate/scripts.pory"
	.string "The Gallade dissapeared in to the cave.$"

PsychicPlateWonCatch_Text_1:
# 61 "data/maps/PsychicPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

PsychicPlateWonCatch_Text_2:
# 62 "data/maps/PsychicPlate/scripts.pory"
	.string "The Original One breathed alone before\nthe universe came.$"

PsychicPlate_CollectGem_Text_0:
# 85 "data/maps/PsychicPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

PsychicPlate_CollectGem_Text_1:
# 88 "data/maps/PsychicPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
