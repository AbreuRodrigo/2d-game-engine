#pragma once

#include <ctime>

class Time
{
private:
    friend class Game;

    static float deltaTime;
    static float initialTime;

    static void initializeTime();

public:
    static const float getDeltaTime();
    static const float getElapsedTime();
    static const float now();
};
