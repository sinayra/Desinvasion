#include "../include/State_play.h"

const int WIDTH = 150;
const int HEIGHT = 100;

void State_play::load(tipoGame stack){
    Ponto p;
    float cellWidth = 2 * WIDTH/MAP_X_DIM;
    float cellHeight = 2 * HEIGHT/MAP_Y_DIM;
    int img;

    cout << "Play" << endl;

    p.y = HEIGHT - cellHeight;
    for(int i = 0; i < MAP_X_DIM; i++){
        p.x = -WIDTH;
        for(int j = 0; j < MAP_Y_DIM + 1; j++){
            mapaLogico[i][j] = VAZIO;
            mapaVisu[i][j] = p;

            p.x += cellWidth;
        }
        p.y -= cellHeight;
    }

    mapaLogico[5][0] = ICC;
    mapaLogico[5][1] = ICC;
    mapaLogico[6][2] = ICC;
    mapaLogico[6][3] = ICC;
    mapaLogico[6][4] = ICC;
    mapaLogico[6][5] = ICC;
    mapaLogico[6][6] = ICC;
    mapaLogico[6][7] = ICC;
    mapaLogico[5][8] = ICC;
    mapaLogico[5][9] = ICC;

    /** Debug (exibindo matriz de visualização) **/
    for(int i = 0; i < MAP_X_DIM; i++){
        for(int j = 0; j < MAP_Y_DIM; j++){

            if(mapaLogico[i][j] == VAZIO){
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

    instancebg = Background::getInstance();
    instanceimg = Imagem::getInstance();

    img = instanceimg->getImg(Imagem::BG_JOGO);

    instancebg->setBG(img);
    p = mapaVisu[MAP_X_DIM - 1][MAP_Y_DIM/2];

    mateus = new Mateus(p.x, p.y, cellWidth, cellHeight, MAP_X_DIM - 1, MAP_Y_DIM/2);
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

    if(ApertouTecla(TECLA_ENTER))
        return GAME_WIN;

    return GAME_NO_CHANGE;
}

void State_play::render(){

    playAPCBase::render();
}
