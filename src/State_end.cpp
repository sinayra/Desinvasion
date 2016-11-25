#include "../include/State_end.h"

void State_end::load(tipoGame stack){
    int img;

    instancebg = Background::getInstance();
    instanceimg = Imagem::getInstance();

    cout << "Ending" << endl;
    img = instanceimg->getImg(Imagem::BG_END);

    instancebg->setBG(img);
}

void State_end::unload(){

}

tipoGame State_end::update(){

    if(ApertouTecla(TECLA_ENTER))
        return GAME_END;

    return GAME_NO_CHANGE;
}

void State_end::render(){

    playAPCBase::render();
}

