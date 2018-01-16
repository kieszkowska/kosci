#ifndef SCORETABLECELL_H
#define SCORETABLECELL_H

#include <SDL2/SDL.h>
#include <iostream>

#include "clickable.h"
#include "writetext.h"


class ScoreTableCell : public Clickable
{
protected:
    SDL_Rect cell;

public:
    ScoreTableCell(int x, int y);
    void click();
};

#endif // SCORETABLECELL_H
