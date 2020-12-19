#include "Time.h"

float TimeSystem::deltaTime = .0f;
float TimeSystem::initialTime = .0f;

int TimeSystem::ticksLastFrame = 0;

void TimeSystem::initializeTime()
{
    initialTime = now();
};

void TimeSystem::update()
{
    int timeToWait = TimeSystem::TARGET_FRAME_RATE - (SDL_GetTicks() - ticksLastFrame);

    if (timeToWait > 0 && timeToWait <= TimeSystem::TARGET_FRAME_RATE)
    {
        SDL_Delay(timeToWait);
    }

    TimeSystem::deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    TimeSystem::deltaTime = (TimeSystem::deltaTime > .05f) ? .05f : TimeSystem::deltaTime;

    ticksLastFrame = SDL_GetTicks();
};

const float TimeSystem::getDeltaTime()
{
    return deltaTime;
};

const float TimeSystem::getElapsedTime()
{
    return now() - initialTime;
};

const float TimeSystem::now()
{
    return static_cast<float>(time(0));
};