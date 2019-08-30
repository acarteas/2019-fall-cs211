#define PDC_DLL_BUILD 1

#include "curses.h"
#include "panel.h"
#include "curspriv.h"

int main()
{
	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	//Initialize our window
	main_window = initscr();

	//resize our window
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);

	//Turn keyboard echo
	noecho();

	//turn on keypad input
	keypad(main_window, TRUE);

	//hide the cursor
	curs_set(FALSE);

	//Main program logic goes here

	for (int i = 0; i < num_cols; i++)
	{	
		//top row
		mvaddch(0, i, ACS_CKBOARD);
		//bottom row
		mvaddch(num_rows - 2, i, ACS_BULLET);
	}
	for (int i = 0; i < num_rows; i++)
	{
		//left column
		mvaddch(i, 0, ACS_LANTERN);
		//right column
		mvaddch(i,num_cols - 2 , ACS_PLUS);
	}

	//refresh tells 
	refresh();

	//END OF PROGRAM LOGIC GOES HERE

	//pause for user input
	char input = getch();

	//end cursor
	endwin();

	return 0;
}