#include "dice.h"

Dice::Dice()
{
    this->value = rand() % 6 + 1;
    this->angle = rand() % 90;
}

int Dice::getValue()
{
    return this->value;
}
