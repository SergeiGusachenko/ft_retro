#ifndef ROCKET_HPP
#define ROCKET_HPP
#include <ncurses.h>
#include "AGameObjects.hpp"

class World;

class Rocket: public AGameObjects
{
private:
public:
	void	update(World *);
	void	draw() const;
			Rocket();
			Rocket(const Rocket & src);
			Rocket(float speed, int x, int y);
			~Rocket();
	void	takeDamage();
	void	attack();
	void	move(std::string);
	int		getEdge();
	void	interact_init(AGameObjects *obj);
	void	interact(Player *);
	void	interact(Enemy *);
	void	interact(Rocket *);
	void	interact(Asteroid *);

	Rocket & operator=(const Rocket & src);
};

#endif
