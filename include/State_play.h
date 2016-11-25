#pragma once

#include "State.h"

class State_play : public State{
    private:

    public:
        void load(tipoGame stack = GAME_NO_CHANGE);
        void unload();
        int update(int dt);
        void render();

        void checkCollision(int dt);
};
