#include "InputSystem.h"
#include <iostream>

SDL_Event InputSystem::event;

KeyCode InputSystem::getKeyCode()
{
    SDL_PollEvent(&event);
    return static_cast<KeyCode>(event.key.keysym.sym);
};

bool InputSystem::isKeyDownEvent() 
{
    return event.type == SDL_EventType::SDL_KEYDOWN;
};

bool InputSystem::isKeyUpEvent()
{
    return event.type == SDL_EventType::SDL_KEYUP;
};

bool InputSystem::getKeyDown(KeyCode keyCode)
{
    return InputSystem::processKey(keyCode, SDL_EventType::SDL_KEYDOWN);
};

bool InputSystem::getKeyUp(KeyCode keyCode)
{
    return InputSystem::processKey(keyCode, SDL_EventType::SDL_KEYUP);
};

bool InputSystem::processKey(KeyCode keyCode, int eventType)
{    
    //event.type == SDL_QUIT ||

    SDL_PollEvent(&event);
    KeyCode passedKey = static_cast<KeyCode>(event.key.keysym.sym);

    if (eventType == event.type && passedKey == keyCode)
    {        
        return true;
    }
    else if (eventType == event.type && passedKey == keyCode)
    {
        return true;
    }

    return false;
};