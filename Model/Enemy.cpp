/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <dezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:28:08 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 22:54:56 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "Rocket.hpp"
#include "Asteroid.hpp"
#include "World.hpp"
Enemy::Enemy(int speed, int x, int y):AGameObjects(speed,x,y,7,3,1)
{
	int screenWidth, screenHeight;
	getmaxyx(stdscr, screenHeight, screenWidth);
	this->x = (rand() % (screenWidth - 40) + 40) ;
	this->y = 0;
}

void Enemy::interact_init(AGameObjects *obj)
{
	obj->interact(this);
}

void Enemy::interact(Player *player)
{
	player->takeDamage();
	this->hp = 0;
}

void Enemy::interact(Enemy *e) {}
void Enemy::interact(Rocket *r) {}
void Enemy::interact(Asteroid *a) {}

# define ENEMYSTEP 0.3

void	Enemy::update(World *world)
{
	this->render_counter++;
	int random = rand() % 9;
	int screenWidth, screenHeight;
	getmaxyx(stdscr, screenHeight, screenWidth);
	if(this->y > screenHeight + this->speed)
		this->y = 0;
	if(this->x > screenWidth + this->speed)
	{
		this->x = random % screenWidth;
		this->y = 0;
	}
	if(this->y < 0)
		this->y = 0;
	if(this->x < 0)
		this->x = this->speed;
	if(random % 9 == 1)
	{
		this->y += ENEMYSTEP;
		this->x += 1;
		this->attack(world);
	}
	if(random % 9 == 2){
		this->y += ENEMYSTEP;
		this->x += 1;
		this->attack(world);
	}
	if(random % 9 == 3){
		this->y += ENEMYSTEP;
		this->x += 1;
	}
	if(random % 9 == 4){
		this->y += ENEMYSTEP;
		this->x -= 1;
	}
	if(random % 9 == 5){
		this->y += ENEMYSTEP;
		this->x -= 1;
	}
	if(random % 9 == 6)
		this->x -= 1;
	if(random % 9 == 7){
		this->x -= 1;
	}
	if(random % 9 == 8){
		this->y += ENEMYSTEP;
		this->x += 1;
		this->attack(world);
	}
}

void	Enemy::attack(World *world)
{
	if (rand() % 10 == 0)
		world->add(new Rocket(0.4, this->x,  this->y + 5));
}

void	Enemy::draw() const
{
	attron(COLOR_PAIR(5));
	mvaddstr(this->y, this->x,"  \\ | / ");
	mvaddstr(this->y + 1, this->x," (o_o_o)");
	mvaddstr(this->y + 2, this->x,"  -\\_/- ");
	attroff(COLOR_PAIR(5));
}

void	Enemy::takeDamage()
{
	this->hp--;
}

Enemy::~Enemy()
{

}

Enemy::Enemy(const Enemy & src) : AGameObjects(src.x, src.y, src.speed, src.sizeX, src.sizeY, src.hp)
{
	this->render_counter = src.render_counter;
}

Enemy & Enemy::operator=(const Enemy & src)
{
	AGameObjects::operator=(src);
	this->render_counter = src.render_counter;
	return *this;
}
