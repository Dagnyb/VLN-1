QT += core
QT -= gui

TARGET = VLN-1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    userinterface.cpp \
    service.cpp \
    database.cpp \
    main.cpp \
    scientist.cpp

HEADERS += \
    userinterface.h \
    service.h \
    database.h \
    scientist.h

