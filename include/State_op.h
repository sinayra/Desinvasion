#pragma once

#include "State.h"
#include "Background.h"
#include "Imagem.h"
#include "Mateus.h"

class State_op : public State{
    private:
        Background *instancebg;
        Imagem *instanceimg;
    public:
        void load(tipoGame stack = GAME_NO_CHANGE);
        void unload();
        tipoGame update();
        void render();
};
