#include "RetryMenuScene.h"
#include <sstream>
#include "Game.h"

void RetryMenuScene::Update()
{
	bt_backToTitle->Update();
	if (game->kbd.IsPressedNow(SDLK_r))
	{
		Quit();
		game->scn_field->Enter();
		return;
	}
	if (bt_backToTitle->IsPushed())
	{
		Quit();
		game->scn_titleMenu->Enter();
		return;
	}
}

void RetryMenuScene::Render()
{
	game->canvas.DrawText(FONT_PLAIN, "You died.", GAME_WINDOW_WIDTH / 2, GAME_WINDOW_HEIGHT / 2 - 150, 100, COLOR_WHITE, TextPosMode::CENTER);
	std::ostringstream scoreStr;
	scoreStr << "Score: " << game->scoreResult;
	game->canvas.DrawText(FONT_PLAIN, scoreStr.str().c_str(), GAME_WINDOW_WIDTH / 2, GAME_WINDOW_HEIGHT / 2, 50, COLOR_WHITE, TextPosMode::CENTER);
	game->canvas.DrawText(FONT_PLAIN, "Press R to retry.", GAME_WINDOW_WIDTH / 2, GAME_WINDOW_HEIGHT / 2 + 100, 50, COLOR_WHITE, TextPosMode::CENTER);
	bt_backToTitle->Render();
}

void RetryMenuScene::Enter()
{
	bt_backToTitle = new Button(game, GAME_WINDOW_WIDTH - 260, GAME_WINDOW_HEIGHT - 40, 250, 30, "BACK TO TITLE", BUTTON_UPPER_CASE);
	game->sounds.StopSF();
	game->sounds.PlaySF(Sounds::SF_Type::RETRY_MENU);
	game->scene = Game::Scene::RETRY_MENU;
}

void RetryMenuScene::Quit()
{
	delete bt_backToTitle;
}

