#pragma once

#include <SDL.h>
#include <glm/glm.hpp>
#include "../systems/AssetSystem.h"
#include "../core/BoundingBox2D.h"
#include "../systems/Camera2DSystem.h"
#include "../systems/EntitySystem.h"
#include "../systems/GameSystem.h"
#include "../systems/TextureSystem.h"
#include "../core/Color.h"
#include "../core/Entity.h"

class AssetSystem;
class GameSystem;

class TileRendererComponent : public RendererComponent
{
protected:
    std::shared_ptr<Texture2D> texture;
    int tileSize;
    int tileScale;
        
public:
    //-----------------------------------------------------------------------------------------------------------------
    TileRendererComponent(int sourceRectX, int sourceRectY, int tileSize, int tileScale, std::string textureId) : 
        TileRendererComponent(sourceRectX, sourceRectY, tileSize, tileScale, textureId, Color::white) {        
    };

    //-----------------------------------------------------------------------------------------------------------------
    TileRendererComponent(int sourceRectX, int sourceRectY, int tileSize, int tileScale, std::string textureId, const Color color) {
        this->texture = GameSystem::getTextureAsset(textureId);
        this->color = color;

        sourceRect.x = sourceRectX;
        sourceRect.y = sourceRectY;
        sourceRect.w = tileSize;
        sourceRect.h = tileSize;
        
        this->tileSize = tileSize;
        this->tileScale = tileScale;
    };

    //-----------------------------------------------------------------------------------------------------------------
    ~TileRendererComponent() {
        SDL_DestroyTexture(texture->getTextureReference());
    };

    //-----------------------------------------------------------------------------------------------------------------
    void render() override {
        SDL_Rect targetRect;
        targetRect.x = static_cast<int>(parent->transform->position.x - Camera2DSystem::getX());
        targetRect.y = static_cast<int>(parent->transform->position.y - Camera2DSystem::getY());
        targetRect.w = tileSize * tileScale;
        targetRect.h = tileSize * tileScale;

        //TextureSystem::drawTexture(texture, boundingBox.getRect(), targetRect);
        TextureSystem::drawTexture(texture, sourceRect, targetRect);
    };
};