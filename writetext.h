#ifndef WRITETEXT_H
#define WRITETEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>


class WriteText
{
protected:
    TTF_Font* font;
    SDL_Color color {255, 255, 255, 255};
    SDL_Color colorSecondary {109, 109, 109, 255};
    SDL_Renderer* ren;

public:
    WriteText(std::string file, int size, SDL_Renderer *ren);
    ~WriteText();
    SDL_Rect write(std::string text, SDL_Point pos);
    SDL_Rect writeSecondary(std::string text, SDL_Point pos);
};

#endif // WRITETEXT_H
