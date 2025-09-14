# 1 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 2 "data/maps/MauvilleCity_GameCorner/scripts.pory"
.set LOCALID_BOUNCER, 24
# 3 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 4 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_MapScripts::
# 5 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerId_Onframe
# 6 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.byte 0
# 7 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 8 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    @ Game Corner prices
# 9 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_DOUBLE_TEAM_COINS, 1500
# 10 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_PSYCHIC_COINS, 3500
# 11 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_FLAMETHROWER_COINS, 4000
# 12 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_THUNDERBOLT_COINS, 4000
# 13 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_ICE_BEAM_COINS, 4000
# 14 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set DOLL_COINS, 1000
# 15 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set RARECANDY_COINS, 4000
# 16 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set SUNSTONE_COINS, 2000
# 17 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set MOONSTONE_COINS, 2000
# 18 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set FIRESTONE_COINS, 2000
# 19 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set THUNDERSTONE_COINS, 2000
# 20 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set WATERSTONE_COINS, 2000
# 21 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set LEAFSTONE_COINS, 2000
# 22 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set CHOICEBAND_COINS, 4500
# 23 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set BRIGHTPOWDER_COINS, 4500
# 24 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 25 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_50,  1000
# 26 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_500, 10000
# 27 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 28 "data/maps/MauvilleCity_GameCorner/scripts.pory"
TrainerId_Onframe:
# 29 "data/maps/MauvilleCity_GameCorner/scripts.pory"
.if GAME_CORNER_VAR_ID_CHECK != 0
# 30 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	map_script_2 GAME_CORNER_VAR_ID_CHECK, 0, BouncerCheck
# 31 "data/maps/MauvilleCity_GameCorner/scripts.pory"
.endif
# 32 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.2byte 0
# 33 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 34 "data/maps/MauvilleCity_GameCorner/scripts.pory"
BouncerCheck::
# 35 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 36 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement LOCALID_BOUNCER, Common_Movement_WalkInPlaceFasterLeft
# 37 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 38 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_PIN
# 39 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement LOCALID_BOUNCER, Common_Movement_ExclamationMark
# 40 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 41 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement LOCALID_BOUNCER, Common_Movement_Delay48
# 42 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 43 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement LOCALID_BOUNCER, Movement_Bouncer_Approach
# 44 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 45 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Bouncer1, MSGBOX_DEFAULT
# 46 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 47 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_ID_CHECK, 1
# 48 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement LOCALID_BOUNCER, Movement_Bouncer_Leave
# 49 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 50 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 51 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 52 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 53 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Movement_Bouncer_Approach:
# 54 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	walk_left
# 55 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	walk_left
# 56 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	step_end	
# 57 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 58 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Movement_Bouncer_Leave:
# 59 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	walk_right
# 60 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	walk_right
# 61 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	walk_in_place_faster_left
# 62 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	step_end		
# 63 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 64 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Blackjack::
# 65 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 66 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 67 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 68 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_BlackJack, MSGBOX_YESNO
# 69 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 70 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelBJ
# 71 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 72 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special StartBlackJack
# 73 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 74 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 75 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 76 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 77 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 78 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 79 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Derby::
# 80 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 81 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 82 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 83 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Derby, MSGBOX_YESNO
# 84 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 85 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelBJ
# 86 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_PEWTER, FALSE
# 87 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special StartDerby
# 88 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 89 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 90 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 91 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq GAME_CORNER_VAR_WINNINGS, 0, MauvilleCity_GameCorner_NoWin
# 92 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 93 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	buffernumberstring STR_VAR_1, GAME_CORNER_VAR_WINNINGS
# 94 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
# 95 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 96 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins GAME_CORNER_VAR_WINNINGS
# 97 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 98 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 99 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 100 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 101 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 102 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 103 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 104 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 105 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 106 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Snake::
# 107 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 108 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 109 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 110 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 111 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, 25, Onix_Not_Enough
# 112 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 113 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Snake, MSGBOX_YESNO
# 114 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 115 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF
# 116 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins 25
# 117 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 118 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 119 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 120 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 121 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_NONE, FALSE
# 122 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special StartSnake
# 123 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 124 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 125 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 126 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq GAME_CORNER_VAR_WINNINGS, 0, MauvilleCity_GameCorner_NoWin
# 127 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 128 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	buffernumberstring STR_VAR_1, GAME_CORNER_VAR_WINNINGS
# 129 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
# 130 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 131 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins GAME_CORNER_VAR_WINNINGS
# 132 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 133 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 134 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 135 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 136 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 137 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 138 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 139 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 140 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 141 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_FlappyBird::
# 142 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 143 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 144 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 145 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 146 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, 25, Butterfree_Not_Enough
# 147 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 148 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Bird, MSGBOX_YESNO
# 149 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 150 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF
# 151 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins 25
# 152 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 153 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 154 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 155 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 156 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_NONE, FALSE
# 157 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special StartFlappyBird
# 158 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 159 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 160 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 161 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq GAME_CORNER_VAR_WINNINGS, 0, MauvilleCity_GameCorner_NoWin
# 162 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 163 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	buffernumberstring STR_VAR_1, GAME_CORNER_VAR_WINNINGS
# 164 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
# 165 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 166 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins GAME_CORNER_VAR_WINNINGS
# 167 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 168 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 169 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 170 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 171 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 172 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 173 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 174 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 175 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 176 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BlockStacker::
# 177 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 178 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 179 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 180 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 181 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, 25, BlockStacker_Not_Enough
# 182 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 183 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_BS, MSGBOX_YESNO
# 184 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 185 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF	
# 186 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins 25
# 187 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 188 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 189 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 190 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 191 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_CASINO_PLUS_1, FALSE
# 192 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special StartBlockStacker
# 193 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    waitstate
# 194 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 195 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 196 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq GAME_CORNER_VAR_WINNINGS, 0, MauvilleCity_GameCorner_NoWin
# 197 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 198 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	buffernumberstring STR_VAR_1, GAME_CORNER_VAR_WINNINGS
# 199 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
# 200 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 201 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins GAME_CORNER_VAR_WINNINGS
# 202 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 203 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 204 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 205 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 206 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 207 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 208 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 209 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 210 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 211 "data/maps/MauvilleCity_GameCorner/scripts.pory"
BlockStacker_Not_Enough::
# 212 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox BS_Not_Enough, MSGBOX_DEFAULT
# 213 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 214 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 215 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 216 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Pinball_Not_Enough::
# 217 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox PB_Not_Enough, MSGBOX_DEFAULT
# 218 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 219 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 220 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 221 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Onix_Not_Enough::
# 222 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox Snake_Not_Enough, MSGBOX_DEFAULT
# 223 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 224 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 225 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 226 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Juice_Not_Enough::
# 227 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox Bjuice_Not_Enough, MSGBOX_DEFAULT
# 228 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 229 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end			
# 230 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 231 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Butterfree_Not_Enough::
# 232 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox Bird_Not_Enough, MSGBOX_DEFAULT
# 233 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 234 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end			
# 235 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 236 "data/maps/MauvilleCity_GameCorner/scripts.pory"
VF_Not_Enough::
# 237 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox Flip_Not_Enough, MSGBOX_DEFAULT
# 238 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 239 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 240 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 241 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Pachinko::	
# 242 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 243 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 244 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 245 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Pachinko, MSGBOX_YESNO
# 246 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 247 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF	
# 248 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_ROUTE1, FALSE
# 249 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	callnative PlayPachinko
# 250 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    waitstate
# 251 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 252 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 253 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 254 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 255 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 256 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PinballMeowth::
# 257 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 258 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 259 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 260 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 261 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, 25, Pinball_Not_Enough
# 262 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 263 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Pinball_Meowth, MSGBOX_YESNO
# 264 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 265 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF	
# 266 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins 25
# 267 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 268 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 269 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 270 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 271 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_POKE_CENTER, FALSE
# 272 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	callnative PlayMeowthPinballGame
# 273 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    waitstate
# 274 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 275 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 276 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq GAME_CORNER_VAR_WINNINGS, 0, MauvilleCity_GameCorner_NoWin
# 277 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 278 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	buffernumberstring STR_VAR_1, GAME_CORNER_VAR_WINNINGS
# 279 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
# 280 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 281 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins GAME_CORNER_VAR_WINNINGS
# 282 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 283 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 284 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 285 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 286 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 287 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 288 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 289 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 290 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 291 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PinballDiglett::
# 292 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 293 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 294 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 295 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 296 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, 50, Pinball_Not_Enough
# 297 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 298 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Pinball_Diglett, MSGBOX_YESNO
# 299 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 300 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF	
# 301 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins 50
# 302 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 303 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 304 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 305 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 306 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_POKE_JUMP, FALSE
# 307 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	callnative PlayDiglettPinballGame
# 308 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    waitstate
# 309 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 310 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 311 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq GAME_CORNER_VAR_WINNINGS, 0, MauvilleCity_GameCorner_NoWin
# 312 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 313 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	buffernumberstring STR_VAR_1, GAME_CORNER_VAR_WINNINGS
# 314 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
# 315 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 316 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins GAME_CORNER_VAR_WINNINGS
# 317 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 318 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 319 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 320 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 321 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 322 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 323 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 324 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 325 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 326 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PinballSeel::
# 327 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 328 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 329 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 330 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 331 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, 25, Pinball_Not_Enough
# 332 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 333 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Pinball_Seel, MSGBOX_YESNO
# 334 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 335 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF	
# 336 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins 25
# 337 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 338 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 339 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 340 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 341 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_SS_ANNE, FALSE
# 342 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	callnative PlaySeelPinballGame
# 343 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    waitstate 
# 344 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 345 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 346 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq GAME_CORNER_VAR_WINNINGS, 0, MauvilleCity_GameCorner_NoWin
# 347 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 348 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	buffernumberstring STR_VAR_1, GAME_CORNER_VAR_WINNINGS
# 349 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
# 350 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 351 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins GAME_CORNER_VAR_WINNINGS
# 352 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 353 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 354 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 355 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 356 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 357 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 358 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 359 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 360 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 361 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PinballGengar::
# 362 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 363 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 364 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 365 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 366 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, 100, Pinball_Not_Enough
# 367 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 368 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Pinball_Gengar, MSGBOX_YESNO
# 369 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 370 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF	
# 371 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins 100
# 372 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 373 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 374 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 375 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 376 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_POKE_TOWER, FALSE
# 377 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	callnative PlayGengarPinballGame
# 378 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    waitstate
# 379 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 380 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq GAME_CORNER_VAR_WINNINGS, 0, MauvilleCity_GameCorner_NoWin
# 381 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 382 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 383 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	buffernumberstring STR_VAR_1, GAME_CORNER_VAR_WINNINGS
# 384 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
# 385 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 386 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins GAME_CORNER_VAR_WINNINGS
# 387 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 388 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 389 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 390 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 391 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 392 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 393 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 394 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 395 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 396 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_VoltorbFlip::
# 397 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 398 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 399 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 400 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 401 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, 50, VF_Not_Enough
# 402 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 403 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_VF, MSGBOX_YESNO
# 404 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 405 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF
# 406 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins 50
# 407 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 408 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 409 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 410 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 411 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_OAK, FALSE
# 412 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 413 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special Special_ViewVoltorbFlip
# 414 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 415 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, 0, VF_Come_Again
# 416 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, 1, VF_Go_On
# 417 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 418 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 419 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 420 "data/maps/MauvilleCity_GameCorner/scripts.pory"
VF_Come_Again::
# 421 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 422 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 423 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox VF_Come_Again_Text, MSGBOX_DEFAULT
# 424 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 425 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 426 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 427 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 428 "data/maps/MauvilleCity_GameCorner/scripts.pory"
VF_Go_On::
# 429 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 430 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	buffernumberstring STR_VAR_1, GAME_CORNER_VAR_WINNINGS	
# 431 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_VF_Keep_Going, MSGBOX_YESNO
# 432 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 433 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, VF_Cash_Out
# 434 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto VF_Loop
# 435 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 436 "data/maps/MauvilleCity_GameCorner/scripts.pory"
VF_Loop::
# 437 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 438 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special Special_ViewVoltorbFlip
# 439 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 440 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, 0, VF_Come_Again
# 441 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, 1, VF_Go_On
# 442 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 443 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 444 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 445 "data/maps/MauvilleCity_GameCorner/scripts.pory"
VF_Cash_Out::	
# 446 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins GAME_CORNER_VAR_WINNINGS
# 447 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar GAME_CORNER_VAR_WINNINGS, 0
# 448 "data/maps/MauvilleCity_GameCorner/scripts.pory"
.if FLIP_VAR_LEVEL != 0
# 449 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar FLIP_VAR_LEVEL, 0
# 450 "data/maps/MauvilleCity_GameCorner/scripts.pory"
.endif
# 451 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 452 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 453 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 454 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 455 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 456 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 457 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 458 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 459 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 460 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gacha_Basic::
# 461 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 462 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 463 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 464 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 1
# 465 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_CINNABAR, FALSE
# 466 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special StartGacha
# 467 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 468 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 469 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 470 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 471 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 472 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 473 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 474 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gacha_Great::
# 475 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 476 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 477 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 478 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 2
# 479 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_CINNABAR, FALSE
# 480 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special StartGacha
# 481 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 482 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 483 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 484 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 485 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 486 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 487 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gacha_Ultra::
# 488 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 489 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 490 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 491 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 3
# 492 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_CINNABAR, FALSE
# 493 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special StartGacha
# 494 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 495 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 496 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 497 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 498 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 499 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 500 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gacha_Master::
# 501 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 502 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 503 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 504 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 4
# 505 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_RG_CINNABAR, FALSE
# 506 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special StartGacha
# 507 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitstate
# 508 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	savebgm MUS_DUMMY
# 509 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	fadedefaultbgm
# 510 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 511 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 512 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 513 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_CancelBJ::
# 514 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 515 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 516 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 517 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 518 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_NoWin::
# 519 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 520 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 521 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 522 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_CancelVF::
# 523 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 524 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 525 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 526 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 527 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 528 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CoinsClerk::
# 529 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 530 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 531 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
# 532 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 533 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
# 534 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
# 535 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 536 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmoneybox 0, 0
# 537 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 6
# 538 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
# 539 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 540 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
# 541 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
# 542 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 543 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 544 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 545 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 546 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 547 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 548 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 549 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
# 550 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
# 551 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 552 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 553 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 554 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 555 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 556 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 557 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy50Coins::
# 558 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 559 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 560 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_50
# 561 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 562 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 50
# 563 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_50
# 564 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox
# 565 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 566 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 567 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 568 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 569 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 570 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 571 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 572 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 573 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy500Coins::
# 574 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 575 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 576 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_500
# 577 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 578 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 500
# 579 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_500
# 580 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox
# 581 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 582 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 583 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 584 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 585 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 586 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 587 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 588 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 589 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NeedCoinCase::
# 590 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
# 591 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 592 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 593 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 594 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
# 595 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
# 596 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 597 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 598 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 599 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 600 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 601 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
# 602 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
# 603 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 604 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 605 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 606 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 607 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 608 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
# 609 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
# 610 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 611 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 612 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 613 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 614 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 615 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
# 616 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 617 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 618 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 619 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 620 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
# 621 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 622 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 623 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 624 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage::
# 625 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 626 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 627 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 628 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 629 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 630 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 631 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize::
# 632 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 633 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 634 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 635 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 636 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrize::
# 637 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
# 638 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 639 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
# 640 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
# 641 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
# 642 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 643 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 644 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 645 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 646 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TreeckoDoll::
# 647 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 648 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
# 649 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 650 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 651 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TorchicDoll::
# 652 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 653 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
# 654 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 655 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 656 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_MudkipDoll::
# 657 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 658 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
# 659 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 660 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 661 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
# 662 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
# 663 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 664 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 665 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
# 666 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
# 667 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
# 668 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 669 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 670 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll::
# 671 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 672 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 673 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 674 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 675 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 676 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 677 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TREECKO_DOLL
# 678 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 679 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 680 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 681 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 682 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 683 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 684 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTorchicDoll::
# 685 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 686 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 687 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 688 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 689 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 690 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 691 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TORCHIC_DOLL
# 692 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 693 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 694 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 695 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 696 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 697 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 698 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyMudkipDoll::
# 699 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 700 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 701 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 702 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 703 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 704 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 705 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_MUDKIP_DOLL
# 706 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 707 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 708 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 709 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 710 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 711 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 712 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
# 713 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 714 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 715 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 716 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 717 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
# 718 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 719 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 720 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 721 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 722 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelDollSelect::
# 723 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 724 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 725 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 726 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 727 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 728 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
# 729 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 730 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 731 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 732 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 733 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
# 734 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 735 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 736 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 737 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerNew::
# 738 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 739 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 740 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 741 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 742 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseNewPrizeMessage
# 743 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 744 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 745 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 746 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerNew2::
# 747 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 748 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 749 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 750 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 751 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseNewPrizeMessage2
# 752 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 753 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 754 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 755 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage::
# 756 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 757 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 758 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 759 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 760 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
# 761 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 762 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseNewPrizeMessage::
# 763 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 764 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 765 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 766 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 767 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseNewPrize	
# 768 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 769 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseNewPrizeMessage2::
# 770 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 771 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 772 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 773 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 774 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseNewPrize2		
# 775 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 776 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize::
# 777 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 778 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 779 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
# 780 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 781 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize::
# 782 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 783 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 784 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseNewPrize	
# 785 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 786 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize2::
# 787 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 788 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 789 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseNewPrize2	
# 790 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 791 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
# 792 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
# 793 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 794 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_TMDoubleTeam
# 795 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_TMPsychic
# 796 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_TMFlamethrower
# 797 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_TMThunderbolt
# 798 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_TMIceBeam
# 799 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 800 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 801 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 802 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 803 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseNewPrize::
# 804 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	@ multichoice 12, 0, MULTI_GAMECORNER_NEW, FALSE
# 805 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 806 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_RareCandy
# 807 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_SunStone
# 808 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_MoonStone
# 809 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_ChoiceBand
# 810 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_BrightPowder
# 811 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 7, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 812 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 813 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 814 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 815 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseNewPrize2::
# 816 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	@ multichoice 12, 0, MULTI_GAMECORNER_NEW2, FALSE
# 817 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 818 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_FireStone
# 819 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_ThunderStone
# 820 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_WaterStone
# 821 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_LeafStone
# 822 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 823 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 824 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 825 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 826 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChoiceBand::
# 827 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 8
# 828 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CHOICE_BAND
# 829 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_CHOICE_BAND
# 830 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmNewPrize
# 831 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 832 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BrightPowder::
# 833 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 9
# 834 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_BRIGHT_POWDER
# 835 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_BRIGHT_POWDER
# 836 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmNewPrize	
# 837 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 838 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_RareCandy::
# 839 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 840 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_RARE_CANDY
# 841 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_RARE_CANDY
# 842 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmNewPrize
# 843 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 844 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SunStone::
# 845 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 846 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_SUN_STONE
# 847 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_SUN_STONE
# 848 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmNewPrize
# 849 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 850 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_MoonStone::
# 851 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 852 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_MOON_STONE
# 853 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_MOON_STONE
# 854 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmNewPrize
# 855 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 856 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ThunderStone::
# 857 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 5
# 858 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_THUNDER_STONE
# 859 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_THUNDER_STONE
# 860 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmNewPrize
# 861 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 862 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_WaterStone::
# 863 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 6
# 864 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_WATER_STONE
# 865 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_WATER_STONE
# 866 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmNewPrize
# 867 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 868 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_LeafStone::
# 869 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 7
# 870 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_LEAF_STONE
# 871 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_LEAF_STONE
# 872 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmNewPrize
# 873 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 874 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_FireStone::
# 875 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 4
# 876 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_FIRE_STONE
# 877 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_FIRE_STONE
# 878 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmNewPrize	
# 879 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 880 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmNewPrize::
# 881 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	//special BufferItemName
# 882 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheNewX, MSGBOX_YESNO
# 883 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 884 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 885 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyRareCandy
# 886 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuySunStone
# 887 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyMoonStone
# 888 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_BuyFireStone
# 889 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_BuyThunderStone
# 890 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 6, MauvilleCity_GameCorner_EventScript_BuyWaterStone
# 891 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 7, MauvilleCity_GameCorner_EventScript_BuyLeafStone
# 892 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 8, MauvilleCity_GameCorner_EventScript_BuyChoiceBand
# 893 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 9, MauvilleCity_GameCorner_EventScript_BuyBrightPowder
# 894 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 895 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 896 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 897 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyBrightPowder::
# 898 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 899 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, BRIGHTPOWDER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew
# 900 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_BRIGHT_POWDER
# 901 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForNew
# 902 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins BRIGHTPOWDER_COINS
# 903 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_BRIGHT_POWDER
# 904 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 905 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 906 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 907 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize
# 908 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 909 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 910 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyChoiceBand::
# 911 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 912 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, CHOICEBAND_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew
# 913 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_CHOICE_BAND
# 914 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForNew
# 915 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins CHOICEBAND_COINS
# 916 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_CHOICE_BAND
# 917 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 918 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 919 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 920 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize
# 921 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 922 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 923 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyRareCandy::
# 924 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 925 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, RARECANDY_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew
# 926 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_RARE_CANDY
# 927 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForNew
# 928 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins RARECANDY_COINS
# 929 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_RARE_CANDY
# 930 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 931 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 932 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 933 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize
# 934 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 935 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 936 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuySunStone::
# 937 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 938 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, SUNSTONE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew
# 939 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_SUN_STONE
# 940 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForNew
# 941 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins SUNSTONE_COINS
# 942 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_SUN_STONE
# 943 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 944 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 945 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 946 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize
# 947 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 948 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 949 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyMoonStone::
# 950 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 951 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, MOONSTONE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew
# 952 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_MOON_STONE
# 953 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForNew
# 954 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins MOONSTONE_COINS
# 955 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_MOON_STONE
# 956 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 957 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 958 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 959 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize
# 960 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 961 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 962 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyFireStone::
# 963 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 964 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, FIRESTONE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew2
# 965 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_FIRE_STONE
# 966 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForNew2
# 967 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins FIRESTONE_COINS
# 968 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_FIRE_STONE
# 969 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 970 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 971 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 972 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize2
# 973 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 974 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 975 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyThunderStone::
# 976 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 977 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, THUNDERSTONE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew2
# 978 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_THUNDER_STONE
# 979 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForNew2
# 980 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins THUNDERSTONE_COINS
# 981 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_THUNDER_STONE
# 982 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 983 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 984 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 985 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize2
# 986 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 987 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 988 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyWaterStone::
# 989 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 990 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, WATERSTONE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew2
# 991 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_WATER_STONE
# 992 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForNew2
# 993 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins WATERSTONE_COINS
# 994 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_WATER_STONE
# 995 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 996 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 997 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 998 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize2
# 999 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1000 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1001 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyLeafStone::
# 1002 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 1003 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, LEAFSTONE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew2
# 1004 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_LEAF_STONE
# 1005 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForNew2
# 1006 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins LEAFSTONE_COINS
# 1007 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_LEAF_STONE
# 1008 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 1009 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 1010 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 1011 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize2
# 1012 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 1013 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1014 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMDoubleTeam::
# 1015 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 1016 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
# 1017 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
# 1018 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 1019 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1020 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMPsychic::
# 1021 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 1022 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
# 1023 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
# 1024 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 1025 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1026 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMFlamethrower::
# 1027 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 1028 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
# 1029 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
# 1030 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 1031 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1032 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMThunderbolt::
# 1033 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 4
# 1034 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
# 1035 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
# 1036 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 1037 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1038 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMIceBeam::
# 1039 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 5
# 1040 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
# 1041 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
# 1042 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 1043 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1044 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
# 1045 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special BufferTMHMMoveName
# 1046 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
# 1047 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 1048 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 1049 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam
# 1050 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuyTMPsychic
# 1051 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower
# 1052 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt
# 1053 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_BuyTMIceBeam
# 1054 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1055 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1056 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam::
# 1057 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 1058 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 1059 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_DOUBLE_TEAM
# 1060 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 1061 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_DOUBLE_TEAM_COINS
# 1062 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_DOUBLE_TEAM
# 1063 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 1064 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 1065 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 1066 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 1067 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1068 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1069 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMPsychic::
# 1070 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 1071 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 1072 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_PSYCHIC
# 1073 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 1074 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_PSYCHIC_COINS
# 1075 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_PSYCHIC
# 1076 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 1077 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 1078 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 1079 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 1080 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1081 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1082 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower::
# 1083 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 1084 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 1085 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_FLAMETHROWER
# 1086 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 1087 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_FLAMETHROWER_COINS
# 1088 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_FLAMETHROWER
# 1089 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 1090 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 1091 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 1092 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 1093 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1094 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1095 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt::
# 1096 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 1097 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 1098 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_THUNDERBOLT
# 1099 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 1100 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_THUNDERBOLT_COINS
# 1101 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_THUNDERBOLT
# 1102 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 1103 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 1104 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 1105 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 1106 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1107 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1108 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMIceBeam::
# 1109 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 1110 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 1111 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_ICE_BEAM
# 1112 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 1113 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_ICE_BEAM_COINS
# 1114 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_ICE_BEAM
# 1115 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 1116 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 1117 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 1118 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 1119 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1120 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1121 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
# 1122 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 1123 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 1124 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1125 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1126 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew::
# 1127 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 1128 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize
# 1129 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 1130 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1131 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForNew2::
# 1132 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 1133 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize2
# 1134 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 1135 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1136 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForTM::
# 1137 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_BagIsFull
# 1138 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 1139 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1140 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1141 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForNew::
# 1142 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_BagIsFull
# 1143 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize
# 1144 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 1145 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1146 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForNew2::
# 1147 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_BagIsFull
# 1148 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseNewPrize2
# 1149 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 1150 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1151 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelTMSelect::
# 1152 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 1153 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 1154 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 1155 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1156 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1157 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman2::
# 1158 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
# 1159 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1160 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1161 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Dealer::
# 1162 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Dealer, MSGBOX_NPC
# 1163 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1164 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1165 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1166 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Dealer2::
# 1167 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Dealer2, MSGBOX_NPC
# 1168 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1169 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 1170 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1171 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_VFGuy1::
# 1172 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_VFGuy1, MSGBOX_NPC
# 1173 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1174 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 1175 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1176 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_VFGuy2::
# 1177 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_VFGuy2, MSGBOX_NPC
# 1178 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1179 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end			
# 1180 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1181 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gentleman::
# 1182 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
# 1183 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1184 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1185 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Girl::
# 1186 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1187 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1188 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 1189 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
# 1190 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
# 1191 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_STARTER_MON
# 1192 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 1193 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 1194 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 1195 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1196 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1197 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
# 1198 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 1199 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 1200 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 1201 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 1202 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TREECKO_DOLL
# 1203 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 1204 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 1205 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1206 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1207 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
# 1208 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 1209 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 1210 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 1211 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 1212 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TORCHIC_DOLL
# 1213 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 1214 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 1215 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1216 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1217 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
# 1218 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 1219 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 1220 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 1221 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 1222 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_MUDKIP_DOLL
# 1223 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 1224 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 1225 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1226 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1227 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
# 1228 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 1229 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
# 1230 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 1231 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1232 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1233 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
# 1234 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
# 1235 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 1236 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1237 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1238 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
# 1239 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
# 1240 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 1241 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1242 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1243 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanM::
# 1244 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1245 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1246 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1247 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
# 1248 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
# 1249 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1250 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1251 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1252 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TryGive20Coins::
# 1253 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 1254 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 1255 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
# 1256 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_20_COINS
# 1257 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 20
# 1258 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
# 1259 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 1260 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 1261 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1262 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1263 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanMNormal::
# 1264 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
# 1265 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1266 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1267 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1268 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_OldMan::
# 1269 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1270 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1271 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
# 1272 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1273 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1274 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1275 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PachinkoGuy::
# 1276 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1277 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1278 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_PachinkoGuy, MSGBOX_DEFAULT
# 1279 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1280 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 1281 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1282 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Hiker::
# 1283 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1284 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1285 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Hiker, MSGBOX_DEFAULT
# 1286 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1287 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 1288 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1289 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Bouncer::
# 1290 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1291 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1292 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Bouncer2, MSGBOX_DEFAULT
# 1293 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1294 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end		
# 1295 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1296 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_DerbyLady1::
# 1297 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1298 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1299 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Derby_1, MSGBOX_DEFAULT
# 1300 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1301 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end			
# 1302 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1303 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_DerbyLady2::
# 1304 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1305 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1306 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Derby_2, MSGBOX_DEFAULT
# 1307 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1308 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end			
# 1309 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1310 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Fisherman::
# 1311 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1312 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1313 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Fisherman, MSGBOX_DEFAULT
# 1314 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1315 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end			
# 1316 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1317 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gachalady::
# 1318 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1319 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1320 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Gachalady, MSGBOX_DEFAULT
# 1321 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 1322 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end			
# 1323 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1324 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Employee::
# 1325 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1326 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1327 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Employee, MSGBOX_DEFAULT
# 1328 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1329 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end			
# 1330 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1331 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Cook::
# 1332 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1333 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1334 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
# 1335 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1336 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1337 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1338 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Man::
# 1339 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1340 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1341 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
# 1342 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1343 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1344 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1345 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_JuiceLady::	
# 1346 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1347 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1348 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1349 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase2
# 1350 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 1351 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_Juice, MSGBOX_YESNO
# 1352 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 1353 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_CancelVF
# 1354 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 1355 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, 10, Juice_Not_Enough
# 1356 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins 10
# 1357 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 1358 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 1359 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	delay 40
# 1360 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 1361 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	giveitem ITEM_BERRY_JUICE
# 1362 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 1363 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1364 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1365 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
# 1366 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 1367 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1368 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 1369 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 1370 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1371 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1372 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Maniac::
# 1373 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1374 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1375 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
# 1376 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1377 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1378 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1379 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman::
# 1380 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 1381 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 1382 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
# 1383 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 1384 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1385 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1386 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine0::
# 1387 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1388 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1389 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1390 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 0
# 1391 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1392 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1393 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1394 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1395 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1396 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1397 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine1::
# 1398 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1399 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1400 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1401 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 1
# 1402 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1403 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1404 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1405 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1406 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1407 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1408 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine2::
# 1409 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1410 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1411 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1412 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 2
# 1413 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1414 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1415 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1416 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1417 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1418 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1419 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine3::
# 1420 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1421 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1422 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1423 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 3
# 1424 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1425 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1426 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1427 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1428 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1429 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1430 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine4::
# 1431 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1432 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1433 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1434 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 4
# 1435 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1436 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1437 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1438 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1439 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1440 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1441 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine5::
# 1442 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1443 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1444 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1445 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 5
# 1446 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1447 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1448 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1449 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1450 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1451 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1452 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine6::
# 1453 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1454 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1455 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1456 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 6
# 1457 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1458 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1459 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1460 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1461 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1462 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1463 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine7::
# 1464 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1465 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1466 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1467 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 7
# 1468 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1469 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1470 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1471 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1472 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1473 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1474 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine8::
# 1475 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1476 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1477 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1478 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 8
# 1479 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1480 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1481 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1482 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1483 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1484 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1485 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine9::
# 1486 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1487 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1488 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1489 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 9
# 1490 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1491 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1492 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1493 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1494 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1495 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1496 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine10::
# 1497 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1498 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1499 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1500 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 10
# 1501 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1502 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1503 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1504 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1505 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1506 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1507 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine11::
# 1508 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 1509 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1510 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 1511 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 11
# 1512 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1513 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playbgm MUS_GAME_CORNER, FALSE
# 1514 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 1515 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1516 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1517 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1518 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoCoinCase::
# 1519 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
# 1520 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1521 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 1522 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1523 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoCoinCase2::
# 1524 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantBuyWithNoCoinCase, MSGBOX_DEFAULT
# 1525 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 1526 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end	
# 1527 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1528 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
# 1529 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is Mauville Game Corner.$"
# 1530 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1531 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_PachinkoGuy:
# 1532 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I used to own one of these dusty old\n"
# 1533 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "DROPSPIN MACHINES.\p"
# 1534 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The manual always said 'Use the\n"
# 1535 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "DIRECTIONAL BUTTONS to TILT and\l"
# 1536 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "change the DROP SPEED…'\p"
# 1537 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I've always wondered what that\n"
# 1538 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "means.$"
# 1539 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1540 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Hiker:
# 1541 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Gah!\n"
# 1542 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I blew it all on that ONIX game.\p"
# 1543 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You need to be careful…\p"
# 1544 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You only win 2 COINS for\n"
# 1545 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "every point in these machines.$"
# 1546 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1547 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Derby_1:
# 1548 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Looking to bet on the DERBY?\n"
# 1549 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "We've gone digital!\p"
# 1550 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Use one of the tablets\n"
# 1551 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "in front of the counter.$"	
# 1552 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1553 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Derby_2:
# 1554 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's not all about CONDITION.\p"
# 1555 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "At the end of the day, it's\n"
# 1556 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "really all luck.\p"
# 1557 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Sometimes it's best to just\n"
# 1558 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "pick your favorite!$"	
# 1559 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1560 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Fisherman:
# 1561 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I come here for the food.\p"
# 1562 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's no CELADON CAFE…\n"
# 1563 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "But it'll do.$"		
# 1564 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1565 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Gachalady:
# 1566 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The LOTTERY MACHINES have odds,\n"
# 1567 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "but nothing is guaranteed.\p"
# 1568 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Some machines are better than\n"
# 1569 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "others, and there are different\l"
# 1570 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "rarities in all of them.\p"
# 1571 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "New POKéMON are also weighted\n"
# 1572 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "By your POKéDEX, so be wary.$"	
# 1573 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1574 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Employee:
# 1575 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I'm on the lookout for cheaters.\n"
# 1576 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Nobody likes a cheater!$"
# 1577 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1578 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Bouncer1:
# 1579 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You need a valid TRAINER ID\n"
# 1580 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "to enter the GAME CORNER.\p"
# 1581 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Let's see…\p"
# 1582 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "…\p"
# 1583 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Hmm…\p"
# 1584 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "…\p"
# 1585 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Everything looks good here.\n"
# 1586 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Enjoy the GAME CORNER!$"	
# 1587 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1588 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Bouncer2:
# 1589 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Enjoy the GAME CORNER!$"	
# 1590 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1591 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Pachinko:
# 1592 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "A DROPSPIN MACHINE!\n"
# 1593 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's 3 COINS per BALL.$"
# 1594 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1595 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
# 1596 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Okay, you wanted some Coins for\n"
# 1597 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the games?\p"
# 1598 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "But you don't have a Coin Case for\n"
# 1599 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "stowing the Coins.$"
# 1600 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1601 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
# 1602 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Were you looking for Coins?\p"
# 1603 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's ¥1000 for 50 Coins.\n"
# 1604 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like some?$"
# 1605 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1606 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
# 1607 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you very much!\n"
# 1608 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here are your Coins!$"
# 1609 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1610 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
# 1611 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Um… You don't appear to have\n"
# 1612 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "enough money…$"
# 1613 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1614 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinCaseIsFull:
# 1615 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh?\n"
# 1616 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Your Coin Case is full.$"
# 1617 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1618 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
# 1619 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh… You don't need Coins, then?\n"
# 1620 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Good luck on your adventure!$"
# 1621 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1622 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
# 1623 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Welcome.\p"
# 1624 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can exchange your Coins for\n"
# 1625 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "prizes here.$"
# 1626 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1627 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WhichPrize:
# 1628 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Which prize would you like?$"
# 1629 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1630 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
# 1631 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is\n"
# 1632 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"
# 1633 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1634 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsTheNewX:
# 1635 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is\n"
# 1636 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the {STR_VAR_1}?$"
# 1637 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1638 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_BlackJack:
# 1639 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's a BLACKJACK TABLE!\n"
# 1640 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Want to play?$"
# 1641 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1642 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Derby:
# 1643 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's the MAUVILLE DERBY!\n"
# 1644 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Want to place a bet?$"	
# 1645 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1646 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Snake:
# 1647 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's ONIX!\n"
# 1648 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It costs 25 COINS to play.$"		
# 1649 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1650 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Bird:
# 1651 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's FLUTTERFREE!\n"
# 1652 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It costs 25 COINS to play.$"		
# 1653 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1654 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Pinball_Meowth:
# 1655 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's a PINBALL MACHINE!\n"
# 1656 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It costs 25 COINS to play.$"
# 1657 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1658 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_BS:
# 1659 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's BLOCK BUILDER!\n"
# 1660 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It costs 25 COINS to play.$"
# 1661 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1662 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Pinball_Seel:
# 1663 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's a PINBALL MACHINE!\n"
# 1664 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It costs 25 COINS to play.$"
# 1665 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1666 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Pinball_Diglett:
# 1667 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's a PINBALL MACHINE!\n"
# 1668 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It costs 50 COINS to play.$"
# 1669 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1670 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Pinball_Gengar:
# 1671 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's a PINBALL MACHINE!\n"
# 1672 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It costs 100 COINS to play.$"
# 1673 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1674 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_VF:
# 1675 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's VOLTORB FLIP!\n"
# 1676 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It costs 50 COINS to play.$"
# 1677 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1678 "data/maps/MauvilleCity_GameCorner/scripts.pory"
VF_Come_Again_Text:
# 1679 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Too bad.\n"
# 1680 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Try again soon!$"
# 1681 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1682 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SendToYourHomePC:
# 1683 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you!\n"
# 1684 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 1685 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1686 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NotEnoughCoins:
# 1687 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough Coins.$"
# 1688 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1689 "data/maps/MauvilleCity_GameCorner/scripts.pory"
PB_YOU_WON_TEXT:
# 1690 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You won\n"
# 1691 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "{STR_VAR_1} COINS!$"
# 1692 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1693 "data/maps/MauvilleCity_GameCorner/scripts.pory"
PB_Not_Enough:
# 1694 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's a PINBALL MACHINE!\p"
# 1695 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS…$"
# 1696 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1697 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Snake_Not_Enough:
# 1698 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's ONIX!\p"
# 1699 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS…$"	
# 1700 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1701 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Bjuice_Not_Enough:
# 1702 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS.$"	
# 1703 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1704 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Bird_Not_Enough:
# 1705 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's FLUTTERFREE!\p"
# 1706 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS…$"		
# 1707 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1708 "data/maps/MauvilleCity_GameCorner/scripts.pory"
BS_Not_Enough:
# 1709 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's BLOCK BUILDER!\p"
# 1710 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS…$"	
# 1711 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1712 "data/maps/MauvilleCity_GameCorner/scripts.pory"
Flip_Not_Enough:
# 1713 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's VOLTORB FLIP!\p"
# 1714 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS…$"
# 1715 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1716 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 1717 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
# 1718 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There isn't any room available for\n"
# 1719 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "placing {STR_VAR_1}.$"
# 1720 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1721 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_VF_Keep_Going:
# 1722 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You've made {STR_VAR_1} COINS.\n"
# 1723 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Keep going?$"
# 1724 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1725 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_OhIsThatSo:
# 1726 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, is that so? \n"
# 1727 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You need to save some Coins before\l"
# 1728 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "coming back here.$"
# 1729 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1730 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
# 1731 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"
# 1732 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1733 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo:
# 1734 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 1735 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1736 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 1737 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
# 1738 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, you can't carry any more than that.$"
# 1739 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1740 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
# 1741 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I made a mistake and got two of\n"
# 1742 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the same Dolls.\p"
# 1743 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like one of them?$"
# 1744 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1745 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo2:
# 1746 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 1747 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1748 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_YouWantItButNotNow:
# 1749 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Huh?\n"
# 1750 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You want it, but not right now?$"
# 1751 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1752 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontBeNegative:
# 1753 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, don't be so negative!\n"
# 1754 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can have this!$"
# 1755 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1756 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantWinJackpot:
# 1757 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There's a prize I want, but I can't win\n"
# 1758 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the jackpot.$"
# 1759 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1760 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
# 1761 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Hey, kid, if you want to play here,\n"
# 1762 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "you need a Coin Case.\p"
# 1763 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I think the young lady next door\n"
# 1764 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "had one. Go see her!$"
# 1765 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1766 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
# 1767 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "My luck can only last so long.\n"
# 1768 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is too much for me.\l"
# 1769 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here, take some Coins!$"
# 1770 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1771 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
# 1772 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Mauville has something for\n"
# 1773 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "everyone.\p"
# 1774 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "For me, it's the Game Corner.$"
# 1775 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1776 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
# 1777 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The Roulette tables have different\n"
# 1778 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "rates.\p"
# 1779 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Check your Coins if you're going to\n"
# 1780 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "pick a table.$"
# 1781 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1782 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
# 1783 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's easy to lose track of time in here. \n"
# 1784 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I should get back to work.$"
# 1785 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1786 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
# 1787 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "COINS are needed to play here\n"
# 1788 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "in the GAME CORNER.$"
# 1789 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1790 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	MauvilleCity_GameCorner_Text_Dealer:
# 1791 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Some say BLACKJACK is about skill.\n"
# 1792 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Others say it's about luck.\p"
# 1793 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I say it's about having fun…\n"
# 1794 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "and maybe winning big!$"
# 1795 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1796 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	MauvilleCity_GameCorner_Text_Dealer2:
# 1797 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can bet anything divisible\n"
# 1798 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "by 10 here.\p"
# 1799 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Maybe you should go all in!$"	
# 1800 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1801 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_VFGuy1:
# 1802 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You want to play VOLTORB FLIP?\p"
# 1803 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You need to be on the other\n"
# 1804 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "side of the table.$"
# 1805 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1806 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_VFGuy2:
# 1807 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Try the other side of\n"
# 1808 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the table, pal.$"	
# 1809 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1810 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
# 1811 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This Roulette thing…\n"
# 1812 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's rather demanding.\p"
# 1813 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Win or lose, it's only by luck.$"
# 1814 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1815 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
# 1816 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Up to three Coins can be used to play\n"
# 1817 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the Slots.$"
# 1818 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1819 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DifficultToStopOn7:
# 1820 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's very difficult to make it stop\n"
# 1821 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "right on “7.”\p"
# 1822 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "If it stops on “7” during the Reel Time\n"
# 1823 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonus game, you'll receive extra Coins.$"
# 1824 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1825 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
# 1826 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here's some information for you\n"
# 1827 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "about the Slots.\p"
# 1828 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The more lightning bolts you stock,\n"
# 1829 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the more Reel Time chances you get.\p"
# 1830 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "In a game with the maximum five\n"
# 1831 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Reel Time chances…\p"
# 1832 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It is possible to receive four regular\n"
# 1833 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonuses, then a big bonus.\p"
# 1834 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "That would total 660 Coins, but it's\n"
# 1835 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "very difficult to get.$"
# 1836 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1837 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
# 1838 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can't play if you don't have\n"
# 1839 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "a Coin Case.$"
# 1840 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 1841 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantBuyWithNoCoinCase:
# 1842 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Huh? Looks like you need\n"
# 1843 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "a COIN CASE.$"
# 1844 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	
# 1845 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_Juice:
# 1846 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "BERRY JUICE!\n"
# 1847 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Just 10 COINS.$"
