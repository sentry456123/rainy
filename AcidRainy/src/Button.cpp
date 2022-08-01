#include "Button.h"
#include "Game.h"



Button::Button(Game* game, int x, int y, int width, int height, const char* text, ButtonMode mode) :
	Cube(game, x, y, width, height), text(text), mode(mode)
{

}

void Button::Update()
{
	pushed = false;
	if (targeted && game->mouse.IsReleasedNow(1) && IsTriggered(this, game->mouse.GetX(), game->mouse.GetY()))
	{
		pushed = true;
		game->sounds.PlaySF(Sounds::SF_Type::BUTTON_PUSHED);
	}
	targeted = false;
	if (IsTriggered(this, game->mouse.GetX(), game->mouse.GetY()))
	{
		if (game->mouse.IsPressed(1))
			targeted = true;
		if(touchedTime != -1)
			touchedTime++;
	}
	else touchedTime = 0;
	if (touchedTime == 1)
		game->sounds.PlaySF(Sounds::SF_Type::BUTTON_TOUCHED);
}

void Button::Render()
{
	game->canvas.SetColor(COLOR_WHITE);
	game->canvas.DrawRect(x, y, width, height);
	if (IsTriggered(this, game->mouse.GetX(), game->mouse.GetY()))
	{
		if (targeted)
			game->canvas.SetColor(COLOR_GRAY);
		else
		{
			if (touchedTime < 10)
				game->canvas.SetColor(Color(touchedTime * 4, touchedTime * 4, touchedTime * 4));
			else game->canvas.SetColor(Color(40, 40, 40));
		}
	}
	else game->canvas.SetColor(COLOR_BLACK);
	game->canvas.FillRect(x + 1, y + 1, width - 2, height - 2);
	{
		if (mode & BUTTON_UPPER_CASE)
			game->canvas.DrawText(FONT_PLAIN, text, x + width / 2, y + height / 2, height, COLOR_WHITE, TextPosMode::CENTER);
		else game->canvas.DrawText(FONT_PLAIN, text, x + width / 2, y + height / 2, height * 2 / 3, COLOR_WHITE, TextPosMode::CENTER);
	}
}

bool Button::IsPushed()
{
	return pushed;
}