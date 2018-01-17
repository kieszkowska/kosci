#ifndef SCORETABLECELL_H
#define SCORETABLECELL_H

#include <SDL2/SDL.h>
#include <iostream>

#include "clickable.h"
#include "writetext.h"
#include "player.h"
#include "turn.h"
#include "countscore.h"


class ScoreTableCell : public Clickable
{
protected:
    SDL_Rect pos;
    Player* player1;
    Player* player2;
    Turn* turn;
    CountScore* count;
    int position;

public:
    ScoreTableCell(int pos, int x, int y, Player* player1, Player *player2, Turn *turn, CountScore *count);
    void click();
};

#endif // SCORETABLECELL_H
