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
    void update(float deltaTime);
    void render();
    bool hasNoEntities();
    Entity& addEntity(std::string entityName);
    std::vector<Entity*> getEntities() const;
    unsigned int getEntityCount();
    void listAllEntities() const;
};

