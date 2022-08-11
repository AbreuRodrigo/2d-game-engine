#include <iostream>
#include "EntitySystem.h"
#include "LayerSystem.h"

//---------------------------------------------------------------------------------------------------------------------
EntitySystem::~EntitySystem() {
    clearData();
};

//---------------------------------------------------------------------------------------------------------------------
void EntitySystem::clearData() {
    // TODO Improve this
    for (auto& element : entitiesMap) {
        for (auto& entity : element.second) {
            entity->destroy();
        }
    }

    entitiesMap.clear();
    entitiesList.clear();
};

//---------------------------------------------------------------------------------------------------------------------
bool EntitySystem::isEmpty() {
    return entitiesMap.size() == 0;
};

//---------------------------------------------------------------------------------------------------------------------
void EntitySystem::sortEntitiesByLayer(LayerSystem* layerSystem) {
    if (layerSystem != nullptr) {
        entitiesList.clear();

        // TODO Improve this
        for (auto& layer : layerSystem->listLayers()) {
            auto entities = entitiesMap.find(layer->getLabel());

            if (entities != entitiesMap.end()) {
                entitiesList.emplace_back(entities->second);
            }
        }
    }
};

//---------------------------------------------------------------------------------------------------------------------
void EntitySystem::update() {
    // TODO Improve this
    for (auto& element : entitiesList) {
        for (auto& entity : element) {
            if (entity->active) {
                entity->update();
            }
        }
    }
};

//---------------------------------------------------------------------------------------------------------------------
void EntitySystem::render() {
    // TODO Improve this
    for (auto& element : entitiesList) {
        for (auto& entity : element) {
            if (entity->active) {
                entity->render();
            }
        }
    }
};

//---------------------------------------------------------------------------------------------------------------------
EntityList EntitySystem::getEntities(std::string layerLabel) const {
    return entitiesMap.at(layerLabel);
};

//---------------------------------------------------------------------------------------------------------------------
unsigned int EntitySystem::getEntityCount() {
    return static_cast<int>(entitiesMap.size());
};

//---------------------------------------------------------------------------------------------------------------------
void EntitySystem::listAllEntities() const {
    unsigned int i = 0;

    // TODO Improve this
    for (auto& element : entitiesMap) {
        for (auto& entity : element.second) {
            std::cout << "Entity[" << i << "]: " << entity->name << std::endl;
            entity->listAllComponents();
            i++;
        }
    }
};