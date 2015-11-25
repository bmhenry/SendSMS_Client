#-------------------------------------------------
#
# Project created by QtCreator 2015-11-03T14:22:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sendsms_client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    titlebar.cpp

HEADERS  += mainwindow.h \
    titlebar.h

FORMS    +=

win32:RC_ICONS = sms.ico

