#include "TextureSystem.h"

#include <SDL.h>
#include <SDL_image.h>
#include "GameSystem.h"

//---------------------------------------------------------------------------------------------------------------------
std::shared_ptr<Texture2D> TextureSystem::loadTexture(const char* fileName) {
    auto texture = std::make_shared<Texture2D>(fileName);
    return texture;
};

//---------------------------------------------------------------------------------------------------------------------
void TextureSystem::drawTexture(std::shared_ptr<Texture2D> texture, SDL_Rect sourceRect, SDL_Rect targetRect) {
    drawTexture(texture, sourceRect, targetRect, SDL_RendererFlip::SDL_FLIP_NONE);
};

//---------------------------------------------------------------------------------------------------------------------
void TextureSystem::drawTexture(std::shared_ptr<Texture2D> texture, SDL_Rect sourceRect, SDL_Rect targetRect, SDL_RendererFlip flip) {
    double rotation = 0;
    SDL_RenderCopyEx(GameSystem::getRenderer(), texture->getTextureReference(), &sourceRect, &targetRect, rotation, nullptr, texture->getFlip());
};
