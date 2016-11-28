#pragma once

#include "Input.h"
#include "Imagem.h"
#include "playAPCBase.h"

class Mateus
{
    public:
        Mateus(float x, float y, float tamw, float tamh, int i, int j);
        virtual ~Mateus();

        void update(int ovelhas_mortas);

        int getAtaque();

        int getCoordi();
        int getCoordj();

        void setCoordi(int i);
        void setCoordj(int j);

        void setPosicao(float x);

    private:
        int coordx, coordy;
        int coordi, coordj;
        int mateusq, mateusg;
        int combo_ovelhas = 0;
        int combo_ataque = 0;
        bool ataque = false;
        Imagem *instanceimg;
};
