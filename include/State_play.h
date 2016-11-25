#pragma once

#include "State.h"
#include "Background.h"
#include "Imagem.h"
#include "Mateus.h"

const int MAP_X_DIM = 10;
const int MAP_Y_DIM = 10;

class State_play : public State{
    private:
        typedef enum{
            VAZIO,
            MATEUS,
            OVELHA,
            TIRO,
            ICC,
            INVADIDO
        }cellState;

        cellState mapaLogico[MAP_X_DIM][MAP_Y_DIM];
        Ponto mapaVisu[MAP_X_DIM][MAP_Y_DIM];
        Background *instancebg;
        Imagem *instanceimg;
        Mateus *mateus;

    public:
        void load(tipoGame stack = GAME_NO_CHANGE);
        void unload();
        tipoGame update();
        void render();

        void checkCollision();
};
