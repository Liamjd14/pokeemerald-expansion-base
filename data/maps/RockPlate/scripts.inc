RockPlate_MapScripts::
# 2 "data/maps/RockPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, RockPlate_OnLoad
	.byte 0


RockPlate_OnLoad::
# 6 "data/maps/RockPlate/scripts.pory"
	call_if_unset FLAG_ROCK_PC, RockPlate_Entrance
# 7 "data/maps/RockPlate/scripts.pory"
	call RockPlate_IsGemCollected
	end


RockPlate_Entrance::
# 12 "data/maps/RockPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/RockPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/RockPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/RockPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/RockPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/RockPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


RockPlate_Battle::
# 22 "data/maps/RockPlate/scripts.pory"
	lockall
# 23 "data/maps/RockPlate/scripts.pory"
	playmoncry SPECIES_PROBOPASS, CRY_MODE_ENCOUNTER
# 24 "data/maps/RockPlate/scripts.pory"
	delay 40
# 25 "data/maps/RockPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/RockPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_PROBOPASS, 50, [ ITEM_ROCK_GEM ], , NATURE_MODEST, 2, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_DAZZLING_GLEAM ], [ MOVE_FLASH_CANNON ], [ MOVE_EARTH_POWER ], [ MOVE_POWER_GEM ]
# 28 "data/maps/RockPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 29 "data/maps/RockPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/RockPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/RockPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/RockPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/RockPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/RockPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq RockPlate_Battle_2
# 38 "data/maps/RockPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq RockPlate_Battle_3
# 41 "data/maps/RockPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq RockPlate_Battle_4
# 44 "data/maps/RockPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq RockPlate_Battle_5
RockPlate_Battle_1:
# 47 "data/maps/RockPlate/scripts.pory"
	waitmessage
# 48 "data/maps/RockPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/RockPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/RockPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/RockPlate/scripts.pory"
	setflag FLAG_ROCK_PC1
# 52 "data/maps/RockPlate/scripts.pory"
	releaseall
	return

RockPlate_Battle_2:
# 36 "data/maps/RockPlate/scripts.pory"
	call RockPlateWonCatch
	goto RockPlate_Battle_1

RockPlate_Battle_3:
# 39 "data/maps/RockPlate/scripts.pory"
	call RockPlateWonCatch
	goto RockPlate_Battle_1

RockPlate_Battle_4:
# 42 "data/maps/RockPlate/scripts.pory"
	call RockPlateRun
	goto RockPlate_Battle_1

RockPlate_Battle_5:
# 45 "data/maps/RockPlate/scripts.pory"
	call RockPlateRun
	goto RockPlate_Battle_1


RockPlateWonCatch::
# 56 "data/maps/RockPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/RockPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/RockPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/RockPlate/scripts.pory"
	msgbox RockPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/RockPlate/scripts.pory"
	giveitem ITEM_STONE_PLATE
# 61 "data/maps/RockPlate/scripts.pory"
	msgbox RockPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/RockPlate/scripts.pory"
	msgbox RockPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


RockPlateRun::
# 67 "data/maps/RockPlate/scripts.pory"
	playmoncry SPECIES_PROBOPASS, CRY_MODE_ENCOUNTER
# 68 "data/maps/RockPlate/scripts.pory"
	waitmoncry
	return


RockPlate_IsGemCollected::
# 73 "data/maps/RockPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ROCK_GEM, RockPlate_IsGemCollected_2
# 77 "data/maps/RockPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
RockPlate_IsGemCollected_1:
	return

RockPlate_IsGemCollected_2:
# 74 "data/maps/RockPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto RockPlate_IsGemCollected_1


RockPlate_CollectGem::
# 83 "data/maps/RockPlate/scripts.pory"
	lockall
# 84 "data/maps/RockPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_ROCK_GEM, RockPlate_CollectGem_2
# 88 "data/maps/RockPlate/scripts.pory"
	msgbox RockPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/RockPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq RockPlate_CollectGem_5
RockPlate_CollectGem_1:
# 98 "data/maps/RockPlate/scripts.pory"
	releaseall
	return

RockPlate_CollectGem_2:
# 85 "data/maps/RockPlate/scripts.pory"
	msgbox RockPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto RockPlate_CollectGem_1

RockPlate_CollectGem_5:
# 90 "data/maps/RockPlate/scripts.pory"
	giveitem ITEM_ROCK_GEM
# 91 "data/maps/RockPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_ROCK_GEM
# 92 "data/maps/RockPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/RockPlate/scripts.pory"
	warp MAP_ROCK_PLATE, 7, 20
# 94 "data/maps/RockPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/RockPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto RockPlate_CollectGem_1


RockPlateWonCatch_Text_0:
# 59 "data/maps/RockPlate/scripts.pory"
	.string "The Probopass dissapeared in to\nthe cave.$"

RockPlateWonCatch_Text_1:
# 61 "data/maps/RockPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

RockPlateWonCatch_Text_2:
# 62 "data/maps/RockPlate/scripts.pory"
	.string "It gathers power from the Plates,\nlistening for the flute's song.$"

RockPlate_CollectGem_Text_0:
# 85 "data/maps/RockPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

RockPlate_CollectGem_Text_1:
# 88 "data/maps/RockPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
