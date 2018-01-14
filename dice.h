#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <iostream>


class Dice
{
protected:
    int value;
    int angle;

public:
    Dice();
    int getValue();
    int getAngle();
};

#endif // DICE_H
