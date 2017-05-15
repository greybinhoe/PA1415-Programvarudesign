#ifndef _CHARACTER_
#define _CHARACTER_
#include <math.h>
#include <string.h>
#include "Point.h"
#include "Item.h"

class Character
{
	private:
		char visual = '@';
		int row;
		int col;
		Item inventory[1];
		std::string name;
		int strength;
		int agility;
		int intelligence;
		int vitality;
		int health;
		int currentHealth;
	public:
		Character();
		Character(int positionX, int positionY, std::string name, int strenght,int agility, int intelligence,int vitality);
		int getRow() const;
		int getCol() const;
		char getVisual() const;
		std::string getName() const;
		int getStrenght() const;
		int getAgility() const;
		int getIntelligence() const;
		int getVitality() const;
		int getHealth() const;
		int getCurrentHealth() const;
		void setPos (int row, int col);
		void setStrength(int strength);
		void setAgility(int agility);
		void setIntelligence(int intelligence);
		void setVitality(int vitality);
		void setItem(Item tileItem);

};

#endif