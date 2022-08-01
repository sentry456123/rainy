#ifndef CUBE_H
#define CUBE_H


#include "GameObject.h"

class Cube : public GameObject
{
public:
	int x, y, width, height;
	Cube(Game* game, int x, int y, int width, int height);
};

bool IsTriggered(Cube*, Cube*);

bool IsTriggered(Cube*, int x, int y);


#endif
