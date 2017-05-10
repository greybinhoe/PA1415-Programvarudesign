#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include "Tile.h"
#include "Item.h"
#include <string>

class Map
{
private:
	Tile ** tileMap;
	Point size;

public:
	Map();
	~Map();

	Item& pickUpItem(Point point);
	bool checkPos(Point point);

	string toString();
};

#endif