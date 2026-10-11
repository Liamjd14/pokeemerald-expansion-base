Route5Grotto_MapScripts::
# 2 "data/maps/Route5Grotto/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, R5GOnTransition
	.byte 0


R5GOnTransition::
# 6 "data/maps/Route5Grotto/scripts.pory"
	goto R5GDecideSpawn
	return


R5GDecideSpawn::
# 10 "data/maps/Route5Grotto/scripts.pory"
	goto_if_unset FLAG_OCEANVIEW_GROTTO, R5GDecideSpawn_2
R5GDecideSpawn_1:
# 50 "data/maps/Route5Grotto/scripts.pory"
	releaseall
	return

R5GDecideSpawn_2:
# 11 "data/maps/Route5Grotto/scripts.pory"
	random 11
# 12 "data/maps/Route5Grotto/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 13 "data/maps/Route5Grotto/scripts.pory"
	switch VAR_TEMP_1
# 15 "data/maps/Route5Grotto/scripts.pory"
	case 0, R5GDecideSpawn_5
# 18 "data/maps/Route5Grotto/scripts.pory"
	case 1, R5GDecideSpawn_6
# 21 "data/maps/Route5Grotto/scripts.pory"
	case 2, R5GDecideSpawn_7
# 24 "data/maps/Route5Grotto/scripts.pory"
	case 3, R5GDecideSpawn_8
# 27 "data/maps/Route5Grotto/scripts.pory"
	case 4, R5GDecideSpawn_9
# 30 "data/maps/Route5Grotto/scripts.pory"
	case 5, R5GDecideSpawn_10
# 33 "data/maps/Route5Grotto/scripts.pory"
	case 6, R5GDecideSpawn_11
# 36 "data/maps/Route5Grotto/scripts.pory"
	case 7, R5GDecideSpawn_12
# 39 "data/maps/Route5Grotto/scripts.pory"
	case 8, R5GDecideSpawn_13
# 42 "data/maps/Route5Grotto/scripts.pory"
	case 9, R5GDecideSpawn_14
# 45 "data/maps/Route5Grotto/scripts.pory"
	case 10, R5GDecideSpawn_15
	goto R5GDecideSpawn_1

R5GDecideSpawn_5:
# 16 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( BULBASAUR )
	goto R5GDecideSpawn_1

R5GDecideSpawn_6:
# 19 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( CHARMANDER )
	goto R5GDecideSpawn_1

R5GDecideSpawn_7:
# 22 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SQUIRTLE )
	goto R5GDecideSpawn_1

R5GDecideSpawn_8:
# 25 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PIKACHU )
	goto R5GDecideSpawn_1

R5GDecideSpawn_9:
# 28 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SANDSHREW )
	goto R5GDecideSpawn_1

R5GDecideSpawn_10:
# 31 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( NIDORAN_F )
	goto R5GDecideSpawn_1

R5GDecideSpawn_11:
# 34 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( JIGGLYPUFF )
	goto R5GDecideSpawn_1

R5GDecideSpawn_12:
# 37 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( ODDISH )
	goto R5GDecideSpawn_1

R5GDecideSpawn_13:
# 40 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PARAS )
	goto R5GDecideSpawn_1

R5GDecideSpawn_14:
# 43 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( VENONAT )
	goto R5GDecideSpawn_1

R5GDecideSpawn_15:
# 46 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_TEMP_2, ITEM_POKE_BALL
# 47 "data/maps/Route5Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	goto R5GDecideSpawn_1


R5GTypeToUse::
# 54 "data/maps/Route5Grotto/scripts.pory"
	lockall
# 55 "data/maps/Route5Grotto/scripts.pory"
	switch VAR_TEMP_1
# 57 "data/maps/Route5Grotto/scripts.pory"
	case 0, R5GTypeToUse_3
# 60 "data/maps/Route5Grotto/scripts.pory"
	case 1, R5GTypeToUse_4
# 63 "data/maps/Route5Grotto/scripts.pory"
	case 2, R5GTypeToUse_5
# 66 "data/maps/Route5Grotto/scripts.pory"
	case 3, R5GTypeToUse_6
# 69 "data/maps/Route5Grotto/scripts.pory"
	case 4, R5GTypeToUse_7
# 72 "data/maps/Route5Grotto/scripts.pory"
	case 5, R5GTypeToUse_8
# 75 "data/maps/Route5Grotto/scripts.pory"
	case 6, R5GTypeToUse_9
# 78 "data/maps/Route5Grotto/scripts.pory"
	case 7, R5GTypeToUse_10
# 81 "data/maps/Route5Grotto/scripts.pory"
	case 8, R5GTypeToUse_11
# 84 "data/maps/Route5Grotto/scripts.pory"
	case 9, R5GTypeToUse_12
# 87 "data/maps/Route5Grotto/scripts.pory"
	case 10, R5GTypeToUse_13
R5GTypeToUse_1:
# 90 "data/maps/Route5Grotto/scripts.pory"
	releaseall
	return

R5GTypeToUse_3:
# 58 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_4:
# 61 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_5:
# 64 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_6:
# 67 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_7:
# 70 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_8:
# 73 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_9:
# 76 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_10:
# 79 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_11:
# 82 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_12:
# 85 "data/maps/Route5Grotto/scripts.pory"
	goto R5GPokemonScript
	goto R5GTypeToUse_1

R5GTypeToUse_13:
# 88 "data/maps/Route5Grotto/scripts.pory"
	goto R5GItemScript
	goto R5GTypeToUse_1


R5GItemScript::
# 94 "data/maps/Route5Grotto/scripts.pory"
	giveitem VAR_TEMP_2, 1
# 95 "data/maps/Route5Grotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 96 "data/maps/Route5Grotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 97 "data/maps/Route5Grotto/scripts.pory"
	releaseall
	return


R5GPokemonScript::
# 101 "data/maps/Route5Grotto/scripts.pory"
	switch VAR_TEMP_1
# 103 "data/maps/Route5Grotto/scripts.pory"
	case 0, R5GPokemonScript_3
# 107 "data/maps/Route5Grotto/scripts.pory"
	case 1, R5GPokemonScript_4
# 111 "data/maps/Route5Grotto/scripts.pory"
	case 2, R5GPokemonScript_5
# 115 "data/maps/Route5Grotto/scripts.pory"
	case 3, R5GPokemonScript_6
# 119 "data/maps/Route5Grotto/scripts.pory"
	case 4, R5GPokemonScript_7
# 123 "data/maps/Route5Grotto/scripts.pory"
	case 5, R5GPokemonScript_8
# 127 "data/maps/Route5Grotto/scripts.pory"
	case 6, R5GPokemonScript_9
# 131 "data/maps/Route5Grotto/scripts.pory"
	case 7, R5GPokemonScript_10
# 135 "data/maps/Route5Grotto/scripts.pory"
	case 8, R5GPokemonScript_11
# 139 "data/maps/Route5Grotto/scripts.pory"
	case 9, R5GPokemonScript_12
R5GPokemonScript_1:
# 143 "data/maps/Route5Grotto/scripts.pory"
	dowildbattle
# 144 "data/maps/Route5Grotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 145 "data/maps/Route5Grotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 146 "data/maps/Route5Grotto/scripts.pory"
	releaseall
	return

R5GPokemonScript_3:
# 104 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
# 105 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_BULBASAUR, 5
	goto R5GPokemonScript_1

R5GPokemonScript_4:
# 108 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_ENCOUNTER
# 109 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_CHARMANDER, 5
	goto R5GPokemonScript_1

R5GPokemonScript_5:
# 112 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
# 113 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_SQUIRTLE, 5
	goto R5GPokemonScript_1

R5GPokemonScript_6:
# 116 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
# 117 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_PIKACHU, 5
	goto R5GPokemonScript_1

R5GPokemonScript_7:
# 120 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_SANDSHREW, CRY_MODE_ENCOUNTER
# 121 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_SANDSHREW, 5
	goto R5GPokemonScript_1

R5GPokemonScript_8:
# 124 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_ENCOUNTER
# 125 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_NIDORAN_F, 5
	goto R5GPokemonScript_1

R5GPokemonScript_9:
# 128 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_ENCOUNTER
# 129 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_JIGGLYPUFF, 5
	goto R5GPokemonScript_1

R5GPokemonScript_10:
# 132 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_ODDISH, CRY_MODE_ENCOUNTER
# 133 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_ODDISH, 5
	goto R5GPokemonScript_1

R5GPokemonScript_11:
# 136 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 137 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_PARAS, 5
	goto R5GPokemonScript_1

R5GPokemonScript_12:
# 140 "data/maps/Route5Grotto/scripts.pory"
	playmoncry SPECIES_VENONAT, CRY_MODE_ENCOUNTER
# 141 "data/maps/Route5Grotto/scripts.pory"
	setwildbattle SPECIES_VENONAT, 5
	goto R5GPokemonScript_1

