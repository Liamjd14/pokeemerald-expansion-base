WildArea2Grotto_MapScripts::
# 2 "data/maps/WildArea2Grotto/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, WA2GOnTransition
	.byte 0


WA2GOnTransition::
# 6 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GDecideSpawn
	return


WA2GDecideSpawn::
# 10 "data/maps/WildArea2Grotto/scripts.pory"
	goto_if_unset FLAG_OCEANVIEW_GROTTO, WA2GDecideSpawn_2
WA2GDecideSpawn_1:
# 50 "data/maps/WildArea2Grotto/scripts.pory"
	releaseall
	return

WA2GDecideSpawn_2:
# 11 "data/maps/WildArea2Grotto/scripts.pory"
	random 11
# 12 "data/maps/WildArea2Grotto/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 13 "data/maps/WildArea2Grotto/scripts.pory"
	switch VAR_TEMP_1
# 15 "data/maps/WildArea2Grotto/scripts.pory"
	case 0, WA2GDecideSpawn_5
# 18 "data/maps/WildArea2Grotto/scripts.pory"
	case 1, WA2GDecideSpawn_6
# 21 "data/maps/WildArea2Grotto/scripts.pory"
	case 2, WA2GDecideSpawn_7
# 24 "data/maps/WildArea2Grotto/scripts.pory"
	case 3, WA2GDecideSpawn_8
# 27 "data/maps/WildArea2Grotto/scripts.pory"
	case 4, WA2GDecideSpawn_9
# 30 "data/maps/WildArea2Grotto/scripts.pory"
	case 5, WA2GDecideSpawn_10
# 33 "data/maps/WildArea2Grotto/scripts.pory"
	case 6, WA2GDecideSpawn_11
# 36 "data/maps/WildArea2Grotto/scripts.pory"
	case 7, WA2GDecideSpawn_12
# 39 "data/maps/WildArea2Grotto/scripts.pory"
	case 8, WA2GDecideSpawn_13
# 42 "data/maps/WildArea2Grotto/scripts.pory"
	case 9, WA2GDecideSpawn_14
# 45 "data/maps/WildArea2Grotto/scripts.pory"
	case 10, WA2GDecideSpawn_15
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_5:
# 16 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( BULBASAUR )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_6:
# 19 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( CHARMANDER )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_7:
# 22 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SQUIRTLE )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_8:
# 25 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PIKACHU )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_9:
# 28 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SANDSHREW )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_10:
# 31 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( NIDORAN_F )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_11:
# 34 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( JIGGLYPUFF )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_12:
# 37 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( ODDISH )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_13:
# 40 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PARAS )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_14:
# 43 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( VENONAT )
	goto WA2GDecideSpawn_1

WA2GDecideSpawn_15:
# 46 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_TEMP_2, ITEM_POKE_BALL
# 47 "data/maps/WildArea2Grotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	goto WA2GDecideSpawn_1


WA2GTypeToUse::
# 54 "data/maps/WildArea2Grotto/scripts.pory"
	lockall
# 55 "data/maps/WildArea2Grotto/scripts.pory"
	switch VAR_TEMP_1
# 57 "data/maps/WildArea2Grotto/scripts.pory"
	case 0, WA2GTypeToUse_3
# 60 "data/maps/WildArea2Grotto/scripts.pory"
	case 1, WA2GTypeToUse_4
# 63 "data/maps/WildArea2Grotto/scripts.pory"
	case 2, WA2GTypeToUse_5
# 66 "data/maps/WildArea2Grotto/scripts.pory"
	case 3, WA2GTypeToUse_6
# 69 "data/maps/WildArea2Grotto/scripts.pory"
	case 4, WA2GTypeToUse_7
# 72 "data/maps/WildArea2Grotto/scripts.pory"
	case 5, WA2GTypeToUse_8
# 75 "data/maps/WildArea2Grotto/scripts.pory"
	case 6, WA2GTypeToUse_9
# 78 "data/maps/WildArea2Grotto/scripts.pory"
	case 7, WA2GTypeToUse_10
# 81 "data/maps/WildArea2Grotto/scripts.pory"
	case 8, WA2GTypeToUse_11
# 84 "data/maps/WildArea2Grotto/scripts.pory"
	case 9, WA2GTypeToUse_12
# 87 "data/maps/WildArea2Grotto/scripts.pory"
	case 10, WA2GTypeToUse_13
WA2GTypeToUse_1:
# 90 "data/maps/WildArea2Grotto/scripts.pory"
	releaseall
	return

WA2GTypeToUse_3:
# 58 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_4:
# 61 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_5:
# 64 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_6:
# 67 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_7:
# 70 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_8:
# 73 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_9:
# 76 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_10:
# 79 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_11:
# 82 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_12:
# 85 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GPokemonScript
	goto WA2GTypeToUse_1

WA2GTypeToUse_13:
# 88 "data/maps/WildArea2Grotto/scripts.pory"
	goto WA2GItemScript
	goto WA2GTypeToUse_1


WA2GItemScript::
# 94 "data/maps/WildArea2Grotto/scripts.pory"
	giveitem VAR_TEMP_2, 1
# 95 "data/maps/WildArea2Grotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 96 "data/maps/WildArea2Grotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 97 "data/maps/WildArea2Grotto/scripts.pory"
	releaseall
	return


WA2GPokemonScript::
# 101 "data/maps/WildArea2Grotto/scripts.pory"
	switch VAR_TEMP_1
# 103 "data/maps/WildArea2Grotto/scripts.pory"
	case 0, WA2GPokemonScript_3
# 107 "data/maps/WildArea2Grotto/scripts.pory"
	case 1, WA2GPokemonScript_4
# 111 "data/maps/WildArea2Grotto/scripts.pory"
	case 2, WA2GPokemonScript_5
# 115 "data/maps/WildArea2Grotto/scripts.pory"
	case 3, WA2GPokemonScript_6
# 119 "data/maps/WildArea2Grotto/scripts.pory"
	case 4, WA2GPokemonScript_7
# 123 "data/maps/WildArea2Grotto/scripts.pory"
	case 5, WA2GPokemonScript_8
# 127 "data/maps/WildArea2Grotto/scripts.pory"
	case 6, WA2GPokemonScript_9
# 131 "data/maps/WildArea2Grotto/scripts.pory"
	case 7, WA2GPokemonScript_10
# 135 "data/maps/WildArea2Grotto/scripts.pory"
	case 8, WA2GPokemonScript_11
# 139 "data/maps/WildArea2Grotto/scripts.pory"
	case 9, WA2GPokemonScript_12
WA2GPokemonScript_1:
# 143 "data/maps/WildArea2Grotto/scripts.pory"
	dowildbattle
# 144 "data/maps/WildArea2Grotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 145 "data/maps/WildArea2Grotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 146 "data/maps/WildArea2Grotto/scripts.pory"
	releaseall
	return

WA2GPokemonScript_3:
# 104 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
# 105 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_BULBASAUR, 5
	goto WA2GPokemonScript_1

WA2GPokemonScript_4:
# 108 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_ENCOUNTER
# 109 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_CHARMANDER, 5
	goto WA2GPokemonScript_1

WA2GPokemonScript_5:
# 112 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
# 113 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_SQUIRTLE, 5
	goto WA2GPokemonScript_1

WA2GPokemonScript_6:
# 116 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
# 117 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_PIKACHU, 5
	goto WA2GPokemonScript_1

WA2GPokemonScript_7:
# 120 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_SANDSHREW, CRY_MODE_ENCOUNTER
# 121 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_SANDSHREW, 5
	goto WA2GPokemonScript_1

WA2GPokemonScript_8:
# 124 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_ENCOUNTER
# 125 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_NIDORAN_F, 5
	goto WA2GPokemonScript_1

WA2GPokemonScript_9:
# 128 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_ENCOUNTER
# 129 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_JIGGLYPUFF, 5
	goto WA2GPokemonScript_1

WA2GPokemonScript_10:
# 132 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_ODDISH, CRY_MODE_ENCOUNTER
# 133 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_ODDISH, 5
	goto WA2GPokemonScript_1

WA2GPokemonScript_11:
# 136 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 137 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_PARAS, 5
	goto WA2GPokemonScript_1

WA2GPokemonScript_12:
# 140 "data/maps/WildArea2Grotto/scripts.pory"
	playmoncry SPECIES_VENONAT, CRY_MODE_ENCOUNTER
# 141 "data/maps/WildArea2Grotto/scripts.pory"
	setwildbattle SPECIES_VENONAT, 5
	goto WA2GPokemonScript_1

