#ifndef GAMECONTROLLER_H
# define GAMECONTROLLER_H

# include "IController.hpp"
# include "Input.hpp"
#include "../Model/World.hpp"

class GameController : public IController
{
	private:
	World _world;

	GameController();

	public:
	GameController(int level);
	GameController(const GameController & src);
	~GameController();
	IController * update(const Input &);
	void render() const;

	GameController & operator=(const GameController & src);
};

#endif
