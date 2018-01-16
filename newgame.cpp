#include "newgame.h"


NewGame::NewGame()
{

}

void NewGame::click()
{
    this->player1->newGame();
    this->player2->newGame();
}

void NewGame::newGameWrite(std::string text, SDL_Point pos, WriteText* writer)
{
    this->pos = writer->write(text, pos);
}

void NewGame::setPlayers(Player *player1, Player *player2)
{
    this->player1 = player1;
    this->player2 = player2;
}
