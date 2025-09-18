PoisonPlate_MapScripts::
# 2 "data/maps/PoisonPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PoisonPlate_OnLoad
	.byte 0


PoisonPlate_OnLoad::
# 6 "data/maps/PoisonPlate/scripts.pory"
	call_if_unset FLAG_POISON_PC, PoisonPlate_Entrance
# 7 "data/maps/PoisonPlate/scripts.pory"
	call PoisonPlate_IsGemCollected
	end


PoisonPlate_Entrance::
# 12 "data/maps/PoisonPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/PoisonPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/PoisonPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/PoisonPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/PoisonPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/PoisonPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


PoisonPlate_Battle::
# 22 "data/maps/PoisonPlate/scripts.pory"
	lockall
# 23 "data/maps/PoisonPlate/scripts.pory"
	playmoncry SPECIES_SNEASLER, CRY_MODE_ENCOUNTER
# 24 "data/maps/PoisonPlate/scripts.pory"
	delay 40
# 25 "data/maps/PoisonPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/PoisonPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_SNEASLER, 50, [ ITEM_POISON_GEM ], , NATURE_JOLLY, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_DIRE_CLAW ], [ MOVE_CLOSE_COMBAT ], [ MOVE_X_SCISSOR ], [ MOVE_THROAT_CHOP ]
# 28 "data/maps/PoisonPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/PoisonPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/PoisonPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/PoisonPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/PoisonPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/PoisonPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/PoisonPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq PoisonPlate_Battle_2
# 38 "data/maps/PoisonPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PoisonPlate_Battle_3
# 41 "data/maps/PoisonPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq PoisonPlate_Battle_4
# 44 "data/maps/PoisonPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq PoisonPlate_Battle_5
PoisonPlate_Battle_1:
# 47 "data/maps/PoisonPlate/scripts.pory"
	waitmessage
# 48 "data/maps/PoisonPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/PoisonPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/PoisonPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/PoisonPlate/scripts.pory"
	setflag FLAG_POISON_PC1
# 52 "data/maps/PoisonPlate/scripts.pory"
	releaseall
	return

PoisonPlate_Battle_2:
# 36 "data/maps/PoisonPlate/scripts.pory"
	call PoisonPlateWonCatch
	goto PoisonPlate_Battle_1

PoisonPlate_Battle_3:
# 39 "data/maps/PoisonPlate/scripts.pory"
	call PoisonPlateWonCatch
	goto PoisonPlate_Battle_1

PoisonPlate_Battle_4:
# 42 "data/maps/PoisonPlate/scripts.pory"
	call PoisonPlateRun
	goto PoisonPlate_Battle_1

PoisonPlate_Battle_5:
# 45 "data/maps/PoisonPlate/scripts.pory"
	call PoisonPlateRun
	goto PoisonPlate_Battle_1


PoisonPlateWonCatch::
# 56 "data/maps/PoisonPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/PoisonPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/PoisonPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/PoisonPlate/scripts.pory"
	msgbox PoisonPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/PoisonPlate/scripts.pory"
	giveitem ITEM_TOXIC_PLATE
# 61 "data/maps/PoisonPlate/scripts.pory"
	msgbox PoisonPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/PoisonPlate/scripts.pory"
	msgbox PoisonPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


PoisonPlateRun::
# 67 "data/maps/PoisonPlate/scripts.pory"
	playmoncry SPECIES_SNEASLER, CRY_MODE_ENCOUNTER
# 68 "data/maps/PoisonPlate/scripts.pory"
	waitmoncry
	return


PoisonPlate_IsGemCollected::
# 73 "data/maps/PoisonPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_POISON_GEM, PoisonPlate_IsGemCollected_2
# 77 "data/maps/PoisonPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
PoisonPlate_IsGemCollected_1:
	return

PoisonPlate_IsGemCollected_2:
# 74 "data/maps/PoisonPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto PoisonPlate_IsGemCollected_1


PoisonPlate_CollectGem::
# 83 "data/maps/PoisonPlate/scripts.pory"
	lockall
# 84 "data/maps/PoisonPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_POISON_GEM, PoisonPlate_CollectGem_2
# 88 "data/maps/PoisonPlate/scripts.pory"
	msgbox PoisonPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/PoisonPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PoisonPlate_CollectGem_5
PoisonPlate_CollectGem_1:
# 98 "data/maps/PoisonPlate/scripts.pory"
	releaseall
	return

PoisonPlate_CollectGem_2:
# 85 "data/maps/PoisonPlate/scripts.pory"
	msgbox PoisonPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto PoisonPlate_CollectGem_1

PoisonPlate_CollectGem_5:
# 90 "data/maps/PoisonPlate/scripts.pory"
	giveitem ITEM_POISON_GEM
# 91 "data/maps/PoisonPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_POISON_GEM
# 92 "data/maps/PoisonPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/PoisonPlate/scripts.pory"
	warp MAP_POISON_PLATE, 7, 20
# 94 "data/maps/PoisonPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/PoisonPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto PoisonPlate_CollectGem_1


PoisonPlateWonCatch_Text_0:
# 59 "data/maps/PoisonPlate/scripts.pory"
	.string "The Sneasler dissapeared in to the\ncave.$"

PoisonPlateWonCatch_Text_1:
# 61 "data/maps/PoisonPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

PoisonPlateWonCatch_Text_2:
# 62 "data/maps/PoisonPlate/scripts.pory"
	.string "The rules of time and space change with\nin the opposite world.$"

PoisonPlate_CollectGem_Text_0:
# 85 "data/maps/PoisonPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

PoisonPlate_CollectGem_Text_1:
# 88 "data/maps/PoisonPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
