#ifndef WORLD_HPP
#define WORLD_HPP
#include "../Controller/Input.hpp"
#include "Player.hpp"
#include "GameObjectList.hpp"
#include "../Controller/IController.hpp"
class World
{
	private:
	int _level;
	int _time;
	int _score;
	int _timeTillEnemy;
	Player _player;
	GameObjectList _gameObjects;
	GameObjectList _newObjects;

	World();

	public:
	World(int level);
	World(const World & src);
	~World();
	void add(AGameObjects *);
	IController *update(const Input &);
	void render() const;

	World & operator=(const World & src);
};

#endif
