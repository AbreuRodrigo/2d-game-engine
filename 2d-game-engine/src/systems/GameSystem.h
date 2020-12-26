#pragma once

#include <SDL.h>
#include "../utils/Game.h"
#include "../utils/Color.h"
#include "AssetSystem.h"
#include "EntitySystem.h"

class AssetSystem;
class EntitySystem;
class Game;
class TimeSystem;

class GameSystem
{
private:
    friend class GameRunner;

    //Engine Methods
    void initialize();

    //System
    void initializeSDL();
    void initializeWindow();
    void initializeRenderer();

protected:
    //Components    
    Game* gameInstance;
    SDL_Window* window;

    static std::unique_ptr<AssetSystem> assetSystem;
    static std::unique_ptr<EntitySystem> entitySystem;
    static SDL_Renderer* renderer;

    //Engine Methods
    void processInput();
    void update();
    void render();
    void destroy();

public:
    GameSystem(Game* gameInstance);

    template <typename T>
    static T& createEntity(std::string entityName)
    {
        return entitySystem->createEntity<T>(entityName);
    };

    static SDL_Renderer* getRenderer();
    static void loadTextureAsset(std::string textureId, std::string texturePath);
    static SDL_Texture* getTextureAsset(std::string textureId);
};