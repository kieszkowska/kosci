#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <iostream>

#include "clickable.h"


class Dice : public Clickable
{
protected:
    int value;
    int angle;
    bool locked = false;

public:
    Dice();
    int getValue();
    int getAngle();
    bool isLocked();
    void unlock();
    void click();
    void checkBounds(int x, int y);
};

#endif // DICE_H
