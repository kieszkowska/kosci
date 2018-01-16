#ifndef COUNTSCORE_H
#define COUNTSCORE_H

#include "dices.h"
#include "dice.h"

#include <iostream>
#include <algorithm>


class CountScore
{
protected:
    Dices* dices;
    Dice* tab[5];
    int valTab[5];
    int valTabUnique[5];

public:
    CountScore(Dices* dices);
    int countScore(int cell);
};

#endif // COUNTSCORE_H
