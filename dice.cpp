#include "dice.h"

Dice::Dice()
{
    static int position;
    if (position == 5) {
        position = 0;
    }
    this->x = 432;
    this->y = position * 106 + 52;
    position++;
    this->reset();
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
    if (this->locked == false) {
        this->locked = true;
    }

    else {
        this->locked = false;
    }
}

bool Dice::checkBounds(int mx, int my)
{
    if (pow(this->r, 2) > pow(x - mx, 2) + pow(y - my, 2)) {
        return true;
    }

    return false;
}

void Dice::reset()
{
    this->value = rand() % 6 + 1;
    this->angle = rand() % 90;
}
