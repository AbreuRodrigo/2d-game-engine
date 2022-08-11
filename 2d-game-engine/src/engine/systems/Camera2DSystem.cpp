#include "Camera2DSystem.h"
#include <iostream>

SDL_Rect Camera2DSystem::camera = { 0, 0, 0, 0 };
int Camera2DSystem::xLimit = 0;
int Camera2DSystem::yLimit = 0;

//---------------------------------------------------------------------------------------------------------------------
void Camera2DSystem::initialize(int xLim, int yLim) {
    Camera2DSystem::camera.w = ScreenSystem::getWidth();
    Camera2DSystem::camera.h = ScreenSystem::getHeight();
    Camera2DSystem::xLimit = xLim > ScreenSystem::getWidth() ? (xLim - ScreenSystem::getWidth()) : ScreenSystem::getWidth();
    Camera2DSystem::yLimit = yLim > ScreenSystem::getHeight() ? (yLim - ScreenSystem::getHeight()) : ScreenSystem::getHeight();
};

//---------------------------------------------------------------------------------------------------------------------
void Camera2DSystem::update(float x, float y) {
    Camera2DSystem::camera.x = static_cast<int>(x - ScreenSystem::getMiddleCenter().x);
    Camera2DSystem::camera.y = static_cast<int>(y - ScreenSystem::getMiddleCenter().y);

    int limitX = static_cast<int>(ScreenSystem::getMiddleCenter().x);
    int limitY = static_cast<int>(ScreenSystem::getMiddleCenter().y);

    Camera2DSystem::camera.x = Camera2DSystem::camera.x < 0 ? 0 : Camera2DSystem::camera.x;
    Camera2DSystem::camera.y = Camera2DSystem::camera.y < 0 ? 0 : Camera2DSystem::camera.y;
    Camera2DSystem::camera.x = Camera2DSystem::camera.x > Camera2DSystem::xLimit ? Camera2DSystem::xLimit : Camera2DSystem::camera.x;
    Camera2DSystem::camera.y = Camera2DSystem::camera.y > Camera2DSystem::yLimit ? Camera2DSystem::yLimit : Camera2DSystem::camera.y;
};

//---------------------------------------------------------------------------------------------------------------------
int Camera2DSystem::getX() {
    return Camera2DSystem::camera.x;
};

//---------------------------------------------------------------------------------------------------------------------
int Camera2DSystem::getY() {
    return Camera2DSystem::camera.y;
};