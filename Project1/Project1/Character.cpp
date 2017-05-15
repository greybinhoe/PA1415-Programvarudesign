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

int Character::getCol() const
{
	return this->col;
}
int Character::getRow() const
{
	return this->row;
}
char Character::getVisual() const
{
	return this->visual;
}
std::string Character::getName() const
{
	return this->name;
}
int Character::getStrenght() const
{
	return this->strength;
}
int Character::getAgility() const
{
	return this->agility;
}
int Character::getIntelligence() const
{
	return this->intelligence;
}
int Character::getVitality() const
{
	return this->vitality;
}
int Character::getHealth() const
{
	return this->health;
}
int Character::getCurrentHealth() const
{
	return this->currentHealth;
}

void Character::setPos(int row, int col)
{
	this->row = row;
	this->col = col;
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