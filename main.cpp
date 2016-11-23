#include <playAPC/playapc.h>
#include <iostream>



int imgnada, imgenter, imgload; //imgs comuns entre estados

int main(){
    int bg;
    tipoEstado st;
    int imghow, imgfim;

    AbreJanela(720, 480, "Disivasion");

    stateIntro(&bg);

    st = stateGame(bg);

    stateFim(bg, st);

    Desenha();
    return 0;
}
