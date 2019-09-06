#define PDC_DLL_BUILD 1

#include "curses.h"
#include "curspriv.h"
#include "panel.h"
#include <stdlib.h>


int main(void)
{
	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	//SETUP

	//initialize our screen
	main_window = initscr();

	//resize our window
	resize_term(100, 100);
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);
	attron(A_DIM);
	wborder(main_window, 0, 0, 0, 0, 0, 0, 0, 0);
	attroff(A_DIM);

	//create text field
	WINDOW * sub_window;
	sub_window = subwin(main_window, num_rows - 2, num_cols - 2, 1, 1);
	//Use to verify location of sub_window
	box(sub_window, 047, 055);

	//turn off keyboard echo
	noecho();

	//turn on keypad input
	keypad(main_window, true);

	//hide the cursor
	curs_set(FALSE);

	//MAIN PROGRAM LOGIC GOES HERE

	//add file menu header to screen
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color(); /* Start color */
	init_pair(1, COLOR_WHITE, COLOR_BLACK); //sets the color of text and background

	attron(COLOR_PAIR(1));
	attron(A_UNDERLINE);
	mvaddstr(0, 2, "File");
	mvaddstr(0, 8, "Edit");
	mvaddstr(0, 14, "Options");
	mvaddstr(0, 23, "Tools");
	mvaddstr(0, 30, "About");
	attroff(A_UNDERLINE);
	attroff(COLOR_PAIR(1));


	//add border to screen
	/*for (int i = 0; i < num_cols; i++)
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
	}*/

	//refresh tells curses to draw everything
	refresh();
	wrefresh(sub_window);

	//END OF PROGRAM LOGIC GOES HERE

	//Pause for user input
	//char input = getch();
	attron(A_STANDOUT);
	mvwaddstr(sub_window, num_cols / 2, num_rows / 2, "TYPE ASTERICK * TO EXIT");
	attroff(A_STANDOUT);
	wmove(sub_window, 4, 1);
	char typing = ' ';

	while (typing != '*')
	{
		int type_input = getch();
		mvwaddch(sub_window, num_cols / 2, num_rows / 2, type_input);
		//addch(type_input);
		typing = type_input;
	}

	if (typing == '*')
	{
		return 0;
	}

	//end curses mode
	delwin(sub_window);
	endwin();
}