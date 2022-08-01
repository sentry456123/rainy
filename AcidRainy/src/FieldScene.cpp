#include "FieldScene.h"
#include <sstream>
#include "Game.h"

void FieldScene::Update()
{
	player->Update();
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies.at(i).Update();
		if (enemies.at(i).x < 0 && enemies.at(i).direction == Enemy::Direction::LEFT || enemies.at(i).y > GAME_WINDOW_HEIGHT && enemies.at(i).direction == Enemy::Direction::DOWN)
		{
			enemies.erase(enemies.begin() + i);
			i--;
			player->score++;
		}
	}
	if (interval >= 600 / GAME_FPS)
	{
		switch (direction % 2)
		{
		case 0:
			enemies.push_back(Enemy(game, rand()%(GAME_WINDOW_WIDTH - 50), -50, 50, 50, 8, Enemy::Direction::DOWN));
			break;
		case 1:
			enemies.push_back(Enemy(game, GAME_WINDOW_WIDTH, rand() % (GAME_WINDOW_HEIGHT - 50), 50, 50, 8, Enemy::Direction::LEFT));
			break;
		}
		direction++;
		interval = 0;
	}
	else interval++;
}

void FieldScene::Render()
{
	player->Render();
	for (int i = 0; i < enemies.size(); i++)
		enemies.at(i).Render();
	std::ostringstream oss;
	oss << "Score: " << player->score;
	game->canvas.DrawText(FONT_PLAIN, oss.str().c_str(), GAME_WINDOW_WIDTH - 10, GAME_WINDOW_HEIGHT - 10, 50, COLOR_WHITE, TextPosMode::BOTTOM_RIGHT);
}

void FieldScene::Enter()
{
	game->sounds.StopSF();
	game->sounds.PlaySF(Sounds::SF_Type::BUTTON_PUSHED);
	game->sounds.PlayBGM();
	player = new Player(game, GAME_WINDOW_WIDTH / 2 - 25, GAME_WINDOW_HEIGHT - 100, 50, 100, 5);
	enemies = {};
	game->scene = Game::Scene::FIELD;
}

void FieldScene::Quit()
{
	game->scoreResult = player->score;
	delete player;
	game->sounds.StopBGM();
}
