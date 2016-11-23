#include "State_op.h"

void State_op::load(int stack){
    bg = new Sprite("img/op.png");

    audio = new Audio("sfx/Invader Zim - Main Title Theme.mp3");

    iniciar = new Text("ttf/Vera.ttf", "(I)niciar", 20, 0, BLACK);
    sair = new Text("ttf/Vera.ttf", "(S)air", 20, 0, BLACK);

    audio->Play(-1);
    input = input->getInstance();
}

void State_op::unload(){
    delete(bg);
    delete(audio);

    delete(iniciar);
    delete(sair);
}

int State_op::update(int dt){

    if(input->isKeyUp(SDLK_s))
        return GAME_END;
    else if(input->isKeyDown(SDLK_i))
        return GAME_PLAY;

    return GAME_NO_CHANGE;
}

void State_op::render(){
    Ponto textPos;

    bg->render(0,0);


    textPos.x = 350;
    textPos.y = 370;
    iniciar->render(textPos);

    textPos.x = 350;
    textPos.y = 400;
    sair->render(textPos);
}

