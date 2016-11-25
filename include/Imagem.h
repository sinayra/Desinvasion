#pragma once

#include <playAPC/playapc.h>

using namespace std;

class Imagem{
    public:
        typedef enum{
            JOGADOR_1,
            JOGADOR_2,
            OVELHA,
            LIVRO,
            BG_INICIO,
            BG_JOGO,
            BG_END
        }tipoImg;

        int getImg(tipoImg img);
        static Imagem *getInstance();
    private:
        Imagem();
        ~Imagem();
        static Imagem *instance;

        int jogador[2], ovelha, livro, bg_jogo, bg_inicio, bg_end, nada;
};
