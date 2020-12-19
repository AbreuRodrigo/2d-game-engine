#include "ScreenSystem.h"

int ScreenSystem::width = 0;
int ScreenSystem::height = 0;

void ScreenSystem::setSize(int w, int h)
{
    width = w;
    height = h;
};

int ScreenSystem::getWidth()
{
    return width;
};

int ScreenSystem::getHeight()
{
    return height;
};

glm::vec2 ScreenSystem::getTopLeft()
{
    return glm::vec2(0.f, 0.f);
};

glm::vec2 ScreenSystem::getTopCenter()
{
    return glm::vec2(static_cast<float>(width) * .5f, 0.f);
};

glm::vec2 ScreenSystem::getTopRight() 
{
    return glm::vec2(static_cast<float>(width), 0.f);
};

glm::vec2 ScreenSystem::getBottomLeft() 
{
    return glm::vec2(0.f, static_cast<float>(height));
};

glm::vec2 ScreenSystem::getBottomCenter()
{
    return glm::vec2(static_cast<float>(width) * .5f, static_cast<float>(height));
};

glm::vec2 ScreenSystem::getBottomRight() 
{
    return glm::vec2(static_cast<float>(width), static_cast<float>(height));
};

glm::vec2 ScreenSystem::getMiddleLeft()
{
    return glm::vec2(0.f, static_cast<float>(height) * .5f);
};

glm::vec2 ScreenSystem::getMiddleCenter()
{
    return glm::vec2(static_cast<float>(width) * .5f, static_cast<float>(height) * .5f);
};

glm::vec2 ScreenSystem::getMiddleRight()
{
    return glm::vec2(static_cast<float>(width), static_cast<float>(height) * .5f);
};