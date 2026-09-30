OceanviewGtotto_MapScripts::
# 2 "data/maps/OceanviewGtotto/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OVGOnTransition
	.byte 0


OVGOnTransition::
# 6 "data/maps/OceanviewGtotto/scripts.pory"
	goto DecideSpawn
	return


DecideSpawn::
# 10 "data/maps/OceanviewGtotto/scripts.pory"
	goto_if_unset FLAG_OCEANVIEW_GROTTO, DecideSpawn_2
DecideSpawn_1:
# 50 "data/maps/OceanviewGtotto/scripts.pory"
	releaseall
	return

DecideSpawn_2:
# 11 "data/maps/OceanviewGtotto/scripts.pory"
	random 11
# 12 "data/maps/OceanviewGtotto/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 13 "data/maps/OceanviewGtotto/scripts.pory"
	switch VAR_TEMP_1
# 15 "data/maps/OceanviewGtotto/scripts.pory"
	case 0, DecideSpawn_5
# 18 "data/maps/OceanviewGtotto/scripts.pory"
	case 1, DecideSpawn_6
# 21 "data/maps/OceanviewGtotto/scripts.pory"
	case 2, DecideSpawn_7
# 24 "data/maps/OceanviewGtotto/scripts.pory"
	case 3, DecideSpawn_8
# 27 "data/maps/OceanviewGtotto/scripts.pory"
	case 4, DecideSpawn_9
# 30 "data/maps/OceanviewGtotto/scripts.pory"
	case 5, DecideSpawn_10
# 33 "data/maps/OceanviewGtotto/scripts.pory"
	case 6, DecideSpawn_11
# 36 "data/maps/OceanviewGtotto/scripts.pory"
	case 7, DecideSpawn_12
# 39 "data/maps/OceanviewGtotto/scripts.pory"
	case 8, DecideSpawn_13
# 42 "data/maps/OceanviewGtotto/scripts.pory"
	case 9, DecideSpawn_14
# 45 "data/maps/OceanviewGtotto/scripts.pory"
	case 10, DecideSpawn_15
	goto DecideSpawn_1

DecideSpawn_5:
# 16 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( BULBASAUR )
	goto DecideSpawn_1

DecideSpawn_6:
# 19 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( CHARMANDER )
	goto DecideSpawn_1

DecideSpawn_7:
# 22 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SQUIRTLE )
	goto DecideSpawn_1

DecideSpawn_8:
# 25 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PIKACHU )
	goto DecideSpawn_1

DecideSpawn_9:
# 28 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SANDSHREW )
	goto DecideSpawn_1

DecideSpawn_10:
# 31 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( NIDORAN_F )
	goto DecideSpawn_1

DecideSpawn_11:
# 34 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( JIGGLYPUFF )
	goto DecideSpawn_1

DecideSpawn_12:
# 37 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( ODDISH )
	goto DecideSpawn_1

DecideSpawn_13:
# 40 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( PARAS )
	goto DecideSpawn_1

DecideSpawn_14:
# 43 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( VENONAT )
	goto DecideSpawn_1

DecideSpawn_15:
# 46 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_TEMP_2, ITEM_POKE_BALL
# 47 "data/maps/OceanviewGtotto/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	goto DecideSpawn_1


TypeToUse::
# 54 "data/maps/OceanviewGtotto/scripts.pory"
	lockall
# 55 "data/maps/OceanviewGtotto/scripts.pory"
	switch VAR_TEMP_1
# 57 "data/maps/OceanviewGtotto/scripts.pory"
	case 0, TypeToUse_3
# 60 "data/maps/OceanviewGtotto/scripts.pory"
	case 1, TypeToUse_4
# 63 "data/maps/OceanviewGtotto/scripts.pory"
	case 2, TypeToUse_5
# 66 "data/maps/OceanviewGtotto/scripts.pory"
	case 3, TypeToUse_6
# 69 "data/maps/OceanviewGtotto/scripts.pory"
	case 4, TypeToUse_7
# 72 "data/maps/OceanviewGtotto/scripts.pory"
	case 5, TypeToUse_8
# 75 "data/maps/OceanviewGtotto/scripts.pory"
	case 6, TypeToUse_9
# 78 "data/maps/OceanviewGtotto/scripts.pory"
	case 7, TypeToUse_10
# 81 "data/maps/OceanviewGtotto/scripts.pory"
	case 8, TypeToUse_11
# 84 "data/maps/OceanviewGtotto/scripts.pory"
	case 9, TypeToUse_12
# 87 "data/maps/OceanviewGtotto/scripts.pory"
	case 10, TypeToUse_13
TypeToUse_1:
# 90 "data/maps/OceanviewGtotto/scripts.pory"
	releaseall
	return

TypeToUse_3:
# 58 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_4:
# 61 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_5:
# 64 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_6:
# 67 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_7:
# 70 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_8:
# 73 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_9:
# 76 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_10:
# 79 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_11:
# 82 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_12:
# 85 "data/maps/OceanviewGtotto/scripts.pory"
	goto PokemonScript
	goto TypeToUse_1

TypeToUse_13:
# 88 "data/maps/OceanviewGtotto/scripts.pory"
	goto ItemScript
	goto TypeToUse_1


ItemScript::
# 94 "data/maps/OceanviewGtotto/scripts.pory"
	giveitem VAR_TEMP_2, 1
# 95 "data/maps/OceanviewGtotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 96 "data/maps/OceanviewGtotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 97 "data/maps/OceanviewGtotto/scripts.pory"
	releaseall
	return


PokemonScript::
# 101 "data/maps/OceanviewGtotto/scripts.pory"
	switch VAR_TEMP_1
# 103 "data/maps/OceanviewGtotto/scripts.pory"
	case 0, PokemonScript_3
# 107 "data/maps/OceanviewGtotto/scripts.pory"
	case 1, PokemonScript_4
# 111 "data/maps/OceanviewGtotto/scripts.pory"
	case 2, PokemonScript_5
# 115 "data/maps/OceanviewGtotto/scripts.pory"
	case 3, PokemonScript_6
# 119 "data/maps/OceanviewGtotto/scripts.pory"
	case 4, PokemonScript_7
# 123 "data/maps/OceanviewGtotto/scripts.pory"
	case 5, PokemonScript_8
# 127 "data/maps/OceanviewGtotto/scripts.pory"
	case 6, PokemonScript_9
# 131 "data/maps/OceanviewGtotto/scripts.pory"
	case 7, PokemonScript_10
# 135 "data/maps/OceanviewGtotto/scripts.pory"
	case 8, PokemonScript_11
# 139 "data/maps/OceanviewGtotto/scripts.pory"
	case 9, PokemonScript_12
PokemonScript_1:
# 143 "data/maps/OceanviewGtotto/scripts.pory"
	dowildbattle
# 144 "data/maps/OceanviewGtotto/scripts.pory"
	setflag FLAG_OCEANVIEW_GROTTO
# 145 "data/maps/OceanviewGtotto/scripts.pory"
	removeobject LOCALID_ENCAOUNTER
# 146 "data/maps/OceanviewGtotto/scripts.pory"
	releaseall
	return

PokemonScript_3:
# 104 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
# 105 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_BULBASAUR, 5
	goto PokemonScript_1

PokemonScript_4:
# 108 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_CHARMANDER, CRY_MODE_ENCOUNTER
# 109 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_CHARMANDER, 5
	goto PokemonScript_1

PokemonScript_5:
# 112 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_ENCOUNTER
# 113 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_SQUIRTLE, 5
	goto PokemonScript_1

PokemonScript_6:
# 116 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
# 117 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_PIKACHU, 5
	goto PokemonScript_1

PokemonScript_7:
# 120 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_SANDSHREW, CRY_MODE_ENCOUNTER
# 121 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_SANDSHREW, 5
	goto PokemonScript_1

PokemonScript_8:
# 124 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_ENCOUNTER
# 125 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_NIDORAN_F, 5
	goto PokemonScript_1

PokemonScript_9:
# 128 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_ENCOUNTER
# 129 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_JIGGLYPUFF, 5
	goto PokemonScript_1

PokemonScript_10:
# 132 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_ODDISH, CRY_MODE_ENCOUNTER
# 133 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_ODDISH, 5
	goto PokemonScript_1

PokemonScript_11:
# 136 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_PARAS, CRY_MODE_ENCOUNTER
# 137 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_PARAS, 5
	goto PokemonScript_1

PokemonScript_12:
# 140 "data/maps/OceanviewGtotto/scripts.pory"
	playmoncry SPECIES_VENONAT, CRY_MODE_ENCOUNTER
# 141 "data/maps/OceanviewGtotto/scripts.pory"
	setwildbattle SPECIES_VENONAT, 5
	goto PokemonScript_1

