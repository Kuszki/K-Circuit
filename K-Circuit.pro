#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T15:55:53
#
#-------------------------------------------------

QT		+=	core gui widgets svg
CONFIG	+=	c++14

TARGET	=	kcircuit
TEMPLATE	=	app

SOURCES	+=	main.cpp \
			mainwindow.cpp \
    toolwidget.cpp \
    schemeview.cpp \
    variablewidget.cpp \
    schemeitem.cpp \
    itemtemplate.cpp \
    itemdialog.cpp

HEADERS	+=	mainwindow.hpp \
    toolwidget.hpp \
    schemeview.hpp \
    variablewidget.hpp \
    schemeitem.hpp \
    itemtemplate.hpp \
    itemdialog.hpp

FORMS	+=	mainwindow.ui \
    toolwidget.ui \
    variablewidget.ui \
    itemdialog.ui

RESOURCES += \
    resources.qrc
