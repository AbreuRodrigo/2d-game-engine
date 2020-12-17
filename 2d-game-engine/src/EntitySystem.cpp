#include "EntitySystem.h"
#include <iostream>

void EntitySystem::clearData()
{
    for (auto& entity : entities)
    {
        entity->destroy();
    }
};

bool EntitySystem::hasNoEntities()
{
    return entities.size() == 0;
};

void EntitySystem::update(float deltaTime)
{
    for (auto& entity : entities)
    {
        entity->update(deltaTime);
    }
};

void EntitySystem::render()
{
    for (auto& entity : entities)
    {
        entity->render();
    }
};

Entity& EntitySystem::addEntity(std::string entityName)
{
    Entity* entity = new Entity(*this, entityName);
    entities.emplace_back(entity);

    return *entity;
};

std::vector<Entity*> EntitySystem::getEntities() const
{
    return entities;
};

unsigned int EntitySystem::getEntityCount()
{
    return (int) entities.size();
};

void EntitySystem::listAllEntities() const
{
    unsigned int i = 0;

    for (auto& entity : entities)
    {
        std::cout << "Entity[" << i << "]: " << entity->name << std::endl;
        entity->listAllComponents();
        i++;
    }
};