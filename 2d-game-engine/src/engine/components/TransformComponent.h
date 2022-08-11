#pragma once

#include <glm/glm.hpp>
#include "../core/Component.h"

class Component;

class TransformComponent : public Component {
public:
    glm::vec2 position;
    glm::vec2 scale;

    //-----------------------------------------------------------------------------------------------------------------
    TransformComponent() : position(glm::vec2(0.f, 0.f)), scale(glm::vec2(1.f, 1.f)) {
    };

    //-----------------------------------------------------------------------------------------------------------------
    TransformComponent(float xPosition, float yPosition) : scale(glm::vec2(1.f, 1.f)) {
        position = glm::vec2(xPosition, yPosition);
    };

    //-----------------------------------------------------------------------------------------------------------------
    TransformComponent(float xPosition, float yPosition, float xScale, float yScale) {
        position = glm::vec2(xPosition, yPosition);
        scale = glm::vec2(xScale, yScale);
    };
};
