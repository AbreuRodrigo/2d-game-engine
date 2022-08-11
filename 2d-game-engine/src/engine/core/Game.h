#pragma once

#include "Color.h"
#include "GameConfig.h"

class Game {
public:
    const char* screenTitle;

    bool isRunning = false;
    bool isFullScreen = false;

    int windowWidth = 0;
    int windowHeight = 0;

    Color bgColor = Color::black;

    Game(GameConfig gameConfig) {
        this->windowWidth = gameConfig.getWidth();
        this->windowHeight = gameConfig.getHeight();
        this->isFullScreen = gameConfig.isFullScreen();
        this->bgColor = gameConfig.getBgColor();
        this->screenTitle = gameConfig.getGameName();
        this->isRunning = false;
    };

    virtual void onSetup() = 0;
    virtual void onLevelLoaded(int levelIndex) = 0;
    virtual void onDestroy() = 0;
    virtual void onUpdate() = 0;
};
