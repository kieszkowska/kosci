TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dice.cpp \
    dices.cpp \
    player.cpp \
    rollbutton.cpp \
    clickable.cpp \
    writetext.cpp \
    newgame.cpp \
    scoretable.cpp \
    scoretablecell.cpp \
    countscore.cpp \
    turn.cpp
LIBS += -lSDL2
LIBS += -lSDL2_image
LIBS += -lSDL2_ttf

HEADERS += \
    dice.h \
    dices.h \
    player.h \
    rollbutton.h \
    clickable.h \
    writetext.h \
    newgame.h \
    scoretable.h \
    scoretablecell.h \
    countscore.h \
    turn.h
