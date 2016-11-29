#pragma once

#include <playAPC/playapc.h>
#include <chrono>
using namespace std::chrono;

class playAPCBase{
    private:

    public:
        static bool inicializaPlayAPC();
        static void render();
        static void freeze();

        static milliseconds tempo();
        static bool duracao(milliseconds tic, int tempo);
};
