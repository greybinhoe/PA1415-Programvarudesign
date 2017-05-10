#include <iostream>
#include "Map.h"
#include "Character.h"
#include <Windows.h>
//#include "Character.h"

int main()
{
	bool gameActive = true;
	Map map;
	//Character player;

	//Gameloop
	while (gameActive)
	{
		//Clear console
		system("cls");
		//Output the map visual
		std::cout << map.toString();

		//Move Up
		if (GetAsyncKeyState(VK_NUMPAD8))
		{
			//Check if player can move to spot
			//Move player
		}
		//Move Down
		else if (GetAsyncKeyState(VK_NUMPAD2))
		{
		}
		//Move Left
		else if (GetAsyncKeyState(VK_NUMPAD4))
		{
		}
		//Move Right
		else if (GetAsyncKeyState(VK_NUMPAD6))
		{
		}
	}

	return 0;
}