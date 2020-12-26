#pragma once

#include <iostream>
#include "../utils/Game.h"
#include "../systems/GameSystem.h"

class Game;
class GameSystem;

class GameRunner
{
public:
    template <typename T>
    static void run()
    {
        GameRunner::run<T>(Color::black);
    };

    template <typename T>
    static void run(Color backgroundColor)
    {
        static_assert(std::is_base_of<Game, T>::value, "GameRunner::run -> T must inherit from Game");
        std::unique_ptr<T> gameInstance(new T(backgroundColor));
        std::unique_ptr<GameSystem> gameSystem(new GameSystem(gameInstance.get()));
        gameSystem->initialize();
    };

    template <typename T>
    static void run(int windowWidth, int windowHeight, Color backgroundColor, const char* windowTitle)
    {
        static_assert(std::is_base_of<Game, T>::value, "GameRunner::run -> T must inherit from Game");
        std::unique_ptr<T> gameInstance(new T(windowWidth, windowHeight, backgroundColor, windowTitle));
        std::unique_ptr<GameSystem> gameSystem(new GameSystem(gameInstance.get()));
        gameSystem->initialize();
    };
};