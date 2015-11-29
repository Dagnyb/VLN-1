QT += core
QT -= gui

TARGET = VLN-1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    VLN-1.cpp \
    scientists_repo.cpp \
    userinterface.cpp

HEADERS += \
    scientists_repo.h \
    userinterface.h

