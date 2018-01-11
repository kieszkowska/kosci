#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

#define SCREEN_W 800
#define SCREEN_H 530

#include "dices.h"
#include "player.h"
#include "rollbutton.h"

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

    RollButton* rollButton = new RollButton(664, 316, 54, 53);

    Dices* dices = new Dices(ren);

    Player* player1 = new Player();
    Player* player2 = new Player();

    SDL_Texture* background = IMG_LoadTexture(ren, "table.png");

    int x, y;

    while (run) {

        while(SDL_PollEvent(&e)) {
            SDL_RenderClear(ren);
            SDL_RenderCopy(ren, background, NULL, NULL);

            dices->Draw(ren);

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                dices->roll();
           }

            if (e.type == SDL_QUIT) {
                run = false;
            }

            if (e.type == SDL_MOUSEBUTTONUP && SDL_BUTTON(SDL_BUTTON_LEFT)) {
                SDL_GetMouseState(&x, &y);
                if(rollButton->checkBounds(x, y)) {
                    dices->roll();
                }
            }
        }

        SDL_RenderPresent(ren);

    }




    delete player1;
    delete player2;
    delete dices;
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(w);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

