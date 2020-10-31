#include <SDL.h>
#include "Game.h"
#include "Constants.h"
#include <stdio.h>
#include <iostream>

int main(int argc, char* args[])
{
    new Game(WINDOW_WIDTH, WINDOW_HEIGHT, true);
    return EXIT_APPLICATION;
}