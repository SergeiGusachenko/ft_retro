/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dezzeddi <dezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:30:51 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/21 22:55:40 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
#include "AGameObjects.hpp"
#include <ncurses.h>
#include "Rocket.hpp"

class World;

class Player: public AGameObjects
{
	private:
		float	rocket_speed;
	public:
				Player();
				Player(int x, int y);
				Player(const Player & src);
		void	update(World *);
		void	move(std::string direction);
		void	attack(World *);
		void	takeDamage();
		void	draw() const;
		void	draw(int x, int y) const;
		void	interact_init(AGameObjects *obj);
		void	interact(Player *);
		void	interact(Enemy *);
		void	interact(Rocket *);
		void	interact(Asteroid *);
				~Player();

				Player & operator=(const Player & src);
};
#include "World.hpp"

#endif
