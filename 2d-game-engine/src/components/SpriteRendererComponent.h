#pragma once

#include <SDL.h>
#include "../Game.h"
#include "../Color.h"
#include "../Sprite.h"

class RendererComponent;
class TextureSystem;

class SpriteRendererComponent : public RendererComponent
{
private:
    Sprite* sprite = nullptr;

public:
    SpriteRendererComponent(const char* spriteFileName)
    {
        this->sprite = new Sprite(spriteFileName);
        this->size.x = static_cast<float>(sprite->getSourceRect().x);
        this->size.y = static_cast<float>(sprite->getSourceRect().y);
        this->color = Color::white;
    };

    SpriteRendererComponent(const char* spriteFileName, int width, int height)
    {
        this->sprite = new Sprite(spriteFileName, width, height);
        this->size.x = static_cast<float>(sprite->getSourceRect().x);
        this->size.y = static_cast<float>(sprite->getSourceRect().y);
        this->color = Color::white;
    };

    SpriteRendererComponent(const char* spriteFileName, const Color color)
    {
        this->sprite = new Sprite(spriteFileName);
        this->size.x = static_cast<float>(sprite->getSourceRect().x);
        this->size.y = static_cast<float>(sprite->getSourceRect().y);
        this->color = color;
    };

    ~SpriteRendererComponent()
    {
        delete sprite;
    };

    void setSpriteTexture(const char* spriteFileName)
    {
        sprite->setTexture(spriteFileName);
    };

    void render() override
    {
        sprite->update(parent->getComponent<TransformComponent>(), parent->getComponent<Animator2DComponent>());
        TextureSystem::drawSprite(sprite);
    };
};