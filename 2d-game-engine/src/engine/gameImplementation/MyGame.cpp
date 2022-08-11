#include "MyGame.h"
#include "entities/Chopper.h"
#include "../core/Map.h"

//---------------------------------------------------------------------------------------------------------------------
MyGame::MyGame(GameConfig gameConfig) : Game::Game(gameConfig) { };

Chopper* player;
std::unique_ptr<Map> map;

//---------------------------------------------------------------------------------------------------------------------
void MyGame::onSetup() {
    //GameSystem::createLayer(LayerLabel::TILEMAP);
    GameSystem::createLayer(LayerLabel::VEGETATION);
    GameSystem::createLayer(LayerLabel::ENEMY);
    GameSystem::createLayer(LayerLabel::PLAYER);
    GameSystem::createLayer(LayerLabel::PROJECTILE);
    //GameSystem::createLayer(LayerLabel::GUI);

    //GameSystem::loadTextureAsset("TankImage", "assets/images/tank-big-right.png");
    GameSystem::loadTextureAsset("ChopperImage", "assets/images/chopper-spritesheet.png");
    //GameSystem::loadTextureAsset("RadarImage", "assets/images/radar.png");
    GameSystem::loadTextureAsset("JungleTileTexture", "assets/tilemaps/jungle.png");
};

//---------------------------------------------------------------------------------------------------------------------
void MyGame::onLevelLoaded(int levelIndex) {
    map = std::unique_ptr<Map>(new Map("JungleTileTexture", 2, 32));
    map->loadMap("assets/tilemaps/jungle.map", 25, 20);// TODO change this once we have configs

    player = &GameSystem::createEntity<Chopper>("Chopper", LayerLabel::PLAYER);

    GameSystem::initializeCamera(map->getWidth(), map->getHeight());
};

//---------------------------------------------------------------------------------------------------------------------
void MyGame::onUpdate() {
    if (player != nullptr) {
        GameSystem::cameraFollowsEntity(player);
    }
};

//---------------------------------------------------------------------------------------------------------------------
void MyGame::onDestroy() {
};