#include <ncurses.h>
#include <iostream>
#include "World.hpp"
#include "../Controller/Input.hpp"
// This constructor should never be called.
World::World() : _enemy(0, 0, 0), _enemy1(0, 0, 0), _player(0, 0, 0) {}

World::World(int level) : _level(level), _enemy(level,1,1), _enemy1(level + 1,1,1), _player(1, 20, 20) {}

World::World(const World & src) : _level(src._level), _enemy(src._enemy), _enemy1(src._enemy1), _player(src._player) {}
World::~World() {}

void World::update(const Input & input)
{
	if (input.keyDown(KEY_LEFT)) // 37 - left arrow
		this->_player.move("left");
	if (input.keyDown(KEY_DOWN)) // 38 - up arrow
		this->_player.move("up");
	if (input.keyDown(KEY_RIGHT)) // 39 - right arrow
		this->_player.move("right");
	if (input.keyDown(KEY_UP)) // 40 - down arrow
		this->_player.move("down");
	if (input.keyPressed(' '))
		this->_player.attack();
	this->_enemy1.update();
	this->_enemy.update();
	this->_player.update();
}

void World::render() const
{
	Player new_player = Player(1, 30, 30);
	this->_player.draw();
	this->_enemy.draw();
	this->_enemy1.draw();
	if (this->_player.collide(new_player))
		mvaddstr(20, 20, "COLLIDES");
}

World & World::operator=(const World & src)
{
	this->_level = src._level;
	return *this;
}
