#include "Weapon.h"

Weapon::Weapon(std::string name, std::string description, char visual)
	:Item(name, description, visual = '/')
{
	this->damage = 0;
}

Weapon::~Weapon()
{
	//
}

int Weapon::getDamage() const
{
	return this->damage;
}

void Weapon::setDamage(const int damage)
{
	this->damage = damage;
}