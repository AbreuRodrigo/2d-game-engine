#pragma once

class Entity;

class Component
{
public:
    Entity* parent;
    virtual ~Component() {}
    virtual void initialize() {}
    virtual void update(float deltaTime) {}
};