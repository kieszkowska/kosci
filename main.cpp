#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

#define SCREEN_W 640
#define SCREEN_H 480

#include "dices.h"

int main()
{
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Blad SDL_Init(): " << SDL_GetError() << std::endl;
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

    bool run = true;
    SDL_Event e;
    Dices* dices = new Dices(ren);

    while (run) {
        while(SDL_PollEvent(&e)) {
            SDL_RenderClear(ren);
            if (e.type == SDL_QUIT) {
                run = false;
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
                SDL_RenderClear(ren);

                Dices* dices = new Dices(ren);
                dices->Draw(ren);

                SDL_RenderPresent(ren);
            }
        }

    }

    delete dices;
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(w);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

