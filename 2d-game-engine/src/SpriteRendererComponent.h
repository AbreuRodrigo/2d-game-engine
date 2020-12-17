#pragma once

#include <SDL.h>
#include "Game.h"
#include "Color.h"
#include "Sprite.h"

class RendererComponent;
class TextureSystem;

class SpriteRendererComponent : public RendererComponent
{
private: 
    Sprite* sprite = nullptr;

public:
    SpriteRendererComponent(const char* spriteFileName, const Color color)
    {
        this->sprite = new Sprite(spriteFileName);
        this->size.x = sprite->originalSize.x;
        this->size.y = sprite->originalSize.y;
        this->color = color;
    };

    ~SpriteRendererComponent()
    {
        delete sprite;
    }

    void render() override
    {
        sprite->updatePosition(parent->getComponent<TransformComponent>());
        TextureSystem::drawSprite(sprite);
    };
};