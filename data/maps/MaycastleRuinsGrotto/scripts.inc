MaycastleRuinsGrotto_MapScripts::
# 2 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MRGOnTransition
	.byte 0


MRGOnTransition::
# 6 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGDecideSpawn
	return


MRGDecideSpawn::
# 10 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto_if_unset FLAG_OCEANVIEW_GROTTO, MRGDecideSpawn_2
MRGDecideSpawn_1:
# 50 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	releaseall
	return

MRGDecideSpawn_2:
# 11 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	random 11
# 12 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 13 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	switch VAR_TEMP_1
# 15 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 0, MRGDecideSpawn_5
# 18 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 1, MRGDecideSpawn_6
# 21 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 2, MRGDecideSpawn_7
# 24 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 3, MRGDecideSpawn_8
# 27 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 4, MRGDecideSpawn_9
# 30 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 5, MRGDecideSpawn_10
# 33 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 6, MRGDecideSpawn_11
# 36 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 7, MRGDecideSpawn_12
# 39 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 8, MRGDecideSpawn_13
# 42 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 9, MRGDecideSpawn_14
# 45 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 10, MRGDecideSpawn_15
	goto MRGDecideSpawn_1

MRGDecideSpawn_5:
# 16 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( BULBASAUR ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_6:
# 19 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( CHARMANDER ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_7:
# 22 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SQUIRTLE ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_8:
# 25 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PIKACHU ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_9:
# 28 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SANDSHREW ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_10:
# 31 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( NIDORAN_F ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_11:
# 34 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( JIGGLYPUFF ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_12:
# 37 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( ODDISH ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_13:
# 40 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PARAS ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_14:
# 43 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( VENONAT ), FALSE
	goto MRGDecideSpawn_1

MRGDecideSpawn_15:
# 46 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_TEMP_2, ITEM_POKE_BALL
# 47 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	goto MRGDecideSpawn_1


MRGTypeToUse::
# 54 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	lockall
# 55 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	switch VAR_TEMP_1
# 57 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 0, MRGTypeToUse_3
# 60 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 1, MRGTypeToUse_4
# 63 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 2, MRGTypeToUse_5
# 66 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 3, MRGTypeToUse_6
# 69 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 4, MRGTypeToUse_7
# 72 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 5, MRGTypeToUse_8
# 75 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 6, MRGTypeToUse_9
# 78 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 7, MRGTypeToUse_10
# 81 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 8, MRGTypeToUse_11
# 84 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 9, MRGTypeToUse_12
# 87 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 10, MRGTypeToUse_13
MRGTypeToUse_1:
# 90 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	releaseall
	return

MRGTypeToUse_3:
# 58 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_4:
# 61 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_5:
# 64 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_6:
# 67 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_7:
# 70 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_8:
# 73 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_9:
# 76 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_10:
# 79 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_11:
# 82 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_12:
# 85 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGPokemonScript
	goto MRGTypeToUse_1

MRGTypeToUse_13:
# 88 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	goto MRGItemScript
	goto MRGTypeToUse_1


MRGItemScript::
# 94 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	giveitem VAR_TEMP_2, 1
# 95 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 96 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 97 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	releaseall
	return


MRGPokemonScript::
# 101 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	switch VAR_TEMP_1
# 103 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 0, MRGPokemonScript_3
# 107 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 1, MRGPokemonScript_4
# 111 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 2, MRGPokemonScript_5
# 115 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 3, MRGPokemonScript_6
# 119 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 4, MRGPokemonScript_7
# 123 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 5, MRGPokemonScript_8
# 127 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 6, MRGPokemonScript_9
# 131 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 7, MRGPokemonScript_10
# 135 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 8, MRGPokemonScript_11
# 139 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	case 9, MRGPokemonScript_12
MRGPokemonScript_1:
# 143 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	dowildbattle
# 144 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 145 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 146 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	releaseall
	return

MRGPokemonScript_3:
# 104 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
# 105 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_BULBASAUR, 5
	goto MRGPokemonScript_1

MRGPokemonScript_4:
# 108 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_ENCOUNTER
# 109 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_CHARMANDER, 5
	goto MRGPokemonScript_1

MRGPokemonScript_5:
# 112 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
# 113 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_SQUIRTLE, 5
	goto MRGPokemonScript_1

MRGPokemonScript_6:
# 116 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
# 117 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_PIKACHU, 5
	goto MRGPokemonScript_1

MRGPokemonScript_7:
# 120 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_SANDSHREW, CRY_MODE_ENCOUNTER
# 121 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_SANDSHREW, 5
	goto MRGPokemonScript_1

MRGPokemonScript_8:
# 124 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_ENCOUNTER
# 125 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_NIDORAN_F, 5
	goto MRGPokemonScript_1

MRGPokemonScript_9:
# 128 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_ENCOUNTER
# 129 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_JIGGLYPUFF, 5
	goto MRGPokemonScript_1

MRGPokemonScript_10:
# 132 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_ODDISH, CRY_MODE_ENCOUNTER
# 133 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_ODDISH, 5
	goto MRGPokemonScript_1

MRGPokemonScript_11:
# 136 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 137 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_PARAS, 5
	goto MRGPokemonScript_1

MRGPokemonScript_12:
# 140 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	playmoncry SPECIES_VENONAT, CRY_MODE_ENCOUNTER
# 141 "data/maps/MaycastleRuinsGrotto/scripts.pory"
	setwildbattle SPECIES_VENONAT, 5
	goto MRGPokemonScript_1

