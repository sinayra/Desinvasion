#pragma once

#include "State.h"
#include "Background.h"
#include "Imagem.h"
#include "Mateus.h"
#include "Ovelha.h"
#include "Tiro.h"
#include "playAPCBase.h"
#include "Progresso.h"
#include "Sound.h"
#include <vector>
#include <stdlib.h>

const int MAP_X_DIM = 10;
const int MAP_Y_DIM = 10;

class State_play : public State{
    private:
        typedef enum{
            VAZIO,
            OVELHA,
            TIRO,
            CONST0,
            CONST1,
            CONST2,
            ICC,
            INVADIDO
        }cellState;

        cellState mapaLogico[MAP_X_DIM][MAP_Y_DIM + 1];
        Ponto mapaVisu[MAP_X_DIM][MAP_Y_DIM + 1]; //esse +1 é para ajustar o ataque do Mateus, somente para a visualização do ataque

        Background *instancebg;
        Imagem *instanceimg;
        Mateus *mateus;
        vector<Ovelha*> ovelhas;
        Tiro *tiro;
        vector<Tiro*> constituicao;
        Progresso *progresso;

        milliseconds *tic, timer;
        int dificuldade, especial;

        void updateMateus(int ovelhas);
        void updateOvelhas();
        void updateTiro(Tiro *t, cellState st);
        int checkCollision();

        unsigned int random_uint(unsigned int limit);

        int vitoria;

    public:
        void load(tipoGame stack = GAME_NO_CHANGE);
        void unload();
        tipoGame update();
        void render();
};
