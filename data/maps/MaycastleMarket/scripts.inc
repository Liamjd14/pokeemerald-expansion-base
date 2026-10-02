MaycastleMarket_MapScripts::
	.byte 0


MarketMart1::
# 4 "data/maps/MaycastleMarket/scripts.pory"
	lock
# 5 "data/maps/MaycastleMarket/scripts.pory"
	faceplayer
# 6 "data/maps/MaycastleMarket/scripts.pory"
	message MarketMart1_Text_0
# 7 "data/maps/MaycastleMarket/scripts.pory"
	waitmessage
# 8 "data/maps/MaycastleMarket/scripts.pory"
	pokemart MarketMart1Shop
# 9 "data/maps/MaycastleMarket/scripts.pory"
	msgbox MarketMart1_Text_1
# 10 "data/maps/MaycastleMarket/scripts.pory"
	release
	return


	.align 2
# 13 "data/maps/MaycastleMarket/scripts.pory"
MarketMart1Shop:
# 14 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_POKE_BALL
# 15 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 16 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 17 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 18 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_NET_BALL
# 19 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_NEST_BALL
# 20 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 21 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 22 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_TIMER_BALL
# 23 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 24 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 25 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_NONE

MarketMart2::
# 29 "data/maps/MaycastleMarket/scripts.pory"
	lock
# 30 "data/maps/MaycastleMarket/scripts.pory"
	faceplayer
# 31 "data/maps/MaycastleMarket/scripts.pory"
	message MarketMart1_Text_0
# 32 "data/maps/MaycastleMarket/scripts.pory"
	waitmessage
# 33 "data/maps/MaycastleMarket/scripts.pory"
	pokemart MarketMart2Shop
# 34 "data/maps/MaycastleMarket/scripts.pory"
	msgbox MarketMart1_Text_1
# 35 "data/maps/MaycastleMarket/scripts.pory"
	release
	return


	.align 2
# 38 "data/maps/MaycastleMarket/scripts.pory"
MarketMart2Shop:
# 39 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_LONELY_MINT
# 40 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_ADAMANT_MINT
# 41 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_NAUGHTY_MINT
# 42 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_BRAVE_MINT
# 43 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_BOLD_MINT
# 44 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_IMPISH_MINT
# 45 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_LAX_MINT
# 46 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_RELAXED_MINT
# 47 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_MODEST_MINT
# 48 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_MILD_MINT
# 49 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_RASH_MINT
# 50 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_QUIET_MINT
# 51 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_CALM_MINT
# 52 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_GENTLE_MINT
# 53 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_CAREFUL_MINT
# 54 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_SASSY_MINT
# 55 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_TIMID_MINT
# 56 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_HASTY_MINT
# 57 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_JOLLY_MINT
# 58 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_NAIVE_MINT
# 59 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_NONE

MarketMart3::
# 63 "data/maps/MaycastleMarket/scripts.pory"
	lock
# 64 "data/maps/MaycastleMarket/scripts.pory"
	faceplayer
# 65 "data/maps/MaycastleMarket/scripts.pory"
	message MarketMart1_Text_0
# 66 "data/maps/MaycastleMarket/scripts.pory"
	waitmessage
# 67 "data/maps/MaycastleMarket/scripts.pory"
	pokemart MarketMart3Shop
# 68 "data/maps/MaycastleMarket/scripts.pory"
	msgbox MarketMart1_Text_1
# 69 "data/maps/MaycastleMarket/scripts.pory"
	release
	return


	.align 2
# 72 "data/maps/MaycastleMarket/scripts.pory"
MarketMart3Shop:
# 73 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_POTION
# 74 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 75 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 76 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_MAX_POTION
# 77 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 78 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_REVIVE
# 79 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 80 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 81 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 82 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 83 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_AWAKENING
# 84 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_NONE

Vendingmachine::
# 88 "data/maps/MaycastleMarket/scripts.pory"
	lock
# 89 "data/maps/MaycastleMarket/scripts.pory"
	pokemart VendingmachineShop
# 90 "data/maps/MaycastleMarket/scripts.pory"
	release
	return


	.align 2
# 93 "data/maps/MaycastleMarket/scripts.pory"
VendingmachineShop:
# 94 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_FRESH_WATER
# 95 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_SODA_POP
# 96 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_LEMONADE
# 97 "data/maps/MaycastleMarket/scripts.pory"
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_NONE

LassText::
# 101 "data/maps/MaycastleMarket/scripts.pory"
	msgbox LassText_Text_0, MSGBOX_NPC
	end


Boy1Text::
# 108 "data/maps/MaycastleMarket/scripts.pory"
	msgbox Boy1Text_Text_0, MSGBOX_NPC
	end


Boy2Text::
# 114 "data/maps/MaycastleMarket/scripts.pory"
	msgbox Boy2Text_Text_0, MSGBOX_NPC
	end


WomanText::
# 121 "data/maps/MaycastleMarket/scripts.pory"
	msgbox WomanText_Text_0, MSGBOX_NPC
	end


OldWomanText::
# 128 "data/maps/MaycastleMarket/scripts.pory"
	msgbox OldWomanText_Text_0, MSGBOX_NPC
	end


Herdier::
# 134 "data/maps/MaycastleMarket/scripts.pory"
	playmoncry SPECIES_HERDIER, CRY_MODE_ENCOUNTER
# 135 "data/maps/MaycastleMarket/scripts.pory"
	waitmoncry
# 136 "data/maps/MaycastleMarket/scripts.pory"
	msgbox Herdier_Text_0, MSGBOX_NPC
	end


DoorText::
# 141 "data/maps/MaycastleMarket/scripts.pory"
	msgbox DoorText_Text_0, MSGBOX_NPC
	end


MarketMart1_Text_0:
# 6 "data/maps/MaycastleMarket/scripts.pory"
	.string "Welcome,\n How can I help you?$"

MarketMart1_Text_1:
# 9 "data/maps/MaycastleMarket/scripts.pory"
	.string "Come again soon.$"

LassText_Text_0:
# 101 "data/maps/MaycastleMarket/scripts.pory"
	.string "Shame they dont sell more beauty\n"
	.string "produtcs here. I will have to travle\l"
	.string "to another town to get what I want.$"

Boy1Text_Text_0:
# 108 "data/maps/MaycastleMarket/scripts.pory"
	.string "I here they sell some items not avalible\n"
	.string "at the front from that door sometimes.$"

Boy2Text_Text_0:
# 114 "data/maps/MaycastleMarket/scripts.pory"
	.string "Mum wont stop shopping all the time!\n"
	.string "All i want to do is play with my Maschiff\l"
	.string "at home.$"

WomanText_Text_0:
# 121 "data/maps/MaycastleMarket/scripts.pory"
	.string "They have a variety of products here.\n"
	.string "Everything from daily necessities, to\l"
	.string "trainer supplies$"

OldWomanText_Text_0:
# 128 "data/maps/MaycastleMarket/scripts.pory"
	.string "I'm here to buy my Herdier some treats.\n"
	.string "He loves Lava Cookies.$"

Herdier_Text_0:
# 136 "data/maps/MaycastleMarket/scripts.pory"
	.string "Ruff$"

DoorText_Text_0:
# 141 "data/maps/MaycastleMarket/scripts.pory"
	.string "The Door is locked. \n"
	.string "A note says to come back later.$"
