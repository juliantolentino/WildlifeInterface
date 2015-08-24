#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T15:22:43
#
#-------------------------------------------------

QT       += core gui multimediawidgets multimedia opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    gazeplot.cpp
HEADERS  += mainwindow.h \
    qcustomplot.h \
    gazeplot.h

FORMS    += mainwindow.ui \
    gazeplot.ui

QMAKE_CXXFLAGS += -std=gnu++11

RESOURCES += \
    myres.qrc

DISTFILES +=

CONFIG += c++11

