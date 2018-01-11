#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

#define SCREEN_W 800
#define SCREEN_H 530

#include "dices.h"
#include "round.h"

int main()
{
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Blad SDL_Init(): " << SDL_GetError() << std::endl;
        return 0;
    }

    if(TTF_Init() == -1) {
        std::cout << "Blad TTF_Init: " << TTF_GetError() << std::endl;
        return 0;
    }

    IMG_Init(IMG_INIT_PNG);

    SDL_Window *w = SDL_CreateWindow("Kosci", 100, 100, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
    if (w == nullptr) {
        std::cout << "Blad SDL_CreateWindow(): " << SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
        std::cout << "Blad SDL_CreateRenderer(): " << SDL_GetError() << std::endl;
        return 0;
    }

    TTF_Font *font;
    font = TTF_OpenFont("OpenSans.ttf", 16);
    if(!font) {
        std::cout << "Blad TTF_OpenFont: " << TTF_GetError() << std::endl;
    }

    bool run = true;
    SDL_Event e;
    Dices* dices = new Dices(ren);

    SDL_Texture* background = IMG_LoadTexture(ren, "table.png");

    while (run) {

        while(SDL_PollEvent(&e)) {
            SDL_RenderClear(ren);
            SDL_RenderCopy(ren, background, NULL, NULL);

            dices->Draw(ren);

            if (e.type == SDL_QUIT) {
                run = false;
            }
        }

        SDL_RenderPresent(ren);

    }

    delete dices;
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(w);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

