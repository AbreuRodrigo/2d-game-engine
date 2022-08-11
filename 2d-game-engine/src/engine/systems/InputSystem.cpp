#include "InputSystem.h"
#include <iostream>

SDL_Event InputSystem::event;

//---------------------------------------------------------------------------------------------------------------------
KeyCode InputSystem::getKeyCode() {
    SDL_PollEvent(&event);
    return static_cast<KeyCode>(event.key.keysym.sym);
};

//---------------------------------------------------------------------------------------------------------------------
bool InputSystem::isKeyDownEvent() {
    return event.type == SDL_EventType::SDL_KEYDOWN;
};

//---------------------------------------------------------------------------------------------------------------------
bool InputSystem::isKeyUpEvent() {
    return event.type == SDL_EventType::SDL_KEYUP;
};

//---------------------------------------------------------------------------------------------------------------------
bool InputSystem::getKeyDown(KeyCode keyCode) {
    return InputSystem::processKey(keyCode, SDL_EventType::SDL_KEYDOWN);
};

//---------------------------------------------------------------------------------------------------------------------
bool InputSystem::getKeyUp(KeyCode keyCode) {
    return InputSystem::processKey(keyCode, SDL_EventType::SDL_KEYUP);
};

//---------------------------------------------------------------------------------------------------------------------
bool InputSystem::isCloseWindowEvent() {
    SDL_PollEvent(&event);
    return event.type == SDL_QUIT;
};

//---------------------------------------------------------------------------------------------------------------------
bool InputSystem::processKey(KeyCode keyCode, int eventType) {
    SDL_PollEvent(&event);
    KeyCode receivedKey = static_cast<KeyCode>(event.key.keysym.sym);

    if (eventType == event.type && receivedKey == keyCode) {
        return true;
    }

    return false;
};