#ifndef ENEMY_H
#define ENEMY_H



#include "Cube.h"

class Enemy : public Cube
{
public:
	enum class Direction
	{
		DOWN,
		LEFT,
	} direction;
private:
	int speed;
public:
	Enemy(Game* game, int x, int y, int width, int height, int speed, Direction direction);

	void Update() override;
	void Render() override;
};


#endif
