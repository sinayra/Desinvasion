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

void playAPCBase::tic(){
    glfwSetTime(0);
}

double playAPCBase::tac(){
    return glfwGetTime();
}
