#include "Animation2D.h"

Animation2D::Animation2D() : index(0), frames(0), speed(0)
{
};

Animation2D::Animation2D(unsigned int index, unsigned int frames, unsigned int speed)
{
    this->index = index;
    this->frames = frames;
    this->speed = speed;
};