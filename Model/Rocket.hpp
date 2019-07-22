#ifndef ROCKET_HPP
#define ROCKET_HPP
#include <ncurses.h>
#include "AGameObjects.hpp"
class Rocket: public AGameObjects
{
private:
public:
	void	update();
	void	draw(int x, int y) const;
			Rocket();
			Rocket(int speed, int x, int y);
			~Rocket();
	void	takeDamage();
	void	attack();
	void	move(std::string);
};

#endif
