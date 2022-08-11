#include "AssetSystem.h"
#include "TextureSystem.h"

//---------------------------------------------------------------------------------------------------------------------
AssetSystem::~AssetSystem() {
    clearData();
};

//---------------------------------------------------------------------------------------------------------------------
void AssetSystem::clearData() {
    for (auto& texture : textures) {
        SDL_DestroyTexture(texture.second);
    }

    textures.clear();
};

//---------------------------------------------------------------------------------------------------------------------
void AssetSystem::addTexture(std::string textureId, const char* filePath) {
    textures.emplace(textureId, TextureSystem::loadTexture(filePath));
};

//---------------------------------------------------------------------------------------------------------------------
SDL_Texture* AssetSystem::getTexture(std::string textureId) {
    return textures[textureId];
};