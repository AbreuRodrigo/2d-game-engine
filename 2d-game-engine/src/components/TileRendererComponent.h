#pragma once

#include <SDL.h>
#include <glm.hpp>
#include "../systems/AssetSystem.h"
#include "../systems/Camera2DSystem.h"
#include "../systems/EntitySystem.h"
#include "../systems/GameSystem.h"
#include "../systems/TextureSystem.h"
#include "../utils/Color.h"
#include "../utils/Entity.h"

class AssetSystem;
class GameSystem;

class TileRendererComponent : public RendererComponent
{
protected:
    SDL_Texture* texture;

public:
    TileRendererComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string textureId) : 
        TileRendererComponent(sourceRectX, sourceRectY, x, y, tileSize, tileScale, textureId, Color::white)
    {        
    };

    TileRendererComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string textureId, const Color color)
    {
        texture = GameSystem::getTextureAsset(textureId);

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
    };

    ~TileRendererComponent()
    {
        SDL_DestroyTexture(texture);
    };

    void render() override
    {
        destinationRect.x = static_cast<int>(parent->transform->position.x - Camera2DSystem::getX());
        destinationRect.y = static_cast<int>(parent->transform->position.y - Camera2DSystem::getY());

        TextureSystem::drawTexture(texture, sourceRect, destinationRect);
    };
};