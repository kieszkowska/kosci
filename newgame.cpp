#include "newgame.h"


NewGame::NewGame(SDL_Renderer *ren, std::string text, SDL_Point pos, WriteText writer)
{
    this->pos = writer.write(ren, text, pos);
}

NewGame::~NewGame()
{

}
