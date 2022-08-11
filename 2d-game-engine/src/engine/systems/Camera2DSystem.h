#pragma once

#include <SDL.h>
#include "ScreenSystem.h"

class Camera2DSystem
{
private:
    static int xLimit, yLimit;
    static SDL_Rect camera;

public:
    static void initialize(int xLim, int yLim);
    static void update(float x, float y);
    static int getX();
    static int getY();
};