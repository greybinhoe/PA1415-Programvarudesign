#ifndef SCREEN_H
#define SCREEN_H

#include "include\curses.h"

class Screen
{
private:
	int height, width;
public:
	Screen();
	~Screen();

	void add(const char * message);

	int getHeight() const;
	int getWidth() const;

};

#endif
