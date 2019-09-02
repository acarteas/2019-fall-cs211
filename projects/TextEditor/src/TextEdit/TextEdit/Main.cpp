#define PDC_DLL_BUILD 1

#include "curses.h"
#include "curspriv.h"
#include "panel.h"

int main(void)
{
	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	//SETUP

	//initialize our screen
	main_window = initscr();

	//resize our window
	resize_term(5000, 5000);
	//getmaxyx(main_window, num_rows, num_cols);
	//resize_term(num_rows - 1, num_cols - 1);
	//getmaxyx(main_window, num_rows, num_cols);
	wborder(main_window, 0, 0, 0, 0, 0, 0, 0, 0);

	//turn off keyboard echo
	noecho();

	//turn on keypad input
	keypad(main_window, true);

	//hide the cursor
	curs_set(FALSE);

	//MAIN PROGRAM LOGIC GOES HERE

	//add character to screen
	//mvaddch(2,2, 'Y');
	//addstr("This is a test!");
	//char mesg[] = "Hello there!";
	mvaddstr(0, 2, "File");
	mvaddstr(0, 8, "Edit");
	mvaddstr(0, 14, "Options");
	mvaddstr(0, 23, "Tools");
	mvaddstr(0, 30, "About");

	//add border to screen
	for (int i = 0; i < num_cols; i++)
	{
		//top row
		mvaddch(0, i, ACS_BLOCK);

		//bottom row
		mvaddch(num_rows - 1, i, ACS_BLOCK);
	}

	for (int i = 0; i < num_cols; i++)
	{
		//left column
		mvaddch(i, 0, ACS_BLOCK);

		//right column
		mvaddch(i, num_cols - 1, ACS_BLOCK);
	}

	//refresh tells curses to draw everything
	refresh();

	//END OF PROGRAM LOGIC GOES HERE

	//Pause for user input
	char input = getch();

	//end curses mode
	endwin();
}