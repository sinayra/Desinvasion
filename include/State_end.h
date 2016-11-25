#pragma once

#include "State.h"
#include "Background.h"
#include "Imagem.h"

class State_end : public State{

    public:
        void load(tipoGame stack = GAME_NO_CHANGE);
        void unload();
        tipoGame update();
        void render();

    private:
        Background *instancebg;
        Imagem *instanceimg;
};
