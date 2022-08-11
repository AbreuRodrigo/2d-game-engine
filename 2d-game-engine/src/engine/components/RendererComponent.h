#pragma once

#include "TransformComponent.h"
#include "../core/BoundingBox2D.h"
#include "../core/Color.h"

class Component;
class TransformComponent;

class RendererComponent : public Component {
public:
    //BoundingBox2D boundingBox;
    SDL_Rect sourceRect;
    Color color;

    //-----------------------------------------------------------------------------------------------------------------
    RendererComponent() : color(Color::white), sourceRect({0, 0, 0, 0}) {
    };

    //-----------------------------------------------------------------------------------------------------------------
    RendererComponent(float width, float height, Color& color) : color(color), sourceRect({ 0, 0, 0, 0 }) {
    };

    //-----------------------------------------------------------------------------------------------------------------
    ~RendererComponent() {
    };

    //-----------------------------------------------------------------------------------------------------------------
    virtual void render() {
    };
};
