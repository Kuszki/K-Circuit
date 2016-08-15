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

#ifndef SCHEMEITEM_HPP
#define SCHEMEITEM_HPP

#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QAction>
#include <QPointF>
#include <QMenu>
#include <QList>

#include "itemtemplate.hpp"
#include "itemdialog.hpp"

class SchemeItem : public QGraphicsSvgItem
{

	private:

		const ItemTemplate::TYPE TYPE;

		QList<const SchemeItem*> Connections;

		QString Value;

	protected:

		virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* Event) override;
		virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* Event) override;
		virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent* Event) override;

	public:

		explicit SchemeItem(ItemTemplate::TYPE Type, QGraphicsItem* Parent = nullptr);
		virtual ~SchemeItem(void) override;

		QPointF GetConnectionPoint(int Index) const;

		bool ConnectItem(const SchemeItem* Item, int Slot = 0);

		void DisconnectItem(const SchemeItem* Item);

		void DisconnectSlot(int Slot);

		const QList<const SchemeItem*> GetConnections(void) const;

	public slots:

		void SaveNewValue(const QString& NewValue);

		void TriggerEditAction(void);

	signals:

		void onConnectRequest(int);

};

#endif // SCHEMEITEM_HPP
