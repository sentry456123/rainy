#ifndef FIELD_H
#define FIELD_H

#include "Scene.h"
#include "Consts.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class FieldScene : public Scene
{
private:
	int interval;
	int direction;
public:
	using Scene::Scene;
public:
	Player* player;
	std::vector<Enemy> enemies;
public:
	void Update() override;
	void Render() override;
	void Enter() override;
	void Quit() override;
};


#endif
