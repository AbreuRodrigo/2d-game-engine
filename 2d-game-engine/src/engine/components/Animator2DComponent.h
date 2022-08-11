#pragma once

#include <map>
#include <string>
#include "../core/Animation2D.h"
#include "../core/Component.h"
#include "../core/Entity.h"

class Component;

class Animator2DComponent : public Component {
private:
    bool fixed;
    unsigned int curAnimationIndex;
    unsigned int curAnimationFrames;
    unsigned int curAnimationSpeed;
    std::map<std::string, Animation2D> animations;
    std::string currentAnimation;

public:
    //-----------------------------------------------------------------------------------------------------------------
    Animator2DComponent(int frames, int speed, bool fixed, bool hasDirections) {
        this->curAnimationFrames = frames;
        this->curAnimationSpeed = speed;
        this->fixed = fixed;

        if (hasDirections) {
            Animation2D downAnimation = Animation2D(0, frames, speed);
            Animation2D rightAnimation = Animation2D(1, frames, speed);
            Animation2D leftAnimation = Animation2D(2, frames, speed);
            Animation2D upAnimation = Animation2D(3, frames, speed);

            animations.emplace("DownAnimation", downAnimation);
            animations.emplace("RightAnimation", rightAnimation);
            animations.emplace("LeftAnimation", leftAnimation);
            animations.emplace("UpAnimation", upAnimation);

            this->curAnimationIndex = 0;
            this->currentAnimation = "DownAnimation";
        }
        else {
            this->curAnimationIndex = curAnimationIndex;
            this->currentAnimation = "SimpleAnimation";
            Animation2D simpleAnimation = Animation2D(0, frames, speed);
            animations.emplace("SimpleAnimation", simpleAnimation);
        }

        play(this->currentAnimation);
    };

    //-----------------------------------------------------------------------------------------------------------------
    unsigned int getIndex() const {
        return curAnimationIndex;
    };

    //-----------------------------------------------------------------------------------------------------------------
    unsigned int getFrames() const {
        return curAnimationFrames;
    };

    //-----------------------------------------------------------------------------------------------------------------
    unsigned int getSpeed() const {
        return curAnimationSpeed;
    };

    //-----------------------------------------------------------------------------------------------------------------
    void play(std::string animationName) {
        if (animations.find(animationName) != animations.end()) {
            auto anim = animations[animationName];
            curAnimationIndex = anim.index;
            curAnimationFrames = anim.frames;
            curAnimationSpeed = anim.speed;
        }
    };
};