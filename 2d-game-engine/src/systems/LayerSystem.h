#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../utils/Layer.h"

class LayerSystem
{
private:
    std::vector<Layer*> layers;
    std::map<std::string, Layer*> layersMap;

protected:
    void clearData();

public:
    ~LayerSystem();

    Layer* createLayer(std::string layerLabel);
    Layer* getLayerByLabel(std::string layerLabel);
    Layer* getLayerByIndex(int layerIndex);
    std::vector<Layer*> listLayers();
    bool hasLayer(std::string layerLabel);
    bool hasLayer(int layerIndex);
};
