#pragma once

#include "State.h"
#include "Background.h"

class State_op : public State{

    public:
        void load(tipoGame stack = GAME_NO_CHANGE);
        void unload();
        tipoGame update();
        void render();
};
