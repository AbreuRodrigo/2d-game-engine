#pragma once

#include <glm.hpp>
#include "Component.h"

class RendererComponent : public Component
{
public:
    glm::vec2 size;
    virtual void render() {}
};
