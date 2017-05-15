#include "Screen.h"

Screen::Screen()
{
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	//Screen dimensions
	getmaxyx(stdscr, this->height, this->width);
}

Screen::~Screen()
{
	endwin();
}

void Screen::add(const char * message)
{
	printw(message);
}	

int Screen::getHeight() const
{
	return this->height;
}

int Screen::getWidth() const
{
	return this->width;
}
