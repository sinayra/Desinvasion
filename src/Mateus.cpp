#include "../include/Mateus.h"

Mateus::Mateus(float x, float y, float tamw, float tamh, int i, int j): coordx(x), coordy(y), coordi(i), coordj(j){
    Ponto p;
    int img;

    this->combo_ovelhas = 0;
	this->combo_ataque = 0;
	this->ataque = false;
        
    p.x = this->coordx;
    p.y = this->coordy;

    this->mateusg = CriaGrupo(); /**/

    this->mateusq = CriaRetangulo(tamw, tamh, p); /**/
    Pintar(255, 255, 255);

    instanceimg = Imagem::getInstance();
    img = instanceimg->getImg(Imagem::JOGADOR_STAND);
    
    instancesnd = Sound::getInstance();
    
    AssociaImagem(img, RETANGULO, this->mateusq); /**/
}

bool Mateus::getEspaco(){
    return this->espaco;
}

bool Mateus::getAtirou(){
    return this->ataque;
}

int Mateus::getCombo(){
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
		
		if(!instancesnd->getIsPlaying())
		{
			instancesnd->play(5);
        }
		this->espaco = true;
        this->tic = playAPCBase::tempo();

        instanceimg = Imagem::getInstance();
        img = instanceimg->getImg(Imagem::JOGADOR_ATTACK);

        AssociaImagem(img, RETANGULO, this->mateusq); /**/

        this->combo_ataque = (this->combo_ataque + 1) % 2;

        if(!this->ataque){
            this->ataque = true;
            this->coordy += 100;
        }

        if(this->combo_ataque){
            Redimensiona(-1, 2, mateusg); /**/
        }
        else{
            Redimensiona(1, 2, mateusg); /**/
        }
    }
    else{
        this->espaco = false;
    }

    if(this->ataque && playAPCBase::duracao(this->tic, 500) ){
        this->ataque = false;
        instanceimg = Imagem::getInstance();
        img = instanceimg->getImg(Imagem::JOGADOR_STAND);

        AssociaImagem(img, RETANGULO, this->mateusq); /**/
        this->coordy -= 100;

        Redimensiona(1, 1, mateusg); /**/
    }
}

Mateus::~Mateus(){
    ApagaGrupo(mateusg);
}
