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
        for(int j = 0; j < MAP_Y_DIM; j++){
            mapaLogico[i][j] = VAZIO;
            mapaVisu[i][j] = p;

            p.x += cellWidth;
        }
        p.y -= cellHeight;
    }

    for(int i = 0; i < MAP_X_DIM; i++){
        for(int j = 0; j < MAP_Y_DIM; j++){
            CriaPonto(mapaVisu[i][j]);
            Pintar(255, 0, 0);
            Grafite(5);
        }
    }

    instancebg = Background::getInstance();
    instanceimg = Imagem::getInstance();

    img = instanceimg->getImg(Imagem::BG_JOGO);

    instancebg->setBG(img);
    p = mapaVisu[MAP_X_DIM - 1][MAP_Y_DIM/2];

    mateus = new Mateus(p.x, p.y, cellWidth, cellHeight, MAP_X_DIM - 1, MAP_Y_DIM/2);
    mapaLogico[MAP_X_DIM - 1][MAP_Y_DIM/2] = MATEUS;

}

void State_play::unload(){

}


void State_play::checkCollision(){

}

tipoGame State_play::update(){
    int j = mateus->getCoordj();

    if(ApertouTecla(TECLA_ESQ) && j > 0){
        mapaLogico[MAP_X_DIM - 1][j] = VAZIO;

        j--;
        mateus->setPosicao(mapaVisu[MAP_X_DIM - 1][j].x);
        mateus->setCoordj(j);
        mapaLogico[MAP_X_DIM - 1][j] = MATEUS;
    }
    if(ApertouTecla(TECLA_DIR) && j < MAP_Y_DIM - 1){
        mapaLogico[MAP_X_DIM - 1][j] = VAZIO;

        j++;
        mateus->setPosicao(mapaVisu[MAP_X_DIM - 1][j].x);
        mateus->setCoordj(j);
        mapaLogico[MAP_X_DIM - 1][j] = MATEUS;
    }

    if(ApertouTecla(TECLA_ENTER))
        return GAME_WIN;

    return GAME_NO_CHANGE;
}

void State_play::render(){

    playAPCBase::render();
}
