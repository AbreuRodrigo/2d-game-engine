#include "Sprite.h"
#include "Entity.h"
#include "../systems/GameSystem.h"
#include "../systems/AssetSystem.h"

//---------------------------------------------------------------------------------------------------------------------
Sprite::Sprite(const char* textureId, bool isStatic) {
    setTexture(textureId);
    this->isStatic = isStatic;
};

//---------------------------------------------------------------------------------------------------------------------
Sprite::Sprite(const char* textureId, int width, int height, bool isStatic) {
    setTexture(textureId, width, height);
    this->isStatic = isStatic;
};

//---------------------------------------------------------------------------------------------------------------------
int Sprite::getWidth() const {
    return width;
};

//---------------------------------------------------------------------------------------------------------------------
int Sprite::getHeight() const {
    return height;
};

//---------------------------------------------------------------------------------------------------------------------
SDL_Texture* Sprite::getTexture() const {
    return texture;
};

//---------------------------------------------------------------------------------------------------------------------
void Sprite::setTexture(const char* textureId) {
    texture = GameSystem::getTextureAsset(textureId);
    SDL_QueryTexture(texture, &format, nullptr, &width, &height);
};

//---------------------------------------------------------------------------------------------------------------------
void Sprite::setTexture(const char* textureId, int width, int height) {
    texture = GameSystem::getTextureAsset(textureId);
    format = SDL_PIXELFORMAT_ARGB8888;
    this->width = width;
    this->height = height;
};

//---------------------------------------------------------------------------------------------------------------------
//BoundingBox2D Sprite::getBoundingBox() const {
//    return parentRenderer->boundingBox;
//};
SDL_Rect Sprite::getBoundingBox() const {
    return parentRenderer->sourceRect;
};

//---------------------------------------------------------------------------------------------------------------------
SDL_RendererFlip Sprite::getRendererFlip() {
    return flip;
};

//---------------------------------------------------------------------------------------------------------------------
void Sprite::initialize(RendererComponent* parentRenderer) {
    if (this->isInitialized == false) {
        this->isInitialized = true;
        this->parentRenderer = parentRenderer;
        this->parentAnimator2d = parentRenderer->parent->getComponent<Animator2DComponent>();
    }
};

//---------------------------------------------------------------------------------------------------------------------
void Sprite::update() {
    if (parentAnimator2d != nullptr) {
        //parentRenderer->boundingBox.x = (parentRenderer->boundingBox.width * (SDL_GetTicks() / parentAnimator2d->getSpeed() % parentAnimator2d->getFrames()));
        //parentRenderer->boundingBox.y = parentAnimator2d->getIndex() * this->height;
        parentRenderer->sourceRect.x = (parentRenderer->sourceRect.w * (SDL_GetTicks() / parentAnimator2d->getSpeed() % parentAnimator2d->getFrames()));
        parentRenderer->sourceRect.y = parentAnimator2d->getIndex() * this->height;
    }
    else {
        //parentRenderer->boundingBox.y = 0 * this->height;
        parentRenderer->sourceRect.y = 0 * this->height;
    }
};