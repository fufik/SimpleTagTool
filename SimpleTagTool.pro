#-------------------------------------------------
#
# Project created by QtCreator 2016-03-13T09:20:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleTagTool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/include
#LIBS += -ltaglib
CONFIG += link_pkgconfig
PKGCONFIG += taglib
