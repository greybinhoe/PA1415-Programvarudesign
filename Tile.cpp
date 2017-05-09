#include "Tile.h"

void Tile::randomItemGenerator()
{
	srand(time(NULL));
	unsigned int randomValue = rand() % 100 + 1;
	if (randomValue <= 5)
	{
		this->contain = Weapon("Name: Unknown", "Description: Unknown", '/');
	}
	else
	{
		this->contain = Air("Air", "This is air");
	}
}

Tile::Tile()
{
	
}

Tile::Tile(bool containsWall)
{

	if (containsWall == true)
	{
		this->contain = Wall("Wall","This is a wall made of rock.");
	}
	else
	{
		this->randomItemGenerator();
	}
}



Tile::~Tile()
{

}

Item & Tile::takeItem()
{
	return this->contain; //WHATHTEHFUCK
}

bool Tile::checkPos() const
{
	bool check = false;

	if (!this->contain.getName == "Wall")
	{
		check = true;
	}

	return check;
}

char Tile::getVisual() const
{
	return this->contain.getVisual();
}
