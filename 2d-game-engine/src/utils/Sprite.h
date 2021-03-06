#pragma once

#include "../components/Animator2DComponent.h"
#include "../components/RendererComponent.h"
#include "../components/TransformComponent.h"
#include "../utils/BoundingBox2D.h"

class AssetSystem;
class GameSystem;

class Sprite
{
private:
    friend class SpriteRendererComponent;

    Animator2DComponent* parentAnimator2d = nullptr;
    RendererComponent* parentRenderer = nullptr;

    SDL_Texture* texture = nullptr;
    SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
    int width = 0;
    int height = 0;
    Uint32 format = 0;
    bool isInitialized = false;
    bool isStatic = false;

    void update();

public:
    Sprite(const char* textureId, bool isStatic);
    Sprite(const char* textureId, int width, int height, bool isStatic);
    int getWidth() const;
    int getHeight() const;
    SDL_Texture* getTexture() const;
    void setTexture(const char* textureId);
    void setTexture(const char* textureId, int width, int height);
    BoundingBox2D getBoundingBox() const;
    SDL_RendererFlip getRendererFlip();
    void initialize(RendererComponent* parentRenderer);
};