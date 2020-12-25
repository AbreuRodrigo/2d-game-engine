#pragma once

class Animation2D
{
public:
    unsigned int index;
    unsigned int frames;
    unsigned int speed;

    Animation2D();
    Animation2D(unsigned int index, unsigned int frames, unsigned int speed);
};