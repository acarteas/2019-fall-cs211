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
#include <locale>
#include <codecvt>

using namespace std;

int main(int argc, char* argv[])
{

	cout << "Argument output: " << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}

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
	curs_set(FALSE);
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

	//END OF PROGRAM LOGIC GOES HERE

	//Pause for user input
	attron(A_STANDOUT);
	mvwaddstr(main_window, 2, (num_cols / 2) - 25, "INPUT ASTERICK * TO EXIT");
	attroff(A_STANDOUT);

	char typing = ' ';
	int row_loc = 3;
	int col_loc = 1;

	//scrolling features
	int maxy;
	int maxx;
	int i = 2;
	getmaxyx(sub_window, maxy, maxx);

	if (col_loc > num_cols - 2)
	{
		while (1)
		{
			wprintw(sub_window, "%d - this is a scrolling test!");
			++i;
			wrefresh(sub_window);
		}
	}

	//while typing any key but asterick, getch() will save value to type_input
	//then it will be added to subwin as a char based on the current location of col_loc and
	//row_loc, counter for column will then increment by one unless it's at the end of the 
	//screen, then row_loc will increment by one and col_loc will revert to default location
	while (typing != '*')
	{
		int type_input = getch();

		if (type_input == 27)
		{
			//string filename = argv[1];
			vector<wstring> myFile;
			ifstream src;
			src.open("Test.txt");
			//src.open(filename);
			string line;
			//wstring newline;

			while (!src.eof())
			{

				getline(src, line);
				//std::wstring str_turned_to_wstr = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(line);
				//std::string wstr_turned_to_str = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(newline);
				//myFile.push_back(newline);
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

			if (type_input == '`')
			{
				ofstream src;
				src.open("test.txt");

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
	}

	wrefresh(sub_window);

	//end curses mode, deletes both windows
	delwin(sub_window);
	endwin();
}

