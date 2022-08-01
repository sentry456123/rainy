#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "SDL.h"

class Keyboard
{
	friend class Game;
private:
	SDL_Keycode pressed, released;
public:
	bool IsPressed(int scancode);
	bool IsPressedNow(SDL_Keycode keycode);
	bool IsReleasedNow(SDL_Keycode keycode);
};


#endif
