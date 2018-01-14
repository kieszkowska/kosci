#ifndef DICEHOVER_H
#define DICEHOVER_H

#include <SDL2/SDL.h>

#include "dices.h"


class DiceHover
{
protected:
    SDL_Rect rect;
    Dices* dices;

public:
    DiceHover(Dices* dices);
    void draw(SDL_Renderer *ren);
};

#endif // DICEHOVER_H
