#define PDC_DLL_BUILD 1
#define PDC_WIDE 1
//#define MOUSE_WHEEL_SCROLL 

#include "curses.h"
#include "curspriv.h"
#include "panel.h"
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
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
	WINDOW* sub_window;
	sub_window = subwin(main_window, num_rows - 2, num_cols - 2, 1, 1);


	//Use to verify location of sub_window
	//box(sub_window, 0, 0);

	//turn off keyboard echo
	noecho();

	//allow scrolling
	scrollok(sub_window, TRUE);

	//turn on keypad input
	keypad(main_window, true);

	//hide the cursor
	curs_set(TRUE);
	wmove(sub_window, 0, 0);
	wrefresh(sub_window);

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
	attron(A_STANDOUT);
	mvwaddstr(main_window, 2, (num_cols / 2) - 25, "INPUT ASTERICK * TO EXIT");
	attroff(A_STANDOUT);
	//wmove(sub_window, 20, 20);
	char typing = ' ';
	int row_loc = 3;
	int col_loc = 1;

	//while typing any key but asterick, getch() will save value to type_input
	//then it will be added to subwin as a char based on the current location of col_loc and
	//row_loc, counter for row will then increment by one unless it's at the end of the 
	//screen, then row_loc will increment by one and row will revert to zero
	while (typing != '*')
	{
		int type_input = getch();

		if (type_input == 27)
		{

			vector<wstring> myFile;
			ifstream src;
			src.open("test.txt");
			string line;

			while (!src.eof())
			{

				getline(src, line);
				myFile.push_back(wstring{ line.begin(), line.end() });
			}

			src.close();

			//string newline;

			//Note to self: possibly use copy constructor instead of for loop?row_loc

			for (int i = 0; i < myFile.size(); i++)
			{

				//col_loc = sizeof(line) + col_loc;
				mvwaddwstr(sub_window, col_loc, row_loc, myFile[i].c_str());
				col_loc++;
				
			}
			wrefresh(sub_window);
		}

		//if enter key is pressed, move to new line
		if (type_input == 10)
		{
			row_loc++;
			col_loc = 0;
		}
		else
		{
			mvwaddch(sub_window, row_loc, col_loc, type_input);
			typing = type_input;
			wrefresh(sub_window);
		}
		if (col_loc >= num_cols - 20)
		{
			row_loc++;
			col_loc = 0;
		}
		col_loc++;
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
