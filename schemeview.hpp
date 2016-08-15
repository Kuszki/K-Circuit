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

#ifndef SCHEMEVIEW_HPP
#define SCHEMEVIEW_HPP

#include <QGraphicsView>
#include <QListWidget>
#include <QObject>
#include <QWidget>

#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>

#include "itemtemplate.hpp"
#include "schemeitem.hpp"

class SchemeView : public QGraphicsView
{

		Q_OBJECT

	private:

		QGraphicsScene* mainScene;

	public:

		explicit SchemeView(QWidget* Parent = nullptr);
		virtual ~SchemeView(void) override;

		virtual void dragEnterEvent(QDragEnterEvent* Event) override;
		virtual void dragMoveEvent(QDragMoveEvent* Event) override;
		virtual void dragLeaveEvent(QDragLeaveEvent* Event) override;
		virtual void dropEvent(QDropEvent* Event) override;

	private slots:

		void DrawRoute(void);

};

#endif // SCHEMEVIEW_HPP
