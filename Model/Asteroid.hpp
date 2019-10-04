/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:40:42 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/21 22:58:01 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
#define ASTEROID_HPP
#include "AGameObjects.hpp"
#include "Player.hpp"

class Asteroid: public AGameObjects
{
	private:
	public:
		Asteroid();
		Asteroid(const Asteroid & src);
		virtual void	update(World *);
		virtual void	takeDamage();
		void			draw() const;
		void			interact_init(AGameObjects *obj);
		void			interact(Player *);
		void			interact(Enemy *);
		void			interact(Rocket *);
		void			interact(Asteroid *);
		~Asteroid();

		Asteroid & operator=(const Asteroid & src);
};
#endif
