#include "dices.h"

Dices::Dices(SDL_Renderer* ren)
{
    this->tex = IMG_LoadTexture(ren, "dices.png");
}

Dices::~Dices()
{
    SDL_DestroyTexture(this->tex);
}

void Dices::Draw(SDL_Renderer* ren)
{
    for (int i = 0; i < 5; i++) {
        this->dst.h = 64;
        this->dst.w = 64;
        this->dst.x = 400;
        this->dst.y = i * 106 + 20;

        this->src.x = (this->tab[i].getValue() - 1) * 67;
        this->src.y = 0;
        this->src.w = 64;
        this->src.h = 64;

        SDL_RenderCopy(ren, this->tex, &this->src, &this->dst);
    }
}

void Dices::roll()
{
    for (int i = 0; i < 5; i++) {
        this->tab[i] = Dice();
    }
}
