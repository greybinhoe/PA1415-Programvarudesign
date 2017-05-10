#include "Tile.h"

void Tile::randomItemGenerator()
{
	srand((int)time(NULL));
	unsigned int randomValue = rand() % 100 + 1;
	if (randomValue <= 5)
	{
		this->contain = new Weapon("Name: Unknown", "Description: Unknown", '/');
	}
	else
	{
		this->contain = new Air("Air", "This is air");
	}
}

Tile::Tile()
{
}

Tile::Tile(bool containsWall)
{
	if (containsWall == true)
	{
		this->contain = new Wall("Wall", "This is a wall made of rock.");
	}
	else
	{
		this->randomItemGenerator();
	}
}

Tile::~Tile()
{
}

Item * Tile::takeItem()
{
	return this->contain;
}

bool Tile::checkPos() const
{
	bool check = false;

	if (this->contain->getName() != "Wall")
	{
		check = true;
	}

	return check;
}

char Tile::getVisual() const
{
	return this->contain->getVisual();
}