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
    int tileSize;
    int tileScale;

public:
    TileRendererComponent(int sourceRectX, int sourceRectY, int tileSize, int tileScale, std::string textureId) : 
        TileRendererComponent(sourceRectX, sourceRectY, tileSize, tileScale, textureId, Color::white)
    {        
    };

    TileRendererComponent(int sourceRectX, int sourceRectY, int tileSize, int tileScale, std::string textureId, const Color color)
    {
        texture = GameSystem::getTextureAsset(textureId);

        this->color = color;

        boundingBox.x = sourceRectX;
        boundingBox.y = sourceRectY;
        boundingBox.width = tileSize;
        boundingBox.height = tileSize;

        this->tileSize = tileSize;
        this->tileScale = tileScale;
    };

    ~TileRendererComponent()
    {
        SDL_DestroyTexture(texture);
    };

    void render() override
    {
        SDL_Rect rect;
        rect.x = static_cast<int>(parent->transform->position.x - Camera2DSystem::getX());
        rect.y = static_cast<int>(parent->transform->position.y - Camera2DSystem::getY());
        rect.w = tileSize * tileScale;
        rect.h = tileSize * tileScale;

        TextureSystem::drawTexture(texture, boundingBox.getRect(), rect);
    };
};