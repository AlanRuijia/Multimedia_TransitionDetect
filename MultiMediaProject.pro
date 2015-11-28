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
    column.cpp \
    histogram.cpp

HEADERS  += videoeditmainwindow.h \
    corewipedetector.h \
    column.h \
    histogram.h

FORMS    += videoeditmainwindow.ui

INCLUDEPATH += /usr/local/opt/opencv3/include

LIBS += -L/usr/local/opt/opencv3/lib  \
        -lopencv_core \
        -lopencv_imgproc \
        -lopencv_features2d \
        -lopencv_highgui \
        -lopencv_video \
        -lopencv_videoio \
        -lopencv_videostab \
        -lopencv_imgcodecs \
        -lopencv_ml \
        -lopencv_shape \
        -lopencv_photo
