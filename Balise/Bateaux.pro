TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra

SOURCES += main.cpp \
    make-sockaddr.cc \
    EnvoiBalise.cpp

HEADERS += \
    EnvoiBalise.h \
    make-sockaddr.h \
    unistd.h \
    make-sockaddr.h
