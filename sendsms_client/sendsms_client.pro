#-------------------------------------------------
#
# Project created by QtCreator 2015-11-03T14:22:31
#
#-------------------------------------------------

QT       += core gui network

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
    gracefulsms.cpp \
    sms.cpp \
    listener.cpp \
    notification.cpp \
    server.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    titlebar.h \
    threadlist.h \
    threaditem.h \
    messagelist.h \
    messageitem.h \
    sendbar.h \
    fileio.h \
    gracefulsms.h \
    sms.h \
    listener.h \
    notification.h \
    server.h \
    client.h

FORMS    +=

win32:RC_ICONS = sms.ico

DISTFILES += \
    sms_format.txt

