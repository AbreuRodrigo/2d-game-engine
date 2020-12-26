#include <iostream>
#include <SDL.h>
#include "MyGame.h"
#include "../utils/Color.h"
#include "../utils/GameRunner.h"

int main(int argc, char* args[])
{
    GameRunner::run<MyGame>(Color::cornFlowerBlue);
    return 0;
}