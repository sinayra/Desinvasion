#pragma once

#include <playAPC/playapc.h>
#include <sstream>

using namespace std;

class Imagem{
    public:
        typedef enum{
            JOGADOR_STAND,
            JOGADOR_ATTACK,
            OVELHA,
            OVELHA_DANO,
            OVELHA_LIDER,
            OVELHA_LIDER_DANO,
            LIVRO,
            CONSTITUICAO,
            BG_INICIO,
            BG_JOGO,
            BG_END_LOSE,
            BG_END_WIN,
            BG_DIALOGO,
            DIALOGO1,
            DIALOGO2,
            DIALOGO4,
            INVADIU,
            NADA,
            NUM_0,
            NUM_1,
            NUM_2,
            NUM_3,
            NUM_4,
            NUM_5,
            NUM_6,
            NUM_7,
            NUM_8,
            NUM_9,
        }tipoImg;

        int getImg(tipoImg img);
        static Imagem *getInstance();
    private:
        Imagem();
        ~Imagem();
        static Imagem *instance;

        int jogador[2], num[10], ovelha[4], livro, constituicao, bg_jogo, bg_inicio, bg_end_lose, bg_end_win, nada, cenario_dialogo, dialogo1, dialogo2, dialogo4, invadiu;
};
