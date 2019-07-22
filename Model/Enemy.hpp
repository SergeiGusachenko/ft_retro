/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:08:49 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 16:39:08 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "AGameObjects.hpp"
#include "Rocket.hpp"

class Enemy: public AGameObjects
{
	private:
		int x;
		int y;
		int	current_ammo;
		Rocket	*ammo[110];
		int	moove_difference_x;
		int	moove_difference_y;
		int render_counter;
	public:
		Enemy(int speed, int x, int y);
		virtual void	update();
		virtual void	move(std::string);
		virtual void	attack();
		virtual void	takeDamage();
		virtual void	draw(int, int) const;
		void			draw() const;
		~Enemy();
};
#endif
