/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameObjects.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:24:48 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 15:01:31 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAMEOBJECTS_HPP
#define AGAMEOBJECTS_HPP
#include <iostream>
#include <string.h>
class AGameObjects
{
	protected:
		int speed;
		float x;
		float y;
		int is_moove;
		int sizeX;
		int sizeY;
		int hp;
	public:
		AGameObjects(int speed, int x, int y);
		virtual void	update() = 0;
		virtual void	move(std::string) = 0;
		virtual void	attack() = 0;
		virtual void	takeDamage() = 0;
				bool	collide(const AGameObjects &obj) const;
		virtual void	draw(int x, int y) const = 0;
						~AGameObjects();
};
#endif
