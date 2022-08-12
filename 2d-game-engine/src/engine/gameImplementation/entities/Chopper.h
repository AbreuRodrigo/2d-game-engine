#pragma once

#include "../../components/Animator2DComponent.h"
#include "../../components/SpriteRendererComponent.h"
#include "../../components/TransformComponent.h"
#include "../../core/Entity.h"

class Chopper : public Entity {
public:
    Chopper(EntitySystem& entitySystem, std::string name);
    float speed = 50;
protected:
    Animator2DComponent* animator2D = nullptr;
    SpriteRendererComponent* spriteRenderer = nullptr;

    void initialize() override;
    void update() override;

private:
    float xSpeed = 0;
    float ySpeed = 0;
};