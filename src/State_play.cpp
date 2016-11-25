#include "../include/State_play.h"

void State_play::load(tipoGame stack){
    cout << "Play" << endl;
}

void State_play::unload(){

}


void State_play::checkCollision(){

}

tipoGame State_play::update(){

    if(ApertouTecla(TECLA_ENTER))
        return GAME_WIN;

    return GAME_NO_CHANGE;
}

void State_play::render(){

    playAPCBase::render();
}
