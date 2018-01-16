#ifndef NEWGAME_H
#define NEWGAME_H

#include "clickable.h"
#include "writetext.h"
#include "player.h"

#include <iostream>

class NewGame : public Clickable
{
protected:
    Player* player1;
    Player* player2;

public:
    NewGame();
    void click();
    void newGameWrite(SDL_Renderer* ren, std::string text, SDL_Point pos, WriteText* writer);
    void setPlayers(Player* player1, Player* player2);
};

#endif // NEWGAME_H
