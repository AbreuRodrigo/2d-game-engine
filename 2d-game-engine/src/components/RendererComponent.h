#pragma once

#include "TransformComponent.h"
#include "../utils/BoundingBox2D.h"
#include "../utils/Color.h"

class Component;
class TransformComponent;

class RendererComponent : public Component
{
public:
    BoundingBox2D boundingBox;
    Color color;

    RendererComponent() : color(Color::white), boundingBox({ 0, 0, 0, 0 })
    {
    };

    RendererComponent(float width, float height, Color& color) : color(color), boundingBox({ 0, 0, 0, 0 })
    {
    };

    ~RendererComponent()
    {
    };

    virtual void render() {}
};