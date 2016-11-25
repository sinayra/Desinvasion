#include "../include/Input.h"

Input *Input::instance = NULL;

Input::Input(){
    quit = false;
}

Input* Input::getInstance(){
    if(!instance)
        instance = new Input();

    return instance;
}

 void Input::update(){

       if(ApertouTecla(GLFW_KEY_ESC)){
        quit = true;
    }
 }


bool Input::quitGame(){
    return quit;
}
