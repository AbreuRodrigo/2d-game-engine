#pragma once

#include <map>
#include <string>
#include <SDL.h>
#include "TextureSystem.h"
#include "EntitySystem.h"
#include "../core/Texture2D.h"

class TextureSystem;
class Texture2d;

class AssetSystem {
private:
    std::map<std::string, std::shared_ptr<Texture2D>> textures;

protected:
    void clearData();

public:
    ~AssetSystem();

    void addTexture(std::string textureId, const char* filePath);
    std::shared_ptr<Texture2D> getTexture(std::string textureId);
};