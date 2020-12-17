#include "AssetSystem.h"
#include "Game.h"
#include "Sprite.h"

Sprite::Sprite(const char* fileName)
{
    texture = Game::getAssetSystem()->getTexture(fileName);
    SDL_QueryTexture(texture, &format, nullptr, &width, &height);
    originalSize = glm::vec2(width, height);
    sourceRect.x = 0;
    sourceRect.y = 0;
    sourceRect.w = width;
    sourceRect.h = height;
};

SDL_Texture* Sprite::getTexture() const
{
    return texture;
};

SDL_Rect Sprite::getSourceRect()
{
    return sourceRect;
};

SDL_Rect Sprite::getTargetRect()
{
    return targetRect;
};

SDL_RendererFlip Sprite::getRendererFlip()
{
    return flip;
};

void Sprite::updatePosition(TransformComponent* transform)
{
    targetRect.x = (int) transform->position.x;
    targetRect.y = (int) transform->position.y;
    targetRect.w = (int) (width * transform->scale.x);
    targetRect.h = (int) (height * transform->scale.y);
};