#-------------------------------------------------
#
# Project created by QtCreator 2018-11-22T17:32:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Blockchain_Simulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    block.cpp \
    simulator.cpp \
    region.cpp \
    node.cpp \
    data.cpp \
    displaychain.cpp \
    blockWidget.cpp \
    minerwidget.cpp \
    transaction.cpp \
    transactiondisplay.cpp

HEADERS  += mainwindow.h \
    displaychain.h \
    block.h \
    main.h \
    node.h \
    region.h \
    blockWidget.h \
    minerwidget.h \
    transaction.h \
    transactiondisplay.h

FORMS    += mainwindow.ui \
    displaychain.ui \
    minerwidget.ui \
    blockWidget.ui \
    transactiondisplay.ui

CONFIG += c++11
