#-------------------------------------------------
#
# Project created by QtCreator 2016-08-24T10:11:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xzwCalendar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calendar.cpp \
    Date.cpp \
    mylabel.cpp \
    mydialog.cpp \
    myinputdialog.cpp \
    mydeletedialog.cpp

HEADERS  += mainwindow.h \
    calendar.h \
    Date.h \
    mylabel.h \
    mydialog.h \
    myinputdialog.h \
    mydeletedialog.h

FORMS    += mainwindow.ui \
    mydialog.ui \
    myinputdialog.ui \
    mydeletedialog.ui

TRANSLATIONS += eng.ts

