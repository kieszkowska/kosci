#ifndef TURN_H
#define TURN_H


class Turn
{
protected:
    int turnCount = 1;
    int rollCount = 1;

public:
    Turn();
    void increaseTurnCount();
    void increaseRollCount();
    void resetTurnCount();
    void resetRollCount();
    int getTurnCount();
    int getRollCount();
};

#endif // TURN_H
