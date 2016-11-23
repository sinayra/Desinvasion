#include "StateManager.h"

StateManager::StateManager(){

    estadoAtual = new State_op();
    estadoAtual->load();

    stack = GAME_START;
}

StateManager::~StateManager(){
    estadoAtual->unload();
    free(estadoAtual);
}

void StateManager::run(){
    bool quit;

    quit = estadoAtual->render();

    while(!quit){

        switch(estadoAtual->update(dt)){
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
    }
}
