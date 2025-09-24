FairyPlate_MapScripts::
# 2 "data/maps/FairyPlate/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FairyPlate_OnLoad
	.byte 0


FairyPlate_OnLoad::
# 6 "data/maps/FairyPlate/scripts.pory"
	call_if_unset FLAG_FAIRY_PC, FairyPlate_Entrance
# 7 "data/maps/FairyPlate/scripts.pory"
	call FairyPlate_IsGemCollected
# 8 "data/maps/FairyPlate/scripts.pory"
	call FairyPlate_ConditionCheck
	end


FairyPlate_Entrance::
# 13 "data/maps/FairyPlate/scripts.pory"
	setmetatile 6, 15, METATILE_Cave_EntranceCover, TRUE
# 14 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 15, METATILE_Cave_EntranceCover, TRUE
# 15 "data/maps/FairyPlate/scripts.pory"
	setmetatile 8, 15, METATILE_Cave_EntranceCover, TRUE
# 16 "data/maps/FairyPlate/scripts.pory"
	setmetatile 6, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 17 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 18 "data/maps/FairyPlate/scripts.pory"
	setmetatile 8, 16, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


FairyPlate_Battle::
# 23 "data/maps/FairyPlate/scripts.pory"
	lockall
# 24 "data/maps/FairyPlate/scripts.pory"
	playmoncry SPECIES_TOGEKISS, CRY_MODE_ENCOUNTER
# 25 "data/maps/FairyPlate/scripts.pory"
	delay 40
# 26 "data/maps/FairyPlate/scripts.pory"
	waitmoncry
# 28 "data/maps/FairyPlate/scripts.pory"
	createmon B_SIDE_OPPONENT, 0, SPECIES_TOGEKISS, 50, [ ITEM_FAIRY_GEM ], , NATURE_TIMID, 1, , 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, [ MOVE_AIR_SLASH ], [ MOVE_FLAMETHROWER ], [ MOVE_ANCIENT_POWER ], [ MOVE_ROOST ]
# 29 "data/maps/FairyPlate/scripts.pory"
	settotemboost B_BATTLER_1, 0, 0, 2, 2, 0, 1, 0
# 30 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_B_SMART_WILD_AI
# 31 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_B_NO_CATCHING
# 32 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_B_NO_BAG_USE
# 34 "data/maps/FairyPlate/scripts.pory"
	dowildbattle
# 35 "data/maps/FairyPlate/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FairyPlate_Battle_2
# 39 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FairyPlate_Battle_3
# 42 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FairyPlate_Battle_4
# 45 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FairyPlate_Battle_5
FairyPlate_Battle_1:
# 48 "data/maps/FairyPlate/scripts.pory"
	waitmessage
# 49 "data/maps/FairyPlate/scripts.pory"
	clearflag FLAG_B_NO_BAG_USE
# 50 "data/maps/FairyPlate/scripts.pory"
	clearflag FLAG_B_NO_CATCHING
# 51 "data/maps/FairyPlate/scripts.pory"
	clearflag FLAG_B_SMART_WILD_AI
# 52 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_FAIRY_PC1
# 53 "data/maps/FairyPlate/scripts.pory"
	releaseall
	return

FairyPlate_Battle_2:
# 37 "data/maps/FairyPlate/scripts.pory"
	call FairyPlateWonCatch
	goto FairyPlate_Battle_1

FairyPlate_Battle_3:
# 40 "data/maps/FairyPlate/scripts.pory"
	call FairyPlateWonCatch
	goto FairyPlate_Battle_1

FairyPlate_Battle_4:
# 43 "data/maps/FairyPlate/scripts.pory"
	call FairyPlateRun
	goto FairyPlate_Battle_1

FairyPlate_Battle_5:
# 46 "data/maps/FairyPlate/scripts.pory"
	call FairyPlateRun
	goto FairyPlate_Battle_1


FairyPlateWonCatch::
# 57 "data/maps/FairyPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 58 "data/maps/FairyPlate/scripts.pory"
	removeobject 1
# 59 "data/maps/FairyPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlateWonCatch_Text_0, [ MSGBOX_DEFAULT ]
# 61 "data/maps/FairyPlate/scripts.pory"
	giveitem ITEM_PIXIE_PLATE
# 62 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlateWonCatch_Text_1, [ MSGBOX_DEFAULT ]
# 63 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlateWonCatch_Text_2, [ MSGBOX_DEFAULT ]
	return


FairyPlateRun::
# 68 "data/maps/FairyPlate/scripts.pory"
	playmoncry SPECIES_TOGEKISS, CRY_MODE_ENCOUNTER
# 69 "data/maps/FairyPlate/scripts.pory"
	waitmoncry
	return


FairyPlate_IsGemCollected::
# 74 "data/maps/FairyPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FAIRY_GEM, FairyPlate_IsGemCollected_2
# 78 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
FairyPlate_IsGemCollected_1:
	return

FairyPlate_IsGemCollected_2:
# 75 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
	goto FairyPlate_IsGemCollected_1


FairyPlate_CollectGem::
# 84 "data/maps/FairyPlate/scripts.pory"
	lockall
# 85 "data/maps/FairyPlate/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_FAIRY_GEM, FairyPlate_CollectGem_2
# 89 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlate_CollectGem_Text_1, MSGBOX_YESNO
# 90 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FairyPlate_CollectGem_5
FairyPlate_CollectGem_1:
# 99 "data/maps/FairyPlate/scripts.pory"
	releaseall
	return

FairyPlate_CollectGem_2:
# 86 "data/maps/FairyPlate/scripts.pory"
	msgbox FairyPlate_CollectGem_Text_0, MSGBOX_DEFAULT
	goto FairyPlate_CollectGem_1

FairyPlate_CollectGem_5:
# 91 "data/maps/FairyPlate/scripts.pory"
	giveitem ITEM_FAIRY_GEM
# 92 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_HIDDEN_ITEM_FAIRY_GEM
# 93 "data/maps/FairyPlate/scripts.pory"
	fadescreen FADE_TO_BLACK
# 94 "data/maps/FairyPlate/scripts.pory"
	warp MAP_FAIRY_PLATE, 7, 20
# 95 "data/maps/FairyPlate/scripts.pory"
	setmetatile 7, 21, METATILE_Cave_ShoalCave_BlueStone_Small, TRUE
# 96 "data/maps/FairyPlate/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto FairyPlate_CollectGem_1


FairyPlate_ConditionCheck::
# 103 "data/maps/FairyPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_MESPIRT, FairyPlate_ConditionCheck_2
FairyPlate_ConditionCheck_1:
	return

FairyPlate_ConditionCheck_2:
# 104 "data/maps/FairyPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_AZELF, FairyPlate_ConditionCheck_4
	goto FairyPlate_ConditionCheck_1

FairyPlate_ConditionCheck_4:
# 105 "data/maps/FairyPlate/scripts.pory"
	goto_if_set FLAG_CAUGHT_UXIE, FairyPlate_ConditionCheck_6
	goto FairyPlate_ConditionCheck_1

FairyPlate_ConditionCheck_6:
# 106 "data/maps/FairyPlate/scripts.pory"
	checkitem ITEM_FAIRY_GEM, 1
# 107 "data/maps/FairyPlate/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FairyPlate_ConditionCheck_8
	goto FairyPlate_ConditionCheck_1

FairyPlate_ConditionCheck_8:
# 108 "data/maps/FairyPlate/scripts.pory"
	setflag FLAG_FAIRY_PC
	goto FairyPlate_ConditionCheck_1


FairyPlateWonCatch_Text_0:
# 60 "data/maps/FairyPlate/scripts.pory"
	.string "The Togekiss dissapeared in to the cave.$"

FairyPlateWonCatch_Text_1:
# 62 "data/maps/FairyPlate/scripts.pory"
	.string "There is an engraving on the Plate.$"

FairyPlateWonCatch_Text_2:
# 63 "data/maps/FairyPlate/scripts.pory"
	.string "The Original One is in all things. The\nOriginal One is nowhere at all.$"

FairyPlate_CollectGem_Text_0:
# 86 "data/maps/FairyPlate/scripts.pory"
	.string "The Gem Cluster has Shrunken$"

FairyPlate_CollectGem_Text_1:
# 89 "data/maps/FairyPlate/scripts.pory"
	.string "There is a large gem cluster here,\nCollect it?$"
