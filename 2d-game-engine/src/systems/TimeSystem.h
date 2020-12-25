#pragma once

#include <ctime>
#include <SDL.h>

class TimeSystem
{
private:
    friend class GameSystem;

    static const int FPS = 60;
    static const int TARGET_FRAME_RATE = 1000 / FPS;

    static int targetFrame;
    static int ticksLastFrame;

    static float deltaTime;
    static float initialTime;

    static void initializeTime();
    static void update();

public:
    static const float getDeltaTime();
    static const float getElapsedTime();
    static const float now();
};