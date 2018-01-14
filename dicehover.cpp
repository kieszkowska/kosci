#include "dicehover.h"

DiceHover::DiceHover(Dices* dices)
{
    this->dices = dices;
}

void DiceHover::draw(SDL_Renderer* ren)
{
    for (int i = 0; i < 5; i++) {
        if (this->dices->isDiceLocked(i)) {
            this->rect.w = 95;
            this->rect.h = 95;
            this->rect.x = 400 - 15;
            this->rect.y = i * (95 + 11) + 5;
            SDL_SetRenderDrawColor(ren, 58, 58, 58, 128);
            SDL_RenderDrawRect(ren, &this->rect);
        }
    }
}

