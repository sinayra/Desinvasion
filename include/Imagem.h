#pragma once

#include <playAPC/playapc.h>

using namespace std;

class Imagem{
    public:
        typedef enum{
            JOGADOR_STAND,
            JOGADOR_ATTACK,
            OVELHA,
            LIVRO,
            BG_INICIO,
            BG_JOGO,
            BG_END,
            NADA
        }tipoImg;

        int getImg(tipoImg img);
        static Imagem *getInstance();
    private:
        Imagem();
        ~Imagem();
        static Imagem *instance;

        int jogador[2], ovelha, livro, bg_jogo, bg_inicio, bg_end, nada;
};
