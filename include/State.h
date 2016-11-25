#pragma once

typedef enum{
    GAME_NO_CHANGE,
    GAME_START,
    GAME_PLAY,
    GAME_PAUSE,
    GAME_WIN,
    GAME_LOSE,
    GAME_END
}tipoGame;


class State{
    public:
        virtual void load(tipoGame stack = GAME_NO_CHANGE) = 0;
        virtual void unload() = 0;
        virtual int update() = 0;
        virtual void render() = 0;
};
