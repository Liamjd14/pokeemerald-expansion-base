FightingPlate_MapScripts::
# 2 "data/maps/FightingPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FightingPlate_OnLoad
	.byte 0


FightingPlate_OnLoad::
# 6 "data/maps/FightingPlate/scripts.pory"
	call_if_unset FLAG_FIGHTING_PC, FightingPlate_Entrance
# 7 "data/maps/FightingPlate/scripts.pory"
	call FightingPlate_IsGemCollected
	end


FightingPlate_Entrance::
# 12 "data/maps/FightingPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/FightingPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/FightingPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/FightingPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/FightingPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/FightingPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


FightingPlate_Battle::
# 22 "data/maps/FightingPlate/scripts.pory"
	lockall
# 23 "data/maps/FightingPlate/scripts.pory"
	playmoncry SPECIES_LUCARIO, CRY_MODE_ENCOUNTER
# 24 "data/maps/FightingPlate/scripts.pory"
	delay 40
# 25 "data/maps/FightingPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/FightingPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_LUCARIO, 50, [ ITEM_FIGHTING_GEM ], , NATURE_JOLLY, 1, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_SWORDS_DANCE ], [ MOVE_CLOSE_COMBAT ], [ MOVE_METEOR_MASH ], [ MOVE_EXTREME_SPEED ]
# 28 "data/maps/FightingPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/FightingPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/FightingPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/FightingPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/FightingPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/FightingPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/FightingPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightingPlate_Battle_2
# 38 "data/maps/FightingPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightingPlate_Battle_3
# 41 "data/maps/FightingPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FightingPlate_Battle_4
# 44 "data/maps/FightingPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FightingPlate_Battle_5
FightingPlate_Battle_1:
# 47 "data/maps/FightingPlate/scripts.pory"
	waitmessage
# 48 "data/maps/FightingPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/FightingPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/FightingPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/FightingPlate/scripts.pory"
	setflag FLAG_FIGHTING_PC1
# 52 "data/maps/FightingPlate/scripts.pory"
	releaseall
	return

FightingPlate_Battle_2:
# 36 "data/maps/FightingPlate/scripts.pory"
	call FightingPlateWonCatch
	goto FightingPlate_Battle_1

FightingPlate_Battle_3:
# 39 "data/maps/FightingPlate/scripts.pory"
	call FightingPlateWonCatch
	goto FightingPlate_Battle_1

FightingPlate_Battle_4:
# 42 "data/maps/FightingPlate/scripts.pory"
	call FightingPlateRun
	goto FightingPlate_Battle_1

FightingPlate_Battle_5:
# 45 "data/maps/FightingPlate/scripts.pory"
	call FightingPlateRun
	goto FightingPlate_Battle_1


FightingPlateWonCatch::
# 56 "data/maps/FightingPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/FightingPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/FightingPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/FightingPlate/scripts.pory"
	msgbox FightingPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/FightingPlate/scripts.pory"
	giveitem ITEM_FIST_PLATE
# 61 "data/maps/FightingPlate/scripts.pory"
	msgbox FightingPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/FightingPlate/scripts.pory"
	msgbox FightingPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


FightingPlateRun::
# 67 "data/maps/FightingPlate/scripts.pory"
	playmoncry SPECIES_LUCARIO, CRY_MODE_ENCOUNTER
# 68 "data/maps/FightingPlate/scripts.pory"
	waitmoncry
	return


FightingPlate_IsGemCollected::
# 73 "data/maps/FightingPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FIGHTING_GEM, FightingPlate_IsGemCollected_2
# 77 "data/maps/FightingPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
FightingPlate_IsGemCollected_1:
	return

FightingPlate_IsGemCollected_2:
# 74 "data/maps/FightingPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto FightingPlate_IsGemCollected_1


FightingPlate_CollectGem::
# 83 "data/maps/FightingPlate/scripts.pory"
	lockall
# 84 "data/maps/FightingPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FIGHTING_GEM, FightingPlate_CollectGem_2
# 88 "data/maps/FightingPlate/scripts.pory"
	msgbox FightingPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/FightingPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FightingPlate_CollectGem_5
FightingPlate_CollectGem_1:
# 98 "data/maps/FightingPlate/scripts.pory"
	releaseall
	return

FightingPlate_CollectGem_2:
# 85 "data/maps/FightingPlate/scripts.pory"
	msgbox FightingPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto FightingPlate_CollectGem_1

FightingPlate_CollectGem_5:
# 90 "data/maps/FightingPlate/scripts.pory"
	giveitem ITEM_FIGHTING_GEM
# 91 "data/maps/FightingPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_FIGHTING_GEM
# 92 "data/maps/FightingPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/FightingPlate/scripts.pory"
	warp MAP_FIGHTING_PLATE, 7, 20
# 94 "data/maps/FightingPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/FightingPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto FightingPlate_CollectGem_1


FightingPlateWonCatch_Text_0:
# 59 "data/maps/FightingPlate/scripts.pory"
	.string "The Lucario dissapeared in to the\ncave.$"

FightingPlateWonCatch_Text_1:
# 61 "data/maps/FightingPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

FightingPlateWonCatch_Text_2:
# 62 "data/maps/FightingPlate/scripts.pory"
	.string "The rift is born of disorder on the\nother side of this world.$"

FightingPlate_CollectGem_Text_0:
# 85 "data/maps/FightingPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

FightingPlate_CollectGem_Text_1:
# 88 "data/maps/FightingPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
