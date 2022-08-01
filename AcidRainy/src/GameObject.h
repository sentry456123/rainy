#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H


class Game;

class GameObject
{
protected:
	Game* game;
public:
	GameObject(Game* game);

	virtual void Update() abstract;
	virtual void Render() abstract;
};


#endif
