#pragma once

#include <SDL.h>
#include <glm.hpp>
#include "TransformComponent.h"

class Game;
class AssetSystem;

class Sprite
{
private:
    SDL_Texture* texture = nullptr;
    SDL_Rect sourceRect;
    SDL_Rect targetRect;
    SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
    int width;
    int height;
    Uint32 format;

public:
    Sprite(const char* fileName);
    glm::vec2 originalSize;
    SDL_Texture* getTexture() const;
    SDL_Rect getSourceRect();
    SDL_Rect getTargetRect();
    SDL_RendererFlip getRendererFlip();
    void updatePosition(TransformComponent* transform);
};