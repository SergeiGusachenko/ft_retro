/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:30:51 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 14:16:40 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
#include "AGameObjects.hpp"
#include <ncurses.h>
#include "Rocket.hpp"

class Player: public AGameObjects
{
	private:
		int		rocket_speed;
		Rocket	*ammo[1000];
		int		current_ammo;
	public:
				Player();
				Player(int speed, int x, int y);
		void	update();
		void	move(std::string direction);
		void	attack();
		void	takeDamage();
		void	draw() const;
		void	draw(int x, int y) const;
				~Player();
};

#endif
