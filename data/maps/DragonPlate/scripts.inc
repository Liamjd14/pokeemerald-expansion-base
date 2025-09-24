DragonPlate_MapScripts::
# 2 "data/maps/DragonPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DragonPlate_OnLoad
	.byte 0


DragonPlate_OnLoad::
# 6 "data/maps/DragonPlate/scripts.pory"
	call_if_unset FLAG_DRAGON_PC, DragonPlate_Entrance
# 7 "data/maps/DragonPlate/scripts.pory"
	call DragonPlate_IsGemCollected
# 8 "data/maps/DragonPlate/scripts.pory"
	call DragonPlate_ConditionCheck
	end


DragonPlate_Entrance::
# 13 "data/maps/DragonPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/DragonPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/DragonPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/DragonPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/DragonPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/DragonPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


DragonPlate_Battle::
# 23 "data/maps/DragonPlate/scripts.pory"
	lockall
# 24 "data/maps/DragonPlate/scripts.pory"
	playmoncry SPECIES_GARCHOMP, CRY_MODE_ENCOUNTER
# 25 "data/maps/DragonPlate/scripts.pory"
	delay 40
# 26 "data/maps/DragonPlate/scripts.pory"
	waitmoncry
# 28 "data/maps/DragonPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_GARCHOMP, 50, [ ITEM_DRAGON_GEM ], , NATURE_JOLLY, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_SANDSTORM ], [ MOVE_OUTRAGE ], [ MOVE_IRON_HEAD ], [ MOVE_EARTHQUAKE ]
# 29 "data/maps/DragonPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 30 "data/maps/DragonPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/DragonPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/DragonPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/DragonPlate/scripts.pory"
	dowildbattle
# 35 "data/maps/DragonPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/DragonPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DragonPlate_Battle_2
# 39 "data/maps/DragonPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DragonPlate_Battle_3
# 42 "data/maps/DragonPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq DragonPlate_Battle_4
# 45 "data/maps/DragonPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq DragonPlate_Battle_5
DragonPlate_Battle_1:
# 48 "data/maps/DragonPlate/scripts.pory"
	waitmessage
# 49 "data/maps/DragonPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/DragonPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/DragonPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/DragonPlate/scripts.pory"
	setflag FLAG_DRAGON_PC1
# 53 "data/maps/DragonPlate/scripts.pory"
	releaseall
	return

DragonPlate_Battle_2:
# 37 "data/maps/DragonPlate/scripts.pory"
	call DragonPlateWonCatch
	goto DragonPlate_Battle_1

DragonPlate_Battle_3:
# 40 "data/maps/DragonPlate/scripts.pory"
	call DragonPlateWonCatch
	goto DragonPlate_Battle_1

DragonPlate_Battle_4:
# 43 "data/maps/DragonPlate/scripts.pory"
	call DragonPlateRun
	goto DragonPlate_Battle_1

DragonPlate_Battle_5:
# 46 "data/maps/DragonPlate/scripts.pory"
	call DragonPlateRun
	goto DragonPlate_Battle_1


DragonPlateWonCatch::
# 57 "data/maps/DragonPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/DragonPlate/scripts.pory"
	removeobject 1
# 59 "data/maps/DragonPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/DragonPlate/scripts.pory"
	msgbox DragonPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/DragonPlate/scripts.pory"
	giveitem ITEM_DRACO_PLATE
# 62 "data/maps/DragonPlate/scripts.pory"
	msgbox DragonPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/DragonPlate/scripts.pory"
	msgbox DragonPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


DragonPlateRun::
# 68 "data/maps/DragonPlate/scripts.pory"
	playmoncry SPECIES_GARCHOMP, CRY_MODE_ENCOUNTER
# 69 "data/maps/DragonPlate/scripts.pory"
	waitmoncry
	return


DragonPlate_IsGemCollected::
# 74 "data/maps/DragonPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_DRAGON_GEM, DragonPlate_IsGemCollected_2
# 78 "data/maps/DragonPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
DragonPlate_IsGemCollected_1:
	return

DragonPlate_IsGemCollected_2:
# 75 "data/maps/DragonPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto DragonPlate_IsGemCollected_1


DragonPlate_CollectGem::
# 84 "data/maps/DragonPlate/scripts.pory"
	lockall
# 85 "data/maps/DragonPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_DRAGON_GEM, DragonPlate_CollectGem_2
# 89 "data/maps/DragonPlate/scripts.pory"
	msgbox DragonPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/DragonPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DragonPlate_CollectGem_5
DragonPlate_CollectGem_1:
# 99 "data/maps/DragonPlate/scripts.pory"
	releaseall
	return

DragonPlate_CollectGem_2:
# 86 "data/maps/DragonPlate/scripts.pory"
	msgbox DragonPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto DragonPlate_CollectGem_1

DragonPlate_CollectGem_5:
# 91 "data/maps/DragonPlate/scripts.pory"
	giveitem ITEM_DRAGON_GEM
# 92 "data/maps/DragonPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_DRAGON_GEM
# 93 "data/maps/DragonPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/DragonPlate/scripts.pory"
	warp MAP_DRAGON_PLATE, 7, 20
# 95 "data/maps/DragonPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/DragonPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto DragonPlate_CollectGem_1


DragonPlate_ConditionCheck::
# 103 "data/maps/DragonPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, DragonPlate_ConditionCheck_2
DragonPlate_ConditionCheck_1:
	return

DragonPlate_ConditionCheck_2:
# 104 "data/maps/DragonPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, DragonPlate_ConditionCheck_4
	goto DragonPlate_ConditionCheck_1

DragonPlate_ConditionCheck_4:
# 105 "data/maps/DragonPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, DragonPlate_ConditionCheck_6
	goto DragonPlate_ConditionCheck_1

DragonPlate_ConditionCheck_6:
# 106 "data/maps/DragonPlate/scripts.pory"
	checkitem ITEM_DRAGON_GEM, 1
# 107 "data/maps/DragonPlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DragonPlate_ConditionCheck_8
	goto DragonPlate_ConditionCheck_1

DragonPlate_ConditionCheck_8:
# 108 "data/maps/DragonPlate/scripts.pory"
	setflag FLAG_DRAGON_PC
	goto DragonPlate_ConditionCheck_1


DragonPlateWonCatch_Text_0:
# 60 "data/maps/DragonPlate/scripts.pory"
	.string "The Garchomp dissapeared in to\nthe cave.$"

DragonPlateWonCatch_Text_1:
# 62 "data/maps/DragonPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

DragonPlateWonCatch_Text_2:
# 63 "data/maps/DragonPlate/scripts.pory"
	.string "Three beings were born to bind\ntime and space.$"

DragonPlate_CollectGem_Text_0:
# 86 "data/maps/DragonPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

DragonPlate_CollectGem_Text_1:
# 89 "data/maps/DragonPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
