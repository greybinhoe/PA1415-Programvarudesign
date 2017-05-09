#ifndef TILE_H
#define TILE_H
#include <time.h>

//#include "map.h"
#include "item.h"
#include "Weapon.h"

class Tile
{
private:
	Item contain;
	char visual;
public:
	Tile();
	Tile(Item contain, char visual);
	//Tile(const Tile &origObj);
	virtual ~Tile();
	//void operator=(const Tile &origObj);

	Item& takeItem();
	bool checkPos()const;
};
#endif // !TILE_H
