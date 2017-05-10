#-------------------------------------------------
#
# Project created by QtCreator 2016-07-10T15:51:01
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FLOWCTLR_QT_FOR_WINDOWS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    comcmd.h

FORMS    += mainwindow.ui
