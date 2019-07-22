/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:28:08 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 16:42:32 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "Rocket.hpp"
Enemy::Enemy(int speed, int x, int y):AGameObjects(speed,x,y)
{
	int screenWidth, screenHeight;
	this->current_ammo = 0;
	getmaxyx(stdscr, screenHeight, screenWidth);
	this->x = (rand() % (screenWidth - 40) + 40) ;
	this->y = 0;
}

void	Enemy::update()
{

	this->render_counter++;
	for (int i = 0; i < current_ammo; i++)
	{
		if(this->render_counter % (5 - this->speed - 1) == 0)
			ammo[i]->update();
	}
	if(current_ammo == 99)
	{
		for (int i = 0; i < 99 ; i ++)
				delete ammo[i];
		current_ammo = 0;
	}
	if (this->render_counter % (6 - this->speed) == 0)
	{
		this->move("fake");
	}
}

void	Enemy::draw(int x, int y) const
{
	this->draw();
}

void	Enemy::draw() const
{
	mvaddstr(this->y, this->x,"  \\ | / ");
	mvaddstr(this->y + 1, this->x," (o_o_o)");
	mvaddstr(this->y + 2, this->x,"  -\\_/- ");
	for (int i = 0; i < current_ammo; i++)
		ammo[i]->draw(1,1);
}


void	Enemy::move(std::string fake)
{
	fake = " ";
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
	if(this->y < 0 && this->speed % 2 == 1)
		this->y = 0;
	if(this->x < 0)
		this->x = this->speed;
	if(random % 9 == 1)
	{
		this->y += 1;
		this->x += 1;
		this->attack();
	}
	if(random % 9 == 2){
		this->y += 1;
		this->x += 1;
		this->attack();
	}
	if(random % 9 == 3){
		this->y += 1;
		this->x += 1;
	}
	if(random % 9 == 4){
		this->y += 1;
		this->x -= 1;
	}
	if(random % 9 == 5){
		this->y += 1;
		this->x -= 1;
	}
	if(random % 9 == 6)
		this->x -= 1;
	if(random % 9 == 7){
		this->x -= 1;
	}
	if(random % 9 == 8){
		this->y += 1;
		this->x += 1;
		this->attack();
	}
}

void	Enemy::attack()
{
	this->ammo[current_ammo] = new Rocket(2, this->x,  this->y + 5);
	current_ammo++;
}

void	Enemy::takeDamage()
{

}

Enemy::~Enemy()
{

}
