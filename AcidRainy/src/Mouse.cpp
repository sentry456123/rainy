#include "Mouse.h"
#include "SDL.h"

int Mouse::GetX()
{
	int x;
	SDL_GetMouseState(&x, nullptr);
	return x;
}

int Mouse::GetY()
{
	int y;
	SDL_GetMouseState(nullptr, &y);
	return y;
}

bool Mouse::IsPressed(int mousecode)
{
	return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(mousecode);
}

bool Mouse::IsPressedNow(int mousecode)
{
	return pressed == mousecode;
}

bool Mouse::IsReleasedNow(int mousecode)
{
	return released == mousecode;
}
