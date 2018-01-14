#ifndef NEWGAME_H
#define NEWGAME_H

#include "clickable.h"
#include "writetext.h"

#include <iostream>

class NewGame : public Clickable
{
protected:


public:
    NewGame(SDL_Renderer* ren, std::string text, SDL_Point pos, WriteText writer);
    ~NewGame();
    void click();
};

#endif // NEWGAME_H
