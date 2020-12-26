#include <fstream>
#include "Map.h"
#include "../systems/GameSystem.h"
#include "../systems/EntitySystem.h"
#include "../components/TileRendererComponent.h"

Map::Map(std::string textureId, int scale, int tileSize)
{
    this->textureId = textureId;
    this->scale = scale;
    this->tileSize = tileSize;
};

Map::~Map()
{
};

void Map::loadMap(std::string filePath, int mapSizeX, int mapSizeY)
{
    std::fstream mapFile;
    mapFile.open(filePath);

    for (int y = 0; y < mapSizeY; y++)
    {
        for (int x = 0; x < mapSizeX; x++)
        {
            char mapChar;
            mapFile.get(mapChar);
            int sourceRectY = atoi(&mapChar) * tileSize;
            mapFile.get(mapChar);
            int sourceRectX = atoi(&mapChar) * tileSize;

            addTile(sourceRectX, sourceRectY, x * (scale * tileSize), y * (scale * tileSize));
            mapFile.ignore(); // To avoid reading the comma in the map file
        };
    };
};

void Map::addTile(int sourceRectX, int sourceRectY, int x, int y)
{
    Entity& tile(GameSystem::createEntity<Entity>("Tile"));
    tile.addComponent<TileRendererComponent>(sourceRectX, sourceRectY, x, y, tileSize, scale, textureId);
};