#pragma once

#include "Imagem.h"
#include "playAPCBase.h"
#include <iostream>

class Tiro
{
    public:
        Tiro(float x, float y, float tamw, float tamh, int i, int j);
        ~Tiro();

        int getCoordi();
        int getCoordj();

        void setCoordi(int i);
        void setCoordj(int j);

        bool getAtirou();

        void atira(int i, int j, bool especial);
        void cessa();
        void update();

        void setPosicao(int x, int y);

    private:
        bool atirou;
        int coordx, coordy, coordi, coordj, coordi_original, coordj_original;
        int tiroq, tirog, rot;
        Imagem *instanceimg;

        milliseconds tic;
};

