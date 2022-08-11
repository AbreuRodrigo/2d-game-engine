#pragma once

#include <SDL.h>
#include "../core/Color.h"
#include "../core/Game.h"
#include "AssetSystem.h"
#include "Camera2DSystem.h"
#include "EntitySystem.h"
#include "LayerSystem.h"
#include "../utils/InternalConstants.h"

class AssetSystem;
class Camera2DSystem;
class EntitySystem;
class Game;
class LayerSystem;
class TimeSystem;

class GameSystem {
private: 
    friend class GameRunner;

    Color& backgroundColor;

    // Engine Methods
    void initialize();
    void startLayers();
    void startGameLoop();

    // System Methods
    void initializeSDL();
    void initializeWindow();
    void initializeRenderer();

protected:
    Game* gameInstance;
    SDL_Window* window;

    static std::unique_ptr<AssetSystem> assetSystem;
    static std::unique_ptr<EntitySystem> entitySystem;
    static std::unique_ptr<LayerSystem> layerSystem;

    static SDL_Renderer* renderer;

    // Engine Methods
    void processInput();
    void update();
    void render();
    void destroy();

public:
    GameSystem(Game* gameInstance);

    // LayerSystem Wrapper
    static Layer* createLayer(std::string layerLabel);
    static std::vector<Layer*> listLayers();

    static void initializeCamera(int xLimit, int yLimit);
    static void updateCamera(float x, float y);
    static void cameraFollowsEntity(Entity* entity);

    // EntitySystem Wrapper
    template <typename T>
    static T& createEntity(std::string entityName) {
        return createEntity<T>(entityName, LayerLabel::DEFAULT);
    };

    template <typename T>
    static T& createEntity(std::string entityName, std::string layerLabel) {
        return entitySystem->createEntity<T>(entityName, layerLabel);
    };

    // AssetSystem Wrapper
    static void loadTextureAsset(std::string textureId, std::string texturePath);
    static SDL_Texture* getTextureAsset(std::string textureId);

    static SDL_Renderer* getRenderer();
};

