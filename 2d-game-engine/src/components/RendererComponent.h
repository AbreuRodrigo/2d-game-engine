#pragma once

#include <glm.hpp>
#include <SDL.h>
#include "TransformComponent.h"
#include "../utils/Color.h"

class Component;
class TransformComponent;

class RendererComponent : public Component
{
public:
    SDL_Rect sourceRect;
    SDL_Rect destinationRect;

    RendererComponent() : size(glm::vec2(0, 0)), color(Color::white), sourceRect({ 0, 0, 0, 0 }), destinationRect({ 0, 0, 0, 0 })
    {
    };

    RendererComponent(float width, float height, Color& color) : size(width, height), color(color), sourceRect({ 0, 0, 0, 0 }), destinationRect({ 0, 0, 0, 0 })
    {
    };

    ~RendererComponent()
    {
    };

    glm::vec2 size;
    Color color;

    virtual void render() {}
};