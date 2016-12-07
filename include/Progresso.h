#pragma once

#include "Imagem.h"
#include "playAPCBase.h"


class Progresso{
    public:
        Progresso();
        virtual ~Progresso();

        void setOvelhasRestantes(int qt);
    private:
        int progressog;
        int dezq, uniq;

        Imagem *instanceimg;

        int retornaNum(int n);
};

