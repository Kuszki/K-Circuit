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

#ifndef VARIABLEWIDGET_HPP
#define VARIABLEWIDGET_HPP

#include <QRegExpValidator>
#include <QDoubleValidator>
#include <QValidator>
#include <QLineEdit>
#include <QWidget>
#include <QRegExp>

#include <cfloat>

#include <QDebug>

namespace Ui
{
	class VariableWidget;
}

class VariableWidget : public QWidget
{

		Q_OBJECT

	private:

		Ui::VariableWidget* ui;

		QValidator* NameValidator;
		QValidator* ValueValidator;

		QString LastData;
		QString StrZero;

	public:

		explicit VariableWidget(QWidget* Parent = nullptr);
		virtual ~VariableWidget(void) override;

	private slots:

		void AddButtonClicked(void);
		void RemoveButtonClicked(void);

		void CellEditStarted(int Row, int Col);
		void CellValueChanged(int Row, int Col);

};

#endif // VARIABLEWIDGET_HPP
