#pragma once

#include <SDL.h>

class BoundingBox2D
{
public:
    int x;
    int y;
    int width;
    int height;

    BoundingBox2D(int x, int y, int width, int height);

    SDL_Rect getRect();
};

