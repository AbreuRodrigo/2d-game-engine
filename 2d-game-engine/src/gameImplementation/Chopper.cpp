#include "Chopper.h"

Chopper::Chopper(EntitySystem& entitySystem, std::string name) : Entity(entitySystem, name)
{
};

void Chopper::initialize()
{
    transform = &this->addComponent<TransformComponent>(ScreenSystem::getMiddleCenter().x - 16, ScreenSystem::getTopCenter().y, 0.f, 0.f);
    spriteRenderer = &this->addComponent<SpriteRendererComponent>("chopperImage", 32, 32);
    animator2D = &this->addComponent<Animator2DComponent>(2, 75, false, true);
};

void Chopper::update()
{
    if (InputSystem::isKeyDownEvent())
    {
        if (InputSystem::getKeyCode() == KeyCode::LEFT_ARROW || InputSystem::getKeyCode() == KeyCode::RIGHT_ARROW)
        {
            xSpeed = 30;
        }
        if (InputSystem::getKeyCode() == KeyCode::UP_ARROW || InputSystem::getKeyCode() == KeyCode::DOWN_ARROW)
        {
            ySpeed = 30;
        }
    }

    if (InputSystem::isKeyUpEvent())
    {
        if (InputSystem::getKeyCode() == KeyCode::LEFT_ARROW || InputSystem::getKeyCode() == KeyCode::RIGHT_ARROW)
        {
            xSpeed = 0;
        }
        if (InputSystem::getKeyCode() == KeyCode::UP_ARROW || InputSystem::getKeyCode() == KeyCode::DOWN_ARROW)
        {
            ySpeed = 0;
        }
    }

    if (InputSystem::getKeyDown(KeyCode::UP_ARROW))
    {
        transform->position.y -= ySpeed * TimeSystem::getDeltaTime();
        animator2D->play("UpAnimation");
    }
    
    if (InputSystem::getKeyDown(KeyCode::DOWN_ARROW))
    {
        transform->position.y += ySpeed * TimeSystem::getDeltaTime();
        animator2D->play("DownAnimation");
    }

    if (InputSystem::getKeyDown(KeyCode::LEFT_ARROW))
    {
        transform->position.x -= xSpeed * TimeSystem::getDeltaTime();
        animator2D->play("LeftAnimation");
    }

    if (InputSystem::getKeyDown(KeyCode::RIGHT_ARROW))
    {
        transform->position.x += xSpeed * TimeSystem::getDeltaTime();
        animator2D->play("RightAnimation");
    }


};