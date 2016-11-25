#include "State_op.h"
#include "State_play.h"
#include "State_end.h"

class State_manager{
    private:
        State *estadoAtual;
        int stack;
    public:
        State_manager();
        ~State_manager();
        void run();
};
