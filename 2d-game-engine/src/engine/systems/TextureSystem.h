#pragma once

#include <SDL.h>
#include "GameSystem.h"
#include "../core/Sprite.h"

class GameSystem;

class TextureSystem {
public:
    static std::shared_ptr<Texture2D> loadTexture(const char* fileName);
    static void drawTexture(std::shared_ptr<Texture2D> texture, SDL_Rect sourceRect, SDL_Rect targetRect);
    static void drawTexture(std::shared_ptr<Texture2D> texture, SDL_Rect sourceRect, SDL_Rect targetRect, SDL_RendererFlip flip);
};