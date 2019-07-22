#include <ncurses.h>
#include <iostream>

#include "GameController.hpp"
#include "MainMenu.hpp"
#include "Input.hpp"

GameController::GameController() : _world(0) {}

GameController::GameController(int level) : _world(level) {}

GameController::GameController(const GameController & src) : _world(src._world) {}
GameController::~GameController() {}

IController * GameController::update(const Input & input)
{
	this->_world.update(input);
	return NULL;
}

void GameController::render() const
{
	this->_world.render();
}

GameController & GameController::operator=(const GameController & src)
{
	this->_world = src._world;
	return *this;
}
