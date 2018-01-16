#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <iostream>
#include <math.h>

#include "clickable.h"


class Dice : public Clickable
{
protected:
    int value;
    int angle;
    bool locked = false;
    int x, y;
    int r = 46;

public:
    Dice();
    int getValue();
    int getAngle();
    bool isLocked();
    void unlock();
    void click();
    bool checkBounds(int mx, int my);
    void reset();
};

#endif // DICE_H
