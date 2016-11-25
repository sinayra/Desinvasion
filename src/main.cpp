#include "../include/State_manager.h"
#include "../include/playAPCBase.h"


int main (int argc, char *argv[]){

     if(playAPCBase::inicializaPlayAPC()){
        State_manager controleJogo;
        controleJogo.run();
     }

    return 0;
}
