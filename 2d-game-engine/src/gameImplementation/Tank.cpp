#include "Tank.h"

Tank::Tank(EntitySystem& entitySystem, std::string name): Entity::Entity(entitySystem, name)
{
};

void Tank::initialize()
{   
    this->addComponent<TransformComponent>(ScreenSystem::getMiddleCenter().x - 100, ScreenSystem::getMiddleCenter().y + 220);
    this->addComponent<SpriteRendererComponent>("TankImage", 32, 32);
};

void Tank::update()
{
    transform->position.x += 10 * TimeSystem::getDeltaTime();
};