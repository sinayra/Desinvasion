#pragma once

//#include "playAPCBase.h"
#include <windows.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

//int id;
//void *tocaSom(void*);
//bool isPlaying=false;

class Sound
{
    private:
		int id;
		bool isPlaying;
		static Sound *instance;

    public:
		Sound();
        void *tocaSom();

        bool getIsPlaying();
        void setIsPlaying(bool);
		int getId();
        void setId(int);
        void play(int);

        static Sound *getInstance();

        static void *tocaSom_helper(void *context)
        {
			return ((Sound*)context)->tocaSom();
		}
};


