#-------------------------------------------------
#
# Project created by QtCreator 2015-11-24T14:15:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MultiMediaProject
TEMPLATE = app


SOURCES += main.cpp\
        videoeditmainwindow.cpp \
    corewipedetector.cpp \
    column.cpp

HEADERS  += videoeditmainwindow.h \
    corewipedetector.h \
    column.h

FORMS    += videoeditmainwindow.ui

DISTFILES +=

LIBS +=`pkg-config opencv --libs`\
