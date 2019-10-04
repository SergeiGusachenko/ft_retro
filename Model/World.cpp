#include <ncurses.h>
#include <iostream>
#include "World.hpp"
#include "../Controller/IController.hpp"
#include "../Controller/Input.hpp"
#include "../Controller/GameOver.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Asteroid.hpp"
#include "Scenery.hpp"

// This constructor should never be called.
World::World() : _player(0, 0) {}

World::World(int level) : _player(20, 20)
{
	int screenWidth, screenHeight;
	getmaxyx(stdscr, screenHeight, screenWidth);
	this->_level = level;
	this->_time = 0;
	this->_score = 0;
	this->_timeTillEnemy = 0;
	this->add(new Scenery(screenWidth, screenHeight));
}

World::World(const World & src)
{
	this->_level = src._level;
	this->_player = src._player;
	this->_score = src._score;
	this->_gameObjects = src._gameObjects;
	this->_newObjects = src._newObjects;
}

World::~World() {}

void World::add(AGameObjects *obj)
{
	this->_newObjects.add(obj);
}

IController *World::update(const Input & input)
{
	// Spawn enemies
	if (this->_timeTillEnemy <= 0)
	{
		if (rand() % 10 == 0)
			this->add(new Asteroid());
		else
			this->add(new Enemy(2, 1, 1));
		this->_timeTillEnemy = 420.0 + rand() % 200 - this->_level * 150;
		this->_score += 100;
	}
	this->_timeTillEnemy--;

	// Add objects that were created on the previous frame
	this->_newObjects.dump(this->_gameObjects);

	// Update
	if (input.keyDown(KEY_LEFT)) // 37 - left arrow
		this->_player.move("left");
	if (input.keyDown(KEY_DOWN)) // 38 - up arrow
		this->_player.move("up");
	if (input.keyDown(KEY_RIGHT)) // 39 - right arrow
		this->_player.move("right");
	if (input.keyDown(KEY_UP)) // 40 - down arrow
		this->_player.move("down");
	if (input.keyPressed(' '))
		this->_player.attack(this);
	this->_player.update(this);
	for (int i = 0; i < this->_gameObjects.getSize(); i++)
		this->_gameObjects.get(i)->update(this);

	// Collisions => Interact
	AGameObjects *a, *b;
	for (int i = 0; i < this->_gameObjects.getSize(); i++)
	{
		a = this->_gameObjects.get(i);
		for (int j = i + 1; j < this->_gameObjects.getSize(); j++)
		{
			b = this->_gameObjects.get(j);
			if (a->collide(b))
			{
				a->interact_init(b);
				b->interact_init(a);
			}
		}
		if (this->_player.collide(a))
		{
			a->interact(&(this->_player));
			this->_player.interact_init(a);
		}
	}

	// Clean up dead objects
	this->_gameObjects.cleanDead();

	// HUD
	this->_time++;

	// Return
	if (this->_player.isDead())
		return (new GameOver(this->_score + (this->_time / 42) * 10 * (this->_level + 1)));
	return (NULL);
}

void World::render() const
{
	for (int i = 0; i < this->_gameObjects.getSize(); i++)
		this->_gameObjects.get(i)->draw();
	this->_player.draw();
	for (int i = 0; i < 5; i++)
		mvaddstr(i, 0, "                |");
	mvaddstr(5, 0, "----------------+");
	mvprintw(1, 1, "Level: %d", this->_level);
	mvprintw(2, 1, "Time: %d:%.2d:%.2d", this->_time / 3600, (this->_time / 60) % 60, this->_time % 60);
	int realScore = this->_score + (this->_time / 42) * 10 * (this->_level + 1);
	if (realScore > 999999)
		realScore = 999999;
	mvprintw(3, 1, "Score: %.6d", this->_score + (this->_time / 42) * 10 * (this->_level + 1));
}

World & World::operator=(const World & src)
{
	this->_level = src._level;
	this->_player = src._player;
	this->_score = src._score;
	this->_gameObjects = src._gameObjects;
	this->_newObjects = src._newObjects;
	return *this;
}
