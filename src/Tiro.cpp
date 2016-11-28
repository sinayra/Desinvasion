#include "../include/Tiro.h"

Tiro::Tiro(int nqtd, int tamw, int tamh): qtd(nqtd){
    int img;
    Ponto p;

    this->livros = (bool *)calloc(this->qtd, sizeof(bool));
    this->livrosq = (int *)calloc(this->qtd, sizeof(int));
    this->livrosg = (int *)calloc(this->qtd, sizeof(int));
    this->coordi = (int *)calloc(this->qtd, sizeof(int));
    this->coordj = (int *)calloc(this->qtd, sizeof(int));

    instanceimg = Imagem::getInstance();
    img = instanceimg->getImg(Imagem::NADA);

    p.x = 0;
    p.y = 0;
    for(int i = 0; i < qtd; i++){
        this->livrosq[i] = CriaRetangulo(tamw, tamh, p);
        Pintar(255, 255, 255);
        AssociaImagem(img, RETANGULO, this->livrosq[i]);

        this->coordi[i] = 0;
        this->coordj[i] = 0;
    }
}

Tiro::~Tiro(){
    free(livros);

    for(int i = 0; i < this->qtd; i++){
        ApagaGrupo(this->livrosg[i]);
    }

    free(livrosq);
    free(livrosg);
}


int Tiro::getCoordi(int k){
    return this->coordi[k];
}

int Tiro::getCoordj(int k){
    return this->coordj[k];
}

void Tiro::setCoordi(int k, int i){
    this->coordi[k] = i;
}

void Tiro::setCoordj(int k, int j){
    this->coordj[k] = j;
}

void Tiro::atira(int k){
    int img;

    instanceimg = Imagem::getInstance();
    img = instanceimg->getImg(Imagem::LIVRO);

    this->livros[k] = true;
    AssociaImagem(img, RETANGULO, this->livrosq[k]);

}

void Tiro::cessa(int k){
    int img;

    instanceimg = Imagem::getInstance();
    img = instanceimg->getImg(Imagem::NADA);

    this->livros[k] = true;
    AssociaImagem(img, RETANGULO, this->livrosq[k]);
}

void Tiro::update(){
    for(int i; i < this->qtd; i++){
        if(this->livros[i]){
            this->coordi--;
        }
    }
}
