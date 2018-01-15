TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra

SOURCES += main.cpp \
    EnvoiBalise.cpp \
    make-sockaddr.cc

HEADERS += \
    EnvoiBalise.h \
    make-sockaddr.h \
    unistd.h \
    make-sockaddr.h
