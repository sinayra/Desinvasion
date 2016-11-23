#pragma once

#define GAME_NO_CHANGE 0
#define GAME_START 1
#define GAME_PLAY 2
#define GAME_PAUSE 3
#define GAME_WIN 5
#define GAME_LOSE 6
#define GAME_END 7

class State{
    public:
        virtual void load(int stack = 0) = 0;
        virtual void unload() = 0;
        virtual int update() = 0;
        virtual void render() = 0;
};
