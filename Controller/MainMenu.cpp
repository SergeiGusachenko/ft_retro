#include <ncurses.h>
#include <iostream>

#include "MainMenu.hpp"
#include "Input.hpp"
#include "GameController.hpp"

# define MAINMENU_WIDTH 64
# define MAINMENU_HEIGHT 20

MainMenu::MainMenu() : _option(0)
{
	int screenWidth, screenHeight;
	getmaxyx(stdscr, screenHeight, screenWidth);
	this->_offsetX = (screenWidth - MAINMENU_WIDTH) / 2;
	if (this->_offsetX < 0) this->_offsetX = 0;
	this->_offsetY = (screenHeight - MAINMENU_HEIGHT) / 2;
	if (this->_offsetY < 0) this->_offsetY = 0;
}

MainMenu::MainMenu(const MainMenu & src) : _option(src._option) {}
MainMenu::~MainMenu() {}

IController * MainMenu::update(const Input & input)
{
	if (input.keyPressed(KEY_DOWN) && this->_option < 3)
		this->_option++;
	if (input.keyPressed(KEY_UP) && this->_option > 0)
		this->_option--;
	if (input.keyPressed(10)) // 10-ENTER
		return new GameController(this->_option);
	return NULL;
}

void MainMenu::mvaddstr_relative(int y, int x, const std::string & str) const
{
	mvaddstr(this->_offsetY + y, this->_offsetX + x, str.c_str());
}

void MainMenu::render() const
{
	for (int i = 1; i < MAINMENU_WIDTH; i++)
	{
		mvaddch(this->_offsetY, this->_offsetX + i, '-');
		mvaddch(this->_offsetY + MAINMENU_HEIGHT - 1, this->_offsetX + i, '-');
	}
	for (int i = 1; i < MAINMENU_HEIGHT; i++)
	{
		mvaddch(this->_offsetY + i, this->_offsetX, '|');
		mvaddch(this->_offsetY + i, this->_offsetX + MAINMENU_WIDTH - 1, '|');
	}
	mvaddch(this->_offsetY, this->_offsetX, '+');
	mvaddch(this->_offsetY, this->_offsetX + MAINMENU_WIDTH - 1, '+');
	mvaddch(this->_offsetY + MAINMENU_HEIGHT - 1, this->_offsetX, '+');
	mvaddch(this->_offsetY + MAINMENU_HEIGHT - 1, this->_offsetX + MAINMENU_WIDTH - 1, '+');
	mvaddstr_relative(2, 20, "####  ####  ## ##  ####");
	mvaddstr_relative(3, 20, "#     #  #  # # #  #");
	mvaddstr_relative(4, 20, "# ##  ####  # # #  ####");
	mvaddstr_relative(5, 20, "#  #  #  #  #   #  #");
	mvaddstr_relative(6, 20, "####  #  #  #   #  ####");
	mvaddstr_relative(8, 22, "NEW GAME");
	mvaddstr_relative(10, 22, "CONTINUE FROM LEVEL 1");
	mvaddstr_relative(12, 22, "CONTINUE FROM LEVEL 2");
	mvaddstr_relative(14, 22, "CONTINUE FROM LEVEL 3");
	mvaddstr_relative(17, 4, "nwhitlow                dezzeddi                sgusache");
	mvaddstr_relative(8 + this->_option * 2, 19, ">");
}

MainMenu & MainMenu::operator=(const MainMenu & src)
{
	this->_option = src._option;
	return *this;
}
