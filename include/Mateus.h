#pragma once

#include "Input.h"
#include "Imagem.h"
#include "Sound.h"
#include "playAPCBase.h"
#include <chrono>
#include <openssl/rand.h>

using namespace std::chrono;

class Mateus
{
    public:
        Mateus(float x, float y, float tamw, float tamh, int i, int j);
        virtual ~Mateus();

        void update(int ovelhas_mortas);

        int getCombo();
        bool getAtirou();
        bool getEspaco();

        int getCoordi();
        int getCoordj();

        void setCoordi(int i);
        void setCoordj(int j);

        void setPosicao(float x);

    private:
        int coordx, coordy;
        int coordi, coordj;
        int mateusq, mateusg;
        int combo_ovelhas;
        int combo_ataque;
        bool ataque;
        Imagem *instanceimg;
        Sound *instancesnd;
        bool espaco;

        milliseconds tic;
};
