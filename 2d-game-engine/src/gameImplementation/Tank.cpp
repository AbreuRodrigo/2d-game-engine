#include "Tank.h"

Tank::Tank(EntitySystem& entitySystem, std::string name): Entity(entitySystem, name)
{
};

void Tank::initialize()
{   
    this->addComponent<TransformComponent>(ScreenSystem::getMiddleCenter().x - 16, ScreenSystem::getBottomCenter().y - 32, 0.f, 0.f);
    this->addComponent<SpriteRendererComponent>("tankImage", 32, 32);
};

void Tank::update()
{
    transform->position.x += 20 * TimeSystem::getDeltaTime();
};