#-------------------------------------------------
#
# Project created by QtCreator 2015-11-03T14:22:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GracefulSMS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    titlebar.cpp \
    threadlist.cpp \
    threaditem.cpp \
    messageitem.cpp \
    messagelist.cpp \
    sendbar.cpp \
    fileio.cpp \
    gracefulsms.cpp

HEADERS  += mainwindow.h \
    titlebar.h \
    threadlist.h \
    threaditem.h \
    messagelist.h \
    messageitem.h \
    sendbar.h \
    fileio.h \
    gracefulsms.h

FORMS    +=

win32:RC_ICONS = sms.ico

