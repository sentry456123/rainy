#ifndef SOUNDS_H
#define SOUNDS_H

#include "SDL_mixer.h"

class Sounds
{
public:
	enum class SF_Type;
private:
	Mix_Music* bgm;

	Mix_Chunk* sf_opening;
	Mix_Chunk* sf_buttonTouched;
	Mix_Chunk* sf_buttonPushed;
	Mix_Chunk* sf_rotate;
	Mix_Chunk* sf_death;
public:
	void Init();
	void Quit();

	void PlayBGM();
	void StopBGM();

	void PlaySF(SF_Type type);
	void StopSF();

public:
	enum class SF_Type
	{
		OPENING,
		BUTTON_TOUCHED,
		BUTTON_PUSHED,
		ROTATE,
		RETRY_MENU,
	};
};


#endif
