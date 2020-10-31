#pragma once

#include <SDL.h>

class Game
{
public:
    Game(int width, int height, bool fullScreen);
    ~Game();

protected:
    int windowWidth = 0;
    int windowHeight = 0;
    bool isRunning = false;
    bool isFullScreen = false;

    //properties    
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    //functions
    void initialize();
    void destroy();
    void start();
    void processInput();
    void update();
    void render();

    //system
    void initializeWindow();
    void initializeRenderer();
};
