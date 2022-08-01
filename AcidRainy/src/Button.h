#ifndef BUTTON_H
#define BUTTON_H

#include "Cube.h"

#define BUTTON_DEFAULT    ButtonMode(0x00000000)
#define BUTTON_UPPER_CASE ButtonMode(0x00000001)

typedef int ButtonMode;

class Button : public Cube
{
protected:
	const char* text;
	bool targeted = false;
	bool pushed = false;
	unsigned int touchedTime = 0;
	ButtonMode mode;
public:
	Button(Game* game, int x, int y, int width, int height, const char* text, ButtonMode mode);
	void Update() override;
	void Render() override;
	bool IsPushed();
};



#endif
