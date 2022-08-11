#pragma once

#include <SDL.h>
#include "GameSystem.h"
#include "../core/Sprite.h"

class GameSystem;

class TextureSystem
{
public:
    static SDL_Texture* loadTexture(const char* fileName);
    static void drawTexture(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect);
    static void drawTexture(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_RendererFlip flip);
};