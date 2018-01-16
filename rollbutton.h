#ifndef ROLLBUTTON_H
#define ROLLBUTTON_H

#include <SDL2/SDL.h>
#include <iostream>

#include "clickable.h"
#include "dices.h"
#include "turn.h"


class RollButton : public Clickable
{
protected:
    Dices* dices;
    Turn* turn;

public:
    RollButton(int x, int y, int h, int w, Turn* turn);
    ~RollButton();
    SDL_Rect getRect();
    void click();
    void bindDices(Dices* dices);
};

#endif // ROLLBUTTON_H
