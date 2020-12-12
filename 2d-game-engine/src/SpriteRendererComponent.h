#pragma once

#include <SDL.h>
#include "Game.h"
#include "Color.h"
#include "Constants.h"
#include "RendererComponent.h"

class SpriteRendererComponent : public RendererComponent
{
public:

    SpriteRendererComponent(float width, float height)
    {
        size = glm::vec2(width, height);
    };

    void render() override
    {
        SDL_Rect transformRectangle = {
            parent->transform->position.x,
            parent->transform->position.y,
            size.x,
            size.y
        };

        SDL_SetRenderDrawColor(Game::getRenderer(), Color::white.r, Color::white.g, Color::white.b, Color::white.a);
        SDL_RenderFillRect(Game::getRenderer(), &transformRectangle);
    };
};