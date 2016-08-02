#-------------------------------------------------
#
# Project created by QtCreator 2016-07-23T14:07:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1_7
TEMPLATE = app


SOURCES += main.cpp\
    chatemotion.cpp \
    myqlable.cpp \
    chat.cpp

HEADERS  += \
    chatemotion.h \
    myqlable.h \
    chat.h

FORMS    += \
    chatemotion.ui \
    chat.ui

RESOURCES += \
    face/res.qrc \
    res.qrc
