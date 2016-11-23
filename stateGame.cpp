#include "stateGame.h"
#include <iostream>

#define P_WIDTH 10
#define P_HEIGHT 11

#define WW_WIDTH 20
#define WW_HEIGHT 13

#define C_WIDTH 7
#define C_HEIGHT 8

#define QTD_IMGS 53
#define QTD_ZUMBIS 10

#define W_ESCADA 30
#define W_PORTA 10
#define VIDAS 28

extern int imgenter, imgload, imgnada;
const int Y_ANDAR[4] = {-86, -32, 22, 79};

tipoCorredor corr[4];
tipoHeroi hero;
tipoMonstro zumbi[QTD_ZUMBIS];
tipoMonstro ww;
float dificuldade;
int porta[22] = {0, 2, 3, 4, 5, 6, 8, 10, 11, 12, 13, 14, 15, 16, 17, 19, 20, 21, 23, 24, 25, 26};
tipoMorador morador[4];

int load, loadret, bar, barret;
int imghero[7], imgm[6], imgw1[6], imgw2[6], imgw3[6], imgww[6], imgz[6], imgdoce[2];
int qhero, qm, qw1[4], qw2[4], qw3[4], qww, qz[QTD_ZUMBIS], qdoce[VIDAS];
int ghero, gm, gw1[4], gw2[4], gw3[4], gww, gz[QTD_ZUMBIS], gdoce;

int gcorredor[4], gplaca[4], gnumeros[8], gporta[4], gtapete[4];
int qcorredor[4], qplaca[4], qnumeros[8], qporta[4], qtapete[8];
int imgcorredor, imgplaca, imgporta, imgnumeros[10], imgtapete;

void carregaSprite(string header, int v[], int *q, int base, int altura){
    Ponto p;
    string imgpath;
    stringstream ss;

    p.x = 0;
    p.y = 13;

    *q = CriaRetangulo(base, altura, p);
    AssociaImagem(imgnada);
    Pintar(255, 255, 255);

    if(header.compare("hero") == 0)
        v[6] = AbreImagem("img/sprite/hero0.png");

    for(int i = 0; i < 3; i++){
        ss.str("");
        ss  << "img/sprite/" << header << i + 1 << ".png";
        imgpath = ss.str();

        v[i] = AbreImagem(imgpath.c_str());

        ss.str("");
        ss  << "img/sprite/d" << header << i + 1 << ".png";
        imgpath = ss.str();

        v[i + 3] = AbreImagem(imgpath.c_str());
    }
}

void carregaImgs(){
    Ponto p;
    int l = 1;
    int borda;
    int ratio = 100/QTD_IMGS;
    int espelha;

    load = CriaGrupo();
    p.x = 80;
    p.y = -90;
    loadret = CriaRetangulo(QTD_IMGS, 8, p);
    Pintar(255, 255, 255);

    AssociaImagem(imgload);

    p.x = -25.5;
    p.y = 0;
    borda = CriaGrupo();
    CriaRetangulo(QTD_IMGS + 1, 20, p);
    Pintar(148, 87, 27);

    bar = CriaGrupo();
    p.x = 0;
    p.y = 0;
    CriaRetangulo(1, 20, p);
    Pintar(220, 143, 68);
    p.x = -25.5;
    Move(p, bar);

    Desenha1Frame();

    p.x = -133.5;
    p.y = -100;
    imgcorredor = AbreImagem("img/fundo/corredor.png");
    espelha = 1;
    for(int i = 0; i < 4; i++){
        gcorredor[i] = CriaGrupo();
        qcorredor[i] = CriaRetangulo(267, 55, p);

        corr[i].escada = (espelha > 0 ? 51 : -90);

        Pintar(255, 255, 255);
        AssociaImagem(imgnada);
        Redimensiona(espelha, 1, gcorredor[i]);

        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();

        espelha *= -1;
        p.y += 55;
    }



    p.x = -100;
    p.y = -75;
    imgplaca = AbreImagem("img/fundo/placa.png");
    for(int i = 0; i < 4; i++){
        gplaca[i] = CriaGrupo();
        qplaca[i] = CriaRetangulo(7, 7, p);
        Pintar(255, 255, 255);
        AssociaImagem(imgnada);

        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();

        p.x *= -1;
        p.y += 55;
    }


    for(int i = 0; i < 10; i++){
        string imgpath;
        stringstream ss;

        ss << "img/fundo/" << i << ".png";
        imgpath = ss.str();
        imgnumeros[i] = AbreImagem(imgpath.c_str());

        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();
    }
    p.x = -99;
    p.y = -73;
    for(int i = 0; i < 8; i += 2){
        p.x = (p.x < 0 ? -99 : 101);
        int px_aux = p.x;

        gnumeros[i] = CriaGrupo();
        qnumeros[i] = CriaRetangulo(2, 3, p);
        Pintar(255, 255, 255);
        AssociaImagem(imgnada);

        p.x += 2;

        gnumeros[i + 1] = CriaGrupo();
        qnumeros[i + 1] = CriaRetangulo(2, 3, p);
        Pintar(255, 255, 255);
        AssociaImagem(imgnada);

        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();

        p.x = px_aux;

        p.x *= -1;
        p.y += 55;
    }

    p.x = -40;
    p.y = -86.5;
    imgporta = AbreImagem("img/fundo/porta.png");
    for(int i = 0; i < 4; i++){
        gporta[i] = CriaGrupo();
        qporta[i] = CriaRetangulo(W_PORTA, 17, p);
        corr[i].porta = p.x;

        Pintar(255, 255, 255);
        AssociaImagem(imgnada);

        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();

        p.x *= -1;
        p.y += 55;
    }

    p.x = -42;
    p.y = -88;
    imgtapete = AbreImagem("img/fundo/tapete.png");
    for(int i = 0; i < 4; i++){
        p.x = (p.x < 0 ? -42 : 38);

        gtapete[i] = CriaGrupo();
        qtapete[4 + i] = CriaRetangulo(13, 3, p);
        Pintar(16, 16, 16);
        qtapete[i] = CriaRetangulo(13, 3, p);
        Pintar(255, 255, 255);
        AssociaImagem(imgnada);

        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();

        p.x *= -1;
        p.y += 55;

    }

    gww = CriaGrupo();
    carregaSprite("ww", imgww, &qww, WW_WIDTH, WW_HEIGHT);
    Redimensiona(ratio * l, 1, bar);
    l++;
    Desenha1Frame();

    p.x = 0;
    p.y = 0;

    for(int i = 0; i < QTD_ZUMBIS; i++){
        gz[i] = CriaGrupo();
        carregaSprite("z", imgz, &qz[i], P_WIDTH, P_HEIGHT);
        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();
    }

    for(int i = 0; i < 4; i++){
        gw3[i] = CriaGrupo();
        carregaSprite("w3", imgw3, &qw3[i], C_WIDTH, C_HEIGHT);
        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();
    }

    for(int i = 0; i < 4; i++){
        gw2[i] = CriaGrupo();
        carregaSprite("w2", imgw2, &qw2[i], P_WIDTH, P_HEIGHT);
        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();
    }

    for(int i = 0; i < 4; i++){
        gw1[i] = CriaGrupo();
        carregaSprite("w1", imgw1, &qw1[i], P_WIDTH, P_HEIGHT);
        Redimensiona(ratio * l, 1, bar);
        l++;
        Desenha1Frame();
    }


    gm = CriaGrupo();
    carregaSprite("m", imgm, &qm, C_WIDTH, C_HEIGHT);
    Redimensiona(ratio * l, 1, bar);
    l++;
    Desenha1Frame();


    ghero = CriaGrupo();
    carregaSprite("hero", imghero, &qhero, P_WIDTH, P_HEIGHT);
    Redimensiona(ratio * l, 1, bar);
    l++;
    Desenha1Frame();

    gdoce = CriaGrupo();
    imgdoce[0] = AbreImagem("img/recursos/doce0.png");
    imgdoce[1] = AbreImagem("img/recursos/doce1.png");
    p.x = -133;
    p.y = 95;
    for(int i = 0 ; i < VIDAS; i++){
        qdoce[i] = CriaRetangulo(5, 5, p);
        Pintar(255, 255, 255);
        AssociaImagem(imgnada);
        p.x += 5;
    }
    l++;
    Redimensiona(ratio * l, 1, bar);
    Desenha1Frame();

    AssociaImagem(imgenter, RETANGULO, loadret);
    while(!ApertouTecla(GLFW_KEY_ENTER))
       Desenha1Frame();

    ApagaGrupo(borda);
    ApagaGrupo(bar);
    ApagaGrupo(load);
}

void criaLobisomem(){
    Ponto p;

    ww.raca = LOBISOMEM;
    ww.andar = rand()%3 + 1;
    ww.lane = rand()%2;
    ww.dir = -1 + rand()%2;
    if(ww.dir == -1){
        ww.posx = -120;
    }
    else{
        ww.posx = 120;
        ww.dir = 1;
    }
    ww.posy = Y_ANDAR[ww.andar] - 10 * ww.lane;
    ww.sprite = 0;
    ww.passo = 0;
    ww.velocidade = (rand()%5 + 1) * dificuldade;

    /*cout << "ww : " << ww.dir << endl;
    cout << "lane : " << ww.lane << endl;
    cout << "andar : " << ww.andar << endl;
    cout << "posx : " << ww.posx << endl;
    cout << "posy : " << ww.posy << endl;
    cout << "velocidade : " << ww.velocidade << endl;*/

    AssociaImagem(imgww[0], RETANGULO, qww);
    p.x = ww.posx;
    p.y = ww.posy;
    Move(p, gww);
    //while(!ApertouTecla(GLFW_KEY_ENTER))
      // Desenha1Frame();
}

void criaZumbi(){
    Ponto p;

    for(int i = 0; i < QTD_ZUMBIS; i++){
        zumbi[i].raca = ZUMBI;
        zumbi[i].andar = rand()%3 + 1;
        zumbi[i].lane = rand()%2;
        zumbi[i].dir = -1 + rand()%3;
        zumbi[i].posx = 120 * zumbi[i].dir;
        zumbi[i].posy = Y_ANDAR[zumbi[i].andar] - 10 * zumbi[i].lane;
        zumbi[i].sprite = 0;
        zumbi[i].passo = 0;
        zumbi[i].velocidade = (rand()%2 + 1) * dificuldade + zumbi[i].lane * 2;

        /*cout << "zumbi " << i << ": " << zumbi[i].dir << endl;
        cout << "lane : " << zumbi[i].lane << endl;
        cout << "andar : " << zumbi[i].andar << endl;
        cout << "posx : " << zumbi[i].posx << endl;
        cout << "posy : " << zumbi[i].posy << endl;
        cout << "velocidade : " << zumbi[i].velocidade << endl;*/


        if(zumbi[i].dir == 0){
            AssociaImagem(imgnada, RETANGULO, qz[i]);
        }
        else{
            AssociaImagem(imgz[0], RETANGULO, qz[i]);
            p.x = zumbi[i].posx;
            p.y = zumbi[i].posy;
            Move(p, gz[i]);
        }

       // while(!ApertouTecla(GLFW_KEY_ENTER))
         //   Desenha1Frame();

    }
}

void mudaNumerosAndar(){

    for(int i = 4; i < 8; i++){
        Pintar(rand()%255, rand()%255, rand()%255, RETANGULO, qtapete[i]); //muda cor do tapete
    }
    for(int i = 0; i < 4; i++){
        if(morador[i].aparece){
            morador[i].aparece = false;
            AssociaImagem(imgnada, RETANGULO, morador[i].q);
        }
    }
    dificuldade += 0.5;
    criaZumbi();

    if(hero.andar > 15)
        criaLobisomem();

    if(hero.andar < 4){
        AssociaImagem(imgnumeros[0], RETANGULO, qnumeros[1]); //0
        AssociaImagem(imgnumeros[1], RETANGULO, qnumeros[3]); //1
        AssociaImagem(imgnumeros[2], RETANGULO, qnumeros[5]); //2
        AssociaImagem(imgnumeros[3], RETANGULO, qnumeros[7]); //3
    }
    else if(hero.andar < 8){
        AssociaImagem(imgnumeros[4], RETANGULO, qnumeros[1]); //4
        AssociaImagem(imgnumeros[5], RETANGULO, qnumeros[3]); //5
        AssociaImagem(imgnumeros[6], RETANGULO, qnumeros[5]); //6
        AssociaImagem(imgnumeros[7], RETANGULO, qnumeros[7]); //7
    }
    else if(hero.andar < 12){
        AssociaImagem(imgnumeros[8], RETANGULO, qnumeros[1]); //8
        AssociaImagem(imgnumeros[9], RETANGULO, qnumeros[3]); //9

        AssociaImagem(imgnumeros[1], RETANGULO, qnumeros[4]);
        AssociaImagem(imgnumeros[1], RETANGULO, qnumeros[6]);

        AssociaImagem(imgnumeros[0], RETANGULO, qnumeros[5]); //10
        AssociaImagem(imgnumeros[1], RETANGULO, qnumeros[7]); //11
    }
    else if(hero.andar < 16){
        AssociaImagem(imgnumeros[1], RETANGULO, qnumeros[0]);
        AssociaImagem(imgnumeros[1], RETANGULO, qnumeros[2]);

        AssociaImagem(imgnumeros[2], RETANGULO, qnumeros[1]); //12
        AssociaImagem(imgnumeros[3], RETANGULO, qnumeros[3]); //13
        AssociaImagem(imgnumeros[4], RETANGULO, qnumeros[5]); //14
        AssociaImagem(imgnumeros[5], RETANGULO, qnumeros[7]); //15
    }
    else if(hero.andar < 20){
        AssociaImagem(imgnumeros[6], RETANGULO, qnumeros[1]); //16
        AssociaImagem(imgnumeros[7], RETANGULO, qnumeros[3]); //17
        AssociaImagem(imgnumeros[8], RETANGULO, qnumeros[5]); //18
        AssociaImagem(imgnumeros[9], RETANGULO, qnumeros[7]); //19

    }
    else if(hero.andar < 24){
        AssociaImagem(imgnumeros[2], RETANGULO, qnumeros[0]);
        AssociaImagem(imgnumeros[2], RETANGULO, qnumeros[2]);
        AssociaImagem(imgnumeros[2], RETANGULO, qnumeros[4]);
        AssociaImagem(imgnumeros[2], RETANGULO, qnumeros[6]);

        AssociaImagem(imgnumeros[0], RETANGULO, qnumeros[1]); //20
        AssociaImagem(imgnumeros[1], RETANGULO, qnumeros[3]); //21
        AssociaImagem(imgnumeros[2], RETANGULO, qnumeros[5]); //22
        AssociaImagem(imgnumeros[3], RETANGULO, qnumeros[7]); //23
    }
    else if(hero.andar < 28){
        AssociaImagem(imgnumeros[4], RETANGULO, qnumeros[1]); //24
        AssociaImagem(imgnumeros[5], RETANGULO, qnumeros[3]); //25
        AssociaImagem(imgnumeros[6], RETANGULO, qnumeros[5]); //26
        AssociaImagem(imgnumeros[7], RETANGULO, qnumeros[7]); //27
    }
    else{
        AssociaImagem(imgnumeros[3], RETANGULO, qnumeros[4]);

        AssociaImagem(imgnumeros[8], RETANGULO, qnumeros[1]); //28
        AssociaImagem(imgnumeros[9], RETANGULO, qnumeros[3]); //29
        AssociaImagem(imgnumeros[0], RETANGULO, qnumeros[5]); //30
        AssociaImagem(imgnada, RETANGULO, qnumeros[7]); //nao existe
    }
}

void inicializaJogo(){
    Ponto p;

    hero.andar = 0;
    hero.doces = VIDAS;
    hero.sprite = 0;
    dificuldade = 0;

    for(int i = 0; i < VIDAS; i++){
        AssociaImagem(imgdoce[1], RETANGULO, qdoce[i]);
    }

    for(int i = 0; i < 4; i++){
        AssociaImagem(imgcorredor, RETANGULO, qcorredor[i]);
        AssociaImagem(imgplaca, RETANGULO, qplaca[i]);
        AssociaImagem(imgporta, RETANGULO, qporta[i]);

        AssociaImagem(imgtapete, RETANGULO, qtapete[i]);
    }
    mudaNumerosAndar();
    AssociaImagem(imghero[6], RETANGULO, qhero);


    p.x = -133;
    p.y = Y_ANDAR[0];
    Move(p, ghero);

    hero.posx = p.x;
    hero.posy = p.y;
    hero.lane = 0;
}

tipoDirecao updateHeroi(){

    if(hero.andar % 2 == 0)
        return DIR_DIR;
    else
        return DIR_ESQ;

}

void andaHero(tipoDirecao dir){
    Ponto p;

    if(hero.andar < 28){
        hero.sprite++;
        hero.sprite %= 3;

        p.x = hero.posx;
        p.y = hero.posy;

        if(dir == DIR_ESQ){
            AssociaImagem(imghero[hero.sprite], RETANGULO, qhero);
            p.x -= 2.5;
        }
        else{
            AssociaImagem(imghero[hero.sprite + 3], RETANGULO, qhero);
            p.x += 2.5;
        }

        if(hero.posx < -133)
            p.x = 133;
        else if(hero.posx > 133)
            p.x = -133;

        Move(p, ghero);
        hero.posx = p.x;
        for(int i = 0; i < 5; i++)
            Desenha1Frame();

    }
    else{
        if(hero.sprite != 6){
            hero.sprite = 6;
            AssociaImagem(imghero[hero.sprite], RETANGULO, qhero);
        }
    }
}

void animaPorta(){
    int andar = hero.andar % 4;
    if(buscaBinaria(porta, 22, hero.andar) && !morador[andar].aparece){
        if(hero.andar == 23){
            morador[andar].roupa = M;
        }
        else{
            morador[andar].roupa = (tipoMoradorRoupa)(rand()%3 + 1);
        }

        switch(morador[andar].roupa){
            case M:
                morador[andar].g = gm;
                morador[andar].q = qm;
                morador[andar].img = imgm;
            break;

            case W1:
                morador[andar].g = gw1[andar];
                morador[andar].q = qw1[andar];
                morador[andar].img = imgw1;
            break;

            case W2:
                morador[andar].g = gw2[andar];
                morador[andar].q = qw2[andar];
                morador[andar].img = imgw2;
            break;

            case W3:
                morador[andar].g = gw3[andar];
                morador[andar].q = qw3[andar];
                morador[andar].img = imgw3;
            break;
        }
        morador[andar].sprite = 0;
        morador[andar].posx = corr[andar].porta;
        morador[andar].posy = Y_ANDAR[andar];
        morador[andar].aparece = true;

        AssociaImagem(morador[andar].img[0], RETANGULO, morador[andar].q);

        //while(!ApertouTecla(GLFW_KEY_ENTER))
            //Desenha1Frame();
    }
}

template<typename NPC>
bool colidiuParede(NPC z){
    if(z.posx > 135 || z.posx < -135){
        return true;
    }
    return false;
}

bool colidiuPorta(int andar){
    if(corr[andar].porta <= hero.posx && corr[andar].porta +  W_PORTA >= hero.posx){
        if(hero.lane == 0)
            return true;
    }
    return false;
}

bool colidiuEscada(int andar){

    if(corr[andar].escada <= hero.posx && corr[andar].escada +  W_ESCADA >= hero.posx){
        return true;
    }
    return false;
}

void removeMorador(int i){
    AssociaImagem(imgnada, RETANGULO, morador[i].q);
    morador[i].aparece = false;
}

void andaMorador(int i){
    Ponto p;

    p.y = morador[i].posy;
    p.x = morador[i].posx;

    morador[i].sprite++;
    morador[i].sprite %= 3;

    if(morador[i].posx < 0){
        p.x--;
        AssociaImagem(morador[i].img[morador[i].sprite], RETANGULO, morador[i].q);
    }
    else{
        p.x++;
        AssociaImagem(morador[i].img[morador[i].sprite + 3], RETANGULO, morador[i].q);
    }

    Move(p, morador[i].g);
    morador[i].posx = p.x;
}

void animaEscada(){
    Ponto p;
    int posyf = Y_ANDAR[(hero.andar + 1) % 4] - 25;
    bool direita = ((corr[hero.andar % 4].escada > 0) ? true : false);

    p.x = corr[hero.andar % 4].escada + (direita ? 20 : 10);
    p.y = Y_ANDAR[hero.andar % 4];
    while(p.y < posyf){
        hero.sprite++;
        hero.sprite %= 3;

        if(direita){
            AssociaImagem(imghero[hero.sprite + 3], RETANGULO, qhero);
            p.x += 1;
            p.y += 1.8;
        }
        else{
            AssociaImagem(imghero[hero.sprite], RETANGULO, qhero);
            p.x -= 1;
            p.y += 1.8;
        }
        Move(p, ghero);
        for(int i = 0; i < 7; i++)
            Desenha1Frame();
    }

    hero.posx = (direita ? 133 : -133);
    hero.andar++;
    hero.posy = Y_ANDAR[hero.andar % 4] - 10 * hero.lane;

    if(hero.andar > 0 && hero.andar % 4 == 0){
        Ponto p;

        p.x = -133;
        mudaNumerosAndar();
        p.y = Y_ANDAR[0];
        Move(p, ghero);
        hero.posx = p.x;
        hero.posy = p.y;
        hero.lane = 0;
    }

}

bool colidiuMonstro(tipoMonstro m){
    if(m.dir != 0){
        if(m.andar == (hero.andar % 4) && m.lane == hero.lane){
            float dist, raio;
            dist = sqrt(pow(m.posx - hero.posx, 2));
            //cout << "dist: " << dist << endl;

            if(m.raca == ZUMBI)
                raio = P_WIDTH;
            else
                raio = (P_WIDTH/2) + (WW_WIDTH/2);
            if(dist <= raio){
                return true;
            }
        }
    }
    return false;
}

void animaMonstro(tipoDirecao dir){
    Ponto p;

    p.x = hero.posx;
    p.y = hero.posy;
    if(dir == DIR_ESQ)
        p.x += 40;
    else
        p.x -= 40;

    if(p.x < -133)
        p.x = 133;
    else if(p.x > 133)
        p.x = 133;

    for(int i = 0; i < 5; i++){
        if(i % 2 == 0)
            Pintar(255, 0, 0, RETANGULO, qhero);
        else
            Pintar(255, 255, 255, RETANGULO, qhero);
        for(int j = 0; j < 5; j++)
            Desenha1Frame();
    }

    Move(p, ghero);
    for(int i = 0; i < 5; i++){
        if(i % 2 == 0)
            Pintar(255, 0, 0, RETANGULO, qhero);
        else
            Pintar(255, 255, 255, RETANGULO, qhero);
        for(int j = 0; j < 5; j++)
            Desenha1Frame();
    }

    Pintar(255, 255, 255, RETANGULO, qhero);

    hero.posx = p.x;
}

void recebeDano(int dano){
    while(dano > 0){
        AssociaImagem(imgdoce[0], RETANGULO, qdoce[hero.doces - 1]);
        hero.doces--;
        dano--;
    }
}

void verificaColisao(tipoDirecao dir){

    andaHero(dir);

    if(colidiuEscada(hero.andar % 4))
        animaEscada();

    if(colidiuPorta(hero.andar % 4))
        animaPorta();
    for(int i = 0; i < QTD_ZUMBIS; i++){
        if(colidiuMonstro(zumbi[i])){
            animaMonstro(dir);
            recebeDano(1);
        }
    }
    if(colidiuMonstro(ww)){
        animaMonstro(dir);
        recebeDano(3);
    }

    for(int i = 0; i < 4; i++){
        if(morador[i].aparece){
            if(colidiuParede(morador[i]))
                removeMorador(i);
            else
                andaMorador(i);
        }
    }
}

void updateTeclado(){
    Ponto p;

    p.x = hero.posx;
    if(ApertouTecla(GLFW_KEY_UP) && hero.lane == 1){
        hero.lane = 0;
        p.y = Y_ANDAR[hero.andar % 4];

        Move(p, ghero);
        hero.posy = p.y;
    }
    else if(ApertouTecla(GLFW_KEY_DOWN) && hero.lane == 0){
        hero.lane = 1;
        p.y = Y_ANDAR[hero.andar % 4] - 10;

        Move(p, ghero);
        hero.posy = p.y;
    }
}


void updateMonstros(){
    Ponto p;
    for(int i = 0; i < QTD_ZUMBIS; i++){
        if(zumbi[i].dir != 0){
            if(zumbi[i].passo == 0){
                if(!colidiuParede(zumbi[i])){
                    zumbi[i].sprite++;
                    zumbi[i].sprite %= 3;

                    p.x = zumbi[i].posx;
                    p.y = zumbi[i].posy;

                    if(zumbi[i].dir > 0){
                        AssociaImagem(imgz[zumbi[i].sprite], RETANGULO, qz[i]);
                        p.x = p.x - 0.5 * zumbi[i].velocidade;
                    }
                    else{
                        AssociaImagem(imgz[zumbi[i].sprite + 3], RETANGULO, qz[i]);
                        p.x = p.x + 0.5 * zumbi[i].velocidade;
                    }

                    Move(p, gz[i]);
                    zumbi[i].posx = p.x;

                }
                else{
                    zumbi[i].dir *= -1;
                    zumbi[i].posx = 130 * zumbi[i].dir;
                }
                zumbi[i].passo++;
            }
            else{
                zumbi[i].passo++;
                if(zumbi[i].passo == 3)
                    zumbi[i].passo = 0;
            }
        }
    }

    if(hero.andar > 15){
        if(!colidiuParede(ww)){
            ww.sprite++;
            ww.sprite %= 3;

            p.x = ww.posx;
            p.y = ww.posy;

            if(ww.dir > 0){
                AssociaImagem(imgww[ww.sprite + 3], RETANGULO, qww);
                p.x = p.x + 0.5 * ww.velocidade;
            }
            else{
                AssociaImagem(imgww[ww.sprite], RETANGULO, qww);
                p.x = p.x - 0.5 * ww.velocidade;
            }

            Move(p, gww);
            ww.posx = p.x;
        }
        else{
            if(ww.dir == 1){
                ww.posx = 130;
                ww.dir = -1;
            }
            else{
                ww.posx = -130;
                ww.dir = 1;
            }
        }
    }
}

tipoEstado stateGame(int fundo){
    tipoEstado st = INGAMING;
    tipoDirecao pos;

    carregaImgs();
    inicializaJogo();

    while(st == INGAMING){
        pos = updateHeroi();
        updateMonstros();
        updateTeclado();
        verificaColisao(pos);

        if(hero.doces <= 0)
            st = LOSE;

        if(hero.andar == 27)
            st = WIN;

        Desenha1Frame();
    }


    //cout << "hero" << endl;
    ApagaGrupo(ghero);

    //while(!ApertouTecla(GLFW_KEY_ENTER))
      //    Desenha1Frame();

    //cout << "ww" << endl;
    ApagaGrupo(gww);
    //while(!ApertouTecla(GLFW_KEY_ENTER))
      //    Desenha1Frame();

    //cout << "m" << endl;
    ApagaGrupo(gm);
    //while(!ApertouTecla(GLFW_KEY_ENTER))
      //    Desenha1Frame();
    for(int i = 0; i < 4; i++){
        //cout << "corredor" << endl;
        ApagaGrupo(gcorredor[i]);
        //cout << "placa" << endl;
        ApagaGrupo(gplaca[i]);
        //cout << "porta" << endl;
        ApagaGrupo(gporta[i]);
        //cout << "tapete" << endl;
        //ApagaGrupo(gtapete[i]);
        AssociaImagem(imgnada, RETANGULO, qtapete[i]);
        Pintar(255, 255, 255, RETANGULO, qtapete[i + 4]);
        AssociaImagem(imgnada, RETANGULO, qtapete[i + 4]);

        //cout << "w2" << endl;
        ApagaGrupo(gw2[i]);
        //cout << "w1" << endl;
        ApagaGrupo(gw1[i]);
        //cout << "w3" << endl;
        ApagaGrupo(gw3[i]);
    }

   // while(!ApertouTecla(GLFW_KEY_ENTER))
     //     Desenha1Frame();
    //cout << "numeros" << endl;
    for(int i = 0; i < 8; i++){
        ApagaGrupo(gnumeros[i]);
    }

   // while(!ApertouTecla(GLFW_KEY_ENTER))
     //     Desenha1Frame();

    //cout << "z" << endl;
    for(int i = 0; i < QTD_ZUMBIS; i++)
        ApagaGrupo(gz[i]);

    //while(!ApertouTecla(GLFW_KEY_ENTER))
      //    Desenha1Frame();

    //cout << "doce" << endl;
    //ApagaGrupo(gdoce);
    //while(!ApertouTecla(GLFW_KEY_ENTER))
      //    Desenha1Frame();
    for(int i = 0; i < VIDAS; i++)
        AssociaImagem(imgnada, RETANGULO, qdoce[i]);

    return st;
}
