#ifndef TILE_H
#define TILE_H

#include <time.h>
//#include "map.h"
#include "Weapon.h"
#include "Air.h"
#include "Wall.h"

class Tile
{
private:
	Item * contain;
	char visual;
	void randomItemGenerator();

public:
	Tile();
	Tile(bool containsWall);
	virtual ~Tile();

	Item * takeItem();
	bool checkPos()const;
	char getVisual()const;
	//tostring som returnerar visual
};
#endif // !TILE_H
