#-------------------------------------------------
#
# Project created by QtCreator 2014-05-05T11:02:59
#
#-------------------------------------------------

QT       -= core gui

TARGET = DllTest
TEMPLATE = lib

DEFINES += DLLTEST_LIBRARY

SOURCES += dlltest.cpp

HEADERS += dlltest.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
