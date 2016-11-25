#pragma once

#include "State.h"

class State_op : public State{

    public:
        void load(tipoGame stack = GAME_NO_CHANGE);
        void unload();
        int update(int dt);
        void render();
};