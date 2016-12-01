#pragma once

#include "playAPCBase.h"
#include "Imagem.h"
#include <playAPC/playapc.h>
#include <iostream>

using namespace std;

class Ovelha{
    public:
        typedef enum{
            VIVA,
            MORTA,
            INVADIU
        }tipoEstadoOvelha;

        Ovelha(float x, float y, float tamw, float tamh, int i, int j);
        virtual ~Ovelha();

        void update();
        void setPosicao(int y);

        int getCoordi();
        int getCoordj();

        void setCoordi(int i);
        void setCoordj(int j);
        void setVel(int v);

        void setAtingiu(bool acao);
        bool getAtingiu();

        void setEstado(tipoEstadoOvelha st);
        bool isViva();

    private:

        bool atingiu;
        int coordx, coordy, coordi, coordj;
        int ovelhaq, ovelhag;
        Imagem *instanceimg;
        int vel;
        milliseconds tic;

        tipoEstadoOvelha st;
};
