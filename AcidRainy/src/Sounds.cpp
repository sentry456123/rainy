#include "Sounds.h"
#include <iostream>
#include "SDL.h"

#define BGM_PATH "bgm.mp3"
#define SOUND_PATH_OPENING "sf_opening.wav"
#define SOUND_PATH_BUTTON_TOUCHED "sf_buttonTouched.wav"
#define SOUND_PATH_BUTTON_PUSHED "sf_buttonPushed.wav"
#define SOUND_PATH_ROTATE "sf_rotate.wav"
#define SOUND_PATH_DIED "sf_died.wav"

void Sounds::Init()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "Error: " << Mix_GetError() << std::endl;
		return;
	}

	bgm = Mix_LoadMUS(BGM_PATH);
	sf_opening = Mix_LoadWAV(SOUND_PATH_OPENING);
	sf_buttonTouched = Mix_LoadWAV(SOUND_PATH_BUTTON_TOUCHED);
	sf_buttonPushed = Mix_LoadWAV(SOUND_PATH_BUTTON_PUSHED);
	sf_rotate = Mix_LoadWAV(SOUND_PATH_ROTATE);
	sf_death = Mix_LoadWAV(SOUND_PATH_DIED);

	Mix_VolumeMusic(50);
	Mix_VolumeChunk(sf_opening, 50);
	Mix_VolumeChunk(sf_buttonTouched, 50);
	Mix_VolumeChunk(sf_buttonPushed, 50);
	Mix_VolumeChunk(sf_rotate, 50);
	Mix_VolumeChunk(sf_death, 50);
}

void Sounds::Quit()
{
	Mix_FreeChunk(sf_opening);
	Mix_FreeChunk(sf_buttonTouched);
	Mix_FreeChunk(sf_buttonPushed);
	Mix_FreeChunk(sf_rotate);
	Mix_FreeChunk(sf_death);
	Mix_FreeMusic(bgm);
	Mix_Quit();
}

void Sounds::PlayBGM()
{
	Mix_PlayMusic(bgm, -1);
}

void Sounds::StopBGM()
{
	Mix_PauseMusic();
}

void Sounds::PlaySF(SF_Type type)
{
	switch (type)
	{
	case SF_Type::OPENING:
		Mix_PlayChannel(-1, sf_opening, 0);
		break;
	case SF_Type::BUTTON_TOUCHED:
		Mix_PlayChannel(-1, sf_buttonTouched, 0);
		break;
	case SF_Type::BUTTON_PUSHED:
		Mix_PlayChannel(-1, sf_buttonPushed, 0);
		break;
	case SF_Type::ROTATE:
		Mix_PlayChannel(-1, sf_rotate, 0);
		break;
	case SF_Type::RETRY_MENU:
		Mix_PlayChannel(-1, sf_death, 0);
		break;
	}
}

void Sounds::StopSF()
{
	Mix_HaltChannel(-1);
}

