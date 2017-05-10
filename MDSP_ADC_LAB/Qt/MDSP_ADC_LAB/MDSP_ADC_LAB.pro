#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T14:10:16
#
#-------------------------------------------------
QT       += serialport
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MDSP_ADC_LAB
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui

DISTFILES += \
    logo_hui.png

RESOURCES += \
    resource.qrc
