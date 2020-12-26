#pragma once

#include <SDL.h>
#include "../components/Animator2DComponent.h"
#include "../components/TransformComponent.h"

class GameSystem;
class AssetSystem;

class Sprite
{
private:
    friend class SpriteRendererComponent;

    SDL_Texture* texture = nullptr;
    SDL_Rect sourceRect;
    SDL_Rect targetRect;
    SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
    int width;
    int height;
    Uint32 format;

    void update(TransformComponent* transform, Animator2DComponent* animator2d);

public:
    Sprite(const char* textureId);
    Sprite(const char* textureId, int width, int height);
    SDL_Texture* getTexture() const;
    void setTexture(const char* textureId);
    void setTexture(const char* textureId, int width, int height);
    SDL_Rect getSourceRect() const;
    SDL_Rect getTargetRect() const;
    SDL_RendererFlip getRendererFlip();
};