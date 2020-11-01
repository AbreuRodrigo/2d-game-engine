#include <iostream>
#include "Game.h"
#include "Constants.h"
#include "Color.h"
#include <SDL.h>

int main(int argc, char* args[])
{
    new Game(WINDOW_WIDTH, WINDOW_HEIGHT, true, Color::orange);
    return EXIT_APPLICATION;
}