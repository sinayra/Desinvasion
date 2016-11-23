#include "stateCutscene.h"

void stateIntro(int *fundo){
    extern int imgnada, imgenter, imgload; //imgs comuns entre estados

    Ponto p;
    int img, press, pressret;
    string imgpath;
    stringstream ss;
    bool skip = false;

    p.x = -133.5;
    p.y = -100;

    *fundo = CriaRetangulo(267, 200, p);
    Pintar(255, 255, 255);

    press = CriaGrupo();

    p.x = 70;
    p.y = -90;
    pressret = CriaRetangulo(50, 8, p);
    Pintar(255, 255, 255);

    for(int i = 0; i < 12 && !skip; i++){
        AssociaImagem(imgnada, RETANGULO, pressret);
        Desenha1Frame();
        ss.str("");
        ss  << "img/cutscene/" << i + 1 << ".png";
        imgpath = ss.str();

        img = AbreImagem(imgpath.c_str());
        AssociaImagem(img, RETANGULO, *fundo);

        esperaSegundos(1);

        AssociaImagem(imgenter, RETANGULO, pressret);

        while(!ApertouTecla(GLFW_KEY_ENTER)){
            if(ApertouTecla('S')){
                skip = true;
                break;
            }
            Desenha1Frame();
        }
    }

    ApagaGrupo(press);
}

void stateFim(int fundo, tipoEstado st){
    extern int imgnada, imgenter, imgload; //imgs comuns entre estados

    Ponto p;
    int img, press, pressret;
    string imgpath, sst;
    stringstream ss;
    bool skip = false;

    if(st == WIN)
        sst = 'w';
    else if(st == LOSE)
        sst = 'l';

    p.x = -133.5;
    p.y = -100;

    press = CriaGrupo();

    p.x = 70;
    p.y = -90;
    pressret = CriaRetangulo(50, 8, p);
    Pintar(255, 255, 255);

    for(int i = 13; i < 15; i++){
        AssociaImagem(imgnada, RETANGULO, pressret);
        Desenha1Frame();
        ss.str("");
        ss  << "img/cutscene/" << i << '-' << sst << ".png";
        imgpath = ss.str();

        img = AbreImagem(imgpath.c_str());
        AssociaImagem(img, RETANGULO, fundo);

        esperaSegundos(1);

        AssociaImagem(imgenter, RETANGULO, pressret);

        while(!ApertouTecla(GLFW_KEY_ENTER)){
            if(ApertouTecla('S')){
                skip = true;
                break;
            }
            Desenha1Frame();
        }
    }

    for(int i = 15; i < 22 && !skip; i++){
        AssociaImagem(imgnada, RETANGULO, pressret);
        Desenha1Frame();
        ss.str("");
        ss  << "img/cutscene/" << i << ".png";
        imgpath = ss.str();

        img = AbreImagem(imgpath.c_str());
        AssociaImagem(img, RETANGULO, fundo);

        esperaSegundos(1);

        AssociaImagem(imgenter, RETANGULO, pressret);

        while(!ApertouTecla(GLFW_KEY_ENTER)){
            if(ApertouTecla('S')){
                skip = true;
                break;
            }
            Desenha1Frame();
        }
    }

    ApagaGrupo(press);
}
