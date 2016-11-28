#include "State_manager.h"

State_manager::State_manager(){
    input = input->getInstance();

    estadoAtual = new State_op();
    estadoAtual->load();

    input->update();

    stack = GAME_START;
}

State_manager::~State_manager(){

}

void State_manager::run(){
    int quit;

    do{
        quit = input->quitGame();

        switch(estadoAtual->update()){
            case GAME_NO_CHANGE:
            break;

            case GAME_END:
                quit = true;
            break;

            case GAME_WIN:
                stack = GAME_WIN;
                estadoAtual->unload();
                estadoAtual = new State_end();
                estadoAtual->load(stack);
            break;
            case GAME_LOSE:
                stack = GAME_LOSE;
                estadoAtual->unload();
                estadoAtual = new State_end();
                estadoAtual->load(stack);
            break;

            case GAME_START:
                estadoAtual->unload();
                estadoAtual = new State_op();
                estadoAtual->load(stack);
                stack = GAME_START;
            break;

            case GAME_PLAY:
                estadoAtual->unload();
                estadoAtual = new State_play();
                estadoAtual->load(stack);
                stack = GAME_PLAY;
            break;


        }

        estadoAtual->render();
    }while(!quit);

    cout << "Freeze" << endl;
    playAPCBase::freeze();
}
