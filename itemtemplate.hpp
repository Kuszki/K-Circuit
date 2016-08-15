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
#ifndef ITEMTEMPLATE_HPP
#define ITEMTEMPLATE_HPP

#include <QObject>
#include <QList>
#include <QMap>

class ItemTemplate : public QObject
{

		Q_OBJECT

	public: enum TYPE: unsigned
	{
		VoltageSource,
		CurrentSource,
		Resistor,
		Ground,
		Node
	};

	private: struct ItemData
	{
		QString Name;
		QString Icon;

		TYPE Type;
	};

	private:

		static QList<ItemData> ItemList;

		static QMap<TYPE, QString> IconMap;
		static QMap<TYPE, QString> NameMap;

	public:

		static const QList<ItemData>& GetTemplate(void);

		static const QMap<TYPE, QString>& GetIcons(void);
		static const QMap<TYPE, QString>& GetNames(void);

		static void Init(void);

};

#endif // ITEMTEMPLATE_HPP
