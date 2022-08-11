#pragma once

#include <SDL.h>
#include "../systems/Camera2DSystem.h"
#include "../systems/GameSystem.h"
#include "../systems/TextureSystem.h"
#include "../components/TransformComponent.h"
#include "../core/Color.h"
#include "../core/Sprite.h"

class RendererComponent;
class TextureSystem;

class SpriteRendererComponent : public RendererComponent {
private:
    std::unique_ptr<Sprite> sprite;

public:
    //-----------------------------------------------------------------------------------------------------------------
    SpriteRendererComponent(const char* spriteFileName, bool isStatic = false) {
        this->sprite = std::unique_ptr<Sprite>(new Sprite(spriteFileName, isStatic));
        //this->boundingBox.width = this->sprite->getWidth();
        //this->boundingBox.height = this->sprite->getHeight();
        this->sourceRect.w = this->sprite->getWidth();
        this->sourceRect.h = this->sprite->getHeight();
        this->color = Color::white;
    };

    //-----------------------------------------------------------------------------------------------------------------
    SpriteRendererComponent(const char* spriteFileName, int width, int height, bool isStatic = false) {
        this->sprite = std::unique_ptr<Sprite>(new Sprite(spriteFileName, width, height, isStatic));
        //this->boundingBox.width = this->sprite->getWidth();
        //this->boundingBox.height = this->sprite->getHeight();
        this->sourceRect.w = this->sprite->getWidth();
        this->sourceRect.h = this->sprite->getHeight();
        this->color = Color::white;
    };

    //-----------------------------------------------------------------------------------------------------------------
    SpriteRendererComponent(const char* spriteFileName, const Color color, bool isStatic = false) {
        this->sprite = std::unique_ptr<Sprite>(new Sprite(spriteFileName, isStatic));
        //this->boundingBox.width = this->sprite->getWidth();
        //this->boundingBox.height = this->sprite->getHeight();
        this->sourceRect.w = this->sprite->getWidth();
        this->sourceRect.h = this->sprite->getHeight();
        this->color = color;
    };

    //-----------------------------------------------------------------------------------------------------------------
    ~SpriteRendererComponent() {
    };

    //-----------------------------------------------------------------------------------------------------------------
    void setSpriteTexture(const char* spriteFileName) {
        sprite->setTexture(spriteFileName);
    };

    //-----------------------------------------------------------------------------------------------------------------
    void render() override {
        if (!sprite->isInitialized) {
            sprite->initialize(this);
        }

        sprite->update();

        SDL_Rect rect;
        rect.x = static_cast<int>(parent->transform->position.x) - (sprite->isStatic ? 0 : Camera2DSystem::getX());
        rect.y = static_cast<int>(parent->transform->position.y) - (sprite->isStatic ? 0 : Camera2DSystem::getY());
        rect.w = static_cast<int>(sprite->getWidth() * parent->transform->scale.x);
        rect.h = static_cast<int>(sprite->getHeight() * parent->transform->scale.y);

        //TextureSystem::drawTexture(sprite->getTexture(), sprite->getBoundingBox().getRect(), rect, sprite->flip);
        TextureSystem::drawTexture(sprite->getTexture(), sprite->getBoundingBox(), rect, sprite->flip);
    };
};
