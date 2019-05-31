QT += core network
QT -= gui
QT += sql

TARGET = EchoServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mytcpserver.cpp \
    dbserver.cpp \
    someclass.cpp

HEADERS += \
    mytcpserver.h \
    dbserver.h \
    someclass.h

