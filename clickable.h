#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SDL2/SDL.h>


class Clickable
{
protected:
    SDL_Rect pos;

public:
    virtual ~Clickable() {}
    virtual void click() = 0;
    virtual bool checkBounds (int x, int y);

};

#endif // CLICKABLE_H
