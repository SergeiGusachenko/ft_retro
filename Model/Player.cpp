/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:30:47 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 15:10:47 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Rocket.hpp"
#include <ncurses.h>

void	Player::update()
{
	for (int i = 0; i < current_ammo; i++)
	{
		ammo[i]->update();
	}
}

void	Player::move(std::string dirrection)
{
	int new_x = this->x;
	int new_y = this->y;
	if (dirrection == "right")
		new_x++;
	if (dirrection == "left")
		new_x--;
	if (dirrection == "up")
		new_y++;
	if (dirrection == "down")
		new_y--;
	this->x = new_x;
	this->y = new_y;
}

void		Player::attack()
{
	ammo[current_ammo] = new Rocket(1, this->x, this->y + 4);
	current_ammo++;
}

Player::Player(int speed, int x, int y): AGameObjects(speed, x, y)
{
	draw(x, y);
	this->x = x;
	this->y = y;
	this->current_ammo = 0;
	this->sizeX = 7;
	this->sizeY = 4;
}

void Player::takeDamage()
{

}
Player::~Player()
{

}

void Player::draw(int x, int y) const
{
	mvaddstr(y, x, "   /\\");
	mvaddstr(y + 1, x, "  (  )");
	mvaddstr(y+ 2, x, "  (  )");
	mvaddstr(y+ 3, x, " /|/\\|\\");
	mvaddstr(y + 4, x, "/_||||_\\");
	for (int i = 0; i < current_ammo; i++)
		ammo[i]->draw(0, 0);
}

void Player::draw() const
{
	this->draw(this->x, this->y);
}
