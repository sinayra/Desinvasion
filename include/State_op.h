#pragma once

#include "State.h"
#include "Background.h"
#include "Imagem.h"
#include "playAPCBase.h"
#include "Sound.h"

class State_op : public State{
    private:

        enum{
            CENA_0,
            CENA_1,
            CENA_2,
            CENA_3,
            NO_CHANGE
        };

        Background *instancebg;
        Imagem *instanceimg;
        Sound *instancesnd;

        int dialog1,dialog2;
        int grupoTelaInicial,grupoTelaPorco,grupoTelaOvelha,grupoTelaCitizen;
        Ponto pPrincipal;
        int cena, cenaant;

        milliseconds tic;
    public:
        void load(tipoGame stack = GAME_NO_CHANGE);
        void unload();
        tipoGame update();
        void render();
};
