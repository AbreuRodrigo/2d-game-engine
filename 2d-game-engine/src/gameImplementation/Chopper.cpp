#include "Chopper.h"

Chopper::Chopper(EntitySystem& entitySystem, std::string name) : Entity(entitySystem, name)
{
};

void Chopper::initialize()
{
    this->addComponent<TransformComponent>(WINDOW_WIDTH * 0.5f, 10, 0.f, 0.f);
    this->addComponent<SpriteRendererComponent>("chopperImage", 32, 32);
    this->addComponent<Animator2DComponent>(2, 75, false, true);
};

void Chopper::update()
{
    transform->position.y += 20 * Time::getDeltaTime();
};