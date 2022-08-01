#ifndef PLAYER_H
#define PLAYER_H

#include "Cube.h"



class Player : public Cube
{
public:
	int speed;
	int score = 0;
public:
	Player(Game* game, int x, int y, int width, int height, int speed);

	void Update() override;
	void Render() override;
};


#endif
