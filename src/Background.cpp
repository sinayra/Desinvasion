#include "../include/Background.h"

Background *Background::instance = NULL;

Background::Background(){
    Ponto p;

    p.x = -150;
    p.y = -100;
    bg = CriaRetangulo(300, 200, p);
    Pintar(255, 255, 255);
}

Background::~Background(){
    //dtor
}

Background *Background::getInstance(){
    if(!instance)
        instance = new Background();

    return instance;
}

void Background::setBG(int img){
    AssociaImagem(img, RETANGULO, bg);
}
