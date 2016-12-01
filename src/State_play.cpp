#include "../include/State_play.h"

const int WIDTH = 150;
const int HEIGHT = 100;

void State_play::load(tipoGame stack){
    Ponto p;
    float cellWidth = 2 * WIDTH/MAP_X_DIM;
    float cellHeight = 2 * HEIGHT/MAP_Y_DIM;
    int img;

    cout << "Play" << endl;

    this->dificuldade = 3000;

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

    /** Debug (exibindo matriz de visualização) **/
    /*for(int i = 0; i < MAP_X_DIM; i++){
        for(int j = 0; j < MAP_Y_DIM; j++){

            if(this->mapaLogico[i][j] == VAZIO){
                CriaPonto(mapaVisu[i][j]);
                Pintar(0, 255, 0);
                Grafite(5);
            }
            else{
                CriaRetangulo(cellWidth - 2, cellHeight - 2, mapaVisu[i][j]);
                Pintar(255, 0, 0);
            }
        }
    }*/

    this->instancebg = Background::getInstance();
    this->instanceimg = Imagem::getInstance();

    img = this->instanceimg->getImg(Imagem::BG_JOGO);

    this->instancebg->setBG(img);
    p = this->mapaVisu[MAP_X_DIM - 1][MAP_Y_DIM/2];

    this->mateus = new Mateus(p.x, p.y, cellWidth, cellHeight, MAP_X_DIM - 1, MAP_Y_DIM/2);
    this->tic = (milliseconds*) malloc(sizeof(milliseconds) * MAP_Y_DIM);

    for(int i = 0; i < MAP_Y_DIM; i++){
        this->ovelhas.push_back(new Ovelha(this->mapaVisu[0][i].x + 3, this->mapaVisu[0][0].y, (cellWidth) * 0.75, (cellHeight + 10) * 0.75, 0, i));
        this->ovelhas[i]->setEstado(Ovelha::MORTA);

        this->tiros.push_back(new Tiro(this->mapaVisu[MAP_X_DIM - 3][i].x, this->mapaVisu[MAP_X_DIM - 3][i].y, cellWidth, cellHeight, i, MAP_X_DIM - 3));

        this->tic[i] = playAPCBase::tempo();
    }

    this->timer = playAPCBase::tempo();
}

void State_play::unload(){
    delete(this->mateus);

    for(int i = 0; i < MAP_Y_DIM; i++){
        delete(this->ovelhas[i]);
    }

    free(this->tic);
}


void State_play::checkCollision(){
    for(int i = 0; i < MAP_Y_DIM; i++){
        if(this->ovelhas[i]->isViva() && !this->ovelhas[i]->getAtingiu()){

            int coordi, coordj;

            coordi = this->ovelhas[i]->getCoordi();
            coordj = this->ovelhas[i]->getCoordj();

            this->ovelhas[i]->setPosicao(mapaVisu[coordi][coordj].y);

            if(this->mapaLogico[coordi][coordj] == VAZIO){
                this->mapaLogico[coordi][coordj] = OVELHA;
            }
            else if(this->mapaLogico[coordi][coordj] == TIRO){
                this->ovelhas[i]->setEstado(Ovelha::MORTA);
                this->tiros[i]->cessa();
                this->mapaLogico[coordi][coordj] = VAZIO;

                this->tic[i] = playAPCBase::tempo();
            }
            else if(this->mapaLogico[coordi][coordj] == ICC){
                this->ovelhas[i]->setAtingiu(true);
                this->ovelhas[i]->setEstado(Ovelha::INVADIU);
            }
        }
    }
}

void State_play::updateMateus(int ovelhas){
    int j;

    this->mateus->update(0);
    j = this->mateus->getCoordj();

    //Verifica se passou dos limites do mapa
    if(j < 0)
        this->mateus->setCoordj(++j);
    else if(j > MAP_Y_DIM - 1)
        this->mateus->setCoordj(--j);

    if(this->mateus->getAtirou()){
        if(this->mateus->getCombo()) //é o da mão esquerda
            j++;

        if(this->mateus->getEspaco())
            this->tiros[this->mateus->getCoordj()]->atira();
    }

    mateus->setPosicao(mapaVisu[MAP_X_DIM - 1][j].x); //Atualiza posição do Mateus

    for(int i = 0; i < MAP_Y_DIM; i++){
        if(this->tiros[i]->getAtirou()){
            int linha, coluna;

            coluna = this->tiros[i]->getCoordi();
            linha = this->tiros[i]->getCoordj();

            if(this->mapaLogico[linha][coluna] != ICC)
                this->mapaLogico[linha][coluna] = VAZIO;

            this->tiros[i]->update();
            coluna = this->tiros[i]->getCoordi();
            linha = this->tiros[i]->getCoordj();

            if(linha < 0)
                this->tiros[i]->cessa();
            else{
                this->tiros[i]->setPosicao(mapaVisu[linha][coluna].y);

                if(this->mapaLogico[linha][coluna] != ICC)
                    this->mapaLogico[linha][coluna] = TIRO;
            }
        }
    }
}

int State_play::updateOvelhas(){

    for(int i = 0; i < MAP_Y_DIM; i++){
        if(this->ovelhas[i]->isViva()){
            if(!this->ovelhas[i]->getAtingiu()){

                int coordi, coordj;

                coordi = this->ovelhas[i]->getCoordi();
                coordj = this->ovelhas[i]->getCoordj();

                this->mapaLogico[coordi][coordj] = VAZIO;

                this->ovelhas[i]->update();
            }
        }
        else{
            int tempo = 1000 + rand() % 10000;

            if(playAPCBase::duracao(this->tic[i], tempo)){
                this->ovelhas[i]->setEstado(Ovelha::VIVA);
                this->ovelhas[i]->setCoordi(0);
                this->mapaLogico[0][i] = OVELHA;
                this->ovelhas[i]->setVel(dificuldade);
            }
        }
    }

    return 0;
}

tipoGame State_play::update(){
    int ovelhas;

    ovelhas = this->updateOvelhas();
    this->updateMateus(ovelhas);

    this->checkCollision();

    if(playAPCBase::duracao(this->timer, 3000)){
        this->dificuldade *= 0.75;
        this->timer = playAPCBase::tempo();
    }

    if(ApertouTecla('W'))
        return GAME_WIN;
    if(ApertouTecla('L'))
        return GAME_WIN;

    return GAME_NO_CHANGE;
}

void State_play::render(){

    playAPCBase::render();
}
