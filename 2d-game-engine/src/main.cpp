#include <iostream>
#include <SDL.h>
#include "Color.h"
#include "Game.h"
#include "GameRunner.h"

int main(int argc, char* args[])
{
    GameRunner::run<Game>(Color::cornFlowerBlue);
    return 0;
}