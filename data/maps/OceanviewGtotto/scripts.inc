OceanviewGtotto_MapScripts::
# 2 "data/maps/OceanviewGtotto/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OVGOnTransition
	.byte 0


OVGOnTransition::
# 6 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGDecideSpawn
	return


OVGDecideSpawn::
# 10 "data/maps/OceanviewGtotto/scripts.pory"
	goto_if_unset FLAG_OCEANVIEW_GROTTO, OVGDecideSpawn_2
OVGDecideSpawn_1:
# 50 "data/maps/OceanviewGtotto/scripts.pory"
	releaseall
	return

OVGDecideSpawn_2:
# 11 "data/maps/OceanviewGtotto/scripts.pory"
	random 11
# 12 "data/maps/OceanviewGtotto/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 13 "data/maps/OceanviewGtotto/scripts.pory"
	switch VAR_TEMP_1
# 15 "data/maps/OceanviewGtotto/scripts.pory"
	case 0, OVGDecideSpawn_5
# 18 "data/maps/OceanviewGtotto/scripts.pory"
	case 1, OVGDecideSpawn_6
# 21 "data/maps/OceanviewGtotto/scripts.pory"
	case 2, OVGDecideSpawn_7
# 24 "data/maps/OceanviewGtotto/scripts.pory"
	case 3, OVGDecideSpawn_8
# 27 "data/maps/OceanviewGtotto/scripts.pory"
	case 4, OVGDecideSpawn_9
# 30 "data/maps/OceanviewGtotto/scripts.pory"
	case 5, OVGDecideSpawn_10
# 33 "data/maps/OceanviewGtotto/scripts.pory"
	case 6, OVGDecideSpawn_11
# 36 "data/maps/OceanviewGtotto/scripts.pory"
	case 7, OVGDecideSpawn_12
# 39 "data/maps/OceanviewGtotto/scripts.pory"
	case 8, OVGDecideSpawn_13
# 42 "data/maps/OceanviewGtotto/scripts.pory"
	case 9, OVGDecideSpawn_14
# 45 "data/maps/OceanviewGtotto/scripts.pory"
	case 10, OVGDecideSpawn_15
	goto OVGDecideSpawn_1

OVGDecideSpawn_5:
# 16 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( BULBASAUR ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_6:
# 19 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( CHARMANDER ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_7:
# 22 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SQUIRTLE ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_8:
# 25 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PIKACHU ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_9:
# 28 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SANDSHREW ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_10:
# 31 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( NIDORAN_F ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_11:
# 34 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( JIGGLYPUFF ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_12:
# 37 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( ODDISH ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_13:
# 40 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PARAS ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_14:
# 43 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( VENONAT ), FALSE
	goto OVGDecideSpawn_1

OVGDecideSpawn_15:
# 46 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_TEMP_2, ITEM_POKE_BALL
# 47 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	goto OVGDecideSpawn_1


OVGTypeToUse::
# 54 "data/maps/OceanviewGtotto/scripts.pory"
	lockall
# 55 "data/maps/OceanviewGtotto/scripts.pory"
	switch VAR_TEMP_1
# 57 "data/maps/OceanviewGtotto/scripts.pory"
	case 0, OVGTypeToUse_3
# 60 "data/maps/OceanviewGtotto/scripts.pory"
	case 1, OVGTypeToUse_4
# 63 "data/maps/OceanviewGtotto/scripts.pory"
	case 2, OVGTypeToUse_5
# 66 "data/maps/OceanviewGtotto/scripts.pory"
	case 3, OVGTypeToUse_6
# 69 "data/maps/OceanviewGtotto/scripts.pory"
	case 4, OVGTypeToUse_7
# 72 "data/maps/OceanviewGtotto/scripts.pory"
	case 5, OVGTypeToUse_8
# 75 "data/maps/OceanviewGtotto/scripts.pory"
	case 6, OVGTypeToUse_9
# 78 "data/maps/OceanviewGtotto/scripts.pory"
	case 7, OVGTypeToUse_10
# 81 "data/maps/OceanviewGtotto/scripts.pory"
	case 8, OVGTypeToUse_11
# 84 "data/maps/OceanviewGtotto/scripts.pory"
	case 9, OVGTypeToUse_12
# 87 "data/maps/OceanviewGtotto/scripts.pory"
	case 10, OVGTypeToUse_13
OVGTypeToUse_1:
# 90 "data/maps/OceanviewGtotto/scripts.pory"
	releaseall
	return

OVGTypeToUse_3:
# 58 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_4:
# 61 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_5:
# 64 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_6:
# 67 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_7:
# 70 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_8:
# 73 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_9:
# 76 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_10:
# 79 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_11:
# 82 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_12:
# 85 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGPokemonScript
	goto OVGTypeToUse_1

OVGTypeToUse_13:
# 88 "data/maps/OceanviewGtotto/scripts.pory"
	goto OVGItemScript
	goto OVGTypeToUse_1


OVGItemScript::
# 94 "data/maps/OceanviewGtotto/scripts.pory"
	giveitem VAR_TEMP_2, 1
# 95 "data/maps/OceanviewGtotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 96 "data/maps/OceanviewGtotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 97 "data/maps/OceanviewGtotto/scripts.pory"
	releaseall
	return


OVGPokemonScript::
# 101 "data/maps/OceanviewGtotto/scripts.pory"
	switch VAR_TEMP_1
# 103 "data/maps/OceanviewGtotto/scripts.pory"
	case 0, OVGPokemonScript_3
# 107 "data/maps/OceanviewGtotto/scripts.pory"
	case 1, OVGPokemonScript_4
# 111 "data/maps/OceanviewGtotto/scripts.pory"
	case 2, OVGPokemonScript_5
# 115 "data/maps/OceanviewGtotto/scripts.pory"
	case 3, OVGPokemonScript_6
# 119 "data/maps/OceanviewGtotto/scripts.pory"
	case 4, OVGPokemonScript_7
# 123 "data/maps/OceanviewGtotto/scripts.pory"
	case 5, OVGPokemonScript_8
# 127 "data/maps/OceanviewGtotto/scripts.pory"
	case 6, OVGPokemonScript_9
# 131 "data/maps/OceanviewGtotto/scripts.pory"
	case 7, OVGPokemonScript_10
# 135 "data/maps/OceanviewGtotto/scripts.pory"
	case 8, OVGPokemonScript_11
# 139 "data/maps/OceanviewGtotto/scripts.pory"
	case 9, OVGPokemonScript_12
OVGPokemonScript_1:
# 143 "data/maps/OceanviewGtotto/scripts.pory"
	dowildbattle
# 144 "data/maps/OceanviewGtotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 145 "data/maps/OceanviewGtotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 146 "data/maps/OceanviewGtotto/scripts.pory"
	releaseall
	return

OVGPokemonScript_3:
# 104 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
# 105 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_BULBASAUR, 5
	goto OVGPokemonScript_1

OVGPokemonScript_4:
# 108 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_ENCOUNTER
# 109 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_CHARMANDER, 5
	goto OVGPokemonScript_1

OVGPokemonScript_5:
# 112 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
# 113 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_SQUIRTLE, 5
	goto OVGPokemonScript_1

OVGPokemonScript_6:
# 116 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
# 117 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_PIKACHU, 5
	goto OVGPokemonScript_1

OVGPokemonScript_7:
# 120 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_SANDSHREW, CRY_MODE_ENCOUNTER
# 121 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_SANDSHREW, 5
	goto OVGPokemonScript_1

OVGPokemonScript_8:
# 124 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_ENCOUNTER
# 125 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_NIDORAN_F, 5
	goto OVGPokemonScript_1

OVGPokemonScript_9:
# 128 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_ENCOUNTER
# 129 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_JIGGLYPUFF, 5
	goto OVGPokemonScript_1

OVGPokemonScript_10:
# 132 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_ODDISH, CRY_MODE_ENCOUNTER
# 133 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_ODDISH, 5
	goto OVGPokemonScript_1

OVGPokemonScript_11:
# 136 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 137 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_PARAS, 5
	goto OVGPokemonScript_1

OVGPokemonScript_12:
# 140 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_VENONAT, CRY_MODE_ENCOUNTER
# 141 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_VENONAT, 5
	goto OVGPokemonScript_1

