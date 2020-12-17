#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <typeinfo>
#include <type_traits>
#include "EntitySystem.h"
#include "Component.h"
#include "TransformComponent.h"
#include "RendererComponent.h"

class Component;
class EntitySystem;
class TransformComponent;

class Entity
{
private:
    EntitySystem& entitySystem;
    bool active;
    std::vector<Component*> components;
    std::map<const std::type_info*, Component*> componentTypes;

public:
    std::string name;

    Entity(EntitySystem& entitySystem);
    Entity(EntitySystem& entitySystem, std::string name);

    TransformComponent* transform;
    RendererComponent* renderer;

    void update(float deltaTime);
    void render();
    void destroy();
    bool isActive() const;
    void listAllComponents() const;
        
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... args)
    {
        T* component(new T(std::forward<TArgs>(args)...));
        component->parent = this;
        
        components.emplace_back(component);
        componentTypes[&typeid(*component)] = component;

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

    template <typename T>
    T* getComponent()
    {
        return static_cast<T*>(componentTypes[&typeid(T)]);
    };

    template <typename T>
    bool hasComponent() const
    {
        return componentTypes.find(&typeid(T)) != componentTypes.end();
    };
};

