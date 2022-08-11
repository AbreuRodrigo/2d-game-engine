#pragma once

#include <map>
#include <string>
#include <vector>
#include "../systems/LayerSystem.h"
#include "../core/Entity.h"
#include "../core/Component.h"
#include "../utils/InternalTypes.h"

class Entity;
class LayerSystem;

class EntitySystem {
private:
    std::map<std::string, EntityList> entitiesMap;
    std::vector<EntityList> entitiesList;

protected:
    void clearData();

public:
    ~EntitySystem();

    void sortEntitiesByLayer(LayerSystem* layerSystem);
    void update();
    void render();
    bool isEmpty();
    EntityList getEntities(std::string layerLabel) const;
    unsigned int getEntityCount();
    void listAllEntities() const;

    template <typename T>
    T& createEntity(std::string entityName, std::string layerLabel) {
        static_assert(std::is_base_of<Entity, T>::value, "T must inherit from Entity");

        T* entity = new T(*this, entityName);
        static_cast<Entity*>(entity)->initialize();

        auto list = entitiesMap.find(layerLabel);

        if (list == entitiesMap.end()) {
            EntityList entityList;
            entityList.emplace_back(entity);
            entitiesMap.emplace(layerLabel, entityList);
        }
        else {
            list->second.emplace_back(entity);
        }

        return *entity;
    };
};