#include "BoundingBox2D.h"

//---------------------------------------------------------------------------------------------------------------------
BoundingBox2D::BoundingBox2D(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->rect = SDL_Rect({ x, y, width, height });
};

//---------------------------------------------------------------------------------------------------------------------
SDL_Rect BoundingBox2D::getRect() {
    return rect;
};