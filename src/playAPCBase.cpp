#include "../include/playAPCBase.h"

bool playAPCBase::inicializaPlayAPC(){
    AbreJanela(720, 480, "Desivasion Game");

    if(Desenha1Frame())
        return true;
    else
        return false;
}

void playAPCBase::render(){
    Desenha1Frame();
}

void playAPCBase::freeze(){
    if(Desenha1Frame())
        Desenha();
}

milliseconds playAPCBase::tempo(){
    return duration_cast< milliseconds >(system_clock::now().time_since_epoch());
}

bool playAPCBase::duracao(milliseconds tic, int tempo){
    if(duration_cast<milliseconds>(playAPCBase::tempo() - tic).count() > tempo)
        return true;
    else
        return false;
}
