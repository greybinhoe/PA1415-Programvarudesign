#include "Character.h"

Character::Character()
{
	this->col = 10;
	this->row = 10;
	this->name = "";
	this->strength = 0;
	this->agility = 0;
	this->intelligence = 0;
	this->vitality = 0;
	this->health = this->vitality * 2 + this->strength / 2 + 1;
	this->currentHealth = this->health;
}
Character::Character(int posX, int posY, std::string name, int strenght, int agility, int intelligence, int vitality)
{
	this->col = posX;
	this->row = posY;
	this->name = name;
	this->strength = strength;
	this->agility = agility;
	this->intelligence = intelligence;
	this->vitality = vitality;
	this->health = this->vitality * 2 + this->strength / 2 + 1;
	this->currentHealth = this->health;
}

int Character::getCol()
{
	return this->col;
}
int Character::getRow()
{
	return this->row;
}
char Character::getVisual()
{
	return this->visual;
}
std::string Character::getName()
{
	return this->name;
}
int Character::getStrenght()
{
	return this->strength;
}
int Character::getAgility()
{
	return this->agility;
}
int Character::getIntelligence()
{
	return this->intelligence;
}
int Character::getVitality()
{
	return this->vitality;
}
int Character::getHealth()
{
	return this->health;
}
int Character::getCurrentHealth()
{
	return this->currentHealth;
}

void Character::setCol(int newCol)
{
	this->col = newCol;
}
void Character::setRow(int newRow)
{
	this->row = newRow;
}
void Character::setStrength(int strength)
{
	this->strength = strength;
	this->health = this->vitality * 2 + this->strength / 2 + 1;
}
void Character::setAgility(int agility)
{
	this->agility = agility;
}
void Character::setVitality(int vitality)
{
	this->vitality = vitality;
	this->health = this->vitality * 2 + this->strength / 2 + 1;
}
void Character::setIntelligence(int intelligence)
{
	this->intelligence = intelligence;
}
void Character::setItem(Item tileItem)
{
	this->inventory[0] = tileItem;
}