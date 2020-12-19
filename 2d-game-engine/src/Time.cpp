#include "Time.h"

float Time::deltaTime = .0f;
float Time::initialTime = .0f;

void Time::initializeTime()
{
    initialTime = now();
};

const float Time::getDeltaTime()
{
    return deltaTime;
};

const float Time::getElapsedTime()
{
    return now() - initialTime;
};

const float Time::now()
{
    return static_cast<float>(time(0));
}