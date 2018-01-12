#include "rollbutton.h"

RollButton::RollButton(int x, int y, int h, int w)
{
    this->pos.x = x;
    this->pos.y = y;
    this->pos.w = w;
    this->pos.h = h;
}

SDL_Rect RollButton::getRect()
{
    return this->pos;
}

void RollButton::click()
{
    dices->roll();
}

void RollButton::bindDices(Dices *dices)
{
    this->dices = dices;
}
