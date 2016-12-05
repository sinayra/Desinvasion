#include "../include/Tiro.h"

Tiro::Tiro(float x, float y, float tamw, float tamh, int i, int j): coordx(x), coordy(y), coordi_original(i), coordj_original(j){
    int img;
    Ponto p;

    p.x = -tamw/2;
    p.y = -tamw/2;

    this->atirou = false;
    this->tirog = CriaGrupo(); /**/

    this->coordi = this->coordi_original;
    this->coordj = this->coordj_original;

    this->tiroq = CriaRetangulo(tamw, tamh, p); /**/
    Pintar(255, 255, 255);

    p.x = this->coordx;
    p.y = this->coordy;

    instanceimg = Imagem::getInstance();

    img = instanceimg->getImg(Imagem::NADA);

    AssociaImagem(img, RETANGULO, this->tirog); /**/

    this->rot = 0;

}

void Tiro::setPosicao(int x, int y){
    Ponto p;

    p.x = x;
    p.y = y;

    //std::cout << "p.x: " << p.x << endl;
    //getchar();

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

void Tiro::atira(int i, int j, bool especial){
    int img;

    instanceimg = Imagem::getInstance();

    if(especial)
        img = instanceimg->getImg(Imagem::CONSTITUICAO);
    else
        img = instanceimg->getImg(Imagem::LIVRO);

    this->coordi = i;
    this->coordj = j;
    this->atirou = true;
    this->tic = playAPCBase::tempo();

    AssociaImagem(img, RETANGULO, this->tiroq);
}

void Tiro::cessa(){
    int img;

    img = instanceimg->getImg(Imagem::NADA);
    AssociaImagem(img, RETANGULO, this->tirog); /**/

    this->atirou = false;

    this->coordj = this->coordj_original;

    this->rot = 0;
}


void Tiro::update(){

    Gira(this->rot, this->tirog);
    this->rot += 30;

    if(playAPCBase::duracao(this->tic, 100)){
        this->coordi--;
        this->tic = playAPCBase::tempo();
    }
}
