#ifndef AIR_H
#define AIR_H

#include "Item.h"

class Air : public Item
{
private:
public:
	Air(std::string name, std::string description, char visual = '.');
	virtual ~Air();
};

#endif // !AIR_H
