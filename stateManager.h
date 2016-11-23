#include "stateGame.h"
#include "stateCutscene.h"

class StateManager{
    private:
        State *estadoAtual;
        int stack;
    public:
        StateManager();
        ~StateManager();
        void run();
};
