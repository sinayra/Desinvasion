#include "../include/Imagem.h"

Imagem *Imagem::instance = NULL;

Imagem* Imagem::getInstance(){
    if(!instance)
        instance = new Imagem();

    return instance;
}

Imagem::Imagem(){
    stringstream s;

    bg_jogo = AbreImagem("resources/PNG/Background.png");
    bg_inicio = AbreImagem("resources/PNG/Tela_Inicial.png");
    bg_end_lose = AbreImagem("resources/PNG/Tela_final_perde.png");
    bg_end_win = AbreImagem("resources/PNG/Tela_final.png");
    ovelha[0] = AbreImagem("resources/PNG/ovelha.png");
    ovelha[1] = AbreImagem("resources/PNG/ovelha_susto.png");
    ovelha[2] = AbreImagem("resources/PNG/ovelha_plus.png");
    ovelha[3] = AbreImagem("resources/PNG/ovelha_plus_susto.png");
    invadiu = AbreImagem("resources/PNG/trovelha.png");
    jogador[0] = AbreImagem("resources/PNG/Estudante_frame1_cartoon.png");
    jogador[1] = AbreImagem("resources/PNG/Estudante_frame2_catoon.png");
    livro = AbreImagem("resources/PNG/livro.png");
    constituicao = AbreImagem("resources/PNG/constituição.png");
    nada = AbreImagem("resources/PNG/nada.png");
    cenario_dialogo = AbreImagem("resources/PNG/cenario_dialogo.png");
    dialogo1 = AbreImagem("resources/PNG/dialog1.png");
    dialogo2 = AbreImagem("resources/PNG/dialog2.png");
    dialogo4 = AbreImagem("resources/PNG/dialogo4_Napoleon.png");

    for(int i = 0; i < 10; i++){
        s.str("");

        s << "resources/PNG/" << i << ".png";
        num[i] = AbreImagem(s.str().c_str());
    }
}

int Imagem::getImg(tipoImg img){
    switch(img){
        case Imagem::JOGADOR_STAND:
            return jogador[0];
        break;

        case Imagem::JOGADOR_ATTACK:
            return jogador[1];
        break;

        case Imagem::OVELHA:
            return ovelha[0];
        break;

        case Imagem::OVELHA_DANO:
            return ovelha[1];
        break;

        case Imagem::OVELHA_LIDER:
            return ovelha[2];
        break;

        case Imagem::OVELHA_LIDER_DANO:
            return ovelha[3];
        break;

        case Imagem::BG_INICIO:
            return bg_inicio;
        break;

        case Imagem::BG_JOGO:
            return bg_jogo;
        break;

        case Imagem::BG_END_LOSE:
            return bg_end_lose;
        break;

        case Imagem::BG_END_WIN:
            return bg_end_win;
        break;

        case Imagem::LIVRO:
            return livro;
        break;

        case Imagem::CONSTITUICAO:
            return constituicao;
        break;

        case Imagem::BG_DIALOGO:
            return cenario_dialogo;
        break;

        case Imagem::DIALOGO1:
            return dialogo1;
        break;

        case Imagem::DIALOGO2:
            return dialogo2;
        break;

        case Imagem::DIALOGO4:
            return dialogo4;
        break;

        case Imagem::INVADIU:
            return invadiu;
        break;

        case Imagem::NUM_0:
            return num[0];
        break;

        case Imagem::NUM_1:
            return num[1];
        break;

        case Imagem::NUM_2:
            return num[2];
        break;

        case Imagem::NUM_3:
            return num[3];
        break;

        case Imagem::NUM_4:
            return num[4];
        break;

        case Imagem::NUM_5:
            return num[5];
        break;

        case Imagem::NUM_6:
            return num[6];
        break;

        case Imagem::NUM_7:
            return num[7];
        break;

        case Imagem::NUM_8:
            return num[8];
        break;

        case Imagem::NUM_9:
            return num[9];
        break;

        case Imagem::NADA:
            return nada;
        break;
    }

    return nada;
}

Imagem::~Imagem()
{
    //dtor
}
