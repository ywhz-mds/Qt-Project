#-------------------------------------------------
#
# Project created by QtCreator 2022-05-27T10:43:53
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main_
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        mybutton.cpp \
        slider.cpp \
        slider2.cpp \
        slider3.cpp \
        widget.cpp \
        selectingwindow.cpp \
        herolabel.cpp \
        mapp.cpp \
        monster.cpp


HEADERS  += mainwindow.h \
        widget.h \
        mybutton.h \
        slider.h \
        slider2.h \
        slider3.h \
        selectingwindow.h \
        herolabel.h \
        mapp.h \
        monster.h

FORMS    += mainwindow.ui \
        widget.ui \
        slider.ui \
        slider2.ui \
        slider3.ui \
        selectingwindow.ui \
        map.ui

RESOURCES += \
        res.qrc
