#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T17:14:19
#
#-------------------------------------------------

QT       += core gui printsupport concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BrainActivityVisualization
TEMPLATE = app


SOURCES += main.cpp\
        gmainwindow.cpp \
    AbstractMatrixReader.cpp \
    AbstractWorker.cpp \
    FileNumberStreamReader.cpp \
    MatrixStatisticWorker.cpp \
    MatrixStatisticWorkerManager.cpp \
    coherenceworkermanager.cpp \
    coherencewidget.cpp

HEADERS  += gmainwindow.h \
    AbstractMatrixReader.h \
    AbstractWorker.h \
    FileNumberStreamReader.h \
    MatrixStatisticWorker.h \
    MatrixStatisticWorkerManager.h \
    coherenceworkermanager.h \
    MatrixStatisticWorkerManager.h \
    coherencewidget.h

FORMS    += gmainwindow.ui \
    gpaintwidget.ui

RESOURCES += \
    resources.qrc
