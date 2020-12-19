#include <iostream>
#include <glm.hpp>
#include <SDL.h>
#include "AssetSystem.h"
#include "Constants.h"
#include "Game.h"
#include "Time.h"
#include "./gameImplementation/Tank.h"
#include "./gameImplementation/Chopper.h"
#include "./gameImplementation/Radar.h"

//Static
EntitySystem entitySystem;

AssetSystem* Game::assetSystem = new AssetSystem(&entitySystem);
AssetSystem* Game::getAssetSystem()
{
    return assetSystem;
};

SDL_Renderer* Game::renderer;
SDL_Renderer* Game::getRenderer()
{
    return renderer;
};

//Public
Game::Game(int width, int height, Color bgColor, bool fullScreen)
{
    this->isRunning = false;
    this->isFullScreen = fullScreen;
    this->windowWidth = width;
    this->windowHeight = height;
    this->bgColor = bgColor;

    this->initialize();
};

Game::Game(int width, int height, Color bgColor, const char* screenTitle)
{
    this->isRunning = false;
    this->isFullScreen = false;
    this->windowWidth = width;
    this->windowHeight = height;
    this->bgColor = bgColor;
    this->screenTitle = screenTitle;

    this->initialize();
};

Game::~Game()
{
    assetSystem->clearData();
    delete assetSystem;
};

//Engine Methods
void Game::loadLevel(int levelIndex)
{
    assetSystem->addTexture("tankImage", std::string("../assets/images/tank-big-right.png").c_str());
    assetSystem->addTexture("chopperImage", std::string("../assets/images/chopper-spritesheet.png").c_str());
    assetSystem->addTexture("radarImage", std::string("../assets/images/radar.png").c_str());

    entitySystem.createEntity<Tank>("Tank");
    entitySystem.createEntity<Chopper>("Chopper");
    entitySystem.createEntity<Radar>("Radar");
};

void Game::initialize()
{
    std::cout << "Game initializing..." << std::endl;

    Time::initializeTime();

    this->initializeSDL();

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

void Game::destroy()
{
    std::cout << "Game finalizing..." << std::endl;

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();

    this->isRunning = false;
    this->~Game();
};

void Game::start() 
{
};

void Game::processInput()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT || 
       (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
    { 
        this->isRunning = false;
    };
};

void Game::update()
{
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(timeToWait);
    }

    Time::deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    Time::deltaTime = (Time::deltaTime > 0.05f) ? 0.05f : Time::deltaTime;
            
    ticksLastFrame = SDL_GetTicks();

    entitySystem.update();
};

void Game::render()
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
void Game::initializeSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    };

    this->initializeWindow();
    this->initializeRenderer();
};

void Game::initializeWindow()
{
    const char* title = (this->screenTitle != nullptr) ? this->screenTitle : "Game Title";

    this->window = SDL_CreateWindow(
        !this->isFullScreen ? this->screenTitle : nullptr,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->windowWidth,
        this->windowHeight,
        this->isFullScreen ? SDL_WindowFlags::SDL_WINDOW_FULLSCREEN : SDL_WindowFlags::SDL_WINDOW_MAXIMIZED
    );

    if (this->window == nullptr)
    {
        std::cerr << "Error creating SDL window." << std::endl;
    };
};

void Game::initializeRenderer()
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