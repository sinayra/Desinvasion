#pragma once
#include <playAPC/playapc.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <math.h>

#include "utils.h"

typedef struct{
    int porta;
    int escada;
    int num;
}tipoCorredor;

typedef enum{
    DIR_ESQ,
    DIR_DIR,
    DIR_CIMA,
    DIR_BAIXO
}tipoDirecao;

typedef enum{
    ZUMBI,
    LOBISOMEM
}tipoMonstroRaca;

typedef enum{
    W1 = 1,
    W2,
    W3,
    M
}tipoMoradorRoupa;

typedef struct{
    tipoMoradorRoupa roupa;
    int q;
    int g;
    int posx, posy;
    int sprite;
    int *img;
    bool aparece;
}tipoMorador;

typedef struct{
    int doces;
    int andar;
    int posx;
    int posy;
    int sprite;
    int lane;
}tipoHeroi;

typedef struct{
    int andar;
    int lane;
    float posx;
    int posy;
    int dir;
    int sprite;
    int passo;
    float velocidade;
    tipoMonstroRaca raca;
}tipoMonstro;

tipoEstado stateGame(int fundo);
