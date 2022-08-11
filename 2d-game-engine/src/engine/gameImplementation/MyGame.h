#pragma once

#include "../core/Game.h"
#include "../core/GameRunner.h"

class MyGame : public Game {
public:
    MyGame(GameConfig gameConfig);

    virtual void onSetup();
    virtual void onLevelLoaded(int levelIndex);
    virtual void onDestroy();
    virtual void onUpdate();
};