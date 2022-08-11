#include "GameConfig.h"

//---------------------------------------------------------------------------------------------------------------------
GameConfig::GameConfig(int windowWidth, int windowHeight) {
    this->width = windowWidth;
    this->height = windowHeight;
};

//---------------------------------------------------------------------------------------------------------------------
GameConfig::GameConfig(int windowWidth, int windowHeight, bool fullScreen) {
    this->width = windowWidth;
    this->height = windowHeight;
    this->fullScreen = fullScreen;
};

//---------------------------------------------------------------------------------------------------------------------
GameConfig::GameConfig(int windowWidth, int windowHeight, bool fullScreen, const Color bgColor, const char* gameName) : 
    bgColor(bgColor), gameName(gameName) {
    this->width = windowWidth;
    this->height = windowHeight;
    this->fullScreen = fullScreen;
};

//---------------------------------------------------------------------------------------------------------------------
int GameConfig::getWidth() {
    return width;
};

//---------------------------------------------------------------------------------------------------------------------
int GameConfig::getHeight() {
    return height;
};

//---------------------------------------------------------------------------------------------------------------------
const Color GameConfig::getBgColor() {
    return bgColor;
};

//---------------------------------------------------------------------------------------------------------------------
bool GameConfig::isFullScreen() {
    return fullScreen;
};

//---------------------------------------------------------------------------------------------------------------------
const char* GameConfig::getGameName() {
    return gameName;
};
