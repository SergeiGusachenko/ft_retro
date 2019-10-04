#ifndef GAMEOBJECTLIST
# define GAMEOBJECTLIST

#include "AGameObjects.hpp"

class GameObjectList
{
	private:
	int _numObjects;
	AGameObjects **_objects;

	public:
	GameObjectList();
	GameObjectList(const GameObjectList & src);
	~GameObjectList();
	void add(AGameObjects *);
	void dump(GameObjectList & dst);
	int	getSize() const;
	AGameObjects *get(int index) const;
	void remove(int index);
	void cleanDead();

	GameObjectList & operator=(const GameObjectList & src);
};

#endif
