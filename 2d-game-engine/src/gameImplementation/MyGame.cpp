#include <iostream>
#include "MyGame.h"
#include "../gameImplementation/Tank.h"
#include "../gameImplementation/Chopper.h"
#include "../gameImplementation/Radar.h"
#include "../systems/GameSystem.h"
#include "../systems/LayerSystem.h"
#include "../utils/Map.h"


MyGame::MyGame() : Game::Game() { };
MyGame::MyGame(Color bgColor) : Game::Game(bgColor) { };
MyGame::MyGame(int width, int height, Color bgColor, const char* screenTitle) : Game::Game(width, height, bgColor, screenTitle) { };

Chopper* player;
std::unique_ptr<Map> map;

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
    int mapZoom = 2;

    map = std::unique_ptr<Map>(new Map("JungleTileTexture", mapZoom, 32));
    map->loadMap("../assets/tilemaps/jungle.map", 35, 20);// TODO change this once we have configs

    player = &GameSystem::createEntity<Chopper>("Chopper", LayerLabel::PLAYER);

    GameSystem::createEntity<Tank>("Tank", LayerLabel::ENEMY);
    GameSystem::createEntity<Radar>("Radar", LayerLabel::GUI);

    GameSystem::initializeCamera(map->getWidth(), map->getHeight());
};

void MyGame::onUpdate()
{
    if (player != nullptr)
    {
        GameSystem::cameraFollowsEntity(player);
    }
};

void MyGame::onDestroy()
{
};