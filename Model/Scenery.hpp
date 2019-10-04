/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenery.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:52:47 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/21 22:53:24 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENERY_HPP
#define SCENERY_HPP
#include "AGameObjects.hpp"

class Scenery: public AGameObjects
{
	private:
		int _width;
		int _height;
		int _tick;
		char **_display;
		char *			newRow();
		Scenery();
	public:
		Scenery(int width, int height);
		Scenery(const Scenery &);
		virtual void	update(World *);
		virtual void	takeDamage();
		void			draw() const;
		void			interact_init(AGameObjects *obj);
		void			interact(Player *);
		void			interact(Enemy *);
		void			interact(Rocket *);
		void			interact(Asteroid *);
		~Scenery();

		Scenery & operator=(const Scenery & src);
};
#endif
