/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:42:04 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/21 23:07:08 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "Enemy.hpp"
#include "Player.hpp"
#include "World.hpp"

Asteroid::Asteroid() : AGameObjects(0,0,-200,11,5,1000)
{
	int screenWidth, screenHeight;
	getmaxyx(stdscr, screenHeight, screenWidth);
	this->x = rand() % (screenWidth - (int) this->sizeX + 1);
}

void Asteroid::interact_init(AGameObjects *obj)
{
	obj->interact(this);
}

void Asteroid::interact(Player *player)
{
	player->takeDamage();
}

void Asteroid::interact(Enemy *enemy)
{
	enemy->takeDamage();
}

void Asteroid::interact(Rocket *rocket)
{
	rocket->takeDamage();
}

void Asteroid::interact(Asteroid *a) {}

void	Asteroid::update(World *world)
{
	int screenWidth, screenHeight;
	getmaxyx(stdscr, screenHeight, screenWidth);
	this->y += 2.0;
	if (this->y > screenHeight)
		this->hp = 0;
}

void	Asteroid::draw() const
{
	if (this->y < 0 - this->sizeY)
	{
		attron(COLOR_PAIR(6));
		mvaddstr(1, this->x, "!!!!!!!!!!!");
		attroff(COLOR_PAIR(6));
	}
	else
	{
		attron(COLOR_PAIR(1));
		mvaddstr(this->y, this->x,    "   ###:##, ");
		mvaddstr(this->y + 1, this->x," ##%## ]###");
		mvaddstr(this->y + 2, this->x,"$##%#*###: ");
		mvaddstr(this->y + 3, this->x,"##X##%##*##");
		mvaddstr(this->y + 4, this->x," ###'#*##' ");
		attroff(COLOR_PAIR(1));
	}
}

void	Asteroid::takeDamage() {}
Asteroid::~Asteroid() {}

Asteroid::Asteroid(const Asteroid & src) : AGameObjects(src.x, src.y, src.speed, src.sizeX, src.sizeY, src.hp) {}

Asteroid & Asteroid::operator=(const Asteroid & src)
{
	AGameObjects::operator=(src);
	return *this;
}
