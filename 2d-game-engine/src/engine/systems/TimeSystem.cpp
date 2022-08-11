#include "TimeSystem.h"

float TimeSystem::deltaTime = .0f;
float TimeSystem::initialTime = .0f;

int TimeSystem::ticksLastFrame = 0;

//---------------------------------------------------------------------------------------------------------------------
void TimeSystem::initializeTime() {
    initialTime = now();
};

//---------------------------------------------------------------------------------------------------------------------
void TimeSystem::update() {
    // TODO: Consider improving frame independent movement with https://gafferongames.com/post/fix_your_timestep/
    int delay = TimeSystem::TARGET_FRAME_RATE - (SDL_GetTicks() - ticksLastFrame);
    if (delay > 0 && delay <= TimeSystem::TARGET_FRAME_RATE) {
        SDL_Delay(delay);
    };

    TimeSystem::deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    TimeSystem::deltaTime = (TimeSystem::deltaTime > .05f) ? .05f : TimeSystem::deltaTime;

    ticksLastFrame = SDL_GetTicks();
};

//---------------------------------------------------------------------------------------------------------------------
const float TimeSystem::getDeltaTime() {
    return deltaTime;
};

//---------------------------------------------------------------------------------------------------------------------
const float TimeSystem::getElapsedTime() {
    return now() - initialTime;
};

//---------------------------------------------------------------------------------------------------------------------
const float TimeSystem::now() {
    return static_cast<float>(time(0));
};
