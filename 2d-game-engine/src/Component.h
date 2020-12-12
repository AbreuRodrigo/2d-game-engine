#pragma once

#include "Entity.h"

class Entity;

class Component
{
public:
    Entity* parent;
    virtual ~Component() {}
    virtual void initialize() {}
    virtual void update(float deltaTime) {}    
};