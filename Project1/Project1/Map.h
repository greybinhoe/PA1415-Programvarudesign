#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include "Tile.h"
#include "Item.h"
#include <string>

class Map
{
private:
	Tile tileMap[30][20];
	int sizeX = 30;
	int sizeY = 20;

public:
	Map();
	~Map();

	Item& pickUpItem(Point point);
	bool checkPos(Point point);

	//string toString() const;
	void rowToCharArray(char * charArray, int row);
	int getRows() const;
	int getCols() const;
};

#endif