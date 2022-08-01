#ifndef ENTITIES_H
#define ENTITIES_H

class Game;

class Scene
{
protected:
	Game* game;
public:
	Scene(Game*);

	virtual void Update() abstract;
	virtual void Render() abstract;
	virtual void Enter() abstract;
	virtual void Quit() abstract;
};


#endif
