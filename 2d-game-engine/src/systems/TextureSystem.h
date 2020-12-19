#pragma once

#include <SDL.h>
#include "../Game.h"
#include "../Sprite.h"

class Game;

class TextureSystem
{
public:
    static SDL_Texture* loadTexture(const char* fileName);
    static void drawTexture(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect targetRect, SDL_RendererFlip flip);
    static void drawSprite(Sprite* sprite);
};
