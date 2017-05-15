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
	bool checkPos();
	char getVisual()const;
	std::string getDescription() const;
	std::string getName() const;
};
#endif // !TILE_H
