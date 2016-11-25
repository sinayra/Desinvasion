#include "State_op.h"
#include "State_play.h"
#include "State_end.h"
#include "Input.h"

class State_manager{
    private:
        State *estadoAtual;
        Input *input;
        tipoGame stack;
    public:
        State_manager();
        ~State_manager();
        void run();
};
