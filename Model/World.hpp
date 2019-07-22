#ifndef WORLD_HPP
#define WORLD_HPP
#include "AGameObjects.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "../Controller/Input.hpp"

class World
{
	private:
	int _level;
	// TODO Generalize or add to copy/assignemnt
	Player _player;
	Enemy _enemy;
	Enemy _enemy1;

	World();

	public:
	World(int level);
	World(const World & src);
	~World();
	void update(const Input &);
	void render() const;

	World & operator=(const World & src);
};

#endif
