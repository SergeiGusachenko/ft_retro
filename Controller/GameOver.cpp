#include <ncurses.h>
#include <iostream>

#include "GameOver.hpp"
#include "MainMenu.hpp"
#include "Input.hpp"

# define GAMEOVER_WIDTH 64
# define GAMEOVER_HEIGHT 13
# define ENTER_KEY 10

GameOver::GameOver() : _option(0), _spectrum(0)
{
	int screenWidth, screenHeight;
	getmaxyx(stdscr, screenHeight, screenWidth);
	this->_offsetX = (screenWidth - GAMEOVER_WIDTH) / 2;
	if (this->_offsetX < 0) this->_offsetX = 0;
	this->_offsetY = (screenHeight - GAMEOVER_HEIGHT) / 2;
	if (this->_offsetY < 0) this->_offsetY = 0;
}

GameOver::GameOver(const GameOver & src) : _option(src._option), _spectrum(src._spectrum) {}
GameOver::~GameOver() {}

IController * GameOver::update(const Input & input)
{
	this->_spectrum++;
	if (this->_spectrum == 140)
		this->_spectrum = 0;
	if (input.keyPressed(ENTER_KEY))
		return new MainMenu;
	return NULL;
}

static const char * g_gameOver[] = {
	"####  ####  ## ##  ####   ####  #  #  ####  ### ",
	"#     #  #  # # #  #      #  #  #  #  #     #  #",
	"# ##  ####  # # #  ####   #  #  #  #  ####  ### ",
	"#  #  #  #  #   #  #      #  #  #  #  #     #  #",
	"####  #  #  #   #  ####   ####   ##   ####  #  #",
};

void GameOver::render() const
{
	attron(COLOR_PAIR(1));
	for (int i = 1; i < GAMEOVER_WIDTH; i++)
	{
		mvaddch(this->_offsetY, this->_offsetX + i, '-');
		mvaddch(this->_offsetY + GAMEOVER_HEIGHT - 1, this->_offsetX + i, '-');
	}
	for (int i = 1; i < GAMEOVER_HEIGHT; i++)
	{
		mvaddch(this->_offsetY + i, this->_offsetX, '|');
		mvaddch(this->_offsetY + i, this->_offsetX + GAMEOVER_WIDTH - 1, '|');
	}
	mvaddch(this->_offsetY, this->_offsetX, '+');
	mvaddch(this->_offsetY, this->_offsetX + GAMEOVER_WIDTH - 1, '+');
	mvaddch(this->_offsetY + GAMEOVER_HEIGHT - 1, this->_offsetX, '+');
	mvaddch(this->_offsetY + GAMEOVER_HEIGHT - 1, this->_offsetX + GAMEOVER_WIDTH - 1, '+');
	attroff(COLOR_PAIR(1));
	int color;
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 48; x++)
		{
			if (g_gameOver[y][x] != ' ')
			{
				if (((x + 1) * (y + 1)) % 7 == this->_spectrum / 20)
					color = 3;
				else
					color = 2;
				attron(COLOR_PAIR(color));
			}
			mvaddch(this->_offsetY + 2 + y, this->_offsetX + 8 + x, g_gameOver[y][x]);
			if (g_gameOver[y][x] != ' ')
				attroff(COLOR_PAIR(color));
		}
	mvaddstr(this->_offsetY + 8, this->_offsetX + 19, "WE PRESENT YOU A NEW QUEST");
	mvaddstr(this->_offsetY + 10, this->_offsetX + 27, "PRESS ENTER");
}

GameOver & GameOver::operator=(const GameOver & src)
{
	this->_option = src._option;
	this->_spectrum = src._spectrum;
	return *this;
}
