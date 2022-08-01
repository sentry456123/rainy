#include "Game.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <random>
#include "Consts.h"


Game::Game(const char* title) : title(title) {}

void Game::Start()
{
	if (!Init()) return;

	Uint32 stop, start;
	start = SDL_GetTicks();
	while (running)
	{
		HandleEvents();
		Update();
		Render();

		stop = SDL_GetTicks();
		if (stop - start < 1000 / GAME_FPS)
		{
			SDL_Delay(1000 / GAME_FPS - (stop - start));
		}
		start = SDL_GetTicks();
	}

	Clean();
}

bool Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "Error: " << SDL_GetError() << std::endl;
		return false;
	}
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
	{
		std::cout << "Error: " << SDL_GetError() << std::endl;
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		std::cout << "Error: " << SDL_GetError() << std::endl;
		return false;
	}
	if (TTF_Init())
	{
		std::cout << "Error: " << TTF_GetError() << std::endl;
		return false;
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "Error: " << IMG_GetError() << std::endl;
		return false;
	}
	sounds.Init();

	srand(time(nullptr));

	scn_titleMenu = new TitleMenuScene(this);
	scn_field = new FieldScene(this);
	scn_retryMenu = new RetryMenuScene(this);

	scene = Scene::TITLE_MENU;
	scn_titleMenu->Enter();

	sounds.PlaySF(Sounds::SF_Type::OPENING);

	return true;
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	kbd.pressed = {};
	kbd.released = {};
	mouse.pressed = {};
	mouse.released = {};
	switch (event.type)
	{
	case SDL_QUIT:
		running = false;
		break;
	case SDL_KEYDOWN:
		kbd.pressed = event.key.keysym.sym;
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			running = false;
			break;
		}
		break;
	case SDL_KEYUP:
		kbd.released = event.key.keysym.sym;
		break;
	case SDL_MOUSEBUTTONDOWN:
		mouse.pressed = event.button.button;
		break;
	case SDL_MOUSEBUTTONUP:
		mouse.released = event.button.button;
		break;
	}
}

void Game::Update()
{
	switch (scene)
	{
	case Scene::TITLE_MENU:
		scn_titleMenu->Update();
		break;
	case Scene::FIELD:
		scn_field->Update();
		break;
	case Scene::RETRY_MENU:
		scn_retryMenu->Update();
		break;
	}
}

void Game::Render()
{
	canvas.SetColor(COLOR_BLACK /* Background color */);
	canvas.Clear();
	switch (scene)
	{
	case Scene::TITLE_MENU:
		scn_titleMenu->Render();
		break;
	case Scene::FIELD:
		scn_field->Render();
		break;
	case Scene::RETRY_MENU:
		scn_retryMenu->Render();
		break;
	}

	canvas.Present();
}

void Game::Clean()
{
	delete scn_titleMenu;
	delete scn_field;
	delete scn_retryMenu;

	sounds.Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

