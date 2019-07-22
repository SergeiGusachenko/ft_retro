#ifndef MAINMENU_H
# define MAINMENU_H

# include "IController.hpp"
# include "Input.hpp"

class MainMenu : public IController
{
	private:
	int _option;
	int _offsetX, _offsetY;
	void mvaddstr_relative(int y, int x, const std::string & str) const;

	public:
	MainMenu();
	MainMenu(const MainMenu & src);
	~MainMenu();
	IController * update(const Input &);
	void render() const;

	MainMenu & operator=(const MainMenu & src);
};

#endif
