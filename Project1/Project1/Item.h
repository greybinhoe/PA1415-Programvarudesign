#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item //Basklass
{
private:
	std::string name;
	std::string description;
	char visual;

public:
	Item();
	Item(std::string name, std::string description, char visual);
	virtual ~Item();

	std::string getName()const;
	char getVisual()const;
	std::string getDescription()const;

	void setName(const std::string name);
	void setVisual(const char visual);
	void setDescription(const std::string description);
};
#endif // !ITEM_H
