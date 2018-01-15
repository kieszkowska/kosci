#include "dice.h"

Dice::Dice()
{
    static int position;
    this->value = rand() % 6 + 1;
    this->angle = rand() % 90;
    this->x = 432;
    this->y = position * 106 + 52;
    position++;
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

bool Dice::checkBounds(int mx, int my)
{
    if (this->r > sqrt(pow(abs(x - mx), 2) * pow(abs(y - my), 2))) {
        return true;
    }

    return false;
}
