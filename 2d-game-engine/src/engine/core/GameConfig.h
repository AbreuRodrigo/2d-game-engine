#pragma once

#include "Color.h"

struct GameConfig {
private:
    int width;
    int height;
    bool fullScreen = true;
    const Color bgColor = Color::black;
    const char* gameName = nullptr;

public:
    GameConfig(int width, int height);
    GameConfig(int width, int height, bool fullScreen);
    GameConfig(int width, int height, bool fullScreen, const Color bgColor, const char* gameName);

    int getWidth();
    int getHeight();
    bool isFullScreen();
    const Color getBgColor();
    const char* getGameName();
};

