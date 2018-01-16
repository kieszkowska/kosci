#include "newgame.h"


NewGame::NewGame()
{

}

void NewGame::click()
{
    this->player1->resetScore();
    this->player2->resetScore();
}

void NewGame::newGameWrite(SDL_Renderer *ren, std::string text, SDL_Point pos, WriteText* writer)
{
    this->pos = writer->write(ren, text, pos);
}

void NewGame::setPlayers(Player *player1, Player *player2)
{
    this->player1 = player1;
    this->player2 = player2;
}
