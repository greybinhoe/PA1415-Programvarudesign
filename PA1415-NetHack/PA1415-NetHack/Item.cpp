#include "Item.h"

Item::Item()
{
	this->name = "";
	this->description = "";
	this->visual = ' ';
}

Item::Item(std::string name, std::string description, char visual)
{
	this->name = name;
	this->description = description;
	this->visual = visual;
}

Item::~Item()
{
	
}

std::string Item::getName() const
{
	return this->name;
}

char Item::getVisual() const
{
	return this->visual;
}

std::string Item::getDescription() const
{
	return this->description;
}

void Item::setName(const std::string name)
{
	this->name = name;
}

void Item::setVisual(const char visual)
{
	this->visual = visual;
}

void Item::setDescription(const std::string description)
{
	this->description = description;
}

char Item::getVisual() const
{
	return this->visual;
}

