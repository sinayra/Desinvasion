#pragma once

#include <playAPC/playapc.h>
#include <stdlib.h>

class Background
{
    public:
        Background();
        virtual ~Background();
        static Background* getInstance();
        void setBG(int img);

    private:
        static Background *instance;
        int bg, overlay;
};

