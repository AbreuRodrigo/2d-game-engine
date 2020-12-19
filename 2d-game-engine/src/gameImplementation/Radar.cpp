#include "Radar.h"

Radar::Radar(EntitySystem& entitySystem, std::string name) : Entity(entitySystem, name)
{
};

void Radar::initialize()
{
    this->addComponent<TransformComponent>(WINDOW_WIDTH - (10.f + 64.f), 10.f);
    this->addComponent<SpriteRendererComponent>("radarImage", 64, 64);
    this->addComponent<Animator2DComponent>(8, 100, true, false);
};

void Radar::update()
{    
};