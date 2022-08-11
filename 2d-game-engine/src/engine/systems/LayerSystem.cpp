#include "LayerSystem.h"

//---------------------------------------------------------------------------------------------------------------------
LayerSystem::~LayerSystem() {
    clearData();
};

//---------------------------------------------------------------------------------------------------------------------
void LayerSystem::clearData() {
    layers.clear();
    layersMap.clear();
};

//---------------------------------------------------------------------------------------------------------------------
Layer* LayerSystem::createLayer(std::string layerLabel) {
    int layerIndex = static_cast<int>(layers.size());

    if (hasLayer(layerLabel)) {
        std::cerr << "LayerSystem::createLayer: There is alreay a layer labeled " << layerLabel << "." << std::endl;
        return nullptr;
    };

    if (hasLayer(layerIndex)) {
        std::cerr << "LayerSystem::createLayer: Something is wrong, there is alreay a layer with index " << 
            layerIndex << "." << std::endl;
        return nullptr;
    };

    // TODO Convert to smart pointer
    Layer* layer = new Layer(layerIndex, layerLabel);
    layers.push_back(layer);
    layersMap.emplace(layerLabel, layer);

    return layer;
};

//---------------------------------------------------------------------------------------------------------------------
Layer* LayerSystem::getLayerByLabel(std::string layerLabel) {
    if (!hasLayer(layerLabel)) {
        std::cerr << "LayerSystem::getLayerByLabel: There is no layer named " << layerLabel << "." << std::endl;
        return nullptr;
    };

    return layersMap.find(layerLabel)->second;
};

//---------------------------------------------------------------------------------------------------------------------
Layer* LayerSystem::getLayerByIndex(int layerIndex) {
    if (!hasLayer(layerIndex)) {
        std::cerr << "LayerSystem::getLayerByIndex: There is no layer with index " << layerIndex << "." << std::endl;
        return nullptr;
    };

    return layers[layerIndex];
};

//---------------------------------------------------------------------------------------------------------------------
std::vector<Layer*> LayerSystem::listLayers() {
    return layers;
};

//---------------------------------------------------------------------------------------------------------------------
bool LayerSystem::hasLayer(std::string layerLabel) {
    return layersMap.find(layerLabel) != layersMap.end();
};

//---------------------------------------------------------------------------------------------------------------------
bool LayerSystem::hasLayer(int layerIndex) {
    return layerIndex < layers.size();
};