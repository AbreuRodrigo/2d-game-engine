#pragma once

#include <SDL.h>
#include "Color.h"
#include "systems/AssetSystem.h"
#include "systems/EntitySystem.h"

class AssetSystem;
class TimeSystem;

class Game
{    
public:
    Game();
    Game(Color bgColor);
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

    //Components    
    SDL_Window* window;
    static AssetSystem* assetSystem;
    static SDL_Renderer* renderer;
    
    //Engine Methods
    void start();
    void loadLevel(int levelIndex);
    void processInput();
    void update();
    void render();
    void destroy();

private:
    friend class GameRunner;

    //Engine Methods
    void initialize();

    //System
    void initializeSDL();
    void initializeWindow();
    void initializeRenderer();
};
