#include "MyGame.h"
#include "../core/GameRunner.h"

//---------------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    GameConfig gameConfig = {
        1280, // width
        720, // height
        false, // fullScreen
        Color::cornFlowerBlue, // backgroundColor
        nullptr // gameName
    };

    GameRunner::run<MyGame>(gameConfig);
    return 0;
}