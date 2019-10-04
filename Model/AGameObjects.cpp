/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameObjects.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <dezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:35:33 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 22:15:31 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AGameObjects.hpp"

AGameObjects::AGameObjects(float speed, int x, int y, int sizeX, int sizeY, int hp)
{
	this->speed = speed;
	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->hp = hp;
}

AGameObjects::~AGameObjects()
{}

bool AGameObjects::collide(const AGameObjects * obj) const
{
	int botLeftX = obj->x;
	int botLeftY = obj->y + obj->sizeY;
	int topRightX = obj->x + obj->sizeX;
	int topRightY = obj->y;

	if		(  ( this->x >  topRightX  ) ||\
			(  (this->x + this->sizeX)  <  botLeftX)||\
			(  this->y > botLeftY ) ||\
			(  this->y + this->sizeY  <  topRightY  ) )
				return (0);
	return (1);
}

void AGameObjects::interact(Player *obj) {}
void AGameObjects::interact(Enemy *obj) {}
void AGameObjects::interact(Rocket *obj) {}

bool AGameObjects::isDead()
{
	return this->hp <= 0;
}

AGameObjects & AGameObjects::operator=(const AGameObjects & src)
{
	this->speed = src.speed;
	this->x = src.x;
	this->y = src.y;
	this->sizeX = src.sizeX;
	this->sizeY = src.sizeY;
	this->hp = src.hp;
	return *this;
}
