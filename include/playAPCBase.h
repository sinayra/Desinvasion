#pragma once

#include <playAPC/playapc.h>
#include <GL/glfw.h>

class playAPCBase{
    private:

    public:
        static bool inicializaPlayAPC();
        static void render();
        static void freeze();

        static void tic();
        static double tac();
};
