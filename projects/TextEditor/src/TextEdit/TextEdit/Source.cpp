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

void check_cursor(int _y, int _x)
{
	if (x <= 2)
		x = 2;
	else if (y <= 2)
		y = 2;
}
int main(int argc, char* argv[])
{
	//Initialize our window
	main_window = initscr();

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
	for (int i = 0; i < num_rows; i++)
	{
		//left column
		mvaddch(i, 1, ACS_VLINE); 
		//right column
//mvaddch(i,num_cols - 2 , ACS_VLINE);
	}

	//Setting up the boder names and giving it some color
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	attron(COLOR_PAIR(1));
	//printw("");

	mvaddstr(0, 2, "File");
	mvaddstr(0, 7, "Edit");
	mvaddstr(0, 12, "Format");
	mvaddstr(0, 19, "View");
	mvaddstr(0, 24, "Help");
	mvaddstr(0, 29, "save");
	attroff(COLOR_PAIR(1));


	//Moving the cursor under the file bar to get ready for typing
	move(2, 2);
	

	//refresh tells 
	refresh();

	//END OF PROGRAM LOGIC GOES HERE

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
	if (input.is_open() == true) {

		while (input.good() == true) {
			char letter;
			input >> letter;
			in_file.push_back(letter);
			mvaddch(y, x, letter);
			x++;
		}
			wrefresh(main_window);
	}
	input.close();
	
	
	//Setting up the special keys.
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	scrollok(main_window, TRUE);

	while (1)
	{

		int input = getch();
		
		switch (input)
		{
		case KEY_MOUSE:
			if (input == MOUSE_WHEEL_SCROLL)
			{
				scroll(main_window);
			}
         break;
		case KEY_RESIZE:
			cbreak();
			resize_term(0, 0);
			break;
		case KEY_UP:
			y--;
			check_cursor(y, x);
			wmove(main_window, y, x); 
			break;
		case KEY_DOWN:
			y++;
			check_cursor(y, x);
			wmove(main_window, y, x);
			break;
		case KEY_LEFT:
			x--;
			check_cursor(y, x);
			wmove(main_window, y, x);
			break;
		case KEY_RIGHT:
			x++;
			check_cursor(y, x);
			wmove(main_window, y, x);
			break;
		case KEY_ENTER: case '\r': case '\n':
			y++;
			x = 2;
			if (y >=num_rows)
				num_rows += 1;
			wmove(main_window, y, x);
			in_file.push_back(input);
			break;

		//The backspace key is not working at the moment
		case KEY_BACKSPACE: case KEY_DC: case 127: case '\b':
			delch();
			x -= 1;
			
			if (x < 2)
			{
				x = num_cols / 2;
				y--;
			}
			else if (y < 2)
			{
				y = 2;
			}
			wmove( main_window, y, x);
			in_file.push_back(input);
			break;

		case KEY_STAB: case '\t':
			x += 8;
		case ' ':
			mvaddch(y, x,' ');
			x++;
			in_file.push_back(input);
			break;

		case 'a':
			mvaddch(y, x, 'a');
			x++;
			in_file.push_back(input);
			break;
		case 'A':
			mvaddch(y, x, 'A');
			x++;
			in_file.push_back(input);
			break;
		case 'b':
			mvaddch(y, x, 'b');
			x++;
			in_file.push_back(input);
			break;
		case 'B':
			mvaddch(y, x, 'B');
			x++;
			in_file.push_back(input);
			break;
		case 'c':
			mvaddch(y, x, 'c');
			x++;
			in_file.push_back(input);
			break;
		case 'C':
			mvaddch(y, x, 'C');
			x++;
			in_file.push_back(input);
			break;
		case 'd':
			mvaddch(y, x, 'd');
			x++;
			in_file.push_back(input);
			break;
		case 'D':
			mvaddch(y, x, 'D');
			x++;
			in_file.push_back(input);
			break;
		case 'e':
			mvaddch(y, x, 'e');
			x++;
			in_file.push_back(input);
			break;
		case 'E':
			mvaddch(y, x, 'E');
			x++;
			in_file.push_back(input);
			break;
		case 'f':
			mvaddch(y, x, 'f');
			x++;
			in_file.push_back(input);
			break;
		case 'F':
			mvaddch(y, x, 'F');
			x++;
			in_file.push_back(input);
			break;
		case 'g':
			mvaddch(y, x, 'g');
			x++;
			in_file.push_back(input);
			break;
		case 'G':
			mvaddch(y, x, 'G');
			x++;
			in_file.push_back(input);
			break;
		case 'h':
			mvaddch(y, x, 'h');
			x++;
			in_file.push_back(input);
			break;
		case 'H':
			mvaddch(y, x, 'H');
			x++;
			in_file.push_back(input);
			break;
		case 'i':
			mvaddch(y, x, 'i');
			x++;
			in_file.push_back(input);
			break;
		case 'I':
			mvaddch(y, x, 'I');
			x++;
			in_file.push_back(input);
			break;
		case 'j':
			mvaddch(y, x, 'j');
			x++;
			in_file.push_back(input);
			break;
		case 'J':
			mvaddch(y, x, 'J');
			x++;
			in_file.push_back(input);
			break;
		case 'k':
			mvaddch(y, x, 'k');
			in_file.push_back(input);
			x++;
			break;
		case 'K':
			mvaddch(y, x, 'K');
			x++; in_file.push_back(input);
			break;
		case 'l':
			mvaddch(y, x, 'l');
			x++;
			in_file.push_back(input);
			break;
		case 'L':
			mvaddch(y, x, 'L');
			x++;
			in_file.push_back(input);
			break;
		case 'm':
			mvaddch(y, x, 'm');
			x++;
			in_file.push_back(input);
			break;
		case 'M':
			mvaddch(y, x, 'M');
			x++;
			in_file.push_back(input);
			break;
		case 'n':
			mvaddch(y, x, 'n');
			x++;
			in_file.push_back(input);
			break;
		case 'N':
			mvaddch(y, x, 'N');
			x++;
			in_file.push_back(input);
			break;
		case 'o':
			mvaddch(y, x, 'o');
			x++;
			in_file.push_back(input);
			break;
		case 'O':
			mvaddch(y, x, 'O');
			x++;
			in_file.push_back(input);
			break;
		case 'p':
			mvaddch(y, x, 'p');
			x++;
			in_file.push_back(input);
			break;
		case 'P':
			mvaddch(y, x, 'P');
			x++;
			in_file.push_back(input);
			break;
		case 'q':
			mvaddch(y, x, 'q');
			x++;
			in_file.push_back(input);
			break;
		case 'Q':
			mvaddch(y, x, 'Q');
			x++;
			in_file.push_back(input);
			break;
		case 'r':
			mvaddch(y, x, 'r');
			x++;
			in_file.push_back(input);
			break;
		case 'R':
			mvaddch(y, x, 'R');
			x++;
			in_file.push_back(input);
			break;
		case 's':
			mvaddch(y, x, 's');
			x++;
			in_file.push_back(input);
			break;
		case 'S':
			mvaddch(y, x, 'S');
			x++;
			in_file.push_back(input);
			break;
		case 't':
			mvaddch(y, x, 't');
			x++;
			in_file.push_back(input);
			break;
		case 'T':
			mvaddch(y, x, 'T');
			x++; 
			in_file.push_back(input);
			break;
		case 'u':
			mvaddch(y, x, 'u');
			x++;
			in_file.push_back(input);
			break;
		case 'U':
			mvaddch(y, x, 'U');
			x++;
			in_file.push_back(input);
			break;
		case 'v':
			mvaddch(y, x, 'v');
			x++;
			in_file.push_back(input);
			break;
		case 'V':
			mvaddch(y, x, 'V');
			x++;
			in_file.push_back(input);
			break;
		case 'w':
			mvaddch(y, x, 'w');
			x++;
			in_file.push_back(input);
			break;
		case 'W':
			mvaddch(y, x, 'W');
			x++;
			in_file.push_back(input);
			break;
		case 'x':
			mvaddch(y, x, 'x');
			x++;
			in_file.push_back(input);
			break;
		case 'X':
			mvaddch(y, x, 'X');
			x++;
			in_file.push_back(input);
			break;
		case 'y':
			mvaddch(y, x, 'y');
			x++;
			in_file.push_back(input);
			break;
		case 'Y':
			mvaddch(y, x, 'Y');
			x++;
			in_file.push_back(input);
			break;
		case 'z':
			mvaddch(y, x, 'z');
			x++;
			in_file.push_back(input);
			break;
		case 'Z':
			mvaddch(y, x, 'Z');
			x++;
			in_file.push_back(input);
			break;
		case '.':
			mvaddch(y, x, '.');
			x++;
			in_file.push_back(input);
			break;
		case ',':
			mvaddch(y, x, ',');
			x++;
			in_file.push_back(input);
			break;
		case ';':
			mvaddch(y, x, ';');
			x++;
			in_file.push_back(input);
			break;
		case '"':
			mvaddch(y, x, '"');
			x++;
			in_file.push_back(input);
			break;
		case '!':
			mvaddch(y, x, '!');
			x++;
			in_file.push_back(input);
			break;
		}
		wrefresh(main_window);
	}
	
	ofstream out_stream("replica.txt");

	for (int i = 0; i < in_file.size(); i++)
	{
		out_stream << in_file[i];
	}
	rename("replica.txt", "sample.txt");


	//end cursor
	endwin();

	return 0;
}
