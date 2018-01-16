#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#define SCREEN_W 800
#define SCREEN_H 530

#include "dices.h"
#include "player.h"
#include "rollbutton.h"
#include "clickable.h"
#include "writetext.h"
#include "newgame.h"
#include "scoretable.h"
#include "scoretablecell.h"
#include "turn.h"
#include "countscore.h"


int main()
{
    srand(time(NULL));

//    Init SDL, TTF, IMG

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Blad SDL_Init(): " << SDL_GetError() << std::endl;
        return 0;
    }

    if(TTF_Init() == -1) {
        std::cout << "Blad TTF_Init: " << TTF_GetError() << std::endl;
        return 0;
    }

    IMG_Init(IMG_INIT_PNG);


//    Create Window, Renderer

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


//    Load Texture

    SDL_Texture* background = IMG_LoadTexture(ren, "table.png");



    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");



    bool run = true;

    SDL_Event e;

    std::vector<Clickable*> ui;

    int mousex, mousey;




    Turn* turn = new Turn();

    RollButton* rollButton = new RollButton(664, 316, 54, 53, turn);

    Dices* dices = new Dices(ren);

    CountScore* count = new CountScore(dices);

    rollButton->bindDices(dices);

    Player* player1 = new Player();
    Player* player2 = new Player();

    WriteText* openSans = new WriteText("OpenSans.ttf", 14, ren);
    SDL_Point newGamePos { 650, 200 };

    NewGame* newGameButton = new NewGame();

    ScoreTable* score = new ScoreTable(player1, player2, ren, openSans, dices);



    newGameButton->setPlayers(player1, player2);

    ui.push_back(rollButton);
    ui.push_back(newGameButton);

    for (int i = 0; i < 5; i++) {
        ui.push_back(dices->getDicePointer(i));
    }

    for (int i = 0; i < 14; i++) {
        ui.push_back(new ScoreTableCell(1, 100, 30 * i + 50, player1, player2, turn, count));
        ui.push_back(new ScoreTableCell(1, 190, 30 * i + 50, player1, player2, turn, count));
    }



    while (run) {

        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, background, NULL, NULL);;

        dices->Draw(ren);
        newGameButton->newGameWrite("Nowa gra", newGamePos, openSans);
        score->write();

        while(SDL_PollEvent(&e)) {

            if (e.type == SDL_QUIT) {
                run = false;
            }

            if (e.type == SDL_MOUSEBUTTONUP && SDL_BUTTON(SDL_BUTTON_LEFT)) {
                SDL_GetMouseState(&mousex, &mousey);
                for (unsigned long i = 0; i < ui.size(); i++) {
                    if (ui[i]->checkBounds(mousex, mousey)) {
                        ui[i]->click();
                    }
                }
            }
        }

        SDL_RenderPresent(ren);

    }


    for (unsigned long i = 0; i < ui.size(); i++) {
        delete ui[i];
    }

    delete turn;
    delete count;
    delete score;
    delete openSans;
    delete player1;
    delete player2;
    delete dices;

    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(w);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}

