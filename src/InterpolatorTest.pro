#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T21:35:33
#
#-------------------------------------------------

QT       += testlib gui

TARGET = tst_interpolatortest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += tst_interpolatortest.cpp \
    model/interpolate/datatable.cpp \
    model/interpolate/interpolation.cpp \
    model/interpolate/lagrange.cpp \
    model/interpolate/newton.cpp \
    model/interpolate/partition.cpp \
    model/parseval/evaluator.cpp \
    model/parseval/parser.cpp \
    model/parseval/symbol.cpp \
    model/parseval/tokenizer.cpp \
    model/model.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    model/interpolate/datatable.h \
    model/interpolate/interpolation.h \
    model/interpolate/lagrange.h \
    model/interpolate/newton.h \
    model/interpolate/partition.h \
    model/parseval/evaluator.h \
    model/parseval/parser.h \
    model/parseval/symbol.h \
    model/parseval/tokenizer.h \
    model/model.h
