#pragma once

#include "Game.h"

class Game;

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
        T* game = new T(backgroundColor);
        static_cast<Game*>(game)->initialize();
    };

    template <typename T>
    static void run(int windowWidth, int windowHeight, Color backgroundColor, const char* windowTitle)
    {
        static_assert(std::is_base_of<Game, T>::value, "GameRunner::run -> T must inherit from Game");

        T* game = new T(windowWidth, windowHeight, backgroundColor, windowTitle);
        static_cast<Game*>(game)->initialize();
    };
};