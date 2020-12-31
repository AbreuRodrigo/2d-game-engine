#pragma once

#include "../utils/Game.h"

class MyGame : public Game
{
public:
    MyGame();
    MyGame(Color bgColor);
    MyGame(int width, int height, Color bgColor, const char* screenTitle);

    virtual void onStart();
    virtual void onLevelLoaded(int levelIndex);
    virtual void onUpdate();
    virtual void onDestroy();
};

