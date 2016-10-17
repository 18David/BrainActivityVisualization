#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T17:14:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BrainActivityVisualization
TEMPLATE = app


SOURCES += main.cpp\
        gmainwindow.cpp \
    AbstractMatrixReader.cpp \
    AbstractWorker.cpp \
    FileNumberStreamReader.cpp \
    MatrixStatisticWorker.cpp \
    MatrixStatisticWorkerManager.cpp

HEADERS  += gmainwindow.h \
    AbstractMatrixReader.h \
    AbstractWorker.h \
    FileNumberStreamReader.h \
    MatrixStatisticWorker.h \
    MatrixStatisticWorkerManager.h

FORMS    += gmainwindow.ui
