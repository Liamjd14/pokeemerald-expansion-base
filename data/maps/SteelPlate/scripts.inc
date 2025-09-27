SteelPlate_MapScripts::
# 2 "data/maps/SteelPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SteelPlate_OnLoad
	.byte 0


SteelPlate_OnLoad::
# 6 "data/maps/SteelPlate/scripts.pory"
	call SteelPlate_IsGemCollected
# 7 "data/maps/SteelPlate/scripts.pory"
	call SteelPlate_ConditionCheck
# 8 "data/maps/SteelPlate/scripts.pory"
	call_if_unset FLAG_STEEL_PC, SteelPlate_Entrance
	end


SteelPlate_Entrance::
# 13 "data/maps/SteelPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/SteelPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/SteelPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/SteelPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


SteelPlate_Battle::
# 23 "data/maps/SteelPlate/scripts.pory"
	lockall
# 24 "data/maps/SteelPlate/scripts.pory"
	playmoncry SPECIES_GOODRA_HISUI, CRY_MODE_ENCOUNTER
# 25 "data/maps/SteelPlate/scripts.pory"
	delay 40
# 26 "data/maps/SteelPlate/scripts.pory"
	waitmoncry
# 28 "data/maps/SteelPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_GOODRA_HISUI, 50, [ ITEM_STEEL_GEM ], , NATURE_MODEST, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_FLASH_CANNON ], [ MOVE_FLAMETHROWER ], [ MOVE_THUNDERBOLT ], [ MOVE_DRACO_METEOR ]
# 29 "data/maps/SteelPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 30 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/SteelPlate/scripts.pory"
	dowildbattle
# 35 "data/maps/SteelPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq SteelPlate_Battle_2
# 39 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SteelPlate_Battle_3
# 42 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SteelPlate_Battle_4
# 45 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SteelPlate_Battle_5
SteelPlate_Battle_1:
# 48 "data/maps/SteelPlate/scripts.pory"
	waitmessage
# 49 "data/maps/SteelPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/SteelPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/SteelPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_STEEL_PC1
# 53 "data/maps/SteelPlate/scripts.pory"
	releaseall
	return

SteelPlate_Battle_2:
# 37 "data/maps/SteelPlate/scripts.pory"
	call SteelPlateWonCatch
	goto SteelPlate_Battle_1

SteelPlate_Battle_3:
# 40 "data/maps/SteelPlate/scripts.pory"
	call SteelPlateWonCatch
	goto SteelPlate_Battle_1

SteelPlate_Battle_4:
# 43 "data/maps/SteelPlate/scripts.pory"
	call SteelPlateRun
	goto SteelPlate_Battle_1

SteelPlate_Battle_5:
# 46 "data/maps/SteelPlate/scripts.pory"
	call SteelPlateRun
	goto SteelPlate_Battle_1


SteelPlateWonCatch::
# 57 "data/maps/SteelPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/SteelPlate/scripts.pory"
	removeobject 1
# 59 "data/maps/SteelPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/SteelPlate/scripts.pory"
	giveitem ITEM_IRON_PLATE
# 62 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


SteelPlateRun::
# 68 "data/maps/SteelPlate/scripts.pory"
	playmoncry SPECIES_GOODRA_HISUI, CRY_MODE_ENCOUNTER
# 69 "data/maps/SteelPlate/scripts.pory"
	waitmoncry
	return


SteelPlate_IsGemCollected::
# 74 "data/maps/SteelPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_STEEL_GEM, SteelPlate_IsGemCollected_2
# 78 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
SteelPlate_IsGemCollected_1:
	return

SteelPlate_IsGemCollected_2:
# 75 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto SteelPlate_IsGemCollected_1


SteelPlate_CollectGem::
# 84 "data/maps/SteelPlate/scripts.pory"
	lockall
# 85 "data/maps/SteelPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_STEEL_GEM, SteelPlate_CollectGem_2
# 89 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SteelPlate_CollectGem_5
SteelPlate_CollectGem_1:
# 99 "data/maps/SteelPlate/scripts.pory"
	releaseall
	return

SteelPlate_CollectGem_2:
# 86 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto SteelPlate_CollectGem_1

SteelPlate_CollectGem_5:
# 91 "data/maps/SteelPlate/scripts.pory"
	giveitem ITEM_STEEL_GEM
# 92 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_STEEL_GEM
# 93 "data/maps/SteelPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/SteelPlate/scripts.pory"
	warp MAP_STEEL_PLATE, 7, 20
# 95 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/SteelPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto SteelPlate_CollectGem_1


SteelPlate_ConditionCheck::
# 103 "data/maps/SteelPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, SteelPlate_ConditionCheck_2
SteelPlate_ConditionCheck_1:
	return

SteelPlate_ConditionCheck_2:
# 104 "data/maps/SteelPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, SteelPlate_ConditionCheck_4
	goto SteelPlate_ConditionCheck_1

SteelPlate_ConditionCheck_4:
# 105 "data/maps/SteelPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, SteelPlate_ConditionCheck_6
	goto SteelPlate_ConditionCheck_1

SteelPlate_ConditionCheck_6:
# 106 "data/maps/SteelPlate/scripts.pory"
	checkitem ITEM_STEEL_GEM, 1
# 107 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SteelPlate_ConditionCheck_8
	goto SteelPlate_ConditionCheck_1

SteelPlate_ConditionCheck_8:
# 108 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_STEEL_PC
	goto SteelPlate_ConditionCheck_1


SteelPlateWonCatch_Text_0:
# 60 "data/maps/SteelPlate/scripts.pory"
	.string "The Goodra dissapeared in to the cave.$"

SteelPlateWonCatch_Text_1:
# 62 "data/maps/SteelPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

SteelPlateWonCatch_Text_2:
# 63 "data/maps/SteelPlate/scripts.pory"
	.string "That which fills the other side of\nthe world can shape the rage and mold it.$"

SteelPlate_CollectGem_Text_0:
# 86 "data/maps/SteelPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

SteelPlate_CollectGem_Text_1:
# 89 "data/maps/SteelPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
