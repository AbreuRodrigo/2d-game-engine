#include "Entity.h"

Entity::Entity(EntityManager& entityManager) : entityManager(entityManager)
{
    this->active = true;
    this->transform = nullptr;
    this->renderer = nullptr;
};

Entity::Entity(EntityManager& entityManager, std::string name) : entityManager(entityManager), name(name)
{
    this->active = true;
    this->transform = nullptr;
    this->renderer = nullptr;
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
    if (renderer != nullptr)
    {
        renderer->render();
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
