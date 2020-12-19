#pragma once

#include <SDL.h>
#include "Color.h"
#include "AssetSystem.h"
#include "EntitySystem.h"

class AssetSystem;
class Time;

class Game
{    
public:    
    Game(int width, int height, Color bgColor, bool fullScreen);
    Game(int width, int height, Color bgColor, const char* screenTitle);
    ~Game();

    static AssetSystem* getAssetSystem();
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
    SDL_Window* window;
    static AssetSystem* assetSystem;
    static SDL_Renderer* renderer;
    
    //Engine Methods
    void loadLevel(int levelIndex);
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
