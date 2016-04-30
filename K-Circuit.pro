#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T15:55:53
#
#-------------------------------------------------

QT		+=	core gui widgets
CONFIG	+=	c++14

TARGET	=	kcircuit
TEMPLATE	=	app

SOURCES	+=	main.cpp \
			mainwindow.cpp \
    toolwidget.cpp \
    schemeview.cpp \
    variablewidget.cpp

HEADERS	+=	mainwindow.hpp \
    toolwidget.hpp \
    schemeview.hpp \
    variablewidget.hpp

FORMS	+=	mainwindow.ui \
    toolwidget.ui \
    variablewidget.ui

RESOURCES += \
    resources.qrc
