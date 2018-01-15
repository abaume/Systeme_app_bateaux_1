TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra
CONFIG += thread
SOURCES += main.cpp \
    EnvoiBalise.cc \
    make-sockaddr.cc

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    EnvoiBalise.h \
    make-sockaddr.h

