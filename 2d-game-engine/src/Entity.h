#pragma once

#include <vector>
#include <string>
#include <type_traits>
#include "EntityManager.h"
#include "Component.h"
#include "TransformComponent.h"
#include "RendererComponent.h"

class EntityManager;

class Entity
{
private:
    EntityManager& entityManager;
    bool active;
    std::vector<Component*> components;

public:
    std::string name;

    Entity(EntityManager& entityManager);
    Entity(EntityManager& entityManager, std::string name);

    TransformComponent* transform;
    RendererComponent* renderer;

    void update(float deltaTime);
    void render();
    void destroy();
    bool isActive() const;

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... args)
    {
        T* component(new T(std::forward<TArgs>(args)...));
        component->parent = this;
        components.emplace_back(component);
        component->initialize();

        if (transform == nullptr)
        {
            transform = dynamic_cast<TransformComponent*>(component);
        }

        if (renderer == nullptr)
        {
            renderer = dynamic_cast<RendererComponent*>(component);
        }        

        return *component;
    };
};

