#pragma once

#include "Imagem.h"
#include "playAPC/playapc.h"


class Progresso{
    public:
        Progresso();
        virtual ~Progresso();

        void setOvelhasRestantes(int qt);
    private:
        int grupo3, grupo4;
        int dezq, uniq;

        Imagem *instanceimg;

        int retornaNum(int n);
};

