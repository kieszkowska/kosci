#ifndef SCORETABLE_H
#define SCORETABLE_H

#include "player.h"
#include "writetext.h"

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

public:
    ScoreTable(Player *player1, Player *player2, SDL_Renderer *ren, WriteText *writer);
    void write();
};

#endif // SCORETABLE_H
