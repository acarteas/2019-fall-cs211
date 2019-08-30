
#define PDC_DLL_BUILD 1
#include "curses.h"
#include <string>

using namespace std;

int main(void) {

	WINDOW* main_window = nullptr;
	int num_rows = 0;
	int num_cols = 0;

	// Initiialize screen, begin curses mode
	main_window = initscr();

	// Take up most of screen
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);

	// Turn off key echo
	noecho;
	nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	curs_set(0);

	// FUN STUFF HAPPENS HERE
	for (int i = 0; i < num_cols; i++) {
		// Top border
		mvaddch(0, i, 219);

		// Bottom border
		mvaddch(num_rows - 1, i, 219);
	}
	
	for (int i = 0; i < num_rows; i++) {

		// Left column
		mvaddch(i, 0, 219);

		// RIght coloumn
		mvaddch(i, num_cols - 1, 219);
	}

	// Tells curses to draw
	refresh();

	// Revert back to normal console mode
	nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	mvaddstr(0, 0, "Press any key to continue...");
	char result = getch();
	endwin();






}