#include <iostream>
#include <SDL.h>
#include "../systems/GameSystem.h"
#include "../utils/Color.h"
#include "../utils/GameRunner.h"

int main(int argc, char* args[])
{
    GameRunner::run<GameSystem>(Color::cornFlowerBlue);
    return 0;
}