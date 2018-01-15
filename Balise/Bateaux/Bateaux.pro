TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    EnvoiBalise.cpp

HEADERS += \
    EnvoiBalise.h \
    make-sockaddr.h \
    unistd.h
