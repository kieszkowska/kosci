#include "clickable.h"


bool Clickable::checkBounds(int x, int y)
{
    if (this->pos.x < x && this->pos.x + this->pos.w > x && this->pos.y < y && this->pos.y + this->pos.h > y) {
        return true;
    }
    return false;
}
