/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  {description}                                                          *
 *  Copyright (C) 2016  Łukasz "Kuszki" Dróżdż  l.drozdz@openmailbox.org   *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the  Free Software Foundation, either  version 3 of the  License, or   *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This  program  is  distributed  in the hope  that it will be useful,   *
 *  but WITHOUT ANY  WARRANTY;  without  even  the  implied  warranty of   *
 *  MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.  See  the   *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have  received a copy  of the  GNU General Public License   *
 *  along with this program. If not, see http://www.gnu.org/licenses/.     *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "itemtemplate.hpp"

QList<ItemTemplate::ItemData> ItemTemplate::ItemList = QList<ItemTemplate::ItemData>();

QMap<ItemTemplate::TYPE, QString> ItemTemplate::IconMap = QMap<ItemTemplate::TYPE, QString>();
QMap<ItemTemplate::TYPE, QString> ItemTemplate::NameMap = QMap<ItemTemplate::TYPE, QString>();

void ItemTemplate::Init(void)
{
	ItemList =
	{
		{ tr("Voltage source"),	":/tools/tool_vsource.svg",	VoltageSource	},
		{ tr("Current source"),	":/tools/tool_csource.svg",	CurrentSource	},
		{ tr("Resistor"),		":/tools/tool_resistor.svg",	Resistor		},
		{ tr("Ground"),		":/tools/tool_ground.svg",	Ground		},
		{ tr("Node"),			":/tools/tool_node.svg",		Node			}
	};

	IconMap =
	{
		{ VoltageSource,	":/tools/tool_vsource.svg"	},
		{ CurrentSource,	":/tools/tool_csource.svg"	},
		{ Resistor,		":/tools/tool_resistor.svg"	},
		{ Ground,			":/tools/tool_ground.svg"	},
		{ Node,			":/tools/tool_node.svg"		}
	};

	NameMap =
	{
		{ VoltageSource,	tr("Voltage source")	},
		{ CurrentSource,	tr("Current source")	},
		{ Resistor,		tr("Resistor")			},
		{ Ground,			tr("Ground")			},
		{ Node,			tr("Node")			}
	};
}

const QList<ItemTemplate::ItemData>& ItemTemplate::GetTemplate(void)
{
	return ItemList;
}

const QMap<ItemTemplate::TYPE, QString>& ItemTemplate::GetIcons(void)
{
	return IconMap;
}

const QMap<ItemTemplate::TYPE, QString>& ItemTemplate::GetNames(void)
{
	return NameMap;
}
