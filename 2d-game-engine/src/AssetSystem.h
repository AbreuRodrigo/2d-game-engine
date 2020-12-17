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
    EntitySystem* entitySystem;
    std::map<std::string, SDL_Texture*> textures;

public:
    AssetSystem(EntitySystem* entitySystem);
    
    void clearData();
    void addTexture(std::string textureId, const char* filePath);
    SDL_Texture* getTexture(std::string textureId);
};

