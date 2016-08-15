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

#include "variablewidget.hpp"
#include "ui_variablewidget.h"

VariableWidget::VariableWidget(QWidget* Parent)
: QWidget(Parent), ui(new Ui::VariableWidget)
{
	NameValidator = new QRegExpValidator(QRegExp("\\b[a-zA-Z_]+[a-zA-Z0-9_]*\\b"), this);
	ValueValidator = new QDoubleValidator(0, DBL_MAX, 6, this);

	StrZero = QString::number(0.0);

	ui->setupUi(this);
}

VariableWidget::~VariableWidget(void)
{
	delete ui;
}

void VariableWidget::AddButtonClicked(void)
{
	const QString Prefix = ui->templateBox->currentText();
	const int Rows = ui->variablesTab->rowCount();

	QString Name = Prefix; int Tmp;

	if (NameValidator->validate(Name, Tmp))
	{
		bool Duplicated = false;
		int Index = 0;

		do
		{
			Duplicated = false;

			for (int i = 0; i < Rows; i++)
			{
				if (ui->variablesTab->item(i, 0)->text() == Name)
				{
					Name = QString("%1%2").arg(Prefix).arg(++Index);
					Duplicated = true;
				}
			}
		}
		while (Duplicated);

		ui->variablesTab->insertRow(Rows);
		ui->variablesTab->setItem(Rows, 0, new QTableWidgetItem(Name));
		ui->variablesTab->setItem(Rows, 1, new QTableWidgetItem(StrZero));
	}
	else
	{
		QMessageBox::warning(this, tr("Error"), tr("Selected prefix is invalid"));
	}
}

void VariableWidget::RemoveButtonClicked(void)
{
	ui->variablesTab->removeRow(ui->variablesTab->currentIndex().row());
}

void VariableWidget::CellEditStarted(int Row, int Col)
{
	LastData = ui->variablesTab->item(Row, Col)->text();
}

void VariableWidget::CellValueChanged(int Row, int Col)
{
	QString CurrentData = ui->variablesTab->item(Row, Col)->text();
	int Pos = 0;

	QValidator* Validator = Col == 0 ? NameValidator : Col == 1 ? ValueValidator : nullptr;

	if (CurrentData.isEmpty() || (Validator && !Validator->validate(CurrentData, Pos)))
	{
		ui->variablesTab->item(Row, Col)->setText(LastData);
	}
}
