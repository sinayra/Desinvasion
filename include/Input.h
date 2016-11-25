#pragma once
#include <playAPC/playapc.h>

#define TECLA_CIMA GLFW_KEY_UP
#define TECLA_BAIXO GLFW_KEY_DOWN
#define TECLA_ENTER GLFW_KEY_ENTER

class Input{
    private:
        static Input *instance;
        bool quit;

        Input();
    public:
        Input *getInstance();
        void update();
        bool quitGame();
};
