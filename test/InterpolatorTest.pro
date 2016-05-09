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

SOURCES += \
    ../src/model/interpolate/datatable.cpp \
    ../src/model/interpolate/interpolation.cpp \
    ../src/model/interpolate/lagrange.cpp \
    ../src/model/interpolate/newton.cpp \
    ../src/model/interpolate/partition.cpp \
    ../src/model/parseval/evaluator.cpp \
    ../src/model/parseval/parser.cpp \
    ../src/model/parseval/symbol.cpp \
    ../src/model/parseval/tokenizer.cpp \
   ../src/ model/model.cpp \
    main.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../src/model/interpolate/datatable.h \
    ../src/model/interpolate/interpolation.h \
    ../src/model/interpolate/lagrange.h \
    ../src/model/interpolate/newton.h \
    ../src/model/interpolate/partition.h \
    ../src/model/parseval/evaluator.h \
    ../src/model/parseval/parser.h \
    ../src/model/parseval/symbol.h \
    ../src/model/parseval/tokenizer.h \
    ../src/model/model.h
