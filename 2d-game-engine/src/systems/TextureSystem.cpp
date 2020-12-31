#include <SDL.h>
#include <SDL_image.h>
#include "GameSystem.h"
#include "TextureSystem.h"

SDL_Texture* TextureSystem::loadTexture(const char* fileName)
{
    SDL_Surface* surface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(GameSystem::getRenderer(), surface);
    SDL_FreeSurface(surface);

    return texture;
};

void TextureSystem::drawTexture(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect)
{
    drawTexture(texture, sourceRect, destinationRect, SDL_RendererFlip::SDL_FLIP_NONE);
};

void TextureSystem::drawTexture(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(GameSystem::getRenderer(), texture, &sourceRect, &destinationRect, 0.0, nullptr, flip);
};

void TextureSystem::drawSprite(Sprite* sprite)
{
    drawTexture(sprite->getTexture(), sprite->getSourceRect(), sprite->getDestinationRect(), sprite->getRendererFlip());
};