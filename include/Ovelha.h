#pragma once

#include "playAPCBase.h"
#include "Imagem.h"
#include <iostream>

using namespace std;

class Ovelha{
    public:
        typedef enum{
            VIVA,
            VIVA_LIDER,
            MORTA,
            DANO,
            INVADIU
        }tipoEstadoOvelha;

        Ovelha(float x, float y, float tamw, float tamh, int i, int j);
        virtual ~Ovelha();

        void update();
        void setPosicao(int y);

        int getCoordi();
        int getCoordj();
        int getVel();
        int getRespawn();
        int getVida();

        void setCoordi(int i);
        void setCoordj(int j);
        void setVel(int v);
        void setRespawn(int v);
        void setVida(int vida);
        void decrementaVida();
        void ressucita(int vida);

        void setInvadiu(bool acao);
        bool getInvadiu();

        void setEstado(tipoEstadoOvelha st);
        bool isViva();
        bool isLider();

    private:

        bool invadiu, lider;
        int coordx, coordy, coordi, coordj;
        int ovelhaq, ovelhag;
        Imagem *instanceimg;
        int vel, respawn, vida;
        //int vida;
        milliseconds tic;

        tipoEstadoOvelha st;
};
