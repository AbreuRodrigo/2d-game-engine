#include "Entity.h"

Entity::Entity(EntitySystem& entitySystem) : entitySystem(entitySystem)
{
    this->active = true;
    this->transform = nullptr;
    this->renderer = nullptr;
};

Entity::Entity(EntitySystem& entitySystem, std::string name) : entitySystem(entitySystem), name(name)
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

void Entity::listAllComponents() const
{
    for (auto component : componentTypes)
    {
        std::cout << "Component<" << component.first->name() << ">" << std::endl;
    }
};