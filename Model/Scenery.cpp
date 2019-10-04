/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenery.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:56:02 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/21 22:53:09 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "Scenery.hpp"
#include "World.hpp"

Scenery::Scenery() : AGameObjects(0,0,0,0,0,1) {}

Scenery::Scenery(int width, int height):AGameObjects(0,0,0,0,0,1)
{
	this->_width = width;
	this->_height = height;
	this->_display = new char * [height + 1];
	for (int y = 0; y < height + 1; y++)
		this->_display[y] = newRow();
	this->_display[20][40] = '*';
	this->_tick = 0;
}

char *Scenery::newRow()
{
	char *row = new char[this->_width];
	for (int x = 0; x < this->_width; x++)
	{
		if (rand() % 84 == 0)
			row[x] = '*';
		else
			row[x] = ' ';
	}
	return row;
}

void Scenery::update(World *world)
{
	this->_tick++;
	if (this->_tick == 10)
	{
		delete this->_display[this->_height];
		for (int y = this->_height; y > 0; y--)
			this->_display[y] = this->_display[y - 1];
		this->_display[0] = newRow();
		this->_tick = 0;
	}
}

void Scenery::draw() const
{
	for (int y = 0; y < this->_height; y++)
		for (int x = 0; x < this->_width; x++)
			mvaddch(y, x, this->_display[y + 1][x]);
}

void Scenery::takeDamage() {}
void Scenery::interact_init(AGameObjects *obj) {}
void Scenery::interact(Player *player) {}
void Scenery::interact(Enemy *e) {}
void Scenery::interact(Rocket *r) {}
void Scenery::interact(Asteroid *a) {}

Scenery::~Scenery()
{
	for (int y = 0; y < this->_height + 1; y++)
		delete this->_display[y];
	delete this->_display;
}

Scenery::Scenery(const Scenery & src) : AGameObjects(0,0,0,0,0,1)
{
	this->_width = src._width;
	this->_height = src._height;
	this->_display = new char * [this->_height + 1];
	for (int y = 0; y < this->_height + 1; y++)
	{
		this->_display[y] = new char[this->_width];
		for (int x = 0; x < this->_width; x++)
			this->_display[y][x] = src._display[y][x];
	}
	this->_tick = src._tick;
}

Scenery & Scenery::operator=(const Scenery & src)
{
	this->_width = src._width;
	this->_height = src._height;
	this->_display = new char * [this->_height + 1];
	for (int y = 0; y < this->_height + 1; y++)
	{
		this->_display[y] = new char[this->_width];
		for (int x = 0; x < this->_width; x++)
			this->_display[y][x] = src._display[y][x];
	}
	this->_tick = src._tick;
	return *this;
}
