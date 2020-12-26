#pragma once

#include <SDL.h>
#include <glm.hpp>
#include "../systems/AssetSystem.h"
#include "../systems/EntitySystem.h"
#include "../systems/GameSystem.h"
#include "../systems/TextureSystem.h"
#include "../utils/Color.h"

class AssetSystem;
class GameSystem;

class TileRendererComponent : public RendererComponent
{
protected:
    SDL_Texture* texture;
    SDL_Rect sourceRect;
    SDL_Rect destinationRect;
    glm::vec2 position;

public:
    TileRendererComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string textureId) : TileRendererComponent(sourceRectX, sourceRectY, x, y, tileSize, tileScale, textureId, Color::white)
    {        
    };

    TileRendererComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string textureId, const Color color)
    {
        texture = GameSystem::getAssetSystem()->getTexture(textureId);

        this->size.x = static_cast<float>(sourceRectX);
        this->size.y = static_cast<float>(sourceRectY);
        this->color = color;

        sourceRect.x = sourceRectX;
        sourceRect.y = sourceRectY;
        sourceRect.w = tileSize;
        sourceRect.h = tileSize;

        destinationRect.x = x;
        destinationRect.y = y;
        destinationRect.w = tileSize * tileScale;
        destinationRect.h = tileSize * tileScale;

        position.x = static_cast<float>(x);
        position.y = static_cast<float>(y);
    };

    ~TileRendererComponent()
    {
        SDL_DestroyTexture(texture);
    };

    void render() override
    {
        TextureSystem::drawTexture(texture, sourceRect, destinationRect, SDL_RendererFlip::SDL_FLIP_NONE);
    };
};