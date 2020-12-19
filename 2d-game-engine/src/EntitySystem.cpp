#include <iostream>
#include "EntitySystem.h"

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

void EntitySystem::update()
{
    for (auto& entity : entities)
    {
        if (entity->active)
        {
            entity->update();
        }
    }
};

void EntitySystem::render()
{
    for (auto& entity : entities)
    {
        if (entity->active)
        {
            entity->render();
        }
    }
};

std::vector<Entity*> EntitySystem::getEntities() const
{
    return entities;
};

unsigned int EntitySystem::getEntityCount()
{
    return static_cast<int>(entities.size());
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