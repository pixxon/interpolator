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

LIBS += -lGLEW

SOURCES += main.cpp\
    opengl/drawable.cpp \
    opengl/camera.cpp \
    parseval/tokenizer.cpp \
    parseval/symbol.cpp \
    parseval/parser.cpp \
    parseval/evaluator.cpp \
    mainview.cpp \
    model.cpp \
    openglview.cpp

HEADERS  += \
    opengl/drawable.h \
    opengl/camera.h \
    parseval/tokenizer.h \
    parseval/symbol.h \
    parseval/parser.h \
    parseval/evaluator.h \
    mainview.h \
    model.h \
    openglview.h

FORMS    +=

DISTFILES += \
    opengl/fragment.shader \
    opengl/myFrag.frag \
    opengl/myVert.vert
