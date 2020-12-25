#pragma once

class Entity;

class Component
{
public:
    Entity* parent;
    virtual ~Component() {}
};