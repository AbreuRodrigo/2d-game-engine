#pragma once

#include <glm.hpp>
#include "../utils/Color.h"

class Component;

class RendererComponent : public Component
{
public:
    RendererComponent() : size(glm::vec2(0, 0)), color(Color::white)
    {
    };

    RendererComponent(float width, float height, Color& color) : size(width, height), color(color)
    {
    };

    ~RendererComponent()
    {
    };

    glm::vec2 size;
    Color color;

    virtual void render() {}
};