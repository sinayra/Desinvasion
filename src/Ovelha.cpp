#include "../include/Ovelha.h"

Ovelha::Ovelha(float x, float y, float tamw, float tamh, int i, int j): coordx(x), coordy(y), coordi(i), coordj(j){
    Ponto p;
    int img;

    p.x = this->coordx;
    p.y = this->coordy;

    this->ovelhag = CriaGrupo(); /**/

    this->ovelhaq = CriaRetangulo(tamw, tamh, p); /**/
    Pintar(255, 255, 255);

    instanceimg = Imagem::getInstance();
    img = instanceimg->getImg(Imagem::OVELHA);

    AssociaImagem(img, RETANGULO, this->ovelhaq); /**/
}

void Ovelha::update(){

}

Ovelha::~Ovelha(){
    //dtor
}
