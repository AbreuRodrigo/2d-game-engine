#pragma once

#include <SDL.h>
#include "../systems/GameSystem.h"
#include "../systems/TextureSystem.h"
#include "../components/TransformComponent.h"
#include "../utils/Color.h"
#include "../utils/Sprite.h"

class RendererComponent;
class TextureSystem;

class SpriteRendererComponent : public RendererComponent
{
private:
    std::unique_ptr<Sprite> sprite;

public:
    SpriteRendererComponent(const char* spriteFileName, bool isStatic = false)
    {
        this->sprite = std::unique_ptr<Sprite>(new Sprite(spriteFileName, isStatic));
        this->size.x = static_cast<float>(this->sourceRect.w = this->sprite->getWidth());
        this->size.y = static_cast<float>(this->sourceRect.h = this->sprite->getHeight());
        this->color = Color::white;
    };

    SpriteRendererComponent(const char* spriteFileName, int width, int height, bool isStatic = false)
    {
        this->sprite = std::unique_ptr<Sprite>(new Sprite(spriteFileName, width, height, isStatic));
        this->size.x = static_cast<float>(this->sourceRect.w = this->sprite->getWidth());
        this->size.y = static_cast<float>(this->sourceRect.h = this->sprite->getHeight());
        this->color = Color::white;
    };

    SpriteRendererComponent(const char* spriteFileName, const Color color, bool isStatic = false)
    {
        this->sprite = std::unique_ptr<Sprite>(new Sprite(spriteFileName, isStatic));
        this->size.x = static_cast<float>(this->sourceRect.w = this->sprite->getWidth());
        this->size.y = static_cast<float>(this->sourceRect.h = this->sprite->getHeight());
        this->color = color;
    };

    ~SpriteRendererComponent()
    {
    };

    void setSpriteTexture(const char* spriteFileName)
    {
        sprite->setTexture(spriteFileName);
    };

    void render() override
    {
        if (!sprite->isInitialized)
        {
            sprite->initialize(this);
        }

        sprite->update();
        TextureSystem::drawSprite(sprite.get());
    };
};