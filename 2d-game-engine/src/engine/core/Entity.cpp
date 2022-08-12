#include "Entity.h"

//---------------------------------------------------------------------------------------------------------------------
Entity::Entity(EntitySystem& entitySystem, std::string name) : entitySystem(entitySystem), name(name) {
    this->active = true;

    // Transform will be automatically added to any entity created.
    // By default, the size of an entity will be considered 1, it might change when/if a renderer is added to it, 
    // so we'll need to update the transform position to make it centralize according to the visual size.
    //this->transform = &this->addComponent<TransformComponent>(
    //    ScreenSystem::getMiddleCenter().x - 16, 
    //    ScreenSystem::getTopCenter().y
    //);

    // Renderer will be null by default
    this->renderer = nullptr;

    this->initialize();
};

//---------------------------------------------------------------------------------------------------------------------
void Entity::initialize() {};

//---------------------------------------------------------------------------------------------------------------------
void Entity::update() {};

//---------------------------------------------------------------------------------------------------------------------
void Entity::render() {
    if (renderer != nullptr) {
        renderer->render();
    };
};

//---------------------------------------------------------------------------------------------------------------------
void Entity::destroy() {
    this->active = false;
};

//---------------------------------------------------------------------------------------------------------------------
bool Entity::isActive() const {
    return this->active;
};

//---------------------------------------------------------------------------------------------------------------------
void Entity::setActive(bool active) {
    this->active = active;
};

//---------------------------------------------------------------------------------------------------------------------
void Entity::listAllComponents() const {
    for (auto component : componentTypes) {
        std::cout << "Component<" << component.first->name() << ">" << std::endl;
    };
};