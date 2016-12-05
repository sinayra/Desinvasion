#include "../include/Progresso.h"

Progresso::Progresso(){
    Ponto pPrincipal;

    pPrincipal.x = 120;
	pPrincipal.y = 80;

	this->grupo3 = CriaGrupo();

	this->dezq = CriaRetangulo(10,15,pPrincipal);
	Pintar(255, 255, 255);

	pPrincipal.x = 133;
	pPrincipal.y = 80;

	this->uniq = CriaRetangulo(10,15,pPrincipal);
	Pintar(255, 255, 255);
}

int Progresso::retornaNum(int n){
    this->instanceimg = Imagem::getInstance();

    switch(n){
        case 0:
            return this->instanceimg->getImg(Imagem::NUM_0);
        break;

        case 1:
            return this->instanceimg->getImg(Imagem::NUM_1);
        break;

        case 2:
            return this->instanceimg->getImg(Imagem::NUM_2);
        break;

        case 3:
            return this->instanceimg->getImg(Imagem::NUM_3);
        break;

        case 4:
            return this->instanceimg->getImg(Imagem::NUM_4);
        break;

        case 5:
            return this->instanceimg->getImg(Imagem::NUM_5);
        break;

        case 6:
            return this->instanceimg->getImg(Imagem::NUM_6);
        break;

        case 7:
            return this->instanceimg->getImg(Imagem::NUM_7);
        break;

        case 8:
            return this->instanceimg->getImg(Imagem::NUM_8);
        break;

        case 9:
            return this->instanceimg->getImg(Imagem::NUM_9);
        break;
	}

	return this->instanceimg->getImg(Imagem::NADA);
}

void Progresso::setOvelhasRestantes(int qt){
    int dez, uni;
    int img;

	dez = qt / 10;
	uni = qt - (dez * 10);

	img = this->retornaNum(dez);
	AssociaImagem(img, RETANGULO, this->dezq);

	img = this->retornaNum(uni);
	AssociaImagem(img, RETANGULO, this->uniq);

}

Progresso::~Progresso(){
    CriaGrupo(); //bug da playAPC
    ApagaGrupo(this->grupo3);
}
