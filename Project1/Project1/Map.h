#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include "Tile.h"
#include "Item.h"
#include <string>

class Map
{
private:
	Tile tileMap[120][25];
	int sizeX = 120;
	int sizeY = 25;

public:
	Map();
	~Map();

	Item& pickUpItem(int y, int x);
	bool checkPos(int y, int x);

	void rowToCharArray(char * charArray, int row);
	int getRows() const;
	int getCols() const;
	std::string getItemDesc(int y, int x) const;
	std::string getItemName(int y, int x) const;
};

#endif