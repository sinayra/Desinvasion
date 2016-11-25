#include "../include/State_end.h"

void State_end::load(tipoGame stack){
    cout << "Ending" << endl;
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

