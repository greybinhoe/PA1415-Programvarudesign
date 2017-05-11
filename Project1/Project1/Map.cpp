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
	//Delete tiles
	for (int i = 0; i < this->sizeX; i++)
	{
		for (int j = 0; j < this->sizeY; j++)
		{
			//delete this->tileMap[i];
		}
		//delete this->tileMap;
	}
}

Item& Map::pickUpItem(Point point)
{
	//Return the adress of the item on "point"
	return *this->tileMap[sizeX][sizeY].takeItem();
}

bool Map::checkPos(Point point)
{
	//If the tile "point" is empty, return true
	return (this->tileMap[sizeX][sizeY].checkPos());
}

/*string Map::toString() const
{
	string mapVisual = "";

	//Get Visual for every tile
	for (int i = 0; i < this->sizeY; i++)
	{
		for (int j = 0; j < this->sizeX; j++)
		{
			mapVisual += this->tileMap[j][i].getVisual();
		}
		mapVisual += "\n";
	}
	return mapVisual;
}*/

void Map::rowToCharArray(char * charArray, int row)
{
	for (int j = 0; j < this->sizeX; j++)
	{
		charArray[j] = this->tileMap[j][row].getVisual();
		//charArray[j + 1] = '\0';
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
