#pragma once

#include "../systems/GameSystem.h"
#include "Color.h"
#include "InternalConstants.h"

class Game
{
private:
    friend class GameSystem;

protected:
    const char* screenTitle;

    bool isRunning = false;
    bool isFullScreen = false;

    int windowWidth = 0;
    int windowHeight = 0;

    Color bgColor = Color::black;

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

    virtual void onStart() = 0;
    virtual void onLevelLoaded(int levelIndex) = 0;
    virtual void onDestroy() = 0;
};
