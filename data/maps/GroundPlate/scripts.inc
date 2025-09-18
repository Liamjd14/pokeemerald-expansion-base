GroundPlate_MapScripts::
# 2 "data/maps/GroundPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GroundPlate_OnLoad
	.byte 0


GroundPlate_OnLoad::
# 6 "data/maps/GroundPlate/scripts.pory"
	call_if_unset FLAG_GROUND_PC, GroundPlate_Entrance
# 7 "data/maps/GroundPlate/scripts.pory"
	call GroundPlate_IsGemCollected
	end


GroundPlate_Entrance::
# 12 "data/maps/GroundPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/GroundPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/GroundPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/GroundPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


GroundPlate_Battle::
# 22 "data/maps/GroundPlate/scripts.pory"
	lockall
# 23 "data/maps/GroundPlate/scripts.pory"
	playmoncry SPECIES_URSALUNA, CRY_MODE_ENCOUNTER
# 24 "data/maps/GroundPlate/scripts.pory"
	delay 40
# 25 "data/maps/GroundPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/GroundPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_URSALUNA, 50, [ ITEM_GROUND_GEM ], , NATURE_JOLLY, 0, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_FACADE ], [ MOVE_HEADLONG_RUSH ], [ MOVE_FIRE_PUNCH ], [ MOVE_ICE_PUNCH ]
# 28 "data/maps/GroundPlate/scripts.pory"
	settotemboost B_BATTLER_1, 2, 0, 2, 0, 0, 1, 0
# 29 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/GroundPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/GroundPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GroundPlate_Battle_2
# 38 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GroundPlate_Battle_3
# 41 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq GroundPlate_Battle_4
# 44 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq GroundPlate_Battle_5
GroundPlate_Battle_1:
# 47 "data/maps/GroundPlate/scripts.pory"
	waitmessage
# 48 "data/maps/GroundPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/GroundPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/GroundPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_GROUND_PC1
# 52 "data/maps/GroundPlate/scripts.pory"
	releaseall
	return

GroundPlate_Battle_2:
# 36 "data/maps/GroundPlate/scripts.pory"
	call GroundPlateWonCatch
	goto GroundPlate_Battle_1

GroundPlate_Battle_3:
# 39 "data/maps/GroundPlate/scripts.pory"
	call GroundPlateWonCatch
	goto GroundPlate_Battle_1

GroundPlate_Battle_4:
# 42 "data/maps/GroundPlate/scripts.pory"
	call GroundPlateRun
	goto GroundPlate_Battle_1

GroundPlate_Battle_5:
# 45 "data/maps/GroundPlate/scripts.pory"
	call GroundPlateRun
	goto GroundPlate_Battle_1


GroundPlateWonCatch::
# 56 "data/maps/GroundPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/GroundPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/GroundPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/GroundPlate/scripts.pory"
	giveitem ITEM_EARTH_PLATE
# 61 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


GroundPlateRun::
# 67 "data/maps/GroundPlate/scripts.pory"
	playmoncry SPECIES_URSALUNA, CRY_MODE_ENCOUNTER
# 68 "data/maps/GroundPlate/scripts.pory"
	waitmoncry
	return


GroundPlate_IsGemCollected::
# 73 "data/maps/GroundPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GROUND_GEM, GroundPlate_IsGemCollected_2
# 77 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
GroundPlate_IsGemCollected_1:
	return

GroundPlate_IsGemCollected_2:
# 74 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto GroundPlate_IsGemCollected_1


GroundPlate_CollectGem::
# 83 "data/maps/GroundPlate/scripts.pory"
	lockall
# 84 "data/maps/GroundPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_GROUND_GEM, GroundPlate_CollectGem_2
# 88 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/GroundPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GroundPlate_CollectGem_5
GroundPlate_CollectGem_1:
# 98 "data/maps/GroundPlate/scripts.pory"
	releaseall
	return

GroundPlate_CollectGem_2:
# 85 "data/maps/GroundPlate/scripts.pory"
	msgbox GroundPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto GroundPlate_CollectGem_1

GroundPlate_CollectGem_5:
# 90 "data/maps/GroundPlate/scripts.pory"
	giveitem ITEM_GROUND_GEM
# 91 "data/maps/GroundPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_GROUND_GEM
# 92 "data/maps/GroundPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/GroundPlate/scripts.pory"
	warp MAP_GROUND_PLATE, 7, 20
# 94 "data/maps/GroundPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/GroundPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto GroundPlate_CollectGem_1


GroundPlateWonCatch_Text_0:
# 59 "data/maps/GroundPlate/scripts.pory"
	.string "The Ursaluna dissapeared in to th\ncave.$"

GroundPlateWonCatch_Text_1:
# 61 "data/maps/GroundPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

GroundPlateWonCatch_Text_2:
# 62 "data/maps/GroundPlate/scripts.pory"
	.string "When the universe was created, it's\nshards became this Plate.$"

GroundPlate_CollectGem_Text_0:
# 85 "data/maps/GroundPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

GroundPlate_CollectGem_Text_1:
# 88 "data/maps/GroundPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
