#include "../include/State_op.h"

void State_op::load(tipoGame stack){
    cout << "Opening" << endl;
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

