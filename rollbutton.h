#ifndef ROLLBUTTON_H
#define ROLLBUTTON_H

#include <SDL2/SDL.h>


class RollButton
{
protected:
    SDL_Rect rect;

public:
    RollButton(int x, int y, int h, int w);
    bool checkBounds(int x, int y);
};

#endif // ROLLBUTTON_H
