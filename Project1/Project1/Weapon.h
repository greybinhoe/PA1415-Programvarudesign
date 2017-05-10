#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item //Subklass
{
private:
	int damage;
	//name
	//description
	//fr�n basklassen.

public:
	Weapon(std::string name, std::string description, char visual = '/');
	~Weapon();

	int getDamage()const;
	void setDamage(const int damage);
};
#endif // !WEAPON_H