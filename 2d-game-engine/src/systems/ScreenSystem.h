#pragma once

#include <glm.hpp>

class Game;

class ScreenSystem
{
public:
    static int getWidth();
    static int getHeight();

    static glm::vec2 getTopLeft();
    static glm::vec2 getTopCenter();
    static glm::vec2 getTopRight();
    static glm::vec2 getBottomLeft();
    static glm::vec2 getBottomCenter();
    static glm::vec2 getBottomRight();
    static glm::vec2 getMiddleLeft();
    static glm::vec2 getMiddleCenter();
    static glm::vec2 getMiddleRight();

private:
    friend class Game;

    static void setSize(int w, int h);
    static int width;
    static int height;
};

