#pragma once

#include "../Entity.h"
#include "../components/SpriteRendererComponent.h"
#include "../components/TransformComponent.h"

class Chopper : public Entity
{
public:
    Chopper(EntitySystem& entitySystem, std::string name);

protected:
    void initialize() override;
    void update() override;
};
