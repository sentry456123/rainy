#include "Keyboard.h"

bool Keyboard::IsPressed(int scancode)
{
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);
    return keystate[scancode];
}

bool Keyboard::IsPressedNow(SDL_Keycode keycode)
{
    return pressed == keycode;
}

bool Keyboard::IsReleasedNow(SDL_Keycode keycode)
{
    return released == keycode;
}
