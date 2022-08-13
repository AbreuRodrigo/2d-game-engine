#include "AssetSystem.h"
#include "TextureSystem.h"

//---------------------------------------------------------------------------------------------------------------------
AssetSystem::~AssetSystem() {
    clearData();
};

//---------------------------------------------------------------------------------------------------------------------
void AssetSystem::clearData() {
    for (auto& texture : textures) {
        SDL_DestroyTexture(texture.second->getTextureReference());
    }

    textures.clear();
};

//---------------------------------------------------------------------------------------------------------------------
void AssetSystem::addTexture(std::string textureId, const char* filePath) {
    textures.emplace(textureId, TextureSystem::loadTexture(filePath));
};

//---------------------------------------------------------------------------------------------------------------------
std::shared_ptr<Texture2D> AssetSystem::getTexture(std::string textureId) {
    return textures[textureId];
};