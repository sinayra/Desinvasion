#include "../include/Sound.h"
#include <stdio.h>

Sound *Sound::instance = NULL;

Sound* Sound::getInstance(){
    if(!instance)
        instance = new Sound();

    return instance;
}

Sound::Sound(){

   	//pthread_join(threadSong,&sdn);

}

bool Sound::getIsPlaying()
{
	return this->isPlaying;
}
void Sound::setIsPlaying(bool s)
{
	this->isPlaying = s;
}

int Sound::getId()
{
	return this->id;
}
void Sound::setId(int s)
{
	this->id = s;
}

void Sound::play(int n)
{
	pthread_t threadSong;
	//void *sdn;
	this->id = n;
	//void *aux;
	//aux = &instance->tocaSom;
    pthread_create(&threadSong, NULL, &Sound::tocaSom_helper, NULL);

}

/*
void *Sound::tocaSom(void*){

	if(this->num== 1){
		PlaySound("resources/SOUND/06_shoot.wav", NULL, SND_FILENAME);
	}
	if(this->num== 2){
		PlaySound("risada.wav", NULL, SND_FILENAME);
	}
	if(this->num== 3){
		PlaySound("trovao.wav", NULL, SND_FILENAME);
	}

	return NULL;
}
*/

void *Sound::tocaSom(){
	srand(time(NULL));

	instance->setIsPlaying(true);

	if(instance->getId() == 1){
		PlaySound("resources/SOUND/01_the_disinvasion_game.wav", NULL, SND_FILENAME);
	}
	if(instance->getId() == 2){
		PlaySound("resources/SOUND/02_sheep.wav", NULL, SND_FILENAME);
	}
	if(instance->getId() == 3){
		PlaySound("resources/SOUND/03_citizen.wav", NULL, SND_FILENAME);
	}
	if(instance->getId() == 4){
		PlaySound("resources/SOUND/04_pig.wav", NULL, SND_FILENAME);
	}
	if(instance->getId() == 5){
		int r = rand()%100;
		//printf("r = %d\n",r);
		if(r>=0 && r<33)
		{
			PlaySound("resources/SOUND/08_shot_and_book.wav", NULL, SND_FILENAME);
			//PlaySound("resources/SOUND/01_the_disinvasion_game.wav", NULL, SND_FILENAME);
		}
		if(r>=33 && r<66)
		{
			PlaySound("resources/SOUND/09_conhecimento.wav", NULL, SND_FILENAME);
		}
		if(r>=66)
		{
			PlaySound("resources/SOUND/10_toma_livro.wav", NULL, SND_FILENAME);
		}

	}
	/*
	if(id == 6){
		PlaySound("resources/SOUND/06_shoot.wav", NULL, SND_FILENAME);
	}
	if(id == 7){
		PlaySound("resources/SOUND/07_book.wav", NULL, SND_FILENAME);
	}
	if(id == 8){
		PlaySound("resources/SOUND/08_shot_and_book.wav", NULL, SND_FILENAME);
	}
	if(id == 9){
		PlaySound("resources/SOUND/09_conhecimento.wav", NULL, SND_FILENAME);
	}
	if(id == 10){
		PlaySound("resources/SOUND/10_toma_livro.wav", NULL, SND_FILENAME);
	}
	if(id == 10){
		PlaySound("resources/SOUND/11_meteoro.wav", NULL, SND_FILENAME);
	}
	*/
	instance->setIsPlaying(false);
	return NULL;
}
