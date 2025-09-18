NormalPlate_MapScripts::
# 2 "data/maps/NormalPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NormalPlate_OnLoad
	.byte 0


NormalPlate_OnLoad::
# 6 "data/maps/NormalPlate/scripts.pory"
	call_if_unset FLAG_HIDDEN_ITEM_ROCK_TERA_SHARD, NormalPlate_Entrance
	end


NormalPlate_Entrance::
# 11 "data/maps/NormalPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 12 "data/maps/NormalPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/NormalPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/NormalPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 15 "data/maps/NormalPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/NormalPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


NormalPlate_Battle::
# 21 "data/maps/NormalPlate/scripts.pory"
	lockall
# 22 "data/maps/NormalPlate/scripts.pory"
	playmoncry SPECIES_WYRDEER, CRY_MODE_ENCOUNTER
# 23 "data/maps/NormalPlate/scripts.pory"
	delay 40
# 24 "data/maps/NormalPlate/scripts.pory"
	waitmoncry
# 26 "data/maps/NormalPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_WYRDEER, 50, [ ITEM_NORMAL_GEM ], , , 0, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_UPROAR ], [ MOVE_PSYSHOCK ], [ MOVE_SHADOW_BALL ], [ MOVE_EARTH_POWER ]
# 27 "data/maps/NormalPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 28 "data/maps/NormalPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 29 "data/maps/NormalPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 30 "data/maps/NormalPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 32 "data/maps/NormalPlate/scripts.pory"
	dowildbattle
# 33 "data/maps/NormalPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 34 "data/maps/NormalPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq NormalPlate_Battle_2
# 37 "data/maps/NormalPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NormalPlate_Battle_3
# 40 "data/maps/NormalPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NormalPlate_Battle_4
# 43 "data/maps/NormalPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NormalPlate_Battle_5
NormalPlate_Battle_1:
# 46 "data/maps/NormalPlate/scripts.pory"
	waitmessage
# 47 "data/maps/NormalPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 48 "data/maps/NormalPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 49 "data/maps/NormalPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 50 "data/maps/NormalPlate/scripts.pory"
	releaseall
	return

NormalPlate_Battle_2:
# 35 "data/maps/NormalPlate/scripts.pory"
	call NormalPlateWonCatch
	goto NormalPlate_Battle_1

NormalPlate_Battle_3:
# 38 "data/maps/NormalPlate/scripts.pory"
	call NormalPlateWonCatch
	goto NormalPlate_Battle_1

NormalPlate_Battle_4:
# 41 "data/maps/NormalPlate/scripts.pory"
	call NormalPlateRun
	goto NormalPlate_Battle_1

NormalPlate_Battle_5:
# 44 "data/maps/NormalPlate/scripts.pory"
	call NormalPlateRun
	goto NormalPlate_Battle_1


NormalPlateWonCatch::
# 54 "data/maps/NormalPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 55 "data/maps/NormalPlate/scripts.pory"
	removeobject 1
# 56 "data/maps/NormalPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 57 "data/maps/NormalPlate/scripts.pory"
	msgbox NormalPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 58 "data/maps/NormalPlate/scripts.pory"
	giveitem ITEM_BLANK_PLATE
# 59 "data/maps/NormalPlate/scripts.pory"
	msgbox NormalPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
	return


NormalPlateRun::
# 64 "data/maps/NormalPlate/scripts.pory"
	playmoncry SPECIES_WYRDEER, CRY_MODE_ENCOUNTER
# 65 "data/maps/NormalPlate/scripts.pory"
	waitmoncry
	return


NormalPlateWonCatch_Text_0:
# 57 "data/maps/NormalPlate/scripts.pory"
	.string "The Wyrdeer dissapeared in to the cave.$"

NormalPlateWonCatch_Text_1:
# 59 "data/maps/NormalPlate/scripts.pory"
	.string "Three beings whose power can hold both\n time and space fixed.$"
