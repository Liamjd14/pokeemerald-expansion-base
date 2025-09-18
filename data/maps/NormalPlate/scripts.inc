NormalPlate_MapScripts::
# 2 "data/maps/NormalPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NormalPlate_OnLoad
	.byte 0


NormalPlate_OnLoad::
# 6 "data/maps/NormalPlate/scripts.pory"
	call_if_unset FLAG_NORMAL_PC, NormalPlate_Entrance
# 7 "data/maps/NormalPlate/scripts.pory"
	call NormalPlate_IsGemCollected
	end


NormalPlate_Entrance::
# 12 "data/maps/NormalPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/NormalPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/NormalPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/NormalPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/NormalPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/NormalPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


NormalPlate_Battle::
# 22 "data/maps/NormalPlate/scripts.pory"
	lockall
# 23 "data/maps/NormalPlate/scripts.pory"
	playmoncry SPECIES_WYRDEER, CRY_MODE_ENCOUNTER
# 24 "data/maps/NormalPlate/scripts.pory"
	delay 40
# 25 "data/maps/NormalPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/NormalPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_WYRDEER, 50, [ ITEM_NORMAL_GEM ], , NATURE_MODEST, 0, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_UPROAR ], [ MOVE_PSYSHOCK ], [ MOVE_SHADOW_BALL ], [ MOVE_EARTH_POWER ]
# 28 "data/maps/NormalPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 29 "data/maps/NormalPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/NormalPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/NormalPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/NormalPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/NormalPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/NormalPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq NormalPlate_Battle_2
# 38 "data/maps/NormalPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NormalPlate_Battle_3
# 41 "data/maps/NormalPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NormalPlate_Battle_4
# 44 "data/maps/NormalPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NormalPlate_Battle_5
NormalPlate_Battle_1:
# 47 "data/maps/NormalPlate/scripts.pory"
	waitmessage
# 48 "data/maps/NormalPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/NormalPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/NormalPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/NormalPlate/scripts.pory"
	setflag FLAG_NORMAL_PC1
# 52 "data/maps/NormalPlate/scripts.pory"
	releaseall
	return

NormalPlate_Battle_2:
# 36 "data/maps/NormalPlate/scripts.pory"
	call NormalPlateWonCatch
	goto NormalPlate_Battle_1

NormalPlate_Battle_3:
# 39 "data/maps/NormalPlate/scripts.pory"
	call NormalPlateWonCatch
	goto NormalPlate_Battle_1

NormalPlate_Battle_4:
# 42 "data/maps/NormalPlate/scripts.pory"
	call NormalPlateRun
	goto NormalPlate_Battle_1

NormalPlate_Battle_5:
# 45 "data/maps/NormalPlate/scripts.pory"
	call NormalPlateRun
	goto NormalPlate_Battle_1


NormalPlateWonCatch::
# 56 "data/maps/NormalPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/NormalPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/NormalPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/NormalPlate/scripts.pory"
	msgbox NormalPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/NormalPlate/scripts.pory"
	giveitem ITEM_BLANK_PLATE
# 61 "data/maps/NormalPlate/scripts.pory"
	msgbox NormalPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/NormalPlate/scripts.pory"
	msgbox NormalPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


NormalPlateRun::
# 67 "data/maps/NormalPlate/scripts.pory"
	playmoncry SPECIES_WYRDEER, CRY_MODE_ENCOUNTER
# 68 "data/maps/NormalPlate/scripts.pory"
	waitmoncry
	return


NormalPlate_IsGemCollected::
# 73 "data/maps/NormalPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_NORMAL_GEM, NormalPlate_IsGemCollected_2
# 77 "data/maps/NormalPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
NormalPlate_IsGemCollected_1:
	return

NormalPlate_IsGemCollected_2:
# 74 "data/maps/NormalPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto NormalPlate_IsGemCollected_1


NormalPlate_CollectGem::
# 83 "data/maps/NormalPlate/scripts.pory"
	lockall
# 84 "data/maps/NormalPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_NORMAL_GEM, NormalPlate_CollectGem_2
# 88 "data/maps/NormalPlate/scripts.pory"
	msgbox NormalPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/NormalPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq NormalPlate_CollectGem_5
NormalPlate_CollectGem_1:
# 98 "data/maps/NormalPlate/scripts.pory"
	releaseall
	return

NormalPlate_CollectGem_2:
# 85 "data/maps/NormalPlate/scripts.pory"
	msgbox NormalPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto NormalPlate_CollectGem_1

NormalPlate_CollectGem_5:
# 90 "data/maps/NormalPlate/scripts.pory"
	giveitem ITEM_NORMAL_GEM
# 91 "data/maps/NormalPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_NORMAL_GEM
# 92 "data/maps/NormalPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/NormalPlate/scripts.pory"
	warp MAP_NORMAL_PLATE, 7, 20
# 94 "data/maps/NormalPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/NormalPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto NormalPlate_CollectGem_1


NormalPlateWonCatch_Text_0:
# 59 "data/maps/NormalPlate/scripts.pory"
	.string "The Wyrdeer dissapeared in to the cave.$"

NormalPlateWonCatch_Text_1:
# 61 "data/maps/NormalPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

NormalPlateWonCatch_Text_2:
# 62 "data/maps/NormalPlate/scripts.pory"
	.string "Three beings whose power can hold both\ntime and space fixed.$"

NormalPlate_CollectGem_Text_0:
# 85 "data/maps/NormalPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

NormalPlate_CollectGem_Text_1:
# 88 "data/maps/NormalPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
