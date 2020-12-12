#pragma once

#include <SDL.h>
#include <glm.hpp>
#include "EntityManager.h"
#include "Component.h"
#include "Game.h"

class TransformComponent : public Component
{
public:
    glm::vec2 position;
    glm::vec2 velocity;
    int width;
    int height;
    int scale;

    TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
    {
        position = glm::vec2(posX, posY);
        velocity = glm::vec2(velX, velY);
        width = w;
        height = h;
        scale = s;
    };

    void initialize() override {

    };

    void update(float deltaTime) override
    {
        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;
    };

    void render() override
    {
        SDL_Rect transformRectangle = {
            (int)position.x,
            (int)position.y,
            width,
            height
        };

        SDL_SetRenderDrawColor(Game::getRenderer(), Color::white.r, Color::white.g, Color::white.b, Color::white.a);
        SDL_RenderFillRect(Game::getRenderer(), &transformRectangle);
    };
};

