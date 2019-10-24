#define PDC_DLL_BUILD 1

#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int num_cols = 0;
int num_rows = 0;
int y, x;
WINDOW* main_window = nullptr;
WINDOW* character_window = nullptr;

void check_cursor(int _y, int _x)
{
	if (x <= 2)
		x = 2;
	else if (y <= 2)
		y = 2;
}
void wrap(WINDOW*,int _y,int _x)
{
	if (_x >= num_cols)
	{
		y++;
		x = 2;
	}
}

void set_boarder()
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	attron(COLOR_PAIR(1));
	//printw("");

	mvaddstr(0, 0, "File");
	mvaddstr(0, 5, "Edit");
	mvaddstr(0, 10, "Format");
	mvaddstr(0, 17, "View");
	mvaddstr(0, 22, "Help");
	attroff(COLOR_PAIR(1));
}


int main(int argc, char* argv[])
{
	//Initialize our window
	main_window = initscr();
	character_window = initscr();

	//resize our window
	resize_term(5000, 5000);
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);




	//Turn keyboard echo
	noecho();

	//turn on keypad input
	keypad(main_window, TRUE);

	//hide the cursor
	//curs_set(FALSE);


	//Main program logic goes here

	//Making the border for the window
	for (int i = 0; i < num_cols; i++)
	{
		//top row
		mvaddch(1, i, ACS_BSBS);
		//bottom row
		//mvaddch(num_rows - 2, i, ACS_BSBS);
	}
	//for (int i = 0; i < num_rows; i++)
	//{
		//left column
		//mvaddch(i, 1, ACS_VLINE); 
		//right column
//mvaddch(i,num_cols - 2 , ACS_VLINE);
	//}

	//Setting up the boder names and giving it some color
	set_boarder();


	//Moving the cursor under the file bar to get ready for typing
	move(2, 0);

	//refresh tells 
	refresh();

	//pause for user input
	cbreak();
	getyx(main_window, y, x);




	//creating an ifstream with the file name sample.txt
	ifstream input("sample.txt");

	//Does not skip whitespace or empty space
	input >> noskipws;

	//creating a vector of chars to take in the date from the file
	vector<char> in_file{};

	// Checks if file name is valid
	if (input.is_open() == false) {
		mvaddstr(y, x, "Invalid file name, could not open\n");
		wmove(main_window, y, x);
		wrefresh(main_window);
	}

	// Reads file to a vector
	if (input.is_open() == true)
	{

		while (input.good() == true)
		{
			char letter;
			input >> letter;
			in_file.push_back(letter);
			mvaddch(y, x, letter);
			x++;
		}
		wrefresh(main_window);
	}
	//closing the file after I am done reading it
	input.close();


	//opening the keywords.txt file to read it into a vector of strings
	input.open("keywords.txt");

	//Checking to see if the file opened correctly
	if (input.is_open() == false)
	{
		mvaddstr(y, x, " Unable to open the file!");
		wmove(main_window, y, x);
		wrefresh(main_window);
	}

	//creating a vector of strings to store data from my file
	vector <string> strVec;

	if (input.is_open() == true)
	{
		while (input.good() == true)
		{
			string word;
			input >> word;
			strVec.push_back(word);
		}
	}
	//Closing the file after im done reading it
	input.close();

	ofstream out_file;
	out_file.open("sample.txt");
	for (int i = 0; i < in_file.size(); i++)
	{
		out_file << in_file[i];
	}
	
	//Setting up the special keys.
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	scrollok(main_window, TRUE);

	while (1)
	{

		int input = getch();
		
		if (main_window != nullptr)
		{
			switch (input)
			{
			case KEY_MOUSE:
				break;
			case KEY_RESIZE:
				cbreak;
				resize_term(0, 0);
				break;
			case KEY_UP:
				y--;
				wmove(main_window, y, x);
				break;
			case KEY_DOWN:
				y++;
				wmove(main_window, y, x);
				break;
			case KEY_LEFT:
				x--;
				wmove(main_window, y, x);
				break;
			case KEY_RIGHT:
				x++;
				wmove(main_window, y, x);
				break;
			case 127: case KEY_DC: case KEY_BACKSPACE:

				if (x = 0)
					y--;
				mvaddch(x, y, '\b');
				wmove(main_window, y, x);
				out_file << '\b' << ' ' << '\b';
				 if (y < 2)
				{
					y = 2;
				}
				break;
			case KEY_ENTER:
				y++;
				x = 0;
				break;
			case ALT_0:
				character_window = newwin(10, 15, y, x+1);
				refresh();
				box(character_window, 0, 0);
				wrefresh(character_window);
				break;
			default:
				waddch(main_window, input);
				x++;
				out_file << (char)input;
				break;
			}
		}	
		wrefresh(main_window);
	}
	out_file.close();


	//end cursor
	endwin();

	return 0;
}
