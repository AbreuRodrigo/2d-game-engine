#pragma once

#include <vector>
#include "Entity.h"
#include "Component.h"

class Entity;

class EntitySystem
{
private:
    std::vector<Entity*> entities;

public:
    void clearData();
    void update();
    void render();
    bool hasNoEntities();
    std::vector<Entity*> getEntities() const;
    unsigned int getEntityCount();
    void listAllEntities() const;

    template <typename T>
    T& createEntity(std::string entityName)
    {
        static_assert(std::is_base_of<Entity, T>::value, "T must inherit from Entity");

        T* entity = new T(*this, entityName);
        static_cast<Entity*>(entity)->initialize();

        entities.emplace_back(entity);

        return *entity;
    };
};
