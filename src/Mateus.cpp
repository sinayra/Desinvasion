#include "../include/Mateus.h"

Mateus::Mateus(float x, float y, float tamw, float tamh, int i, int j): coordx(x), coordy(y), coordi(i), coordj(j){
    Ponto p;
    int img;

    p.x = coordx;
    p.y = coordy;

    mateusg = CriaGrupo();

    mateusq = CriaRetangulo(tamw, tamh, p);
    Pintar(255, 255, 255);

    instanceimg = Imagem::getInstance();
    img = instanceimg->getImg(Imagem::JOGADOR_1);

    AssociaImagem(img, RETANGULO, mateusq);
}

int Mateus::getCoordi(){
    return coordi;
}

int Mateus::getCoordj(){
    return coordj;
}

void Mateus::setCoordi(int i){
    coordi = i;
}

void Mateus::setCoordj(int j){
    coordj = j;
}

void Mateus::setPosicao(float x){
    Ponto p;

    p.x = x;
    p.y = coordy;

    Move(p, mateusg);
}

Mateus::~Mateus(){
    //dtor
}
