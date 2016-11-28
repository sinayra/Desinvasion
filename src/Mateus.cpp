#include "../include/Mateus.h"

Mateus::Mateus(float x, float y, float tamw, float tamh, int i, int j): coordx(x), coordy(y), coordi(i), coordj(j){
    Ponto p;
    int img;

    p.x = this->coordx;
    p.y = this->coordy;

    this->mateusg = CriaGrupo(); /**/

    this->mateusq = CriaRetangulo(tamw, tamh, p); /**/
    Pintar(255, 255, 255);

    instanceimg = Imagem::getInstance();
    img = instanceimg->getImg(Imagem::JOGADOR_STAND);

    AssociaImagem(img, RETANGULO, this->mateusq); /**/
}

int Mateus::getAtaque(){
    return this->combo_ataque;
}

int Mateus::getCoordi(){
    return this->coordi;
}

int Mateus::getCoordj(){
    return this->coordj;
}

void Mateus::setCoordi(int i){
    this->coordi = i;
}

void Mateus::setCoordj(int j){
    this->coordj = j;
}

void Mateus::setPosicao(float x){
    Ponto p;

    p.x = x;
    p.y = this->coordy;

    Move(p, this->mateusg); /**/
}

void Mateus::update(int ovelhas_mortas){
    int img;

    if(ApertouTecla(TECLA_ESQ)){ /**/
        this->coordj--;
    }
    if(ApertouTecla(TECLA_DIR)){ /**/
        this->coordj++;
    }

    if(ApertouTecla(TECLA_ESPACO)){
        this->ataque = true;
        playAPCBase::tic();

        instanceimg = Imagem::getInstance();
        img = instanceimg->getImg(Imagem::JOGADOR_ATTACK);

        AssociaImagem(img, RETANGULO, this->mateusq); /**/

        this->combo_ataque = (this->combo_ataque + 1) % 2;

        if(this->combo_ataque){
            Redimensiona(-1, 1, mateusg); /**/
        }
        else{
            Redimensiona(1, 1, mateusg); /**/
        }
    }

    if(this->ataque && playAPCBase::tac() > 1){
        instanceimg = Imagem::getInstance();
        img = instanceimg->getImg(Imagem::JOGADOR_STAND);

        AssociaImagem(img, RETANGULO, this->mateusq); /**/
    }
}

Mateus::~Mateus(){
    //dtor
}
