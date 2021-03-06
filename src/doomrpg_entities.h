// doomrpg_entities
// Copyright(C) 2020-2022 John D. Corrado
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

#ifndef __DOOMRPG_ENTITIES_H__
#define __DOOMRPG_ENTITIES_H__

#define ENTITY_AXE				0x0001
#define ENTITY_FIRE_EXT			0x0002
#define ENTITY_SHOTGUN			0x0003
#define ENTITY_SUPER_SHOTGN		0x0004
#define ENTITY_CHAINGUN			0x0005
#define ENTITY_ROCKET_LNCHR		0x0006
#define ENTITY_PLASMA_GUN		0x0007
#define ENTITY_BFG				0x0008
#define ENTITY_PISTOL			0x0009
#define ENTITY_HELLHOUND_WPN	0x000A
#define ENTITY_CERBERUS_WPN		0x000B
#define ENTITY_DEMON_WOLF_WPN	0x000C
#define ENTITY_ZOMBIE_PVT		0x0011
#define ENTITY_ZOMBIE_LT		0x0012
#define ENTITY_ZOMBIE_CPT		0x0013
#define ENTITY_HELLHOUND		0x0014
#define ENTITY_CERBERUS			0x0015
#define ENTITY_DEMON_WOLF		0x0016
#define ENTITY_TROOP			0x0017
#define ENTITY_COMMANDO			0x0018
#define ENTITY_ASSASSIN			0x0019
#define ENTITY_IMPLING			0x001A
#define ENTITY_IMP				0x001B
#define ENTITY_IMP_LORD			0x001C
#define ENTITY_PHANTOM			0x001D
#define ENTITY_LOST_SOUL		0x001E
#define ENTITY_NIGHTMARE		0x001F
#define ENTITY_BULL_DEMON		0x0020
#define ENTITY_PINKY			0x0021
#define ENTITY_BELPHEGOR		0x0022
#define ENTITY_MALWRATH			0x0023
#define ENTITY_CACODEMON		0x0024
#define ENTITY_WRETCHED			0x0025
#define ENTITY_BEHOLDER			0x0026
#define ENTITY_RAHOVART			0x0027
#define ENTITY_PAIN_ELEMENTAL	0x0028
#define ENTITY_GHOUL			0x0029
#define ENTITY_FIEND			0x002A
#define ENTITY_REVENANT			0x002B
#define ENTITY_BEHEMOTH			0x002C
#define ENTITY_MANCUBUS			0x002D
#define ENTITY_DRUJ				0x002E
#define ENTITY_INFERNIS			0x002F
#define ENTITY_ARCHVILE			0x0030
#define ENTITY_APOLLYON			0x0031
#define ENTITY_OGRE				0x0032
#define ENTITY_HELL_KNIGHT		0x0033
#define ENTITY_BARON			0x0034
#define ENTITY_CYBERDEMON		0x0035
#define ENTITY_KRONOS			0x0036
#define ENTITY_RED_KEY			0x0041
#define ENTITY_BLUE_KEY			0x0042
#define ENTITY_GREEN_KEY		0x0043
#define ENTITY_YELLOW_KEY		0x0049
#define ENTITY_HALON_CAN		0x0051
#define ENTITY_HALON_CANS		0x0052
#define ENTITY_BULLET_CLIP		0x0053
#define ENTITY_BULLET_CLIPS		0x0054
#define ENTITY_SHELL_CLIP		0x0055
#define ENTITY_SHELL_CLIPS		0x0056
#define ENTITY_ROCKET			0x0057
#define ENTITY_ROCKETS			0x0058
#define ENTITY_CELL_CLIP		0x0059
#define ENTITY_CELL_CLIPS		0x005A
#define ENTITY_HEALTH_VIAL		0x005B
#define ENTITY_ARMOR_SHARD		0x005C
#define ENTITY_FLAK_JACKET		0x005D
#define ENTITY_COMBAT_SUIT		0x005E
#define ENTITY_CREDITS_1		0x005F
#define ENTITY_CREDITS_2		0x0060
#define ENTITY_SM_MEDKIT		0x0063
#define ENTITY_LG_MEDKIT		0x0064
#define ENTITY_SOUL_SPHERE		0x0065
#define ENTITY_BERSERKER		0x0066
#define ENTITY_DOG_COLLAR		0x006E
#define ENTITY_CIVILIAN_1		0x0091
#define ENTITY_SCIENTIST_1		0x0092
#define ENTITY_MARINE_1			0x0093
#define ENTITY_SCIENTIST_2		0x0094
#define ENTITY_SCIENTIST_3		0x0095
#define ENTITY_CIVILIAN_2		0x0096
#define ENTITY_CIVILIAN_3		0x0097
#define ENTITY_MARINE_2			0x0098
#define ENTITY_LAVA_POOL		0x0080
#define ENTITY_FIRE				0x0081
#define ENTITY_BARREL			0x0082
#define ENTITY_POWER_COUPLING	0x0083
#define ENTITY_SINK				0x0084
#define ENTITY_TOILET			0x0085
#define ENTITY_CHAIR			0x0086
#define ENTITY_YELLOW_LAMP		0x0087
#define ENTITY_LIGHT_1			0x0088
#define ENTITY_LIGHT_2			0x0089
#define ENTITY_CABINET			0x008B
#define ENTITY_BLUE_LAMP		0x008C
#define ENTITY_TABLE			0x008D
#define ENTITY_BUNK_BEDS		0x008E
#define ENTITY_CRATE_1			0x00A1
#define ENTITY_CRATE_2			0x00A2
#define ENTITY_JAMMED_DOOR		0x0132
#define ENTITY_WEAK_WALL		0x014C
#define ENTITY_DOOR				0x0131
#define ENTITY_RED_DOOR			0x0134
#define ENTITY_BLUE_DOOR		0x0135
#define ENTITY_GREEN_DOOR		0x0136
#define ENTITY_YELLOW_DOOR		0x0137
#define ENTITY_EXIT_DOOR		0x0138
#define ENTITY_LOCKED_DOOR		0x013A
#define ENTITY_UNLOCKED_DOOR	0x013B
#define ENTITY_PORTAL			0x0153
#define ENTITY_COMPUTER			0x0167
#define ENTITY_ITEM_VENDOR		0x0168

#define ENTITY_TYPE_DOOR			0
#define ENTITY_TYPE_ENEMY			1
#define ENTITY_TYPE_HUMAN			2
#define ENTITY_TYPE_PICKUP			3
#define ENTITY_TYPE_CONSUMABLE		4
#define ENTITY_TYPE_WEAPON			5
#define ENTITY_TYPE_AMMO_SINGLE		6
#define ENTITY_TYPE_AMMO_MULTIPLE	16
#define ENTITY_TYPE_USABLE			7
#define ENTITY_TYPE_FIRE			10
#define ENTITY_TYPE_LAVA			11
#define ENTITY_TYPE_DESTRUCTIBLE	12
#define ENTITY_TYPE_STATIC			13

#define ENTITY_DOOR_NORMAL		0
#define ENTITY_DOOR_LOCKED		1
#define ENTITY_DOOR_UNLOCKED	2

#define ENTITY_PICKUP_HEALTH		0x14
#define ENTITY_PICKUP_ARMOR			0x15
#define ENTITY_PICKUP_CREDITS_1		0x16
#define ENTITY_PICKUP_CREDITS_2		0x17
#define ENTITY_PICKUP_KEYS			0x18

#define ENTITY_CONSUMABLE_SM_MEDKIT		0x19
#define ENTITY_CONSUMABLE_LG_MEDKIT		0x1A
#define ENTITY_CONSUMABLE_SOUL_SPHERE	0x1B
#define ENTITY_CONSUMABLE_BERSERKER		0x1C
#define ENTITY_CONSUMABLE_DOG_COLLAR	0x1D

#define ENTITY_AMMO_HALON	0
#define ENTITY_AMMO_BULLET	1
#define ENTITY_AMMO_SHELL	2
#define ENTITY_AMMO_ROCKET	3
#define ENTITY_AMMO_CELL	4

#define ENTITY_DESTRUCTIBLE_BARREL			1
#define ENTITY_DESTRUCTIBLE_CRATE			2
#define ENTITY_DESTRUCTIBLE_DOOR_WALL		3
#define ENTITY_DESTRUCTIBLE_POWER_COUPLING	4

#endif