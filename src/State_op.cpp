#include "../include/State_op.h"

void State_op::load(tipoGame stack){
    int img;

    this->instancebg = Background::getInstance();
    this->instanceimg = Imagem::getInstance();

    cout << "Opening" << endl;
    img = instanceimg->getImg(Imagem::BG_DIALOGO);

    instancebg->setBG(img);
    instancesnd = Sound::getInstance();

    this->cena = State_op::CENA_1;
    this->tic = playAPCBase::tempo();

    while(playAPCBase::duracao(this->tic, 500));
}

void State_op::unload(){
    CriaGrupo(); /*Bug da playAPC, foi mal*/

    ApagaGrupo(grupoTelaOvelha);
    ApagaGrupo(grupoTelaCitizen);
}

tipoGame State_op::update(){
    int img;

    switch(this->cena){
        case CENA_1:
            this->tic = playAPCBase::tempo();

            this->pPrincipal.x = 150-146;
            this->pPrincipal.y = 100-75;

            this->grupoTelaOvelha = CriaGrupo();
            img = instanceimg->getImg(Imagem::DIALOGO1);

            CriaRetangulo(146,75,this->pPrincipal);
            Pintar(255,255,255);
            AssociaImagem(img);
            Desenha1Frame();

            if(!instancesnd->getIsPlaying())
            {
                instancesnd->play(2);
            }

            this->cena = State_op::NO_CHANGE;
            this->cenaant = State_op::CENA_1;
        break;
        case CENA_2:
            this->tic = playAPCBase::tempo();

            this->pPrincipal.x = -150;
            this->pPrincipal.y = -100;

            this->grupoTelaCitizen = CriaGrupo();
            img = instanceimg->getImg(Imagem::DIALOGO2);
            CriaRetangulo(146,75,this->pPrincipal);
            Pintar(255,255,255);
            AssociaImagem(img);
            Desenha1Frame();

            if(!instancesnd->getIsPlaying())
            {
                instancesnd->play(3);
            }

            this->cena = State_op::NO_CHANGE;
            this->cenaant = State_op::CENA_2;
        break;

        case CENA_3:
            this->tic = playAPCBase::tempo();

            this->pPrincipal.x = 150-146;
            this->pPrincipal.y = 100-75;

            img = instanceimg->getImg(Imagem::DIALOGO4);
            AssociaImagem(img, RETANGULO, this->grupoTelaOvelha);
            Desenha1Frame();

            if(!instancesnd->getIsPlaying())
            {
                instancesnd->play(4);
            }

            this->cena = State_op::NO_CHANGE;
            this->cenaant = State_op::CENA_3;
        break;

        default:
        break;
    }


    if(ApertouTecla(TECLA_ENTER) && playAPCBase::duracao(this->tic, 500) && !instancesnd->getIsPlaying()){
        if(this->cenaant == State_op::CENA_3)
            return GAME_PLAY;
        else
            this->cena = this->cenaant + 1;
    }

    return GAME_NO_CHANGE;
}

void State_op::render(){

    playAPCBase::render();
}

