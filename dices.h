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
    SDL_Rect dices[5];
    int w;
    int h;

public:
    Dices(SDL_Renderer *ren);
    ~Dices();
    void Draw(SDL_Renderer *ren);
    void roll();
    void nextPlayer();
    bool isDiceLocked(int i);
    Dice getDiceTab(int i);
};

#endif // DICES_H
