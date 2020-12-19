#pragma once

#include <map>
#include <string>
#include <SDL.h>
#include "TextureSystem.h"
#include "EntitySystem.h"

class TextureSystem;

class AssetSystem
{
private:
    std::map<std::string, SDL_Texture*> textures;

public:  
    void clearData();
    void addTexture(std::string textureId, const char* filePath);
    SDL_Texture* getTexture(std::string textureId);
};

