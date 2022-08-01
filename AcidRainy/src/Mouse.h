#ifndef MOUSE_H
#define MOUSE_H


#include "SDL.h"

class Mouse
{
	friend class Game;
private:
	int pressed, released;
public:
	int GetX();
	int GetY();

	bool IsPressed(int mousecode);
	bool IsPressedNow(int mousecode);
	bool IsReleasedNow(int mousecode);
};


#endif
