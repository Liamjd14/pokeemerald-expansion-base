FairyPlate_MapScripts::
# 2 "data/maps/FairyPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FairyPlate_OnLoad
	.byte 0


FairyPlate_OnLoad::
# 6 "data/maps/FairyPlate/scripts.pory"
	call_if_unset FLAG_FAIRY_PC, FairyPlate_Entrance
# 7 "data/maps/FairyPlate/scripts.pory"
	call FairyPlate_IsGemCollected
	end


FairyPlate_Entrance::
# 12 "data/maps/FairyPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 13 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/FairyPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/FairyPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 16 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/FairyPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


FairyPlate_Battle::
# 22 "data/maps/FairyPlate/scripts.pory"
	lockall
# 23 "data/maps/FairyPlate/scripts.pory"
	playmoncry SPECIES_TOGEKISS, CRY_MODE_ENCOUNTER
# 24 "data/maps/FairyPlate/scripts.pory"
	delay 40
# 25 "data/maps/FairyPlate/scripts.pory"
	waitmoncry
# 27 "data/maps/FairyPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_TOGEKISS, 50, [ ITEM_FAIRY_GEM ], , NATURE_TIMID, 1, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_AIR_SLASH ], [ MOVE_FLAMETHROWER ], [ MOVE_ANCIENT_POWER ], [ MOVE_ROOST ]
# 28 "data/maps/FairyPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 29 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 30 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 31 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 33 "data/maps/FairyPlate/scripts.pory"
	dowildbattle
# 34 "data/maps/FairyPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FairyPlate_Battle_2
# 38 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FairyPlate_Battle_3
# 41 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FairyPlate_Battle_4
# 44 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FairyPlate_Battle_5
FairyPlate_Battle_1:
# 47 "data/maps/FairyPlate/scripts.pory"
	waitmessage
# 48 "data/maps/FairyPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 49 "data/maps/FairyPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 50 "data/maps/FairyPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 51 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_FAIRY_PC1
# 52 "data/maps/FairyPlate/scripts.pory"
	releaseall
	return

FairyPlate_Battle_2:
# 36 "data/maps/FairyPlate/scripts.pory"
	call FairyPlateWonCatch
	goto FairyPlate_Battle_1

FairyPlate_Battle_3:
# 39 "data/maps/FairyPlate/scripts.pory"
	call FairyPlateWonCatch
	goto FairyPlate_Battle_1

FairyPlate_Battle_4:
# 42 "data/maps/FairyPlate/scripts.pory"
	call FairyPlateRun
	goto FairyPlate_Battle_1

FairyPlate_Battle_5:
# 45 "data/maps/FairyPlate/scripts.pory"
	call FairyPlateRun
	goto FairyPlate_Battle_1


FairyPlateWonCatch::
# 56 "data/maps/FairyPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/maps/FairyPlate/scripts.pory"
	removeobject 1
# 58 "data/maps/FairyPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 59 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 60 "data/maps/FairyPlate/scripts.pory"
	giveitem ITEM_PIXIE_PLATE
# 61 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 62 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


FairyPlateRun::
# 67 "data/maps/FairyPlate/scripts.pory"
	playmoncry SPECIES_TOGEKISS, CRY_MODE_ENCOUNTER
# 68 "data/maps/FairyPlate/scripts.pory"
	waitmoncry
	return


FairyPlate_IsGemCollected::
# 73 "data/maps/FairyPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FAIRY_GEM, FairyPlate_IsGemCollected_2
# 77 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
FairyPlate_IsGemCollected_1:
	return

FairyPlate_IsGemCollected_2:
# 74 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto FairyPlate_IsGemCollected_1


FairyPlate_CollectGem::
# 83 "data/maps/FairyPlate/scripts.pory"
	lockall
# 84 "data/maps/FairyPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FAIRY_GEM, FairyPlate_CollectGem_2
# 88 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlate_CollectGem_Text_1, MSGBOX_YESNO
# 89 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FairyPlate_CollectGem_5
FairyPlate_CollectGem_1:
# 98 "data/maps/FairyPlate/scripts.pory"
	releaseall
	return

FairyPlate_CollectGem_2:
# 85 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto FairyPlate_CollectGem_1

FairyPlate_CollectGem_5:
# 90 "data/maps/FairyPlate/scripts.pory"
	giveitem ITEM_FAIRY_GEM
# 91 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_FAIRY_GEM
# 92 "data/maps/FairyPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 93 "data/maps/FairyPlate/scripts.pory"
	warp MAP_FAIRY_PLATE, 7, 20
# 94 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 95 "data/maps/FairyPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto FairyPlate_CollectGem_1


FairyPlateWonCatch_Text_0:
# 59 "data/maps/FairyPlate/scripts.pory"
	.string "The Togekiss dissapeared in to the cave.$"

FairyPlateWonCatch_Text_1:
# 61 "data/maps/FairyPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

FairyPlateWonCatch_Text_2:
# 62 "data/maps/FairyPlate/scripts.pory"
	.string "The Original One is in all things. The\nOriginal One is nowhere at all.$"

FairyPlate_CollectGem_Text_0:
# 85 "data/maps/FairyPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

FairyPlate_CollectGem_Text_1:
# 88 "data/maps/FairyPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
