/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameObjects.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <dezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:24:48 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 22:55:16 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAMEOBJECTS_HPP
#define AGAMEOBJECTS_HPP
#include <iostream>
#include <string.h>

class World;
class Player;
class Enemy;
class Rocket;
class Asteroid;

class AGameObjects
{
	protected:
		float speed;
		float x;
		float y;
//		int is_moove;
		float sizeX;
		float sizeY;
		int hp;
	public:
		AGameObjects(float speed, int x, int y, int sizeX, int sizeY, int hp);
		virtual void	update(World *) = 0;
		virtual void	takeDamage() = 0;
		virtual void	draw() const = 0;
				bool	collide(const AGameObjects * obj) const;
		virtual void	interact_init(AGameObjects *obj) = 0;
		virtual void	interact(Player *obj) = 0;
		virtual void	interact(Enemy *obj) = 0;
		virtual void	interact(Rocket *obj) = 0;
		virtual void	interact(Asteroid *obj) = 0;
		virtual			~AGameObjects();
				bool	isDead();

		AGameObjects & operator=(const AGameObjects & src);
};

#endif
