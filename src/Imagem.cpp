#include "../include/Imagem.h"

Imagem *Imagem::instance = NULL;

Imagem* Imagem::getInstance(){
    if(!instance)
        instance = new Imagem();

    return instance;
}

Imagem::Imagem(){

    bg_jogo = AbreImagem("resources/PNG/Background.png");
    bg_inicio = AbreImagem("resources/PNG/Tela_Inicial.png");
    bg_end_lose = AbreImagem("resources/PNG/Tela_final_perde.png");
    bg_end_win = AbreImagem("resources/PNG/Tela_final.png");
    ovelha = AbreImagem("resources/PNG/ovelha.png");
    jogador[0] = AbreImagem("resources/PNG/Estudante_frame1_cartoon.png");
    jogador[1] = AbreImagem("resources/PNG/Estudante_frame2_catoon.png");
    livro = AbreImagem("resources/PNG/livro.png");
    nada = AbreImagem("resources/PNG/nada.png");
    cenario_dialogo = AbreImagem("resources/PNG/cenario_dialogo.png");
    dialogo1 = AbreImagem("resources/PNG/dialog1.png");
    dialogo2 = AbreImagem("resources/PNG/dialog2.png");
    dialogo4 = AbreImagem("resources/PNG/dialogo4_Napoleon.png");
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
            return ovelha;
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

        default:
            return nada;
        break;
    }
}

Imagem::~Imagem()
{
    //dtor
}
