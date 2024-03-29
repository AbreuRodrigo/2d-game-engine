#include "Chopper.h"
#include <iostream>

Chopper::Chopper(EntitySystem& entitySystem, std::string name) : Entity::Entity(entitySystem, name) { };

void Chopper::initialize() {
    transform = &this->addComponent<TransformComponent>(ScreenSystem::getMiddleCenter().x - 16, ScreenSystem::getTopCenter().y);
    spriteRenderer = &this->addComponent<SpriteRendererComponent>("ChopperImage", 32, 32);
    animator2D = &this->addComponent<Animator2DComponent>(2, 100, false, true);
};

void Chopper::update() {
    //if (InputSystem::isKeyDownEvent()) {
    //    if (InputSystem::getKeyCode() == KeyCode::LEFT_ARROW || InputSystem::getKeyCode() == KeyCode::RIGHT_ARROW) {
    //        xSpeed = 30;
    //    }
    //    if (InputSystem::getKeyCode() == KeyCode::UP_ARROW || InputSystem::getKeyCode() == KeyCode::DOWN_ARROW) {
    //        ySpeed = 30;
    //    }
    //}

    //if (InputSystem::isKeyUpEvent()) {
    //    if (InputSystem::getKeyCode() == KeyCode::LEFT_ARROW || InputSystem::getKeyCode() == KeyCode::RIGHT_ARROW) {
    //        xSpeed = 0;
    //    }
    //    if (InputSystem::getKeyCode() == KeyCode::UP_ARROW || InputSystem::getKeyCode() == KeyCode::DOWN_ARROW) {
    //        ySpeed = 0;
    //    }
    //}

    //if (InputSystem::getKeyDown(KeyCode::UP_ARROW)) {
    //    transform->position.y -= 30 * TimeSystem::getDeltaTime();
    //    animator2D->play("UpAnimation");
    //}

    //if (InputSystem::getKeyDown(KeyCode::DOWN_ARROW)) {
    //    transform->position.y += 30 * TimeSystem::getDeltaTime();
    //    //animator2D->play("DownAnimation");
    //}

    //if (InputSystem::getKeyDown(KeyCode::LEFT_ARROW)) {
    //    transform->position.x -= 30 * TimeSystem::getDeltaTime();
    //    animator2D->play("LeftAnimation");
    //}

    //if (InputSystem::getKeyDown(KeyCode::RIGHT_ARROW)) {
    //    transform->position.x += 30 * TimeSystem::getDeltaTime();
    //    animator2D->play("RightAnimation");
    //}
    transform->position.y += speed * TimeSystem::getDeltaTime();
};