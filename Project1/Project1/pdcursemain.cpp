#include "include\curses.h"
#include "include\panel.h"
#include "Screen.h"
#include "Frame.h"
#include "Map.h"
#include "Character.h"

void initCurses()
{
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	//Seed randomness
	srand((unsigned)time(NULL));

	//initscr();                    /* Start curses mode */
	//printw("Hello World !!!");    /* Print Hello World */
	//refresh();                    /* Print it on to the real screen */
	//getch();                      /* Wait for user input */
	//endwin();                     /* End curses mode */
}

void log(char * str)
{
	int index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 0; j < 64; j++)
		{
			mvaddch(26 + i + 1, j, mvinch(26 + i, j));
		}
	}
	mvaddstr(26, 0, str);
	mvaddstr(26, index, "                                                               ");
}

void drawMap(Map map)
{
	char bigCHARRAY[25][120];
	for (int i = 0; i < map.getRows(); i++)
	{
		map.rowToCharArray(bigCHARRAY[i], i);
	}
	for (int i = 0; i < map.getRows(); i++)
	{
		mvaddstr(i, 0, bigCHARRAY[i]);
	}
	mvaddstr(25, 0, "INFO LOG:                   ");
}

void gameLoop(Map map, Character player, int ch)
{
	// Check if user wishes to quit
	if (ch == 'q' || ch == 'Q')
	{
		return;
	}

	drawMap(map);
	mvaddch(player.getRow(), player.getCol(), player.getVisual());
	refresh();

	while (1)
	{
		ch = getch();

		if (ch == KEY_LEFT)
		{
			if (map.checkPos(player.getRow(), player.getCol() - 1))
			{
				drawMap(map);
				player.setPos(player.getRow(), player.getCol() - 1);
				mvaddch(player.getRow(), player.getCol(), player.getVisual());
			}
			else
			{
				log("You walked into a wall, stupid.");
			}
			refresh();
		}
		else if (ch == KEY_RIGHT)
		{
			if (map.checkPos(player.getRow(), player.getCol() + 1))
			{
				drawMap(map);
				player.setPos(player.getRow(), player.getCol() + 1);
				mvaddch(player.getRow(), player.getCol(), player.getVisual());
			}
			else
			{
				log("You walked into a wall, stupid.");
			}
			refresh();
		}
		else if (ch == KEY_UP)
		{
			if (map.checkPos(player.getRow() - 1, player.getCol()))
			{
				drawMap(map);
				player.setPos(player.getRow() - 1, player.getCol());
				mvaddch(player.getRow(), player.getCol(), player.getVisual());
			}
			else
			{
				log("You walked into a wall, stupid.");
			}
			refresh();
		}
		else if (ch == KEY_DOWN)
		{
			if (map.checkPos(player.getRow() + 1, player.getCol()))
			{
				drawMap(map);
				player.setPos(player.getRow() + 1, player.getCol());
				mvaddch(player.getRow(), player.getCol(), player.getVisual());
			}
			else
			{
				log("You walked into a wall, stupid.");
			}
			refresh();
		}
		else if (ch == 'e' || ch == 'E')
		{
			std::string x = map.getItemName(player.getRow(), player.getCol());
			x += ": ";
			x += map.getItemDesc(player.getRow(), player.getCol());
			char *y = new char[x.length() + 1];
			std::strcpy(y, x.c_str());
			log(y);
			player.setItem(map.pickUpItem(player.getRow(), player.getCol()));
			delete[] y;
		}
		else if (ch == 'q' || ch == 'Q')
		{
			break;
		}
	}
}

int main()
{
	// Initialize ncurses
	initCurses();

	// Print a welcome message on screen
	printw("Team Unicorn presents UNICORNHACK! The game!\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

	// Wait until the user press a key
	int ch = getch();

	// Initialize our map and player
	Map map;
	Character player(20, 20, "UniHorn", 1, 10, 100, 10);

	// Clear the screen
	clear();
	drawMap(map);

	// Start the game loop
	gameLoop(map, player, ch);

	return 0;
}