 1 #include <ncurses.h>
 2 
 3 int main() {
 4 	// Initialize ncurses
 5 	initscr();
 6 	clear();
 7 
 8 	// Print a string on screen
 9 	printw("Seems that you can use ncurses ...\nPress any key to exit!");
10 
11 	// Wait until the user press a key
12 	getch();
13 
14 	// Clear ncurses data structures
15 	endwin();
16 }

// g++ Character.h Character.cpp Item.h Item.cpp Point.h testmain.cpp -stdc++11 -Wall
