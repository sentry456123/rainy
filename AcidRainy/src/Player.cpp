#include "Player.h"
#include "Game.h"
#include "Sounds.h"

Player::Player(Game* game, int x, int y, int width, int height, int speed) :
	Cube(game, x, y, width, height), speed(speed)
{}

void Player::Update()
{
	if (game->kbd.IsPressed(SDL_SCANCODE_W) && y >= 0)                      y -= speed;
	if (game->kbd.IsPressed(SDL_SCANCODE_S) && y + height <= GAME_WINDOW_HEIGHT) y += speed;
	if (game->kbd.IsPressed(SDL_SCANCODE_A) && x >= 0)                      x -= speed;
	if (game->kbd.IsPressed(SDL_SCANCODE_D) && x + width <= GAME_WINDOW_WIDTH)   x += speed;
	if (game->kbd.IsPressedNow(SDLK_SPACE))
	{
		bool slim = height > width;
		if (slim)
		{
			x -= width / 2;
			y += width / 2;
		} 
		else
		{
			x += height / 2;
			y -= height / 2;
		}
		int temp;
		temp = width;
		width = height;
		height = temp;

		game->sounds.PlaySF(Sounds::SF_Type::ROTATE);
	}
}

void Player::Render()
{
	game->canvas.SetColor(COLOR_RED);
	game->canvas.FillRect(x, y, width, height);
	game->canvas.SetColor(COLOR_WHITE);
	game->canvas.DrawRect(x, y, width, height);
}
