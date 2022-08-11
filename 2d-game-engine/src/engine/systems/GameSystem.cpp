#include <iostream>
#include <glm/glm.hpp>
#include <SDL.h>
#include "GameSystem.h"
#include "AssetSystem.h"
#include "EntitySystem.h"
#include "LayerSystem.h"
#include "ScreenSystem.h"
#include "TimeSystem.h"
#include "InputSystem.h"
#include "../core/Map.h"
#include <SDL_image.h>

//Static
std::unique_ptr<AssetSystem> GameSystem::assetSystem(new AssetSystem());
std::unique_ptr<EntitySystem> GameSystem::entitySystem(new EntitySystem());
std::unique_ptr<LayerSystem> GameSystem::layerSystem(new LayerSystem());

SDL_Renderer* GameSystem::renderer;

//---------------------------------------------------------------------------------------------------------------------
SDL_Renderer* GameSystem::getRenderer() {
    return renderer;
};

//---------------------------------------------------------------------------------------------------------------------
Layer* GameSystem::createLayer(std::string layerLabel) {
    return layerSystem->createLayer(layerLabel);
};

//---------------------------------------------------------------------------------------------------------------------
std::vector<Layer*> GameSystem::listLayers() {
    return layerSystem->listLayers();
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::loadTextureAsset(std::string textureId, std::string texturePath) {
    assetSystem->addTexture(textureId, std::string(texturePath).c_str());
};

//---------------------------------------------------------------------------------------------------------------------
SDL_Texture* GameSystem::getTextureAsset(std::string textureId) {
    return assetSystem->getTexture(textureId);
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::initializeCamera(int xLimit, int yLimit) {
    Camera2DSystem::initialize(xLimit, yLimit);
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::updateCamera(float x, float y) {
    Camera2DSystem::update(x, y);
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::cameraFollowsEntity(Entity* entity) {
    //Camera2DSystem::update(entity->transform->position.x + entity->renderer->size.x * .5f, entity->transform->position.y + entity->renderer->size.y * .5f);
    Camera2DSystem::update(entity->transform->position.x, entity->transform->position.y);
};

//---------------------------------------------------------------------------------------------------------------------
GameSystem::GameSystem(Game* gameInstance) : 
    gameInstance(gameInstance), 
    window(nullptr),
    backgroundColor(gameInstance->bgColor) {
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::initialize() {
    std::cout << "Game initializing..." << std::endl;

    this->initializeSDL();

    TimeSystem::initializeTime();
    ScreenSystem::setSize(gameInstance->windowWidth, gameInstance->windowHeight);

    if (this->window != nullptr && this->renderer != nullptr) {
        startLayers();
        startGameLoop();
    };
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::startLayers() {
    layerSystem->createLayer(LayerLabel::TILEMAP);
    layerSystem->createLayer(LayerLabel::DEFAULT);
    layerSystem->createLayer(LayerLabel::GUI);
}

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::startGameLoop() {
    gameInstance->isRunning = true;

    std::cout << "Game running!" << std::endl;

    gameInstance->onSetup();
    gameInstance->onLevelLoaded(0);

    entitySystem->sortEntitiesByLayer(layerSystem.get());

    while (gameInstance->isRunning) {
        this->processInput();
        this->update();
        this->render();
    };

    this->destroy();
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::destroy() {
    std::cout << "Game finalizing..." << std::endl;

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();

    gameInstance->isRunning = false;
    gameInstance->onDestroy();

    this->~GameSystem();
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::processInput() {
    if (InputSystem::getKeyDown(KeyCode::ESCAPE) ||
        InputSystem::isCloseWindowEvent()) {
        gameInstance->isRunning = false;
    };
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::update() {
    TimeSystem::update();
    entitySystem->update();
    gameInstance->onUpdate();
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::render() {
    // Set the background color
    SDL_SetRenderDrawColor(this->renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);

    // Clear the back-buffer
    SDL_RenderClear(this->renderer);

    entitySystem->render();

    // Swap front-buffer and back-buffer
    SDL_RenderPresent(this->renderer);
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::initializeSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    };

    this->initializeWindow();
    this->initializeRenderer();

    if (gameInstance->isFullScreen) {
        SDL_GetWindowSize(window, &gameInstance->windowWidth, &gameInstance->windowHeight);
    };
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::initializeWindow() {
    const char* title = (gameInstance->screenTitle != nullptr) ? gameInstance->screenTitle : "Game Title";

    this->window = SDL_CreateWindow(
        !gameInstance->isFullScreen ? gameInstance->screenTitle : nullptr,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        gameInstance->windowWidth,
        gameInstance->windowHeight,
        gameInstance->isFullScreen ? SDL_WindowFlags::SDL_WINDOW_FULLSCREEN : SDL_WindowFlags::SDL_WINDOW_INPUT_FOCUS
    );

    if (this->window == nullptr) {
        std::cerr << "Error creating SDL window." << std::endl;
    };
};

//---------------------------------------------------------------------------------------------------------------------
void GameSystem::initializeRenderer() {
    if (this->window != nullptr) {
        this->renderer = SDL_CreateRenderer(this->window, -1, 0);

        if (this->renderer == nullptr) {
            std::cerr << "Error initializing SDL renderer." << std::endl;
        };
    };
}