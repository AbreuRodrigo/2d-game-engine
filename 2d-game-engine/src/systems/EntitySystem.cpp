#include <iostream>
#include "EntitySystem.h"
#include "LayerSystem.h"

EntitySystem::~EntitySystem()
{
    clearData();
};

void EntitySystem::clearData()
{
    for (auto& element : entitiesMap)
    {
        for (auto& entity : element.second)
        {
            entity->destroy();            
        }
    }

    entitiesMap.clear();
    entitiesList.clear();
};

bool EntitySystem::hasNoEntities()
{
    return entitiesMap.size() == 0;
};

void EntitySystem::sortEntities(LayerSystem* layerSystem)
{
    if (layerSystem != nullptr)
    {
        entitiesList.clear();

        for (auto& layer : layerSystem->listLayers())
        {
            auto entities = entitiesMap.find(layer->getLabel());

            if (entities != entitiesMap.end())
            {
                entitiesList.emplace_back(entities->second);
            }
        }
    }
};

void EntitySystem::update()
{
    for (auto& element : entitiesList)
    {
        for (auto& entity : element)
        {
            if (entity->active)
            {
                entity->update();
            }
        }
    }
};

void EntitySystem::render()
{
    for (auto& element : entitiesList)
    {
        for (auto& entity : element)
        {
            if (entity->active)
            {
                entity->render();
            }
        }
    }
};

EntityList EntitySystem::getEntities(std::string layerLabel) const
{
    return entitiesMap.at(layerLabel);
};

unsigned int EntitySystem::getEntityCount()
{
    return static_cast<int>(entitiesMap.size());
};

void EntitySystem::listAllEntities() const
{
    unsigned int i = 0;

    for (auto& element : entitiesMap)
    {
        for (auto& entity : element.second)
        {
            std::cout << "Entity[" << i << "]: " << entity->name << std::endl;
            entity->listAllComponents();
            i++;
        }
    }
};