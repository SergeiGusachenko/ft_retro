/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rocket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <dezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:02:43 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 22:55:59 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Rocket.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

Rocket::Rocket(float speed, int x, int y) : AGameObjects(speed, x, y, 2, 1, 1)
{}

Rocket::~Rocket() {}

void Rocket::draw() const
{
	if (this->speed < 0)
	{
		attron(COLOR_PAIR(4));
		mvaddstr(this->y, this->x, "**");
		attroff(COLOR_PAIR(4));
	}
	else
	{
		attron(COLOR_PAIR(5));
		mvaddstr(this->y, this->x, "**");
		attroff(COLOR_PAIR(5));
	}
}

void Rocket::takeDamage()
{
	this->hp = 0;
}

void Rocket::move(std::string asd){asd = " ";}

void Rocket::attack(){}


void Rocket::update(World *world)
{
	this->y += this->speed;
	int screenWidth, screenHeight;
	getmaxyx(stdscr, screenHeight, screenWidth);
	if (this->y < 0 || this->y > screenHeight)
		this->hp = 0;
}

void Rocket::interact_init(AGameObjects *obj)
{
	obj->interact(this);
}

void Rocket::interact(Player *player)
{
	if (this->speed > 0)
		player->takeDamage();
}

void Rocket::interact(Enemy *enemy)
{
	if (this->speed < 0)
		enemy->takeDamage();
}

void Rocket::interact(Rocket *r)
{
	if (
			(this->speed < 0 && r->speed > 0) ||
			(this->speed > 0 && r->speed < 0)
	)
	{
		this->takeDamage();
		r->takeDamage();
	}
}

void Rocket::interact(Asteroid *a) {}

Rocket::Rocket(const Rocket & src) : AGameObjects(src.x, src.y, src.speed, src.sizeX, src.sizeY, src.hp) {}

Rocket & Rocket::operator=(const Rocket & src)
{
	AGameObjects::operator=(src);
	return *this;
}
