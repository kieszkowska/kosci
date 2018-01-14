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

int Dice::getAngle()
{
    return this->angle;
}

bool Dice::isLocked()
{
    return this->locked;
}

void Dice::unlock()
{
    this->locked = false;
}

void Dice::click()
{
    if (this->locked == true) {
        this->locked = false;
    }

    else {
        this->locked = true;
    }
}

void Dice::checkBounds(int x, int y)
{

}
