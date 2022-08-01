#include "TitleMenuScene.h"
#include "Game.h"
#include "Consts.h"

void TitleMenuScene::Update()
{
	switch (menu)
	{
	case Menu::TITLE:
		bt_tit_play->Update();
		bt_tit_instructions->Update();
		if (bt_tit_play->IsPushed())
		{
			Quit();
			game->scn_field->Enter();
			return;
		}
		if (bt_tit_instructions->IsPushed())
		{
			menu = Menu::INSTRUCTIONS;
			return;
		}
		break;
	case Menu::INSTRUCTIONS:
		bt_ins_back->Update();
		if (bt_ins_back->IsPushed())
		{
			menu = Menu::TITLE;
			return;
		}
		break;
	}

}

void TitleMenuScene::Render()
{
	switch (menu)
	{
	case Menu::TITLE:
		game->canvas.DrawText(FONT_PLAIN, game->title, GAME_WINDOW_WIDTH / 2, GAME_WINDOW_HEIGHT / 2 - 25, 100, COLOR_WHITE, TextPosMode::BOTTOM_MIDDLE);
		bt_tit_play->Render();
		bt_tit_instructions->Render();
		break;
	case Menu::INSTRUCTIONS:
		game->canvas.DrawText(FONT_PLAIN, "INSTRUCTIONS", GAME_WINDOW_WIDTH / 2, 10, 100, COLOR_WHITE, TextPosMode::TOP_MIDDLE);
		game->canvas.DrawText(FONT_PLAIN, "W, A, S or D to move", GAME_WINDOW_WIDTH / 2, 200, 50, COLOR_WHITE, TextPosMode::TOP_MIDDLE);
		game->canvas.DrawText(FONT_PLAIN, "SPACE to rotate", GAME_WINDOW_WIDTH / 2, 300, 50, COLOR_WHITE, TextPosMode::TOP_MIDDLE);
		bt_ins_back->Render();
		break;
	}
	
}

void TitleMenuScene::Enter()
{
	bt_tit_play = new Button(game, GAME_WINDOW_WIDTH / 2 - 150, GAME_WINDOW_HEIGHT / 2 + 100, 300, 30, "PLAY", BUTTON_UPPER_CASE);
	bt_tit_instructions = new Button(game, GAME_WINDOW_WIDTH / 2 - 150, GAME_WINDOW_HEIGHT / 2 + 130, 300, 30, "INSTRUCTIONS", BUTTON_UPPER_CASE);

	bt_ins_back = new Button(game, GAME_WINDOW_WIDTH - 110, GAME_WINDOW_HEIGHT - 40, 100, 30, "BACK", BUTTON_UPPER_CASE);

	game->scene = Game::Scene::TITLE_MENU;
}

void TitleMenuScene::Quit()
{
	delete bt_tit_play;
	delete bt_tit_instructions;
	delete bt_ins_back;
}
