#pragma once

#include <glm.hpp>
#include "../Component.h"

class Component;

class TransformComponent : public Component
{
public:
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec2 scale;

    TransformComponent() : position(glm::vec2(0.f, 0.f)), velocity(glm::vec2(0.f, 0.f)), scale(glm::vec2(1.f, 1.f))
    {        
    };

    TransformComponent(float xPosition, float yPosition) : velocity(glm::vec2(0.f, 0.f)), scale(glm::vec2(1.f, 1.f))
    {
        position = glm::vec2(xPosition, yPosition);
    };

    TransformComponent(float xPosition, float yPosition, float xVelocity, float yVelocity) : scale(glm::vec2(1, 1))
    {
        position = glm::vec2(xPosition, yPosition);
        velocity = glm::vec2(xVelocity, yVelocity);
    };

    TransformComponent(float xPosition, float yPosition, float xVelocity, float yVelocity, float xScale, float yScale)
    {
        position = glm::vec2(xPosition, yPosition);
        velocity = glm::vec2(xVelocity, yVelocity);
        scale = glm::vec2(xScale, yScale);
    };

    //void update() override
    //{
        //position.x += velocity.x * Time::getDeltaTime();
        //position.y += velocity.y * Time::getDeltaTime();
    //};
};
