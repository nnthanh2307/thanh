QT += core
QT -= gui

CONFIG += c++11

TARGET = ObServerPatternEx001
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ASubject.cpp \
    DummyProduct.cpp \
    Shop.cpp

HEADERS += \
    ASubject.h \
    DummyProduct.h \
    IObserver.h \
    Shop.h
