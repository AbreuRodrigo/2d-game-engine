#pragma once

#include <SDL.h>
#include "../utils/KeyCode.h"

class InputSystem
{
public:
    static KeyCode getKeyCode();
    static bool isKeyDownEvent();
    static bool isKeyUpEvent();
    static bool getKeyDown(KeyCode keyCode);
    static bool getKeyUp(KeyCode keyCode);

private:
    static SDL_Event event;
    static bool processKey(KeyCode keyCode, int eventType);
};
