#-------------------------------------------------
#
# Project created by QtCreator 2016-02-26T17:55:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Interpolator
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    model/parseval/tokenizer.cpp \
    model/parseval/symbol.cpp \
    model/parseval/parser.cpp \
    model/parseval/evaluator.cpp \
    model/interpolate/interpolation.cpp \
    model/model.cpp \
    view/opengl/camera.cpp \
    view/opengl/drawable.cpp \
    view/mainview.cpp \
    view/openglview.cpp \
    model/interpolate/lagrange.cpp \
    model/interpolate/datatable.cpp \
    model/interpolate/partition.cpp

HEADERS  += \
    model/parseval/tokenizer.h \
    model/parseval/symbol.h \
    model/parseval/parser.h \
    model/parseval/evaluator.h \
    model/interpolate/interpolation.h \
    model/model.h \
    view/opengl/camera.h \
    view/opengl/drawable.h \
    view/mainview.h \
    view/openglview.h \
    model/interpolate/lagrange.h \
    model/interpolate/datatable.h \
    model/interpolate/partition.h

RESOURCES += \
    resources.qrc

