Character()
{
	this->position(0,0);
	this->name = "";
	this->strength = 0;
	this->agility = 0;
	this->intelligence = 0;
	this->vitality = 0;
	this->health = this->vitality*2+this->strength /2 + 1;
	this->currentHealth = this->health;
}
Character(Point position, std::string name, int strenght,int agility, int intelligence,int vitality)
{
	this->position = position;
	this->name = name;
	this->strength = strength;
	this->agility = agility;
	this->intelligence = intelligence;
	this->vitality = vitality;
	this->health = this->vitality*2 + this->strength / 2 + 1 ;
	this->currentHealth = this->health;
}
Point getPosition()
{
	return this->position;
}
char getVisual()
{
	return this->visual;
}
std::string getName()
{
	return this->name;
}
int getStrenght()
{
	return this->strength;
}
int getAgility()
{
		return this->agility;
}
int getIntelligence()
{
	return this->intelligence;
}
int getVitality()
{
	return this->vitality;
}
int getHealth()
{
	return this->health;
}
int getCurrentHealth()
{
	return this->currentHealth;
}
void setPosition(Point newPos)
{
	this->position = newPos;
}
void setStrength(int strength)
{
	this->strength = strength;
	this->health = this->vitality * 2 + this->strength / 2 + 1;
}
void setAgility(int agility)
{
	this->agility = agility
}
void setVitality(int vitality)
{
	this->vitality = vitality;
	this->health = this->vitality * 2 + this->strength / 2 + 1;
}
void setIntelligence(int intelligence)
{
	this->intelligence = intelligence;
}