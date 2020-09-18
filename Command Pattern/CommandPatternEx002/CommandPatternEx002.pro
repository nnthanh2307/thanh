QT += core
QT -= gui

CONFIG += c++11

TARGET = CommandPatternEx002
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Command.cpp
