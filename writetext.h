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
    SDL_Surface* surf;
    SDL_Texture* tex;

public:
    WriteText(std::string file, int size);
    ~WriteText();
    SDL_Rect write(SDL_Renderer *ren, std::string text, SDL_Point pos);
};

#endif // WRITETEXT_H
