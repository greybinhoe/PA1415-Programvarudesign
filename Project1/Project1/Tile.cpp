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
		//this->contain = new Wall("Wall", "This is a wall made of rock.");
	}
}

Tile::Tile()
{
	this->randomItemGenerator();
}

Tile::Tile(bool containsWall)
{
	if (containsWall == true)
	{
		this->contain = new Wall("Wall", "This is a wall made of rock.");
	}
	else
	{
		this->contain = new Air("Air", "This is not oxygen");
		//this->randomItemGenerator();
	}
}

Tile::~Tile()
{
	//delete this->contain;
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