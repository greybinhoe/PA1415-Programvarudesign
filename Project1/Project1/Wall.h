#ifndef WALL_H
#define WALL_H

#include "Item.h"

class Wall : public Item
{
private:
public:
	Wall(std::string name, std::string description, char visual = '#');
	virtual ~Wall();
};

#endif // !WALL_H
