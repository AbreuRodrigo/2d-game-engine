#pragma once

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <vector>
#include "Component.h"
#include "components/TransformComponent.h"
#include "components/RendererComponent.h"
#include "systems/EntitySystem.h"
#include "systems/ScreenSystem.h"
#include "systems/TimeSystem.h"

class Component;
class EntitySystem;
class TransformComponent;

class Entity
{
private:
    friend class EntitySystem;       
    
    std::vector<Component*> components;
    std::map<const std::type_info*, Component*> componentTypes;
        
    void render();

protected:
    bool active;

    EntitySystem& entitySystem;
        
    virtual void initialize();
    virtual void update();

public:
    Entity(EntitySystem& entitySystem, std::string name);

    std::string name;
        
    TransformComponent* transform;
    RendererComponent* renderer;

    void destroy();
    bool isActive() const;
    void setActive(bool active);
    void listAllComponents() const;
        
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... args)
    {
        T* component(new T(std::forward<TArgs>(args)...));
        component->parent = this;
        
        components.emplace_back(component);
        componentTypes[&typeid(*component)] = component;

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

