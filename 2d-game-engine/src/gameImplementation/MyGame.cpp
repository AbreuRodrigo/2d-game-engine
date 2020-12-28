#include <iostream>
#include "MyGame.h"
#include "../gameImplementation/Tank.h"
#include "../gameImplementation/Chopper.h"
#include "../gameImplementation/Radar.h"
#include "../systems/GameSystem.h"
#include "../systems/LayerSystem.h"
#include "../utils/Map.h"

std::unique_ptr<Map> map;

MyGame::MyGame() : Game::Game() { };
MyGame::MyGame(Color bgColor) : Game::Game(bgColor) { };
MyGame::MyGame(int width, int height, Color bgColor, const char* screenTitle) : Game::Game(width, height, bgColor, screenTitle) { };

void MyGame::onStart()
{
    GameSystem::createLayer(LayerLabel::PLAYER);
    GameSystem::createLayer(LayerLabel::ENEMY);
    GameSystem::createLayer(LayerLabel::VEGETATION);
    GameSystem::createLayer(LayerLabel::PROJECTILE);

    GameSystem::loadTextureAsset("TankImage", "../assets/images/tank-big-right.png");
    GameSystem::loadTextureAsset("ChopperImage", "../assets/images/chopper-spritesheet.png");
    GameSystem::loadTextureAsset("RadarImage", "../assets/images/radar.png");
    GameSystem::loadTextureAsset("JungleTileTexture", "../assets/tilemaps/jungle.png");
};

void MyGame::onLevelLoaded(int levelIndex)
{
    map = std::unique_ptr<Map>(new Map("JungleTileTexture", 2, 32));
    map->loadMap("../assets/tilemaps/jungle.map", 25, 20);// TODO change this once we have configs

    GameSystem::createEntity<Tank>("Tank");
    GameSystem::createEntity<Chopper>("Chopper");
    GameSystem::createEntity<Radar>("Radar");
};

void MyGame::onDestroy()
{
};