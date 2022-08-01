#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(Game* game, int x, int y, int width, int height, int speed, Direction direction) :
	Cube(game, x, y, width, height), speed(speed), direction(direction)
{}

void Enemy::Update()
{
	switch (direction)
	{
	case Direction::DOWN:
		y += speed;
		break;
	case Direction::LEFT:
		x -= speed;
		break;
	}
	if (IsTriggered(this, game->scn_field->player))
	{
		game->scn_field->Quit();
		game->scn_retryMenu->Enter();
		return;
	}
}

void Enemy::Render()
{
	game->canvas.SetColor(COLOR_GREEN);
	game->canvas.FillRect(x, y, width, height);
	game->canvas.SetColor(COLOR_WHITE);
	game->canvas.DrawRect(x, y, width, height);
}