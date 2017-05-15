#include "Tile.h"

void Tile::randomItemGenerator()
{
	unsigned int randomValue = rand() % 1000 + 1;
	if (randomValue <= 5)
	{
		this->contain = new Weapon("Sword", "This is a sword crafted by the dwarves of BTH", '/');
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
		//this->contain = new Air("Air", "This is not oxygen");
		this->randomItemGenerator();
	}
}

Tile::~Tile()
{
	//delete this->contain;
}

Item * Tile::takeItem()
{
	Item * returnValue = this->contain;
	this->contain = new Air("Air", "This is air");
	return returnValue;
}

bool Tile::checkPos()
{
	bool check = false;

	if (this->contain->getWalkable())
	{
		check = true;
	}

	return check;
}

char Tile::getVisual() const
{
	return this->contain->getVisual();
}

std::string Tile::getDescription() const
{
	return this->contain->getDescription();
}

std::string Tile::getName() const
{
	return this->contain->getName();
}
