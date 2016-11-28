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
    bg_end = AbreImagem("resources/PNG/Tela_final.png");
    ovelha = AbreImagem("resources/PNG/ovelha.png");
    jogador[0] = AbreImagem("resources/PNG/Estudante_frame1_cartoon.png");
    jogador[1] = AbreImagem("resources/PNG/Estudante_frame2_catoon.png");
    livro = AbreImagem("resources/PNG/livro.png");
    nada = AbreImagem("resources/PNG/nada.png");
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

        case Imagem::BG_END:
            return bg_end;
        break;

        case Imagem::LIVRO:
            return livro;
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
