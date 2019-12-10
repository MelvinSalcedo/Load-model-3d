#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T20:43:46
#
#-------------------------------------------------
QT += sql
QT       += core gui sql
QT       +=opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QTPLUGIN += QSQLMYSQL
TARGET = opengl
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    model3d.cpp \
    myglwidget.cpp

HEADERS  += mainwindow.h \
    model3d.h \
    myglwidget.h

FORMS    += mainwindow.ui
LIBS += -lOpengl32
DISTFILES +=

RESOURCES += \
    resources.qrc

