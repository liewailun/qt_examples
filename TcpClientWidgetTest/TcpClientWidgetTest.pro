#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T09:43:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpClientWidgetTest
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    client.cpp

HEADERS  += widget.h \
    client.h

FORMS    += widget.ui
