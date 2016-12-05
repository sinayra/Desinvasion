#include "../include/State_end.h"

void State_end::load(tipoGame stack){
    int img;

    instancebg = Background::getInstance();
    instanceimg = Imagem::getInstance();

    if(stack == GAME_LOSE){
        img = instanceimg->getImg(Imagem::BG_END_LOSE);
        this->cena = State_end::CENA_LOSE;
    }
    else if(stack == GAME_WIN){
        img = instanceimg->getImg(Imagem::BG_END_WIN);
        this->cena = State_end::CENA_WIN;
    }
    else{
        img = instanceimg->getImg(Imagem::NADA);
    }

    instancebg->setBG(img);
}

void State_end::unload(){

}

tipoGame State_end::update(){

    if(this->cena == State_end::CENA_LOSE){
        this->tic = playAPCBase::tempo();
        Desenha1Frame();
        PlaySound("resources/SOUND/game_over.wav", NULL, SND_FILENAME);
    }
    else if(this->cena == State_end::CENA_WIN){
        this->tic = playAPCBase::tempo();
        Desenha1Frame();
        PlaySound("resources/SOUND/judge.wav", NULL, SND_FILENAME);
    }
    this->cena = State_end::NO_CHANGE;

    if(ApertouTecla(TECLA_ENTER) && playAPCBase::duracao(this->tic, 500))
        return GAME_END;

    return GAME_NO_CHANGE;
}

void State_end::render(){

    playAPCBase::render();
}

