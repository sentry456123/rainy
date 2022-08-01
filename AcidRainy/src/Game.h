#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "Player.h"
#include "Enemy.h"
#include "Canvas.h"
#include "Scene.h"
#include "TitleMenuScene.h"
#include "RetryMenuScene.h"
#include "FieldScene.h"

#include <vector>
#include "Sounds.h"
#include "Keyboard.h"
#include "Mouse.h"



class Game
{
public:
	const char* title;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
private:
	bool running = true;
public:
	Canvas canvas = {&renderer};
	Sounds sounds = {};
public:
	Game(const char* title);

	void Start();

	bool Init();
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
public:
	enum class Scene
	{
		TITLE_MENU,
		FIELD,
		RETRY_MENU,
	} scene;
public:
	TitleMenuScene* scn_titleMenu;
	FieldScene* scn_field;
	RetryMenuScene* scn_retryMenu;

	int scoreResult;

public:
	Keyboard kbd;
	Mouse mouse;
};


#endif
