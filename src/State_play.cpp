#include "../include/State_play.h"

const int WIDTH = 150;
const int HEIGHT = 100;

void State_play::load(tipoGame stack){
    Ponto p;
    float cellWidth = 2 * WIDTH/MAP_X_DIM;
    float cellHeight = 2 * HEIGHT/MAP_Y_DIM;
    int img;

    this->dificuldade = 10000;

    p.y = HEIGHT - cellHeight;
    for(int i = 0; i < MAP_X_DIM; i++){
        p.x = -WIDTH;
        for(int j = 0; j < MAP_Y_DIM + 1; j++){
            this->mapaLogico[i][j] = VAZIO;
            this->mapaVisu[i][j] = p;

            p.x += cellWidth;
        }
        p.y -= cellHeight;
    }

    this->mapaLogico[5][0] = ICC;
    this->mapaLogico[6][1] = ICC;
    this->mapaLogico[6][2] = ICC;
    this->mapaLogico[6][3] = ICC;
    this->mapaLogico[7][4] = ICC;
    this->mapaLogico[7][5] = ICC;
    this->mapaLogico[6][6] = ICC;
    this->mapaLogico[6][7] = ICC;
    this->mapaLogico[6][8] = ICC;
    this->mapaLogico[5][9] = ICC;

    this->instancebg = Background::getInstance();
    this->instanceimg = Imagem::getInstance();

    img = this->instanceimg->getImg(Imagem::BG_JOGO);

    this->instancebg->setBG(img);
    p = this->mapaVisu[MAP_X_DIM - 1][MAP_Y_DIM/2];

    this->mateus = new Mateus(p.x, p.y, cellWidth, cellHeight, MAP_X_DIM - 1, MAP_Y_DIM/2);
    this->especial = 3;

    this->tic = (milliseconds*) malloc(sizeof(milliseconds) * MAP_Y_DIM);

    this->tiro = new Tiro(mapaVisu[MAP_X_DIM - 3][MAP_Y_DIM - 3].x, 0, cellWidth, cellHeight, 0, 0);

    this->constituicao.push_back(new Tiro(mapaVisu[MAP_X_DIM - 3][MAP_Y_DIM - 3].x, 0, cellWidth, cellHeight, 0, 0));
    this->constituicao.push_back(new Tiro(mapaVisu[MAP_X_DIM - 3][MAP_Y_DIM - 3].x, 0, cellWidth, cellHeight, 0, 0));
    this->constituicao.push_back(new Tiro(mapaVisu[MAP_X_DIM - 3][MAP_Y_DIM - 3].x, 0, cellWidth, cellHeight, 0, 0));

    for(int i = 0; i < MAP_Y_DIM; i++){
        this->ovelhas.push_back(new Ovelha(this->mapaVisu[0][i].x + 3, this->mapaVisu[0][0].y, (cellWidth) * 0.75, (cellHeight + 10) * 0.75, 0, i));
        this->ovelhas[i]->setEstado(Ovelha::MORTA);

        this->tic[i] = playAPCBase::tempo();
    }

    this->progresso = new Progresso();
    this->vitoria = 30;
    this->derrota = 4;

    this->timer = playAPCBase::tempo();
}

void State_play::unload(){
    delete(this->progresso);
    delete(this->mateus);

    for(int i = 0; i < MAP_Y_DIM; i++){
        delete(this->ovelhas[i]);
    }

    for(int i = 0; i < 3; i++){
        delete(this->constituicao[i]);
    }

    delete(this->tiro);
    free(this->tic);
}


int State_play::checkCollision(){
    int ovelhas_mortas = 0;
    for(int i = 0; i < MAP_Y_DIM; i++){
        if(this->ovelhas[i]->isViva() && !this->ovelhas[i]->getInvadiu()){
            int coordi, coordj;

            coordi = this->ovelhas[i]->getCoordi();
            coordj = this->ovelhas[i]->getCoordj();

            if(this->mapaLogico[coordi][coordj] == VAZIO && this->ovelhas[i]->getVida() > 0){

                if(this->ovelhas[i]->isLider())
                    this->ovelhas[i]->setEstado(Ovelha::VIVA_LIDER);
                else
                    this->ovelhas[i]->setEstado(Ovelha::VIVA);

                this->mapaLogico[coordi][coordj] = OVELHA;
            }
            else if(this->mapaLogico[coordi][coordj] == TIRO){
                this->ovelhas[i]->setEstado(Ovelha::DANO);
                this->ovelhas[i]->decrementaVida();
                this->tiro->cessa();

                if(this->ovelhas[i]->getVida() <= 0){
                    ovelhas_mortas++;
                    this->mapaLogico[coordi][coordj] = VAZIO;
                    this->tic[i] = playAPCBase::tempo();

                    this->vitoria--;
                }
                else{
                    this->mapaLogico[coordi][coordj] = OVELHA;
                }
            }
            else if(this->mapaLogico[coordi][coordj] == CONST0 || this->mapaLogico[coordi][coordj] == CONST1 || this->mapaLogico[coordi][coordj] == CONST2){
                this->ovelhas[i]->setEstado(Ovelha::DANO);
                this->ovelhas[i]->setVida(0);
                this->tic[i] = playAPCBase::tempo();

                if(this->mapaLogico[coordi][coordj] == CONST0)
                    this->constituicao[0]->cessa();
                else if(this->mapaLogico[coordi][coordj] == CONST1)
                    this->constituicao[1]->cessa();
                else
                    this->constituicao[2]->cessa();

                this->mapaLogico[coordi][coordj] = VAZIO;
                this->vitoria--;
            }
            else if(this->mapaLogico[coordi][coordj] == ICC){
                this->ovelhas[i]->setEstado(Ovelha::INVADIU);
                this->derrota--;
            }
        }
    }

    return ovelhas_mortas;
}

void State_play::updateTiro(Tiro *t, cellState st){

    if(t->getAtirou()){
        int linha, coluna;

        coluna = t->getCoordj();
        linha = t->getCoordi();

        if(this->mapaLogico[linha][coluna] != ICC)
            this->mapaLogico[linha][coluna] = VAZIO;

        t->update();
        coluna = t->getCoordj();
        linha = t->getCoordi();

        if(linha < 0)
            t->cessa();
        else{
            t->setPosicao(mapaVisu[linha][coluna].x, mapaVisu[linha][coluna].y);

            if(this->mapaLogico[linha][coluna] != ICC)
                this->mapaLogico[linha][coluna] = st;
        }
    }
}

void State_play::updateMateus(int ovelhas_mortas){
    int j;

    this->mateus->update(ovelhas_mortas);
    j = this->mateus->getCoordj();

    //Verifica se passou dos limites do mapa
    if(j < 0)
        this->mateus->setCoordj(++j);
    else if(j > MAP_Y_DIM - 1)
        this->mateus->setCoordj(--j);

    if(this->mateus->getAtirou()){
        if(this->mateus->getCombo()) //é o da mão esquerda
            j++;

        if(this->mateus->getEspaco() && !this->tiro->getAtirou()){
            if(this->mateus->getEspecial()){

                this->constituicao[1]->atira(this->mateus->getCoordi(), this->mateus->getCoordj(), true);

                if(this->mateus->getCoordj() == 0){
                    this->constituicao[2]->atira(this->mateus->getCoordi(), this->mateus->getCoordj() + 1, true);
                    this->constituicao[0]->atira(this->mateus->getCoordi(), this->mateus->getCoordj() + 2, true);
                }
                else if(this->mateus->getCoordj() == MAP_Y_DIM - 1){
                    this->constituicao[0]->atira(this->mateus->getCoordi(), this->mateus->getCoordj() - 1, true);
                    this->constituicao[2]->atira(this->mateus->getCoordi(), this->mateus->getCoordj() - 2, true);
                }
                else{
                    this->constituicao[0]->atira(this->mateus->getCoordi(), this->mateus->getCoordj() - 1, true);
                    this->constituicao[2]->atira(this->mateus->getCoordi(), this->mateus->getCoordj() + 1, true);
                }
                this->mateus->resetEspecial();
            }
            else
                this->tiro->atira(this->mateus->getCoordi(), this->mateus->getCoordj(), false);
        }
    }

    mateus->setPosicao(mapaVisu[MAP_X_DIM - 1][j].x); //Atualiza posição do Mateus

    updateTiro(this->tiro, TIRO);
    updateTiro(this->constituicao[0], CONST0);
    updateTiro(this->constituicao[1], CONST1);
    updateTiro(this->constituicao[2], CONST2);
}

/* Random integer in [0, limit) */
unsigned int State_play::random_uint(unsigned int limit) {
    union {
        unsigned int i;
        unsigned char c[sizeof(unsigned int)];
    } u;

    do {
        if (!RAND_bytes(u.c, sizeof(u.c))) {
            fprintf(stderr, "Can't get random bytes!\n");
            exit(1);
        }
    } while (u.i < (-limit % limit)); /* u.i < (2**size % limit) */
    return u.i % limit;
}

void State_play::updateOvelhas(){

    for(int i = 0; i < MAP_Y_DIM; i++){

        if(this->ovelhas[i]->isViva()){
            if(!this->ovelhas[i]->getInvadiu()){
                int coordi, coordj;

                coordi = this->ovelhas[i]->getCoordi();
                coordj = this->ovelhas[i]->getCoordj();

                this->mapaLogico[coordi][coordj] = VAZIO;

                this->ovelhas[i]->update();

                coordi = this->ovelhas[i]->getCoordi();
                coordj = this->ovelhas[i]->getCoordj();

                this->ovelhas[i]->setPosicao(this->mapaVisu[coordi][coordj].y);
            }
        }
        else{
            int r = this->ovelhas[i]->getRespawn();
            if(r == 0){
                //cout << "ovelha " << i << endl;
                int sorteia = (int)(random_uint(this->dificuldade));

                int tempo = 500 + sorteia;

                this->ovelhas[i]->setRespawn(tempo);
                this->ovelhas[i]->setVel(tempo);

            }
            else{
                if(playAPCBase::duracao(this->tic[i], r)){
                    int sorteia = (int)(random_uint(100));

                    if(sorteia > 75){
                        this->ovelhas[i]->setEstado(Ovelha::VIVA_LIDER);
                        this->ovelhas[i]->ressucita(2);
                    }
                    else{
                        this->ovelhas[i]->setEstado(Ovelha::VIVA);
                        this->ovelhas[i]->ressucita(1);
                    }
                    this->ovelhas[i]->setCoordi(0);
                    this->mapaLogico[0][i] = OVELHA;

                    this->tic[i] = playAPCBase::tempo();
                }
            }
        }
    }

}

tipoGame State_play::update(){
    int ovelhas_mortas;

    ovelhas_mortas = this->checkCollision();
    this->updateOvelhas();
    this->updateMateus(ovelhas_mortas);

    this->progresso->setOvelhasRestantes(this->vitoria);

    if(playAPCBase::duracao(this->timer, 3000)){
        this->dificuldade *= 0.95;
        this->timer = playAPCBase::tempo();
    }

    if(this->vitoria == 0)
        return GAME_WIN;
    if(this->derrota == 0)
        return GAME_LOSE;

    return GAME_NO_CHANGE;
}

void State_play::render(){

    playAPCBase::render();
}
