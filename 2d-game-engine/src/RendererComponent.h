#pragma once

#include <glm.hpp>
#include "Color.h"

class Component;

class RendererComponent : public Component
{
public:
    RendererComponent() : color(Color::white)
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

    virtual void initialize() {}
    virtual void render() {}
};
