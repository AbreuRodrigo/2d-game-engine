#pragma once

#include <string>
#include <vector>
#include "../components/TileRendererComponent.h"

class Map {
private:
    std::string textureId;
    int scale;
    int tileSize;
    int width;
    int height;

public:
    Map(std::string textureId, int scale, int tileSize);
    ~Map();
    void loadMap(std::string filePath, int mapSizeX, int mapSizeY);
    void addTile(int sourceX, int sourceY, int x, int y);
    int getWidth();
    int getHeight();
};