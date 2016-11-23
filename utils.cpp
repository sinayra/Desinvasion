#include "utils.h"

void esperaSegundos(int sec){
    time_t start = time(0);

    while(difftime( time(0), start) < sec){
        Desenha1Frame();
    }
}

bool buscaBinaria(int v[], int tam, int k){
    int inicio = 0, fim = tam, meio;

    while(inicio <= fim){
        meio = (fim + inicio)/2;

        if(v[meio] == k)
            return true;
        else if(v[meio] < k)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return false;
}

