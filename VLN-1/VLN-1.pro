QT += core
QT -= gui

TARGET = VLN-1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    userinterface.cpp \
    anitem.cpp \
    main_.cpp \
    service.cpp \
    database.cpp

HEADERS += \
    userinterface.h \
    anitem.h \
    service.h \
    database.h

