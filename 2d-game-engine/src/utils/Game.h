#pragma once
#include "../systems/GameSystem.h"
#include "Color.h"

class Game
{
private:
    friend class GameSystem;

protected:
    bool isRunning = false;
    bool isFullScreen = false;

    Color bgColor = Color::black;
    const char* screenTitle;

    int windowWidth = 0;
    int windowHeight = 0;

public:
    Game() : Game(bgColor) { };
    Game(Color bgColor) : isRunning(true), isFullScreen(true), bgColor(bgColor), screenTitle("") { };
    Game(int width, int height, Color bgColor, const char* screenTitle)
    {
        this->isRunning = false;
        this->isFullScreen = false;
        this->windowWidth = width;
        this->windowHeight = height;
        this->bgColor = bgColor;
        this->screenTitle = screenTitle;
    };

    virtual void start() = 0;
    virtual void loadLevel(int levelIndex) = 0;
};
