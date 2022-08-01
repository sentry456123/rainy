#ifndef RETRY_MENU_H
#define RETRY_MENU_H


#include "Scene.h"
#include "Button.h"

class RetryMenuScene : public Scene
{
private:
	Button* bt_backToTitle;
public:
	using Scene::Scene;
public:
	void Update() override;
	void Render() override;
	void Enter() override;
	void Quit() override;
};


#endif
