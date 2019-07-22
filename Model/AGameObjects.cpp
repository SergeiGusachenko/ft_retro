/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameObjects.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <dezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:35:33 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 14:41:09 by dezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AGameObjects.hpp"

AGameObjects::AGameObjects(int speed, int x, int y)
{
	this->speed = speed;
	this->x = x;
	this->y = y;
}

AGameObjects::~AGameObjects()
{}

bool AGameObjects::collide(const AGameObjects & obj) const
{
	int botLeftX = obj.x;
	int botLeftY = obj.y + sizeY;
	int topRightX = obj.x + sizeX;
	int topRightY = obj.y;

	if		(  ( this->x >  topRightX  ) ||\
			(  (this->x + sizeX)  <  botLeftX)||\
			(  this->y > botLeftY ) ||\
			(  this->y + sizeY  <  topRightY  ) )
				return (0);
	return (1);
}
