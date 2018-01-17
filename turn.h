#ifndef TURN_H
#define TURN_H

#include "dices.h"


class Turn
{
protected:
    int turnCount = 1;
    int rollCount = 1;
    Dices* dices;

public:
    Turn(Dices* dices);
    void increaseTurnCount();
    void increaseRollCount();
    void resetTurnCount();
    void resetRollCount();
    int getTurnCount();
    int getRollCount();
};

#endif // TURN_H
