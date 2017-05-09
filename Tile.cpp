#include "Tile.h"


Tile::Tile()
{
	srand(time(NULL));
	unsigned int randomValue = rand() % 100 + 1;
	if (randomValue <= 5)
	{
		this->contain = Weapon("Name: Unknown", "Description: Unknown", '/');
	}
	else
	{
		this->visual = '.';
	}
}

Tile::Tile(Item contain, char visual)
{
	this->contain = contain;
	this->visual = visual;
}

//Tile::Tile(const Tile & origObj)
//{
//	this->visual = origObj.visual;
//}

Tile::~Tile()
{

}

//void Tile::operator=(const Tile & origObj)
//{
//}



Item & Tile::takeItem()
{
	return *Item; //WHATHTEHFUCK
	this->visual = '.';
}

bool Tile::checkPos() const
{
	bool check = false;

	if()

	return check;
}
