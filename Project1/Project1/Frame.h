#ifndef FRAME_H
#define FRAME_H

#include "include\curses.h"
#include "include\panel.h"
#include "Character.h"

class Frame
{
private:
	int height, width;
	int row, col;

	bool hasSuper;
	WINDOW * win;
	WINDOW * super;

public:
	Frame(int nrOfRows, int nrOfCols, int row, int col);
	Frame(Frame &swin, int nrOfRows, int nrOfCols, int row, int col);
	~Frame();

	WINDOW * getWindow();
	WINDOW * getSuper();

	bool checkSuper();
	int getHeight();
	int getWidth();
	int getRow();
	int getCol();

	void refresh();
	void move(int row, int col);
	void add(Character &x);
	void erase(Character &x);
	void add(Character &x, int row, int col);
	void center(Character &x);

};
#endif // !FRAME_H
