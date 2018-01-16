#ifndef SCORETABLE_H
#define SCORETABLE_H

#include "player.h"
#include "writetext.h"
#include "dice.h"
#include "dices.h"
#include "countscore.h"

#include <SDL2/SDL.h>
#include <iostream>


class ScoreTable
{
protected:
    Player* player1;
    Player* player2;
    SDL_Renderer* ren;
    SDL_Point pos;
    WriteText* writer;
    Dices* dices;
    Dice* tab[5];
    CountScore* counter;

public:
    ScoreTable(Player *player1, Player *player2, SDL_Renderer *ren, WriteText *writer, Dices* dices);
    ~ScoreTable();
    void write();
};

#endif // SCORETABLE_H
