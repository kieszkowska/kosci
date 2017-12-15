#ifndef DICES_H
#define DICES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "dice.h"


class Dices
{
protected:
    Dice tab[5];
    SDL_Texture* tex;
    SDL_Rect src;
    SDL_Rect dst;
    int w;
    int h;

public:
    Dices(SDL_Renderer *ren);
    ~Dices();
    int Draw(SDL_Renderer *ren);
};

#endif // DICES_H
