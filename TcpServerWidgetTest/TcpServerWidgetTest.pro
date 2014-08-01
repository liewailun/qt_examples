#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T09:42:11
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServerWidgetTest
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    server.cpp

HEADERS  += widget.h \
    server.h

FORMS    += widget.ui
