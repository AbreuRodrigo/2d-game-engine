#include "Game.h"
#include "Sprite.h"
#include "systems/AssetSystem.h"

Sprite::Sprite(const char* fileName)
{
    setTexture(fileName);
    sourceRect.x = 0;
    sourceRect.y = 0;
};

Sprite::Sprite(const char* fileName, int width, int height)
{
    setTexture(fileName, width, height);
    sourceRect.x = 0;
    sourceRect.y = 0;
};

SDL_Texture* Sprite::getTexture() const
{
    return texture;
};

void Sprite::setTexture(const char* fileName)
{
    texture = Game::getAssetSystem()->getTexture(fileName);
    SDL_QueryTexture(texture, &format, nullptr, &width, &height);
    sourceRect.w = width;
    sourceRect.h = height;
};

void Sprite::setTexture(const char* fileName, int width, int height)
{
    texture = Game::getAssetSystem()->getTexture(fileName);
    format = SDL_PIXELFORMAT_ARGB8888;
    this->width = sourceRect.w = width;
    this->height = sourceRect.h = height;
};

SDL_Rect Sprite::getSourceRect() const
{
    return sourceRect;
};

SDL_Rect Sprite::getTargetRect() const
{
    return targetRect;
};

SDL_RendererFlip Sprite::getRendererFlip()
{
    return flip;
};

void Sprite::update(TransformComponent* transform, Animator2DComponent* animator2d)
{
    if (animator2d != nullptr)
    {
        sourceRect.x = (sourceRect.w * (SDL_GetTicks() / animator2d->getSpeed() % animator2d->getFrames()));
        sourceRect.y = animator2d->getIndex() * this->height;
    }
    else
    {
        sourceRect.y = 0 * this->height;
    }

    targetRect.x = static_cast<int>(transform->position.x);
    targetRect.y = static_cast<int>(transform->position.y);
    targetRect.w = static_cast<int>(width * transform->scale.x);
    targetRect.h = static_cast<int>(height * transform->scale.y);
};