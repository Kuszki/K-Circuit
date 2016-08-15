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

#include "schemeview.hpp"

SchemeView::SchemeView(QWidget* Parent)
: QGraphicsView(Parent)
{
	mainScene = new QGraphicsScene(this);

	setAcceptDrops(true);
	setScene(mainScene);
}

SchemeView::~SchemeView(void) {}

void SchemeView::dragEnterEvent(QDragEnterEvent* Event)
{
	Event->acceptProposedAction();
}

void SchemeView::dragMoveEvent(QDragMoveEvent* Event)
{
	Event->acceptProposedAction();
}

void SchemeView::dragLeaveEvent(QDragLeaveEvent* Event)
{
	Event->accept();
}

void SchemeView::dropEvent(QDropEvent* Event)
{
	if (QListWidget* Object = qobject_cast<QListWidget*>(Event->source()))
	{
		QGraphicsItem* Item = new SchemeItem(static_cast<ItemTemplate::TYPE>(Object->currentItem()->data(Qt::UserRole).toUInt()));

		Item->setPos(mapToScene(Event->pos()));

		scene()->addItem(Item);
	}

	if (scene()->items().size() == 2)
	{

	}

	QGraphicsView::dropEvent(Event);
}

void SchemeView::DrawRoute(void)
{
	if (SchemeItem* Item = dynamic_cast<SchemeItem*>(sender()))
	{

	}
}
