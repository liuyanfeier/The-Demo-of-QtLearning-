#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T14:51:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetWork_1
TEMPLATE = app

QT += network

SOURCES += main.cpp\
        mainwindow.cpp \
    network.cpp

HEADERS  += mainwindow.h \
    network.h

FORMS    += mainwindow.ui
