#include "../include/State_play.h"

const int WIDTH = 150;
const int HEIGHT = 100;

void State_play::load(tipoGame stack){
    Ponto p;
    float cellWidth = 2 * WIDTH/MAP_X_DIM;
    float cellHeight = 2 * HEIGHT/MAP_Y_DIM;
    int img;
    int velocidade = 1000;

    cout << "Play" << endl;

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
    for(int i = 0; i < MAP_X_DIM; i++){
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
    }

    this->instancebg = Background::getInstance();
    this->instanceimg = Imagem::getInstance();

    img = this->instanceimg->getImg(Imagem::BG_JOGO);

    this->instancebg->setBG(img);
    p = this->mapaVisu[MAP_X_DIM - 1][MAP_Y_DIM/2];

    this->mateus = new Mateus(p.x, p.y, cellWidth, cellHeight, MAP_X_DIM - 1, MAP_Y_DIM/2);

    for(int i = 0; i < MAP_Y_DIM; i++){
        this->ovelhas.push_back(new Ovelha(this->mapaVisu[0][i].x, this->mapaVisu[0][0].y, cellWidth, cellHeight, 0, i));
        this->mapaLogico[0][i] = OVELHA;
        this->ovelhas[i]->setVel(velocidade);

        velocidade -= 100;
    }
}

void State_play::unload(){

}


void State_play::checkCollision(){

}

tipoGame State_play::update(){
    int j;

    /***********************
    ** Updates do Mateus  **
    ************************/
    mateus->update(0);
    j = mateus->getCoordj();

    //Verifica se passou dos limites do mapa
    if(j < 0)
        mateus->setCoordj(++j);
    else if(j > MAP_Y_DIM - 1)
        mateus->setCoordj(--j);

    if(mateus->getAtirou()){
        if(mateus->getCombo()) //é o da mão esquerda
            j++;
    }

    mateus->setPosicao(mapaVisu[MAP_X_DIM - 1][j].x); //Atualiza posição do Mateus

    /***********************
    ** Updates das Ovelhas  **
    ************************/

    for(int i = 0; i < MAP_Y_DIM; i++){
        if(!this->ovelhas[i]->getAtingiu()){

            int coordi, coordj;

            coordi = this->ovelhas[i]->getCoordi();
            coordj = this->ovelhas[i]->getCoordj();

            this->mapaLogico[coordi][coordj] = VAZIO;

            this->ovelhas[i]->update();

            coordi = this->ovelhas[i]->getCoordi();

            if(this->mapaLogico[coordi][coordj] != ICC){
                this->ovelhas[i]->setPosicao(mapaVisu[coordi][coordj].y);
                this->mapaLogico[coordi][coordj] = OVELHA;
            }
            else{
                this->ovelhas[i]->setAtingiu(true);
            }
        }
    }

    if(ApertouTecla(TECLA_ENTER))
        return GAME_WIN;

    return GAME_NO_CHANGE;
}

void State_play::render(){

    playAPCBase::render();
}
