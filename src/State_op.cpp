#include "../include/State_op.h"

void State_op::load(tipoGame stack){
    int img;

    instancebg = Background::getInstance();
    instanceimg = Imagem::getInstance();

    cout << "Opening" << endl;
    img = instanceimg->getImg(Imagem::BG_INICIO);

    instancebg->setBG(img);
}

void State_op::unload(){

}

tipoGame State_op::update(){

    if(ApertouTecla(TECLA_ENTER))
        return GAME_PLAY;

    return GAME_NO_CHANGE;
}

void State_op::render(){

    playAPCBase::render();
}

