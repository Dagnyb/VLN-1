QT += core
QT -= gui

TARGET = VLN-1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    userinterface.cpp \
    anitem.cpp \
    list.cpp \
    main_.cpp

HEADERS += \
    userinterface.h \
    anitem.h \
    list.h

