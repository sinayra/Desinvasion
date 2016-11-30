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
            BG_END_LOSE,
            BG_END_WIN,
            BG_DIALOGO,
            DIALOGO1,
            DIALOGO2,
            DIALOGO4,
            NADA
        }tipoImg;

        int getImg(tipoImg img);
        static Imagem *getInstance();
    private:
        Imagem();
        ~Imagem();
        static Imagem *instance;

        int jogador[2], ovelha, livro, bg_jogo, bg_inicio, bg_end_lose, bg_end_win, nada, cenario_dialogo, dialogo1, dialogo2, dialogo4;
};
