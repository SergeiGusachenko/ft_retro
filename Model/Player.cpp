/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <dezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:30:47 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 22:52:39 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Rocket.hpp"
#include <ncurses.h>

void	Player::update(World *world)
{
}

void	Player::move(std::string dirrection)
{
	float new_x = this->x;
	float new_y = this->y;
	if (dirrection == "right")
		new_x += 1.7;
	if (dirrection == "left")
		new_x -= 1.7;
	if (dirrection == "up")
		new_y += 0.7;
	if (dirrection == "down")
		new_y -= 0.7;
	this->x = new_x;
	this->y = new_y;
}

void		Player::attack(World *world)
{
	world->add(new Rocket(-0.9, this->x + 3, this->y));
}

Player::Player() : AGameObjects(0, 0, 0, 0, 0, 0)
{
}

Player::Player(int x, int y): AGameObjects(1, x, y, 7, 4, 1)
{
	draw(x, y);
	this->x = x;
	this->y = y;
}

void Player::takeDamage()
{
	this->hp -= 30;
}
Player::~Player()
{

}

void Player::draw(int x, int y) const
{
	attron(COLOR_PAIR(4));
	mvaddstr(y, x, "   /\\");
	mvaddstr(y + 1, x, "  (  )");
	mvaddstr(y+ 2, x, "  (  )");
	mvaddstr(y+ 3, x, " /|/\\|\\");
	mvaddstr(y + 4, x, "/_||||_\\");
	attroff(COLOR_PAIR(4));
}

void Player::draw() const
{
	this->draw(this->x, this->y);
}

void Player::interact_init(AGameObjects *obj)
{
	obj->interact(this);
}

void Player::interact(Player *p) {}
void Player::interact(Enemy *e) {}
void Player::interact(Rocket *r) {}
void Player::interact(Asteroid *a) {}

Player::Player(const Player & src) : AGameObjects(src.x, src.y, src.speed, src.sizeX, src.sizeY, src.hp)
{
	this->rocket_speed = src.rocket_speed;
}

Player & Player::operator=(const Player & src)
{
	AGameObjects::operator=(src);
	this->rocket_speed = src.rocket_speed;
	return *this;
}
