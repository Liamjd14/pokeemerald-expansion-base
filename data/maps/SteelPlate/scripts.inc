SteelPlate_MapScripts::
# 2 "data/maps/SteelPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SteelPlate_OnLoad
	.byte 0


SteelPlate_OnLoad::
# 6 "data/maps/SteelPlate/scripts.pory"
	call_if_unset FLAG_STEEL_PC, SteelPlate_Entrance
# 7 "data/maps/SteelPlate/scripts.pory"
	call SteelPlate_IsGemCollected
	end


SteelPlate_Entrance::
# 12 "data/maps/SteelPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/SteelPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/SteelPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/SteelPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


SteelPlate_Battle::
# 22 "data/maps/SteelPlate/scripts.pory"
	lockall
# 23 "data/maps/SteelPlate/scripts.pory"
	playmoncry SPECIES_GOODRA_HISUI, CRY_MODE_ENCOUNTER
# 24 "data/maps/SteelPlate/scripts.pory"
	delay 40
# 25 "data/maps/SteelPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/SteelPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_GOODRA_HISUI, 50, [ ITEM_STEEL_GEM ], , NATURE_MODEST, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_FLASH_CANNON ], [ MOVE_FLAMETHROWER ], [ MOVE_THUNDERBOLT ], [ MOVE_DRACO_METEOR ]
# 28 "data/maps/SteelPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 29 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/SteelPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/SteelPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq SteelPlate_Battle_2
# 38 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SteelPlate_Battle_3
# 41 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SteelPlate_Battle_4
# 44 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SteelPlate_Battle_5
SteelPlate_Battle_1:
# 47 "data/maps/SteelPlate/scripts.pory"
	waitmessage
# 48 "data/maps/SteelPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/SteelPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/SteelPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_STEEL_PC1
# 52 "data/maps/SteelPlate/scripts.pory"
	releaseall
	return

SteelPlate_Battle_2:
# 36 "data/maps/SteelPlate/scripts.pory"
	call SteelPlateWonCatch
	goto SteelPlate_Battle_1

SteelPlate_Battle_3:
# 39 "data/maps/SteelPlate/scripts.pory"
	call SteelPlateWonCatch
	goto SteelPlate_Battle_1

SteelPlate_Battle_4:
# 42 "data/maps/SteelPlate/scripts.pory"
	call SteelPlateRun
	goto SteelPlate_Battle_1

SteelPlate_Battle_5:
# 45 "data/maps/SteelPlate/scripts.pory"
	call SteelPlateRun
	goto SteelPlate_Battle_1


SteelPlateWonCatch::
# 56 "data/maps/SteelPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/SteelPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/SteelPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/SteelPlate/scripts.pory"
	giveitem ITEM_IRON_PLATE
# 61 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


SteelPlateRun::
# 67 "data/maps/SteelPlate/scripts.pory"
	playmoncry SPECIES_GOODRA_HISUI, CRY_MODE_ENCOUNTER
# 68 "data/maps/SteelPlate/scripts.pory"
	waitmoncry
	return


SteelPlate_IsGemCollected::
# 73 "data/maps/SteelPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_STEEL_GEM, SteelPlate_IsGemCollected_2
# 77 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
SteelPlate_IsGemCollected_1:
	return

SteelPlate_IsGemCollected_2:
# 74 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto SteelPlate_IsGemCollected_1


SteelPlate_CollectGem::
# 83 "data/maps/SteelPlate/scripts.pory"
	lockall
# 84 "data/maps/SteelPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_STEEL_GEM, SteelPlate_CollectGem_2
# 88 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/SteelPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SteelPlate_CollectGem_5
SteelPlate_CollectGem_1:
# 98 "data/maps/SteelPlate/scripts.pory"
	releaseall
	return

SteelPlate_CollectGem_2:
# 85 "data/maps/SteelPlate/scripts.pory"
	msgbox SteelPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto SteelPlate_CollectGem_1

SteelPlate_CollectGem_5:
# 90 "data/maps/SteelPlate/scripts.pory"
	giveitem ITEM_STEEL_GEM
# 91 "data/maps/SteelPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_STEEL_GEM
# 92 "data/maps/SteelPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/SteelPlate/scripts.pory"
	warp MAP_STEEL_PLATE, 7, 20
# 94 "data/maps/SteelPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/SteelPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto SteelPlate_CollectGem_1


SteelPlateWonCatch_Text_0:
# 59 "data/maps/SteelPlate/scripts.pory"
	.string "The Goodra dissapeared in to the cave.$"

SteelPlateWonCatch_Text_1:
# 61 "data/maps/SteelPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

SteelPlateWonCatch_Text_2:
# 62 "data/maps/SteelPlate/scripts.pory"
	.string "That which fills the other side of\nthe world can shape the rage and mold it.$"

SteelPlate_CollectGem_Text_0:
# 85 "data/maps/SteelPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

SteelPlate_CollectGem_Text_1:
# 88 "data/maps/SteelPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
