#define PDC_DLL_BUILD 1

#include "curses.h"
#include "curspriv.h"
#include "panel.h"
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	ifstream src("test.txt");
	//FILE* src = fopen("test.txt", "r");
	//errno_t src;
	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	//SETUP

	//initialize our screen
	main_window = initscr();

	//resize our window
	resize_term(5000, 5000);
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
	//box(sub_window, 0, 0);

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

	wattron(main_window, COLOR_PAIR(1));
	wattron(main_window, A_UNDERLINE);
	mvaddstr(0, 2, "File");
	mvaddstr(0, 8, "Edit");
	mvaddstr(0, 14, "Options");
	mvaddstr(0, 23, "Tools");
	mvaddstr(0, 30, "About");
	wattroff(main_window, A_UNDERLINE);
	wattroff(main_window, COLOR_PAIR(1));

	//refresh tells curses to draw everything
	refresh();
	touchwin(stdscr);
	//wrefresh(sub_window);

	//END OF PROGRAM LOGIC GOES HERE

	//Pause for user input
	//char input = getch();
	wattron(sub_window, A_STANDOUT);
	mvwaddstr(sub_window, 1, 50, "INPUT ASTERICK * TO EXIT");
	wattroff(sub_window, A_STANDOUT);
	//wmove(sub_window, 20, 20);
	char typing = ' ';
	int col_loc = 3;
	int row_loc = 1;

	//while typing any key but asterick, getch() will save value to type_input
	//then it will be added to subwin as a char based on the current location of row_loc and
	//col_loc, counter for row will then increment by one unless it's at the end of the 
	//screen, then col_loc will increment by one and row will revert to zero
	while (typing != '*')
	{
		int type_input = getch();

		if (type_input == 27)
		{
			//char file[500];
			while (!src.eof())
			{
				string line;
				getline(src, line);
				mvwaddstr(sub_window, row_loc, col_loc, line.c_str());
				row_loc++;
				wrefresh(sub_window);
			}

			src.close();
		}

		//if enter key is pressed, move to new line
		if (type_input == 10)
		{
			col_loc++;
			row_loc = 0;
		}
		else
		{
			mvwaddch(sub_window, col_loc, row_loc, type_input);
			typing = type_input;
			wrefresh(sub_window);
		}
		if (row_loc >= num_cols - 4)
		{
			col_loc++;
			row_loc = 0;
		}
		row_loc++;
	}

	//user presses asterick to exit, subwindow clears, main window clears
	//then both windows exit
	if (typing == '*')
	{
		wclear(sub_window);
		clear();
		refresh();
		wrefresh(sub_window);
		exit(1);
	}

	wrefresh(sub_window);

	//end curses mode, deletes both windows
	delwin(sub_window);
	endwin();
}