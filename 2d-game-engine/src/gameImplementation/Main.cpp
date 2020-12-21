#include <iostream>
#include <SDL.h>
#include "../Color.h"
#include "MyGame.h"
#include "../GameRunner.h"

int main(int argc, char* args[])
{
    GameRunner::run<MyGame>(Color::cornFlowerBlue);
    return 0;
}