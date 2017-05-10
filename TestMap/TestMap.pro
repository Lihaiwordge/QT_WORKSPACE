#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T08:33:24
#
#-------------------------------------------------

QT       += core gui
QT += webkitwidgets
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestMapSend
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \

HEADERS  += widget.h \
    ui_widget.h

FORMS    += \
    widget.ui

UI_DIR = ./UI

