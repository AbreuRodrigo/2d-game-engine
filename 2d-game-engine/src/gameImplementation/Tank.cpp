#include "Tank.h"

Tank::Tank(EntitySystem& entitySystem, std::string name): Entity(entitySystem, name)
{
};

void Tank::initialize()
{   
    this->addComponent<TransformComponent>(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f, 0.f, 0.f);
    this->addComponent<SpriteRendererComponent>("tankImage", 32, 32);
};

void Tank::update()
{
    transform->position.x += 20 * Time::getDeltaTime();
};