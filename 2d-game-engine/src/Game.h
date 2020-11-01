#pragma once

#include <SDL.h>
#include "Color.h"

class Game
{
public:
    Game(int width, int height, bool fullScreen, Color bgColor);
    ~Game();

protected:
    Color bgColor = Color::black;
    int windowWidth = 0;
    int windowHeight = 0;
    bool isRunning = false;
    bool isFullScreen = false;

    //Components
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    //Methods
    void initialize();
    void start();
    void processInput();
    void update();
    void render();
    void destroy();

    //System
    void initializeWindow();
    void initializeRenderer();
};
