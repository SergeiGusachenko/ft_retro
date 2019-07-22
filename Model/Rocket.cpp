/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rocket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:02:43 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 16:31:57 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Rocket.hpp"

Rocket::Rocket(int speed, int x, int y) : AGameObjects(speed, x + 3, y - 4)
{}

Rocket::~Rocket()
{}

void Rocket::draw(int x, int y) const
{
	if((int)this->y % 4 == 1 || this->speed != 2)
		mvaddstr(this->y, this->x, "**");
}

void Rocket::takeDamage(){}

void Rocket::move(std::string asd){asd = " ";}

void Rocket::attack(){}


void Rocket::update()
{
	if(this->speed == 2)
	{
		this->y += this->speed;
	}
	else
	{
		this->y -= this->speed;
	}
}
