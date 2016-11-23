#pragma once

#include "State.h"
#include "Background.h"

class State_op : public State{

    public:
        void load(int stack = 0);
        void unload();
        int update(int dt);
        void render();
};
