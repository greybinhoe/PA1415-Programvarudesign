#ifndef _CHARACTER_
#define _CHARACTER_
#include <math.h>
#include <string.h>
#include "Point.h"


class Character
{
	private:
		char visual = '@';
		Point position;
		std::string name;
		int strength;
		int agility;
		int intelligence;
		int vitality;
		int health;
		int currentHealth;
	public:
		Character();
		Character(Point position, std::string name, int strenght,int agility, int intelligence,int vitality);
		Point getPosition();
		char getVisual();
		std::string getName();
		int getStrenght();
		int getAgility();
		int getIntelligence();
		int getVitality();
		int getHealth();
		int getCurrentHealth();
		void setPosition(Point newPos);
		void setStrength(int strength);
		void setAgility(int agility);
		void setIntelligence(int intelligence);
		void setVitality(int vitality);

};

#endif