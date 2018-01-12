#ifndef ROLLBUTTON_H
#define ROLLBUTTON_H

#include <SDL2/SDL.h>
#include <iostream>

#include "clickable.h"
#include "dices.h"


class RollButton : public Clickable
{
protected:
    Dices* dices;

public:
    RollButton(int x, int y, int h, int w);
    SDL_Rect getRect();
    void click();
    void bindDices(Dices* dices);
};

#endif // ROLLBUTTON_H
