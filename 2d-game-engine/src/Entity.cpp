#include "Entity.h"

Entity::Entity(EntityManager& entityManager) : entityManager(entityManager)
{
    this->active = true;
};

Entity::Entity(EntityManager& entityManager, std::string name) : entityManager(entityManager), name(name)
{
    this->active = true;
};

void Entity::update(float deltaTime)
{
    for (auto& component : components)
    {
        component->update(deltaTime);
    }
};

void Entity::render()
{
    for (auto& component : components)
    {
        component->render();
    }
};

void Entity::destroy()
{
    this->active = false;
};

bool Entity::isActive() const
{
    return this->active;
};
