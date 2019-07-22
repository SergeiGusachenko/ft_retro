#ifndef GAMEOVER_H
# define GAMEOVER_H

# include "IController.hpp"
# include "Input.hpp"

class GameOver : public IController
{
	private:
	int _option;
	int _offsetX, _offsetY;
	int _spectrum;
	void mvaddstr_relative(int y, int x, const std::string & str) const;

	public:
	GameOver();
	GameOver(const GameOver & src);
	~GameOver();
	IController * update(const Input &);
	void render() const;

	GameOver & operator=(const GameOver & src);
};

#endif
