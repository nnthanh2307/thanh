QT += core
QT -= gui

#CONFIG += c++11
CONFIG += c++14

TARGET = MediatorPatternEx002
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Mediator.cpp \
    Ship.cpp

HEADERS += \
    IMediator.h \
    IShip.h \
    Mediator.h \
    Ship.h
