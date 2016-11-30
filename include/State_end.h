#pragma once

#include "State.h"
#include "Background.h"
#include "Imagem.h"
#include "playAPCBase.h"
#include <windows.h>
#include <mmsystem.h>

class State_end : public State{

    public:
        void load(tipoGame stack = GAME_NO_CHANGE);
        void unload();
        tipoGame update();
        void render();

    private:
        enum{
            CENA_WIN,
            CENA_LOSE,
            NO_CHANGE
        };
        int cena;
        Background *instancebg;
        Imagem *instanceimg;

        milliseconds tic;
};
