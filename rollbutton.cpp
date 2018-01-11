#include "rollbutton.h"

RollButton::RollButton(int x, int y, int h, int w)
{
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = w;
    this->rect.h = h;
}

bool RollButton::checkBounds(int x, int y)
{
    if (this->rect.x < x && this->rect.x + this->rect.w > x && this->rect.y < y && this->rect.y + this->rect.h > y) {
        return true;
    }
    return false;
}
