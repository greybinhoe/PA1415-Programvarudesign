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
		int getRow();
		int getCol();
		char getVisual();
		std::string getName();
		int getStrenght();
		int getAgility();
		int getIntelligence();
		int getVitality();
		int getHealth();
		int getCurrentHealth();
		void setRow(int newX);
		void setCol(int newY);
		void setStrength(int strength);
		void setAgility(int agility);
		void setIntelligence(int intelligence);
		void setVitality(int vitality);
		void setItem(Item tileItem);

};

#endif