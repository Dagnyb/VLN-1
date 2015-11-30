QT += core
QT -= gui

TARGET = VLN-1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    VLN-1.cpp \
    userinterface.cpp \
    anitem.cpp \
    list.cpp

HEADERS += \
    userinterface.h \
    anitem.h \
    list.h

