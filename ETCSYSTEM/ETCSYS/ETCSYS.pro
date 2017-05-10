#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T15:26:00
#
#-------------------------------------------------
QT       += serialport
QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ETCSYS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    carinfo.cpp


HEADERS  += mainwindow.h \
    carinfo.h \
    database.h

FORMS    += mainwindow.ui
