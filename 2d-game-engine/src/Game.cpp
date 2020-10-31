#include "Game.h"
#include <SDL.h>
#include <iostream>

//Public
Game::Game(int width, int height, bool fullScreen)
{
    this->windowWidth = width;
    this->windowHeight = height;
    this->isFullScreen = fullScreen;
    this->isRunning = false;

    this->initialize();
};

Game::~Game()
{    
};

void Game::initialize()
{
    std::cout << "Game initializing..." << std::endl;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializng SDL." << std::endl;
        return;
    };

    this->initializeWindow();
    this->initializeRenderer();

    if (this->window != nullptr && this->renderer != nullptr)
    {
        std::cout << "Game running!" << std::endl;
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
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();

    this->isRunning = false;
    this->~Game();
};

//Protected
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

};

void Game::render()
{
    SDL_SetRenderDrawColor(this->renderer, 100, 149, 237, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
};

//System
void Game::initializeWindow()
{
    this->window = SDL_CreateWindow(
        nullptr,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->windowWidth,
        this->windowHeight,
        this->isFullScreen ? SDL_WINDOW_FULLSCREEN : 0
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