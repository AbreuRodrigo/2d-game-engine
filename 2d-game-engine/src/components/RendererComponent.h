#pragma once

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
    Color color;

    RendererComponent() : color(Color::white), sourceRect({ 0, 0, 0, 0 }), destinationRect({ 0, 0, 0, 0 })
    {
    };

    RendererComponent(float width, float height, Color& color) : color(color), sourceRect({ 0, 0, 0, 0 }), destinationRect({ 0, 0, 0, 0 })
    {
    };

    ~RendererComponent()
    {
    };


    virtual void render() {}
};