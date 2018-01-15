TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra
SOURCES += main.cpp \
    make-sockaddr.cc \
    EnvoiBalise.cc

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    EnvoiBalise.h \
    make-sockaddr.h

