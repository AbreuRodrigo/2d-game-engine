#include "AssetSystem.h"
#include "TextureSystem.h"

AssetSystem::~AssetSystem()
{
    clearData();
};

void AssetSystem::clearData()
{
    textures.clear();
};

void AssetSystem::addTexture(std::string textureId, const char* filePath)
{
    textures.emplace(textureId, TextureSystem::loadTexture(filePath));
};

SDL_Texture* AssetSystem::getTexture(std::string textureId)
{
    return textures[textureId];
}; 