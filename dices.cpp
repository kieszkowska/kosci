#include "dices.h"

Dices::Dices(SDL_Renderer* ren)
{
    this->tex = IMG_LoadTexture(ren, "dices.png");

    for (int i = 0; i < 5; i++) {
        this->tab[i] = Dice();
    }
}

Dices::~Dices()
{
    SDL_DestroyTexture(this->tex);
}

int Dices::Draw(SDL_Renderer* ren)
{
    for (int i = 0; i < 5; i++) {
        this->dst.h = 64;
        this->dst.w = 64;
        this->dst.x = i * 67;
        this->dst.y = 10;

        this->src.x = (this->tab[i].getValue() - 1) * 67;
        this->src.y = 0;
        this->src.w = 64;
        this->src.h = 64;

        return SDL_RenderCopy(ren, this->tex, &this->src, &this->dst);
    }
}
