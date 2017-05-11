#include "curses.h"
#include "Map.h"
#include "Character.h"

void initCurses()
{
	//initscr();                    /* Start curses mode */
	//printw("Hello World !!!");    /* Print Hello World */
	//refresh();                    /* Print it on to the real screen */
	//getch();                      /* Wait for user input */
	//endwin();                     /* End curses mode */

	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
}

void erase(int y, int x)
{
	mvaddch(y, x, '$');
}

void drawMap(Map map)
{
	char bigCHARRAY[124][124];
	for (int i = 0; i < map.getRows(); i++)
	{
		map.rowToCharArray(bigCHARRAY[i], i);
	}
	for (int i = 0; i < map.getRows(); i++)
	{
		mvaddstr(i, 0, bigCHARRAY[i]);
	}
}

void gameLoop(Character player, Map map, int ch)
{
	while (1)
	{
		if (ch == 'q' || ch == 'Q')
		{
			return;	
		}
		drawMap(map);
		mvaddch(player.getRow(), player.getCol(), player.getVisual());
		refresh();

		for (;;)
		{
			ch = getch();
			
			if (ch == KEY_LEFT)
			{
				player.setCol(player.getCol() - 1);
				drawMap(map);
				mvaddch(player.getRow(), player.getCol(), player.getVisual());
				refresh();
			}
			else if (ch == KEY_RIGHT)
			{
				player.setCol(player.getCol() + 1);
				drawMap(map);
				mvaddch(player.getRow(), player.getCol(), player.getVisual());
				refresh();
			}
			else if (ch == KEY_UP)
			{
				player.setRow(player.getRow() - 1);
				drawMap(map);
				mvaddch(player.getRow(), player.getCol(), player.getVisual());
				refresh();
			}
			else if (ch == KEY_DOWN)
			{
				player.setRow(player.getRow() + 1);
				drawMap(map);
				mvaddch(player.getRow(), player.getCol(), player.getVisual());
				refresh();
			}
		}
	}
}


int main()
{
	// Initialize our objects
	Map map;
	Character player(10, 10, "ninni", 10, 10, 10, 10);

	// Initialize ncurses
	initCurses();
	

	// Print a welcome message on screen
	printw("Team Unicorn presents UNICORNHACK! The game!\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

	// Wait until the user press a key
	int ch = getch();

	// Clear the screen
	clear();

	// Start the game loop
	gameLoop(player, map, ch);
	return 0;
}