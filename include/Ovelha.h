#include "playAPCBase.h"
#include <playAPC/playapc.h>

class Ovelha{
    public:
        Ovelha(float x, float y, float tamw, float tamh, int i, int j);
        virtual ~Ovelha();

    private:
        bool atingiu;
        int coordy, coordx, coordi, coordj;
        int ovelhaq, ovelhag;
};
