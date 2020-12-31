#include "Radar.h"

Radar::Radar(EntitySystem& entitySystem, std::string name) : Entity::Entity(entitySystem, name)
{
};

void Radar::initialize()
{
    this->addComponent<TransformComponent>(ScreenSystem::getTopRight().x - (10.f + 64.f), 10.f);
    this->addComponent<SpriteRendererComponent>("RadarImage", 64, 64, true);
    this->addComponent<Animator2DComponent>(8, 100, true, false);
};

void Radar::update()
{    
};