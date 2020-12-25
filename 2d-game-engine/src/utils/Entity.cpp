#include "Entity.h"

Entity::Entity(EntitySystem& entitySystem, std::string name) : entitySystem(entitySystem), name(name)
{
    this->active = true;
    this->transform = nullptr;
    this->renderer = nullptr;

    this->initialize();
};

void Entity::initialize() { };

void Entity::update() { };

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

void Entity::setActive(bool active)
{
    this->active = active;
};

void Entity::listAllComponents() const
{
    for (auto component : componentTypes)
    {
        std::cout << "Component<" << component.first->name() << ">" << std::endl;
    }
};