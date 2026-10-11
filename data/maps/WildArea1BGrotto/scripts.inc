WildArea1BGrotto_MapScripts::
# 2 "data/maps/WildArea1BGrotto/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, WA1BGOnTransition
	.byte 0


WA1BGOnTransition::
# 6 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGDecideSpawn
	return


WA1BGDecideSpawn::
# 10 "data/maps/WildArea1BGrotto/scripts.pory"
	goto_if_unset FLAG_OCEANVIEW_GROTTO, WA1BGDecideSpawn_2
WA1BGDecideSpawn_1:
# 50 "data/maps/WildArea1BGrotto/scripts.pory"
	releaseall
	return

WA1BGDecideSpawn_2:
# 11 "data/maps/WildArea1BGrotto/scripts.pory"
	random 11
# 12 "data/maps/WildArea1BGrotto/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 13 "data/maps/WildArea1BGrotto/scripts.pory"
	switch VAR_TEMP_1
# 15 "data/maps/WildArea1BGrotto/scripts.pory"
	case 0, WA1BGDecideSpawn_5
# 18 "data/maps/WildArea1BGrotto/scripts.pory"
	case 1, WA1BGDecideSpawn_6
# 21 "data/maps/WildArea1BGrotto/scripts.pory"
	case 2, WA1BGDecideSpawn_7
# 24 "data/maps/WildArea1BGrotto/scripts.pory"
	case 3, WA1BGDecideSpawn_8
# 27 "data/maps/WildArea1BGrotto/scripts.pory"
	case 4, WA1BGDecideSpawn_9
# 30 "data/maps/WildArea1BGrotto/scripts.pory"
	case 5, WA1BGDecideSpawn_10
# 33 "data/maps/WildArea1BGrotto/scripts.pory"
	case 6, WA1BGDecideSpawn_11
# 36 "data/maps/WildArea1BGrotto/scripts.pory"
	case 7, WA1BGDecideSpawn_12
# 39 "data/maps/WildArea1BGrotto/scripts.pory"
	case 8, WA1BGDecideSpawn_13
# 42 "data/maps/WildArea1BGrotto/scripts.pory"
	case 9, WA1BGDecideSpawn_14
# 45 "data/maps/WildArea1BGrotto/scripts.pory"
	case 10, WA1BGDecideSpawn_15
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_5:
# 16 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( BULBASAUR )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_6:
# 19 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( CHARMANDER )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_7:
# 22 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SQUIRTLE )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_8:
# 25 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PIKACHU )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_9:
# 28 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SANDSHREW )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_10:
# 31 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( NIDORAN_F )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_11:
# 34 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( JIGGLYPUFF )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_12:
# 37 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( ODDISH )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_13:
# 40 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PARAS )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_14:
# 43 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( VENONAT )
	goto WA1BGDecideSpawn_1

WA1BGDecideSpawn_15:
# 46 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_TEMP_2, ITEM_POKE_BALL
# 47 "data/maps/WildArea1BGrotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	goto WA1BGDecideSpawn_1


WA1BGTypeToUse::
# 54 "data/maps/WildArea1BGrotto/scripts.pory"
	lockall
# 55 "data/maps/WildArea1BGrotto/scripts.pory"
	switch VAR_TEMP_1
# 57 "data/maps/WildArea1BGrotto/scripts.pory"
	case 0, WA1BGTypeToUse_3
# 60 "data/maps/WildArea1BGrotto/scripts.pory"
	case 1, WA1BGTypeToUse_4
# 63 "data/maps/WildArea1BGrotto/scripts.pory"
	case 2, WA1BGTypeToUse_5
# 66 "data/maps/WildArea1BGrotto/scripts.pory"
	case 3, WA1BGTypeToUse_6
# 69 "data/maps/WildArea1BGrotto/scripts.pory"
	case 4, WA1BGTypeToUse_7
# 72 "data/maps/WildArea1BGrotto/scripts.pory"
	case 5, WA1BGTypeToUse_8
# 75 "data/maps/WildArea1BGrotto/scripts.pory"
	case 6, WA1BGTypeToUse_9
# 78 "data/maps/WildArea1BGrotto/scripts.pory"
	case 7, WA1BGTypeToUse_10
# 81 "data/maps/WildArea1BGrotto/scripts.pory"
	case 8, WA1BGTypeToUse_11
# 84 "data/maps/WildArea1BGrotto/scripts.pory"
	case 9, WA1BGTypeToUse_12
# 87 "data/maps/WildArea1BGrotto/scripts.pory"
	case 10, WA1BGTypeToUse_13
WA1BGTypeToUse_1:
# 90 "data/maps/WildArea1BGrotto/scripts.pory"
	releaseall
	return

WA1BGTypeToUse_3:
# 58 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_4:
# 61 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_5:
# 64 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_6:
# 67 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_7:
# 70 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_8:
# 73 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_9:
# 76 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_10:
# 79 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_11:
# 82 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_12:
# 85 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGPokemonScript
	goto WA1BGTypeToUse_1

WA1BGTypeToUse_13:
# 88 "data/maps/WildArea1BGrotto/scripts.pory"
	goto WA1BGItemScript
	goto WA1BGTypeToUse_1


WA1BGItemScript::
# 94 "data/maps/WildArea1BGrotto/scripts.pory"
	giveitem VAR_TEMP_2, 1
# 95 "data/maps/WildArea1BGrotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 96 "data/maps/WildArea1BGrotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 97 "data/maps/WildArea1BGrotto/scripts.pory"
	releaseall
	return


WA1BGPokemonScript::
# 101 "data/maps/WildArea1BGrotto/scripts.pory"
	switch VAR_TEMP_1
# 103 "data/maps/WildArea1BGrotto/scripts.pory"
	case 0, WA1BGPokemonScript_3
# 107 "data/maps/WildArea1BGrotto/scripts.pory"
	case 1, WA1BGPokemonScript_4
# 111 "data/maps/WildArea1BGrotto/scripts.pory"
	case 2, WA1BGPokemonScript_5
# 115 "data/maps/WildArea1BGrotto/scripts.pory"
	case 3, WA1BGPokemonScript_6
# 119 "data/maps/WildArea1BGrotto/scripts.pory"
	case 4, WA1BGPokemonScript_7
# 123 "data/maps/WildArea1BGrotto/scripts.pory"
	case 5, WA1BGPokemonScript_8
# 127 "data/maps/WildArea1BGrotto/scripts.pory"
	case 6, WA1BGPokemonScript_9
# 131 "data/maps/WildArea1BGrotto/scripts.pory"
	case 7, WA1BGPokemonScript_10
# 135 "data/maps/WildArea1BGrotto/scripts.pory"
	case 8, WA1BGPokemonScript_11
# 139 "data/maps/WildArea1BGrotto/scripts.pory"
	case 9, WA1BGPokemonScript_12
WA1BGPokemonScript_1:
# 143 "data/maps/WildArea1BGrotto/scripts.pory"
	dowildbattle
# 144 "data/maps/WildArea1BGrotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 145 "data/maps/WildArea1BGrotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 146 "data/maps/WildArea1BGrotto/scripts.pory"
	releaseall
	return

WA1BGPokemonScript_3:
# 104 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
# 105 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_BULBASAUR, 5
	goto WA1BGPokemonScript_1

WA1BGPokemonScript_4:
# 108 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_ENCOUNTER
# 109 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_CHARMANDER, 5
	goto WA1BGPokemonScript_1

WA1BGPokemonScript_5:
# 112 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
# 113 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_SQUIRTLE, 5
	goto WA1BGPokemonScript_1

WA1BGPokemonScript_6:
# 116 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
# 117 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_PIKACHU, 5
	goto WA1BGPokemonScript_1

WA1BGPokemonScript_7:
# 120 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_SANDSHREW, CRY_MODE_ENCOUNTER
# 121 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_SANDSHREW, 5
	goto WA1BGPokemonScript_1

WA1BGPokemonScript_8:
# 124 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_ENCOUNTER
# 125 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_NIDORAN_F, 5
	goto WA1BGPokemonScript_1

WA1BGPokemonScript_9:
# 128 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_ENCOUNTER
# 129 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_JIGGLYPUFF, 5
	goto WA1BGPokemonScript_1

WA1BGPokemonScript_10:
# 132 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_ODDISH, CRY_MODE_ENCOUNTER
# 133 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_ODDISH, 5
	goto WA1BGPokemonScript_1

WA1BGPokemonScript_11:
# 136 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 137 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_PARAS, 5
	goto WA1BGPokemonScript_1

WA1BGPokemonScript_12:
# 140 "data/maps/WildArea1BGrotto/scripts.pory"
	playmoncry SPECIES_VENONAT, CRY_MODE_ENCOUNTER
# 141 "data/maps/WildArea1BGrotto/scripts.pory"
	setwildbattle SPECIES_VENONAT, 5
	goto WA1BGPokemonScript_1

