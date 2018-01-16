#include "rollbutton.h"

RollButton::RollButton(int x, int y, int h, int w, Turn *turn)
{
    this->pos.x = x;
    this->pos.y = y;
    this->pos.w = w;
    this->pos.h = h;
    this->turn = turn;
}

RollButton::~RollButton()
{

}

SDL_Rect RollButton::getRect()
{
    return this->pos;
}

void RollButton::click()
{
    if (this->turn->getRollCount() < 3) {
        dices->roll();
        this->turn->increaseRollCount();
    }
}

void RollButton::bindDices(Dices *dices)
{
    this->dices = dices;
}
