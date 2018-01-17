#include "dices.h"

Dices::Dices(SDL_Renderer* ren)
{
    this->tex = IMG_LoadTexture(ren, "dices.png");
    for (int i = 0; i < 5; i++) {
        this->tab[i] = new Dice();
    }
}

Dices::~Dices()
{
    SDL_DestroyTexture(this->tex);
}

void Dices::Draw(SDL_Renderer* ren)
{
    SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
    for (int i = 0; i < 5; i++) {
        this->dst.h = 64;
        this->dst.w = 64;
        this->dst.x = 400;
        this->dst.y = i * 106 + 20;

        this->src.x = (this->tab[i]->getValue() - 1) * 67;
        this->src.y = 0;
        this->src.w = 64;
        this->src.h = 64;

        SDL_RenderCopyEx(ren, this->tex, &this->src, &this->dst, this->tab[i]->getAngle(), NULL, SDL_FLIP_HORIZONTAL);

        if (this->tab[i]->isLocked()) {
            this->rect.w = 95;
            this->rect.h = 95;
            this->rect.x = 400 - 15;
            this->rect.y = i * (95 + 11) + 5;
            SDL_SetRenderDrawColor(ren, 58, 58, 58, 200);
            SDL_RenderFillRect(ren, &this->rect);
        }
    }
}

void Dices::roll()
{
    for (int i = 0; i < 5; i++) {
        if (!this->tab[i]->isLocked()) {
            this->tab[i]->reset();
        }
    }
}

void Dices::reset()
{
    for (int i = 0; i < 5; i++) {
        this->tab[i]->reset();
        this->tab[i]->unlock();
    }
}

void Dices::nextPlayer()
{
    for (int i = 0; i < 5; i++) {
        this->tab[i]->unlock();
    }
}

bool Dices::isDiceLocked(int i)
{
    return this->tab[i]->isLocked();
}

Dice *Dices::getDicePointer(int i)
{
    return tab[i];
}

int Dices::getDiceValue(int i)
{
    return this->tab[i]->getValue();
}
