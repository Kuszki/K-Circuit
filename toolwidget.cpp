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

#include "toolwidget.hpp"
#include "ui_toolwidget.h"

ToolWidget::ToolWidget(QWidget* Parent)
: QWidget(Parent), ui(new Ui::ToolWidget)
{
	ui->setupUi(this);

	for (const auto& Item: ItemTemplate::GetTemplate())
	{
		QListWidgetItem* Tool = new QListWidgetItem(QIcon(Item.Icon), Item.Name);

		Tool->setData(Qt::UserRole, static_cast<unsigned>(Item.Type));
		ui->listWidget->addItem(Tool);
	}
}

ToolWidget::~ToolWidget(void)
{
	delete ui;
}
