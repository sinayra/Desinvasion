#pragma once

#include "Input.h"
#include "Imagem.h"
#include <playAPC/playapc.h>

class Mateus
{
    public:
        Mateus(int x, int y, int tamw, int tamh);
        virtual ~Mateus();

        void update(int ovelhas_mortas);

    private:
        int coordx, coordy;
        int mateusq;
        int combo_ovelhas = 0;
        Imagem *instanceimg;
};

