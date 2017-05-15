#include "Frame.h"

Frame::Frame(int nrOfRows, int nrOfCols, int row, int col)
{
	this->hasSuper = FALSE;
	this->super = NULL;
	this->win = newwin(nrOfRows, nrOfCols, row, col);
	this->height = nrOfRows;
	this->width = nrOfCols;
	this->row = row;
	this->col = col;
}

Frame::Frame(Frame & swin, int nrOfRows, int nrOfCols, int row, int col)
{
	this->hasSuper = TRUE;
	this->super = swin.getWindow();
	this->win = derwin(swin.getWindow(), nrOfRows, nrOfCols, row, col);
	this->height = nrOfRows;
	this->width = nrOfCols;
	this->row = row;
	this->col = col;
}

Frame::~Frame()
{
	delwin(this->win);
}

WINDOW * Frame::getWindow()
{
	return this->win;
}

WINDOW * Frame::getSuper()
{
	return this->super;
}

bool Frame::checkSuper()
{
	return this->hasSuper;
}

int Frame::getHeight()
{
	return this->height;
}

int Frame::getWidth()
{
	return this->width;
}

int Frame::getRow()
{
	return this->row;
}

int Frame::getCol()
{
	return this->col;
}

void Frame::refresh()
{
	if (this->hasSuper)
	{
		touchwin(this->super);
	}
	wrefresh(this->win);
}

void Frame::move(int row, int col)
{
	if (this->hasSuper)
	{
		mvderwin(this->win, row, col);
		this->row = row;
		this->col = col;
		this->refresh();
	}
}

void Frame::add(Character & x)
{
	mvwaddch(this->win, x.getRow(), x.getCol(), x.getVisual());
}

void Frame::erase(Character & x)
{
	mvwaddch(this->win, x.getRow(), x.getCol(), ' ');
}

void Frame::add(Character & x, int row, int col)
{
	if ((this->row >= 0 && this->row < this->height) && (this->col >= 0 && this->col < this->width))
	{
		this->erase(x);
		mvwaddch(this->win, this->row, this->col, x.getVisual());
		x.setPos(this->row, this->col);
	}
}

void Frame::center(Character & x)
{
	if (this->hasSuper)
	{
		int rr = this->row, cc = this->col, hh, ww;
		int xRow = x.getRow() - this->height / 2;
		int xCol = x.getCol() - this->width / 2;

		getmaxyx(this->super, hh, ww);

		if (xCol + this->width >= ww)
		{
			int delta = ww - (xCol + this->width);
			cc = xCol + delta;
		}
		else
		{
			cc = xCol;
		}

		if (xRow + this->height>= hh)
		{
			int delta = hh - (xRow + this->height);
			rr = xRow + delta;
		}
		else
		{
			rr = xRow;
		}

		if (xRow < 0)
		{
			xRow = 0;
		}
		if (xCol < 0)
		{
			xCol = 0;
		}

		this->move(rr, cc);
	}
}
