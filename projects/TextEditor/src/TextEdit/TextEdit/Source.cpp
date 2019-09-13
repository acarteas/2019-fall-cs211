#define PDC_DLL_BUILD 1

#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
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
		mvaddch(i, 0, ACS_VLINE); 
		//right column
		mvaddch(i,num_cols - 2 , ACS_VLINE);
	}

	//Setting up the boder names and giving it some color
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	attron(COLOR_PAIR(1));
	//printw("");
	mvaddstr(0, 0, "File");
	mvaddstr(0, 5, "Edit");
	mvaddstr(0, 10, "Format");
	mvaddstr(0, 17, "View");
	mvaddstr(0, 22, "Help");


	//Moving the cursor under the file bar to get ready for typing
	move(2, 1);
	

	//refresh tells 
	refresh();

	//END OF PROGRAM LOGIC GOES HERE

	//pause for user input
	
	int y, x;
	char space = ' ';
	cbreak();
	getyx(main_window, y, x);

	//Setting up the special keys.
	keypad(stdscr, TRUE);
	while (1)
	{
		int input = getch();

		switch (input)
		{
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
		//The Enter key is not working at the moment 
		case KEY_ENTER:
			y++;
			wmove(main_window, y, x);
			break;
		//The backspace key is not working at the moment
		case KEY_BACKSPACE:
			x--;
			wmove(main_window, y, x);
			break;

		case ' ':
			mvaddch(y, x, ' ');
			x++;
			wmove(main_window, y, x);
			break;

		case 'a':
			mvaddch(y, x, 'a');
			x++;
			wmove(main_window, y, x);
			break;
		case 'A':
			mvaddch(y, x, 'A');
			x++;
			wmove(main_window, y, x);
			break;
		case 'b':
			mvaddch(y, x, 'b');
			x++;
			wmove(main_window, y, x);
			break;
		case 'B':
			mvaddch(y, x, 'B');
			x++;
			wmove(main_window, y, x);
			break;
		case 'c':
			mvaddch(y, x, 'c');
			x++;
			wmove(main_window, y, x);
			break;
		case 'C':
			mvaddch(y, x, 'C');
			x++;
			wmove(main_window, y, x);
			break;
		case 'd':
			mvaddch(y, x, 'd');
			x++;
			wmove(main_window, y, x);
			break;
		case 'D':
			mvaddch(y, x, 'D');
			x++;
			wmove(main_window, y, x);
			break;
		case 'e':
			mvaddch(y, x, 'e');
			x++;
			wmove(main_window, y, x);
			break;
		case 'E':
			mvaddch(y, x, 'E');
			x++;
			wmove(main_window, y, x);
			break;
		case 'f':
			mvaddch(y, x, 'f');
			x++;
			wmove(main_window, y, x);
			break;
		case 'F':
			mvaddch(y, x, 'F');
			x++;
			wmove(main_window, y, x);
			break;
		case 'g':
			mvaddch(y, x, 'g');
			x++;
			wmove(main_window, y, x);
			break;
		case 'G':
			mvaddch(y, x, 'G');
			x++;
			wmove(main_window, y, x);
			break;
		case 'h':
			mvaddch(y, x, 'h');
			x++;
			wmove(main_window, y, x);
			break;
		case 'H':
			mvaddch(y, x, 'H');
			x++;
			wmove(main_window, y, x);
			break;
		case 'i':
			mvaddch(y, x, 'i');
			x++;
			wmove(main_window, y, x);
			break;
		case 'I':
			mvaddch(y, x, 'I');
			x++;
			wmove(main_window, y, x);
			break;
		case 'j':
			mvaddch(y, x, 'j');
			x++;
			wmove(main_window, y, x);
			break;
		case 'J':
			mvaddch(y, x, 'J');
			x++;
			wmove(main_window, y, x);
			break;
		case 'k':
			mvaddch(y, x, 'k');
			x++;
			wmove(main_window, y, x);
			break;
		case 'K':
			mvaddch(y, x, 'K');
			x++;
			wmove(main_window, y, x);
			break;
		case 'l':
			mvaddch(y, x, 'l');
			x++;
			wmove(main_window, y, x);
			break;
		case 'L':
			mvaddch(y, x, 'L');
			x++;
			wmove(main_window, y, x);
			break;
		case 'm':
			mvaddch(y, x, 'm');
			x++;
			wmove(main_window, y, x);
			break;
		case 'M':
			mvaddch(y, x, 'M');
			x++;
			wmove(main_window, y, x);
			break;
		case 'n':
			mvaddch(y, x, 'n');
			x++;
			wmove(main_window, y, x);
			break;
		case 'N':
			mvaddch(y, x, 'N');
			x++;
			wmove(main_window, y, x);
			break;
		case 'o':
			mvaddch(y, x, 'o');
			x++;
			wmove(main_window, y, x);
			break;
		case 'O':
			mvaddch(y, x, 'O');
			x++;
			wmove(main_window, y, x);
			break;
		case 'p':
			mvaddch(y, x, 'p');
			x++;
			wmove(main_window, y, x);
			break;
		case 'P':
			mvaddch(y, x, 'P');
			x++;
			wmove(main_window, y, x);
			break;
		case 'q':
			mvaddch(y, x, 'q');
			x++;
			wmove(main_window, y, x);
			break;
		case 'Q':
			mvaddch(y, x, 'Q');
			x++;
			wmove(main_window, y, x);
			break;
		case 'r':
			mvaddch(y, x, 'r');
			x++;
			wmove(main_window, y, x);
			break;
		case 'R':
			mvaddch(y, x, 'R');
			x++;
			wmove(main_window, y, x);
			break;
		case 's':
			mvaddch(y, x, 's');
			x++;
			wmove(main_window, y, x);
			break;
		case 'S':
			mvaddch(y, x, 'S');
			x++;
			wmove(main_window, y, x);
			break;
		case 't':
			mvaddch(y, x, 't');
			x++;
			wmove(main_window, y, x);
			break;
		case 'T':
			mvaddch(y, x, 'T');
			x++;
			wmove(main_window, y, x);
			break;
		case 'u':
			mvaddch(y, x, 'u');
			x++;
			wmove(main_window, y, x);
			break;
		case 'U':
			mvaddch(y, x, 'U');
			x++;
			wmove(main_window, y, x);
			break;
		case 'v':
			mvaddch(y, x, 'v');
			x++;
			wmove(main_window, y, x);
			break;
		case 'V':
			mvaddch(y, x, 'V');
			x++;
			wmove(main_window, y, x);
			break;
		case 'w':
			mvaddch(y, x, 'w');
			x++;
			wmove(main_window, y, x);
			break;
		case 'W':
			mvaddch(y, x, 'W');
			x++;
			wmove(main_window, y, x);
			break;
		case 'x':
			mvaddch(y, x, 'x');
			x++;
			wmove(main_window, y, x);
			break;
		case 'X':
			mvaddch(y, x, 'X');
			x++;
			wmove(main_window, y, x);
			break;

		case 'y':
			mvaddch(y, x, 'y');
			x++;
			wmove(main_window, y, x);
			break;
		case 'Y':
			mvaddch(y, x, 'Y');
			x++;
			wmove(main_window, y, x);
			break;
		case 'z':
			mvaddch(y, x, 'z');
			x++;
			wmove(main_window, y, x);
			break;
		case 'Z':
			mvaddch(y, x, 'Z');
			x++;
			wmove(main_window, y, x);
			break;
		}
		wrefresh(main_window);
	}

	//int input = getstr('');


	//end cursor
	endwin();

	return 0;
}