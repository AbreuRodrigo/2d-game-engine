#pragma once

#include <SDL.h>
#include "Color.h"
#include "EntityManager.h"

class Game
{
public:
    Game(int width, int height, Color bgColor, bool fullScreen);
    Game(int width, int height, Color bgColor, const char* screenTitle);
    ~Game();
        
    static SDL_Renderer* getRenderer();

protected:
    Color bgColor = Color::black;
    const char* screenTitle;

    //Window
    int windowWidth = 0;
    int windowHeight = 0;
    bool isFullScreen = false;

    //Core
    bool isRunning = false;

    //Time
    int ticksLastFrame = 0;

    //Components    
    EntityManager entityManager;
    SDL_Window* window;
    static SDL_Renderer* renderer;
    
    //Engine Methods
    void loadLevel(int levelNumber);
    void initialize();
    void start();
    void processInput();
    void update();
    void render();
    void destroy();

private:    
    //System
    void initializeSDL();
    void initializeWindow();
    void initializeRenderer();
};
