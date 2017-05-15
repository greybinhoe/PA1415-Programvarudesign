#include "Map.h"

Map::Map()
{
	//Generate tiles
	for (int i = 0; i < this->sizeX; i++)
	{
		for (int j = 0; j < this->sizeY; j++)
		{
			//If the tile is a wall tile
			if (i == 0 || j == 0 || i == this->sizeX-1 || j == this->sizeY-1)
			{
				this->tileMap[i][j] = Tile(true);
			}
			//If the tile is a floor tile
			else
			{
				this->tileMap[i][j] = Tile(false);
			}
		}
	}
}

Map::~Map()
{
}

Item & Map::pickUpItem(int y, int x)
{
	return *this->tileMap[x][y].takeItem();
}

bool Map::checkPos(int y, int x)
{
	return (this->tileMap[x][y].checkPos());
}

void Map::rowToCharArray(char * charArray, int row)
{
	for (int j = 0; j < this->sizeX; j++)
	{
		charArray[j] = this->tileMap[j][row].getVisual();
	}
}

int Map::getRows() const
{
	return this->sizeY;
}

int Map::getCols() const
{
	return this->sizeX;
}

std::string Map::getItemDesc(int y, int x) const
{
	return this->tileMap[x][y].getDescription();
}

std::string Map::getItemName(int y, int x) const
{
	return this->tileMap[x][y].getName();
}
