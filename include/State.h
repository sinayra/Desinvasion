#pragma once

#include <iostream>
#include "playAPCBase.h"
#include "Input.h"

using namespace std;

typedef enum{
    GAME_NO_CHANGE,
    GAME_START,
    GAME_PLAY,
    GAME_WIN,
    GAME_LOSE,
    GAME_END
}tipoGame;


class State{
    public:
        virtual void load(tipoGame stack = GAME_NO_CHANGE) = 0;
        virtual void unload() = 0;
        virtual tipoGame update() = 0;
        virtual void render() = 0;
};
