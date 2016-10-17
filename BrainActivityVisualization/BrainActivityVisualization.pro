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
    AbstractFileReader.cpp \
    AbstractMatrixReader.cpp \
    AbstractWorker.cpp \
    FileNumberStreamReader.cpp \
    MatrixStatisticWorker.cpp \
    MatrixStatisticWorkerManager.cpp \
    QMainWindow.cpp

HEADERS  += gmainwindow.h \
    AbstractFileReader.h \
    AbstractMatrixReader.h \
    AbstractWorker.h \
    FileNumberStreamReader.h \
    MatrixStatisticWorker.h \
    MatrixStatisticWorkerManager.h \
    QMainWindow.h

FORMS    += gmainwindow.ui
