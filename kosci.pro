TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dice.cpp \
    dices.cpp
LIBS += -lSDL2
LIBS += -lSDL2_image

HEADERS += \
    dice.h \
    dices.h
