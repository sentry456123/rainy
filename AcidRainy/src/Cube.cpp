#include "Cube.h"
#include <math.h>
#include <iostream>

Cube::Cube(Game* game, int x, int y, int width, int height)
	:
	GameObject(game), x(x), y(y), width(width), height(height)
{}

bool IsTriggered(Cube* obj1, Cube* obj2)
{
	if (abs(obj1->x + obj1->width / 2 - obj2->x - obj2->width / 2) > obj1->width / 2 + obj2->width / 2)
		return false;
	if (abs(obj1->y + obj1->height / 2 - obj2->y - obj2->height / 2) > obj1->height / 2 + obj2->height / 2)
		return false;
	return true;
}

bool IsTriggered(Cube* obj, int x, int y)
{
	
	if (obj->x >= x)
		return false;
	if (obj->x + obj->width < x)
		return false;
	if (obj->y >= y)
		return false;
	if (obj->y + obj->height < y)
		return false;
	return true;
}
