#include "../include/Ovelha.h"

Ovelha::Ovelha(float x, float y, float tamw, float tamh, int i, int j): coordx(x), coordy(y), coordi(i), coordj(j){
    Ponto p;

    p.x = this->coordx;
    p.y = this->coordy;
    this->atingiu = false;

    this->ovelhag = CriaGrupo(); /**/

    this->ovelhaq = CriaRetangulo(tamw, tamh, p); /**/
    Pintar(255, 255, 255);

    instanceimg = Imagem::getInstance();

    this->tic = playAPCBase::tempo();
}

bool Ovelha::isViva(){
    if(this->st == Ovelha::MORTA)
        return false;

    return true;
}

void Ovelha::setEstado(tipoEstadoOvelha st){
    int img;

    this->st = st;

    switch(this->st){
        case Ovelha::VIVA:
            img = instanceimg->getImg(Imagem::OVELHA);
        break;
        case Ovelha::MORTA:
            img = instanceimg->getImg(Imagem::NADA);
        break;
        case Ovelha::INVADIU:
            img = instanceimg->getImg(Imagem::INVADIU);
        break;
    }

    AssociaImagem(img, RETANGULO, this->ovelhaq); /**/
}

int Ovelha::getCoordi(){
    return this->coordi;
}

int Ovelha::getCoordj(){
    return this->coordj;
}

bool Ovelha::getAtingiu(){
    return this->atingiu;
}

void Ovelha::setCoordi(int i){
    this->coordi = i;
}

void Ovelha::setCoordj(int j){
    this->coordj = j;
}

void Ovelha::setAtingiu(bool acao){
    this->atingiu = acao;
}

void Ovelha::setVel(int vel){
    this->vel = vel;
}

void Ovelha::setPosicao(int y){
    Ponto p;

    p.x = this->coordx;
    p.y = y;

    Move(p, this->ovelhag);

}

void Ovelha::update(){
    if(this->st == Ovelha::VIVA){
        if(playAPCBase::duracao(this->tic, this->vel)){
            this->coordi++;
            this->tic = playAPCBase::tempo();
        }
    }
}

Ovelha::~Ovelha(){
    CriaGrupo(); //bug da playAPC
    ApagaGrupo(this->ovelhag);
}
