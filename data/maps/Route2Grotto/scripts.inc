Route2Grotto_MapScripts::
# 2 "data/maps/Route2Grotto/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, R2GOnTransition
	.byte 0


R2GOnTransition::
# 6 "data/maps/Route2Grotto/scripts.pory"
	goto R2GDecideSpawn
	return


R2GDecideSpawn::
# 10 "data/maps/Route2Grotto/scripts.pory"
	goto_if_unset FLAG_OCEANVIEW_GROTTO, R2GDecideSpawn_2
R2GDecideSpawn_1:
# 50 "data/maps/Route2Grotto/scripts.pory"
	releaseall
	return

R2GDecideSpawn_2:
# 11 "data/maps/Route2Grotto/scripts.pory"
	random 11
# 12 "data/maps/Route2Grotto/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 13 "data/maps/Route2Grotto/scripts.pory"
	switch VAR_TEMP_1
# 15 "data/maps/Route2Grotto/scripts.pory"
	case 0, R2GDecideSpawn_5
# 18 "data/maps/Route2Grotto/scripts.pory"
	case 1, R2GDecideSpawn_6
# 21 "data/maps/Route2Grotto/scripts.pory"
	case 2, R2GDecideSpawn_7
# 24 "data/maps/Route2Grotto/scripts.pory"
	case 3, R2GDecideSpawn_8
# 27 "data/maps/Route2Grotto/scripts.pory"
	case 4, R2GDecideSpawn_9
# 30 "data/maps/Route2Grotto/scripts.pory"
	case 5, R2GDecideSpawn_10
# 33 "data/maps/Route2Grotto/scripts.pory"
	case 6, R2GDecideSpawn_11
# 36 "data/maps/Route2Grotto/scripts.pory"
	case 7, R2GDecideSpawn_12
# 39 "data/maps/Route2Grotto/scripts.pory"
	case 8, R2GDecideSpawn_13
# 42 "data/maps/Route2Grotto/scripts.pory"
	case 9, R2GDecideSpawn_14
# 45 "data/maps/Route2Grotto/scripts.pory"
	case 10, R2GDecideSpawn_15
	goto R2GDecideSpawn_1

R2GDecideSpawn_5:
# 16 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( BULBASAUR )
	goto R2GDecideSpawn_1

R2GDecideSpawn_6:
# 19 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( CHARMANDER )
	goto R2GDecideSpawn_1

R2GDecideSpawn_7:
# 22 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SQUIRTLE )
	goto R2GDecideSpawn_1

R2GDecideSpawn_8:
# 25 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PIKACHU )
	goto R2GDecideSpawn_1

R2GDecideSpawn_9:
# 28 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SANDSHREW )
	goto R2GDecideSpawn_1

R2GDecideSpawn_10:
# 31 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( NIDORAN_F )
	goto R2GDecideSpawn_1

R2GDecideSpawn_11:
# 34 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( JIGGLYPUFF )
	goto R2GDecideSpawn_1

R2GDecideSpawn_12:
# 37 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( ODDISH )
	goto R2GDecideSpawn_1

R2GDecideSpawn_13:
# 40 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PARAS )
	goto R2GDecideSpawn_1

R2GDecideSpawn_14:
# 43 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( VENONAT )
	goto R2GDecideSpawn_1

R2GDecideSpawn_15:
# 46 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_TEMP_2, ITEM_POKE_BALL
# 47 "data/maps/Route2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	goto R2GDecideSpawn_1


R2GTypeToUse::
# 54 "data/maps/Route2Grotto/scripts.pory"
	lockall
# 55 "data/maps/Route2Grotto/scripts.pory"
	switch VAR_TEMP_1
# 57 "data/maps/Route2Grotto/scripts.pory"
	case 0, R2GTypeToUse_3
# 60 "data/maps/Route2Grotto/scripts.pory"
	case 1, R2GTypeToUse_4
# 63 "data/maps/Route2Grotto/scripts.pory"
	case 2, R2GTypeToUse_5
# 66 "data/maps/Route2Grotto/scripts.pory"
	case 3, R2GTypeToUse_6
# 69 "data/maps/Route2Grotto/scripts.pory"
	case 4, R2GTypeToUse_7
# 72 "data/maps/Route2Grotto/scripts.pory"
	case 5, R2GTypeToUse_8
# 75 "data/maps/Route2Grotto/scripts.pory"
	case 6, R2GTypeToUse_9
# 78 "data/maps/Route2Grotto/scripts.pory"
	case 7, R2GTypeToUse_10
# 81 "data/maps/Route2Grotto/scripts.pory"
	case 8, R2GTypeToUse_11
# 84 "data/maps/Route2Grotto/scripts.pory"
	case 9, R2GTypeToUse_12
# 87 "data/maps/Route2Grotto/scripts.pory"
	case 10, R2GTypeToUse_13
R2GTypeToUse_1:
# 90 "data/maps/Route2Grotto/scripts.pory"
	releaseall
	return

R2GTypeToUse_3:
# 58 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_4:
# 61 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_5:
# 64 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_6:
# 67 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_7:
# 70 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_8:
# 73 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_9:
# 76 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_10:
# 79 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_11:
# 82 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_12:
# 85 "data/maps/Route2Grotto/scripts.pory"
	goto R2GPokemonScript
	goto R2GTypeToUse_1

R2GTypeToUse_13:
# 88 "data/maps/Route2Grotto/scripts.pory"
	goto R2GItemScript
	goto R2GTypeToUse_1


R2GItemScript::
# 94 "data/maps/Route2Grotto/scripts.pory"
	giveitem VAR_TEMP_2, 1
# 95 "data/maps/Route2Grotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 96 "data/maps/Route2Grotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 97 "data/maps/Route2Grotto/scripts.pory"
	releaseall
	return


R2GPokemonScript::
# 101 "data/maps/Route2Grotto/scripts.pory"
	switch VAR_TEMP_1
# 103 "data/maps/Route2Grotto/scripts.pory"
	case 0, R2GPokemonScript_3
# 107 "data/maps/Route2Grotto/scripts.pory"
	case 1, R2GPokemonScript_4
# 111 "data/maps/Route2Grotto/scripts.pory"
	case 2, R2GPokemonScript_5
# 115 "data/maps/Route2Grotto/scripts.pory"
	case 3, R2GPokemonScript_6
# 119 "data/maps/Route2Grotto/scripts.pory"
	case 4, R2GPokemonScript_7
# 123 "data/maps/Route2Grotto/scripts.pory"
	case 5, R2GPokemonScript_8
# 127 "data/maps/Route2Grotto/scripts.pory"
	case 6, R2GPokemonScript_9
# 131 "data/maps/Route2Grotto/scripts.pory"
	case 7, R2GPokemonScript_10
# 135 "data/maps/Route2Grotto/scripts.pory"
	case 8, R2GPokemonScript_11
# 139 "data/maps/Route2Grotto/scripts.pory"
	case 9, R2GPokemonScript_12
R2GPokemonScript_1:
# 143 "data/maps/Route2Grotto/scripts.pory"
	dowildbattle
# 144 "data/maps/Route2Grotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 145 "data/maps/Route2Grotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 146 "data/maps/Route2Grotto/scripts.pory"
	releaseall
	return

R2GPokemonScript_3:
# 104 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
# 105 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_BULBASAUR, 5
	goto R2GPokemonScript_1

R2GPokemonScript_4:
# 108 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_ENCOUNTER
# 109 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_CHARMANDER, 5
	goto R2GPokemonScript_1

R2GPokemonScript_5:
# 112 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
# 113 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_SQUIRTLE, 5
	goto R2GPokemonScript_1

R2GPokemonScript_6:
# 116 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
# 117 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_PIKACHU, 5
	goto R2GPokemonScript_1

R2GPokemonScript_7:
# 120 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_SANDSHREW, CRY_MODE_ENCOUNTER
# 121 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_SANDSHREW, 5
	goto R2GPokemonScript_1

R2GPokemonScript_8:
# 124 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_ENCOUNTER
# 125 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_NIDORAN_F, 5
	goto R2GPokemonScript_1

R2GPokemonScript_9:
# 128 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_ENCOUNTER
# 129 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_JIGGLYPUFF, 5
	goto R2GPokemonScript_1

R2GPokemonScript_10:
# 132 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_ODDISH, CRY_MODE_ENCOUNTER
# 133 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_ODDISH, 5
	goto R2GPokemonScript_1

R2GPokemonScript_11:
# 136 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 137 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_PARAS, 5
	goto R2GPokemonScript_1

R2GPokemonScript_12:
# 140 "data/maps/Route2Grotto/scripts.pory"
	playmoncry SPECIES_VENONAT, CRY_MODE_ENCOUNTER
# 141 "data/maps/Route2Grotto/scripts.pory"
	setwildbattle SPECIES_VENONAT, 5
	goto R2GPokemonScript_1

