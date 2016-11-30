#include "../include/Ovelha.h"

Ovelha::Ovelha(float x, float y, float tamw, float tamh, int i, int j): coordx(x), coordy(y), coordi(i), coordj(j){
    Ponto p;
    int img;

    p.x = this->coordx;
    p.y = this->coordy;
    this->atingiu = false;

    this->ovelhag = CriaGrupo(); /**/

    this->ovelhaq = CriaRetangulo(tamw, tamh, p); /**/
    Pintar(255, 255, 255);

    instanceimg = Imagem::getInstance();
    img = instanceimg->getImg(Imagem::OVELHA);

    AssociaImagem(img, RETANGULO, this->ovelhaq); /**/

    this->tic = playAPCBase::tempo();
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
    if(playAPCBase::duracao(this->tic, this->vel)){
        this->coordi++;
        this->tic = playAPCBase::tempo();
    }
}

Ovelha::~Ovelha(){
    CriaGrupo(); //bug da playAPC
    ApagaGrupo(this->ovelhag);
}
