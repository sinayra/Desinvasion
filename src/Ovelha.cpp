#include "../include/Ovelha.h"

Ovelha::Ovelha(float x, float y, float tamw, float tamh, int i, int j): coordx(x), coordy(y), coordi(i), coordj(j){
    Ponto p;

    p.x = this->coordx;
    p.y = this->coordy;
    this->invadiu = false;

    this->ovelhag = CriaGrupo(); /**/

    this->ovelhaq = CriaRetangulo(tamw, tamh, p); /**/
    Pintar(255, 255, 255);

    instanceimg = Imagem::getInstance();

    this->tic = playAPCBase::tempo();
    this->respawn = -1;
    this->vida = 0;
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
            this->lider = false;
        break;
        case Ovelha::VIVA_LIDER:
            img = instanceimg->getImg(Imagem::OVELHA_LIDER);
            this->lider = true;
        break;
        case Ovelha::DANO:
            if(this->lider)
                img = instanceimg->getImg(Imagem::OVELHA_LIDER_DANO);
            else
                img = instanceimg->getImg(Imagem::OVELHA_DANO);

            this->tic = playAPCBase::tempo();
        break;
        case Ovelha::MORTA:
            img = instanceimg->getImg(Imagem::NADA);
            this->respawn = 0;
            this->coordi = 0;
            this->setPosicao(this->coordy);
        break;
        case Ovelha::INVADIU:
            img = instanceimg->getImg(Imagem::INVADIU);
            this->invadiu = true;
        break;
    }

    AssociaImagem(img, RETANGULO, this->ovelhaq); /**/
}

int Ovelha::getVida(){
    return this->vida;
}

int Ovelha::getCoordi(){
    return this->coordi;
}

int Ovelha::getCoordj(){
    return this->coordj;
}

bool Ovelha::getInvadiu(){
    return this->invadiu;
}

int Ovelha::getRespawn(){
    return this->respawn;
}

void Ovelha::setVida(int i){
    this->vida = i;
}

void Ovelha::decrementaVida(){
    this->vida--;
}

void Ovelha::setCoordi(int i){
    this->coordi = i;
}

void Ovelha::setCoordj(int j){
    this->coordj = j;
}

void Ovelha::setInvadiu(bool acao){
    this->invadiu = acao;
}

void Ovelha::setRespawn(int r){
    this->respawn = r;
}

void Ovelha::setVel(int vel){
    this->vel = vel;
}

int Ovelha::getVel(){
    return this->vel;
}

bool Ovelha::isLider(){
    return this->lider;
}

void Ovelha::ressucita(int vida){
    this->tic = playAPCBase::tempo();
    this->vida = vida;
}

void Ovelha::setPosicao(int y){
    Ponto p;

    p.x = this->coordx;
    p.y = y;

    Move(p, this->ovelhag);

}

void Ovelha::update(){

    if(this->st == Ovelha::VIVA || this->st == Ovelha::VIVA_LIDER){
        if(playAPCBase::duracao(this->tic, this->vel)){
            this->coordi++;
            this->tic = playAPCBase::tempo();
        }
    }
    else if(this->st == Ovelha::DANO){

        if(playAPCBase::duracao(this->tic, 1000)){
            if(this->vida <= 0)
                this->setEstado(Ovelha::MORTA);
            else if(this->lider)
                this->st = Ovelha::VIVA_LIDER;

            this->tic = playAPCBase::tempo();
        }

    }
}

Ovelha::~Ovelha(){
    CriaGrupo(); //bug da playAPC
    ApagaGrupo(this->ovelhag);
}
