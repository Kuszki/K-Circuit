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

#include "schemeitem.hpp"
#include <QDebug>
SchemeItem::SchemeItem(ItemTemplate::TYPE Type, QGraphicsItem* Parent)
: QGraphicsSvgItem(ItemTemplate::GetIcons()[Type], Parent), TYPE(Type)
{
	setTransformOriginPoint(boundingRect().width() / 2, boundingRect().height() / 2);
	setFlag(QGraphicsItem::ItemIsMovable, true);

	if (TYPE == ItemTemplate::VoltageSource ||
	    TYPE == ItemTemplate::CurrentSource ||
	    TYPE == ItemTemplate::Resistor)
	{
		Connections.append(nullptr);
		Connections.append(nullptr);
	}
}

SchemeItem::~SchemeItem(void) {}

void SchemeItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* Event)
{
	if (Event->button() == Qt::MiddleButton)
	{
		setRotation(rotation() - 90);
	}

	QGraphicsSvgItem::mouseReleaseEvent(Event);
}

void SchemeItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* Event)
{
	if (Event->button() == Qt::LeftButton)
	{
		TriggerEditAction();
	}

	QGraphicsSvgItem::mouseDoubleClickEvent(Event);
}

void SchemeItem::contextMenuEvent(QGraphicsSceneContextMenuEvent* Event)
{
	static QMenu Menu(tr("Actions"));
	static QList<QAction*> Actions =
	{
		new QAction(QIcon::fromTheme("object-rotate-left"), tr("Rotate left"), &Menu),
		new QAction(QIcon::fromTheme("object-rotate-right"), tr("Rotate right"), &Menu),
		new QAction(QIcon::fromTheme("network-wired"), tr("Connect"), &Menu),
		new QAction(QIcon::fromTheme("preferences-system"), tr("Edit"), &Menu),
		new QAction(QIcon::fromTheme("edit-delete"), tr("Remove"), &Menu)
	};

	if (Menu.isEmpty()) Menu.addActions(Actions);

	QAction* Action = Menu.exec(Event->screenPos());

	if (Action == Actions[0])
	{
		setRotation(rotation() - 90);
	}
	else if (Action == Actions[1])
	{
		setRotation(rotation() + 90);
	}
	else if (Action == Actions[2])
	{
		emit onConnectRequest(1);

		//int(Event->pos().y() > (boundingRect().height() / 2)));

		qDebug() << "connect request on" << int(Event->pos().y() > (boundingRect().height() / 2));
	}
	else if (Action == Actions[3])
	{
		TriggerEditAction();
	}
	else if (Action == Actions[4])
	{
		deleteLater();
	}
}

void SchemeItem::SaveNewValue(const QString& NewValue)
{
	Value = NewValue;

	setToolTip(Value);
}

void SchemeItem::TriggerEditAction(void)
{
	if (TYPE != ItemTemplate::Ground)
	{
		ItemDialog* Dialog = new ItemDialog(Value, scene() ? qobject_cast<QWidget*>(scene()->parent()) : nullptr);

		connect(Dialog, &ItemDialog::onDialogAccepted, this, &SchemeItem::SaveNewValue);
		connect(Dialog, &ItemDialog::accepted, Dialog, &ItemDialog::deleteLater);

		Dialog->exec();
	}
}

QPointF SchemeItem::GetConnectionPoint(int Index) const
{
	if (!scene()) return QPointF();

	const double Width = boundingRect().width();
	const double Height = boundingRect().height();

	switch (TYPE)
	{
		case ItemTemplate::VoltageSource:
		case ItemTemplate::CurrentSource:
		case ItemTemplate::Resistor:
			if (Index == 0) return mapToScene(QPointF(0.5 * Width, 0.1 * Height));
			else if (Index == 1) return mapToScene(QPointF(0.5 * Width, 0.9 * Height));
			else return QPointF();
		break;
		case ItemTemplate::Ground:
			return mapToScene(QPointF(0.5 * Width, 0.292 * Height));
		break;
		case ItemTemplate::Node:
			return mapToScene(QPointF(0.5 * Width, 0.5 * Height));
		break;
		default: return QPointF();
	}
}

bool SchemeItem::ConnectItem(const SchemeItem* Item, int Slot)
{
	if (Slot < 0) return false;

	switch (TYPE)
	{
		case ItemTemplate::VoltageSource:
		case ItemTemplate::CurrentSource:
		case ItemTemplate::Resistor:
			if (Slot > 1 || Connections[Slot]) return false;
			else Connections[Slot] = Item;
		break;
		case ItemTemplate::Ground:
		case ItemTemplate::Node:
			if (Connections.contains(Item)) return false;
			else Connections.append(Item);
		break;
		default: return false;
	}

	return true;
}

void SchemeItem::DisconnectItem(const SchemeItem* Item)
{
	switch (TYPE)
	{
		case ItemTemplate::VoltageSource:
		case ItemTemplate::CurrentSource:
		case ItemTemplate::Resistor:
			for (auto& Connection: Connections) if (Connection == Item) Connection = nullptr;
		break;
		case ItemTemplate::Ground:
		case ItemTemplate::Node:
			if (Connections.contains(Item)) Connections.removeAll(Item);
		break;
	}
}

void SchemeItem::DisconnectSlot(int Slot)
{
	if (Slot < 0 || Slot > 1) return;

	switch (TYPE)
	{
		case ItemTemplate::VoltageSource:
		case ItemTemplate::CurrentSource:
		case ItemTemplate::Resistor:
			Connections[Slot] = nullptr;
		break;
	}
}
