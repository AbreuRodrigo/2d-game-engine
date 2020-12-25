#include <iostream>
#include <glm.hpp>
#include <SDL.h>
#include "../gameImplementation/Tank.h"
#include "../gameImplementation/Chopper.h"
#include "../gameImplementation/Radar.h"
#include "GameSystem.h"
#include "AssetSystem.h"
#include "ScreenSystem.h"
#include "TimeSystem.h"
#include "InputSystem.h"

//Static
EntitySystem entitySystem;

AssetSystem* GameSystem::assetSystem = new AssetSystem();
AssetSystem* GameSystem::getAssetSystem()
{
    return assetSystem;
};

SDL_Renderer* GameSystem::renderer;
SDL_Renderer* GameSystem::getRenderer()
{
    return renderer;
};

//Public
GameSystem::GameSystem() : GameSystem(bgColor)
{
};

GameSystem::GameSystem(Color bgColor) : isRunning(true), isFullScreen(true), bgColor(bgColor), screenTitle(""), window(nullptr)
{    
};

GameSystem::GameSystem(int width, int height, Color bgColor, const char* screenTitle) : window(nullptr)
{
    this->isRunning = false;
    this->isFullScreen = false;
    this->windowWidth = width;
    this->windowHeight = height;
    this->bgColor = bgColor;
    this->screenTitle = screenTitle;
};

GameSystem::~GameSystem()
{
    assetSystem->clearData();
    delete assetSystem;
};

//Engine Methods
void GameSystem::loadLevel(int levelIndex)
{
    assetSystem->addTexture("tankImage", std::string("../assets/images/tank-big-right.png").c_str());
    assetSystem->addTexture("chopperImage", std::string("../assets/images/chopper-spritesheet.png").c_str());
    assetSystem->addTexture("radarImage", std::string("../assets/images/radar.png").c_str());

    entitySystem.createEntity<Tank>("Tank");
    entitySystem.createEntity<Chopper>("Chopper");
    entitySystem.createEntity<Radar>("Radar");
};

void GameSystem::initialize()
{
    std::cout << "Game initializing..." << std::endl;

    this->initializeSDL();

    TimeSystem::initializeTime();
    ScreenSystem::setSize(windowWidth, windowHeight);

    if (this->window != nullptr && this->renderer != nullptr)
    {
        std::cout << "Game running!" << std::endl;

        loadLevel(0);

        this->isRunning = true;
        this->start();

        while (this->isRunning)
        {
            this->processInput();
            this->update();
            this->render();
        };

        this->destroy();
    }        
};

void GameSystem::destroy()
{
    std::cout << "Game finalizing..." << std::endl;

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();

    this->isRunning = false;
    this->~GameSystem();
};

void GameSystem::start() 
{
};

void GameSystem::processInput()
{
    if (InputSystem::getKeyDown(KeyCode::ESPACE))
    { 
        this->isRunning = false;
    };
};

void GameSystem::update()
{
    TimeSystem::update();
    entitySystem.update();
};

void GameSystem::render()
{
    SDL_SetRenderDrawColor(this->renderer, this->bgColor.r, this->bgColor.g, this->bgColor.b, this->bgColor.a);
    SDL_RenderClear(this->renderer);

    if (entitySystem.hasNoEntities())
    {
        return;
    }
    
    entitySystem.render();

    SDL_RenderPresent(this->renderer);
};

//System
void GameSystem::initializeSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    };

    this->initializeWindow();
    this->initializeRenderer();

    if (this->isFullScreen)
    {
        SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    }
};

void GameSystem::initializeWindow()
{
    const char* title = (this->screenTitle != nullptr) ? this->screenTitle : "Game Title";

    this->window = SDL_CreateWindow(
        !this->isFullScreen ? this->screenTitle : nullptr,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->windowWidth,
        this->windowHeight,
        this->isFullScreen ? SDL_WindowFlags::SDL_WINDOW_FULLSCREEN : SDL_WindowFlags::SDL_WINDOW_INPUT_FOCUS
    );

    if (this->window == nullptr)
    {
        std::cerr << "Error creating SDL window." << std::endl;
    };
};

void GameSystem::initializeRenderer()
{
    if (this->window != nullptr)
    {
        this->renderer = SDL_CreateRenderer(this->window, -1, 0);

        if (this->renderer == nullptr)
        {
            std::cerr << "Error initializing SDL renderer." << std::endl;
        };
    }
}