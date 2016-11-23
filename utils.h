#pragma once
#include <time.h>
#include <playAPC/playapc.h>

using namespace std;

typedef enum{
    WIN,
    LOSE,
    INGAMING,
    UNDEF
}tipoEstado;

void esperaSegundos(int sec);

bool buscaBinaria(int v[], int tam, int k);
