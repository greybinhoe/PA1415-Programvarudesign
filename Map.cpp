#include "Map.h"

Map::Map() : size(100, 100)
{
	//Generate tiles
	for (int i = 0; i <= this->size.x; i++)
	{
		for (int j = 0; j <= this->size.y; j++)
		{
			//If the tile is a wall tile
			if(i == 0 || j == 0 || i == 100 || j == 100)
				this->tileMap[i][j] = new Tile(true);
			//If the tile is a floor tile
			else
				this->tileMap[i][j] = new Tile(false);
		}
	}
}

Map::~Map()
{
	//Delete tiles
	for (int i = 0; i <= this->size.x; i++)
	{
		for (int j = 0; j <= this->size.y; j++)
		{
			delete this->tileMap[i][j];
		}
	}
}

Item& Map::pickUpItem(Point point)
{
	//Return the adress of the item on "point"
	return this->tileMap[point.x][point.y].takeItem();
}

bool Map::checkPos(Point point)
{
	//If the tile "point" is empty, return true
	return (this->tileMap[point.x][point.y].checkPos());
}

string Map::toString() const
{
	string mapVisual = "";

	//Get Visual for every tile
	for (int i = 0; i <= this->size.x; i++)
	{
		for (int j = 0; j <= this->size.y; j++)
		{
			mapVisual += this->tileMap[i][j].toString();
		}
		mapVisual += "\n";
	}
	return mapVisual;
}
