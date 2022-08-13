#pragma once

#include <iostream>
#include "Game.h"
#include "GameConfig.h"
#include "../systems/GameSystem.h"

class GameRunner {
public:
    template <typename T>
    static void run(GameConfig gameConfig) {
        static_assert(std::is_base_of<Game, T>::value, "GameRunner::run -> T must inherit from Game.h");
        std::unique_ptr<T> game = std::make_unique<T>(gameConfig);
        std::unique_ptr<GameSystem> gameSystem = std::make_unique<GameSystem>(game.get());
        gameSystem->initialize();
    };
};