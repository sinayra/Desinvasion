#include "../include/Tiro.h"

Tiro::Tiro(float x, float y, float tamw, float tamh, int i, int j): coordx(x), coordy(y), coordi_original(i), coordj_original(j){
    int img;
    Ponto p;

    p.x = this->coordx;
    p.y = this->coordy;

    this->atirou = false;
    this->tirog = CriaGrupo(); /**/

    this->coordi = this->coordi_original;
    this->coordj = this->coordj_original;

    this->tiroq = CriaRetangulo(tamw, tamh, p); /**/
    Pintar(255, 255, 255);

    instanceimg = Imagem::getInstance();

    img = instanceimg->getImg(Imagem::NADA);

    AssociaImagem(img, RETANGULO, this->tirog); /**/

}

void Tiro::setPosicao(int y){
    Ponto p;

    p.x = this->coordx;
    p.y = y;

    Move(p, this->tirog);

}

bool Tiro::getAtirou(){
    return this->atirou;
}

int Tiro::getCoordi(){
    return this->coordi;
}

int Tiro::getCoordj(){
    return this->coordj;
}

void Tiro::setCoordi(int i){
    this->coordi = i;
}

void Tiro::setCoordj(int j){
    this->coordj = j;
}

void Tiro::atira(){
    int img;

    instanceimg = Imagem::getInstance();
    img = instanceimg->getImg(Imagem::LIVRO);

    this->atirou = true;
    this->tic = playAPCBase::tempo();

    AssociaImagem(img, RETANGULO, this->tiroq);
}

void Tiro::cessa(){
    int img;

    img = instanceimg->getImg(Imagem::NADA);
    AssociaImagem(img, RETANGULO, this->tirog); /**/

    this->atirou = false;

    this->coordi = this->coordi_original;
    this->coordj = this->coordj_original;
}


void Tiro::update(){

    if(playAPCBase::duracao(this->tic, 100)){
        this->coordj--;
        this->tic = playAPCBase::tempo();
    }
}
