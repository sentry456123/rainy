#ifndef TITLE_H
#define TITLE_H

#include "Button.h"
#include "Scene.h"


class TitleMenuScene : public Scene
{
private:
	Button* bt_tit_play;
	Button* bt_tit_instructions;
	Button* bt_ins_back;
public:
	using Scene::Scene;

	void Update() override;
	void Render() override;
	void Enter() override;
	void Quit() override;

public:
	enum class Menu
	{
		TITLE,
		INSTRUCTIONS,
	} menu;
};


#endif
