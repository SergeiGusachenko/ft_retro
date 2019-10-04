#include "GameObjectList.hpp"
#include "AGameObjects.hpp"

GameObjectList::GameObjectList()
{
	this->_objects = NULL;
	this->_numObjects = 0;
}

GameObjectList::GameObjectList(const GameObjectList & src)
{
	this->_numObjects = src._numObjects;
	this->_objects = new AGameObjects * [this->_numObjects];
	for (int i = 0; i < this->_numObjects; i++)
		this->_objects[i] = src._objects[i];
	// TODO deep copy
}

GameObjectList::~GameObjectList()
{
	for (int i = 0; i < this->_numObjects; i++)
		delete this->_objects[i];
	delete [] this->_objects;
}

void GameObjectList::add(AGameObjects *obj)
{
	if (obj == NULL)
		return;
	AGameObjects **oldObjects = this->_objects;
	this->_objects = new AGameObjects * [this->_numObjects + 1];
	for (int i = 0; i < this->_numObjects; i++)
		this->_objects[i] = oldObjects[i];
	delete oldObjects;
	this->_objects[this->_numObjects] = obj;
	this->_numObjects++;
}

void GameObjectList::dump(GameObjectList & dst)
{
	for (int i = 0; i < this->_numObjects; i++)
		dst.add(this->_objects[i]);
	this->_numObjects = 0;
	delete this->_objects;
	this->_objects = NULL;
}

int	GameObjectList::getSize() const
{
	return this->_numObjects;
}

AGameObjects *GameObjectList::get(int index) const
{
	if (index < 0 || index >= this->_numObjects)
		return (NULL);
	return this->_objects[index];
}

void GameObjectList::remove(int index)
{
	if (index < 0 || index >= this->_numObjects)
		return;
	delete this->_objects[index];
	for (int i = index; i < this->_numObjects - 1; i++)
		this->_objects[i] = this->_objects[i + 1];
	this->_numObjects--;
}

void GameObjectList::cleanDead()
{
	int i = 0;
	int deleted = 0;
	while (i < this->_numObjects)
	{
		if (this->_objects[i]->isDead())
		{
			delete this->_objects[i];
			deleted++;
		}
		else
			this->_objects[i - deleted] = this->_objects[i];
		i++;
	}
	this->_numObjects -= deleted;
}

GameObjectList & GameObjectList::operator=(const GameObjectList & src)
{
	this->_numObjects = src._numObjects;
	this->_objects = new AGameObjects * [this->_numObjects];
	for (int i = 0; i < this->_numObjects; i++)
		this->_objects[i] = src._objects[i];
	// TODO deep copy
	return *this;
}
