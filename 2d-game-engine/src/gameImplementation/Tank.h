#pragma once

#include "../components/SpriteRendererComponent.h"
#include "../components/TransformComponent.h"
#include "../utils/Entity.h"

class Tank : public Entity
{
public:
    Tank(EntitySystem& entitySystem, std::string name);

protected:
    void initialize() override;
    void update() override;
};
