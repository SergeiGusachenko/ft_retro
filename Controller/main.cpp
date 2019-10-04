#include <iostream>
#include <ncurses.h>
#include <random>
#include <time.h>
#include "Input.hpp"
#include "FrameClock.hpp"
#include "IController.hpp"
#include "MainMenu.hpp"

void displayFPS(float fps)
{
	move(0, 0);
	mvprintw(0, 0, "%.2f", fps);
}

void gameLoop()
{
	Input input;
	FrameClock clock;
	IController * controller = new MainMenu;
	IController * newController;
	for(;;)
	{
		int key = getch();
		if (key != ERR)
			input.takeInput(key);
		if (clock.tick())
		{
			if (input.keyDown(27)) // 27 - ESC
				break;
			newController = controller->update(input);
			if (newController != NULL)
			{
				delete controller;
				controller = newController;
			}
			input.nextFrame();
			erase();	// Clears the window for redrawing
			controller->render();
			move(0, 0);	// Put the cursor in the top left corner
//			displayFPS(clock.getRealFPS());
			refresh();	// Prints the window to screen
		}
	}
}

// TODO Add some defines to make these easier to remember
void init_colors()
{
	start_color();	// Get ncurses ready to use color
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_RED, COLOR_MAGENTA);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_RED);
}

int main()
{
	initscr();				// Initialize the ncurses
	cbreak();				// Read keypresses immediately, instead of waiting for newline
	noecho();				// Suppress echoing of typed characters
	nodelay(stdscr, true);	// Do not stall while waiting for key presses
	keypad(stdscr, true);	// Allows capturing of arrow keys
	init_colors();			// Define a set of standard colors for us to use
	refresh();				// Clear the window
	// TODO xset keyboard delay
	srand(time(0));
	gameLoop();
	endwin();				// Close ncurses
}
