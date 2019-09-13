#define PDC_DLL_BUILD 1

#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include <string>
#include <cstring>

using namespace std;

int num_cols = 0;
int num_rows = 0;
int y, x;
WINDOW* main_window = nullptr;

void backspace()
{
	noecho();
	nocbreak();
	getyx(main_window, y, x);
	move(y, x - 1);
	delch();
	cbreak();
	refresh();
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

	mvaddstr(0, 0, "File");
	mvaddstr(0, 5, "Edit");
	mvaddstr(0, 10, "Format");
	mvaddstr(0, 17, "View");
	mvaddstr(0, 22, "Help");
	attroff(COLOR_PAIR(1));


	//Moving the cursor under the file bar to get ready for typing
	move(2, 2);
	

	//refresh tells 
	refresh();

	//END OF PROGRAM LOGIC GOES HERE

	//pause for user input
	
	char space = ' ';
	cbreak();
	getyx(main_window, y, x);



	//Setting up the special keys.
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	scrollok(main_window, TRUE);
	while (1)
	{
		int input = getch();

		switch (input)
		{
		case KEY_RESIZE:
			resize_term(0, 0);
			break;
		case KEY_UP:
			y--;
			if (y <= 0)
				y = -2;
			wmove(main_window, y, x); 
			break;
		case KEY_DOWN:
			y++;
			
			wmove(main_window, y, x);
			break;
		case KEY_LEFT:
			x--;
			if (x == 0)
				x = 1;
			wmove(main_window, y, x);
			break;
		case KEY_RIGHT:
			x++;
			if (x == num_cols)
				x = num_cols - 3;
			wmove(main_window, y, x);
			break;
		//The Enter key is not working at the moment 
		case KEY_ENTER:
			mvaddch(y, x, '\n');
			y++;
			wmove(main_window, y, x);
			break;

		//The backspace key is not working at the moment
		case KEY_BACKSPACE:
			x -= 1;
			delch();
		move( y, x);
			break;

		case KEY_STAB:
			mvaddch(y, x, ' ');
			x += 5;
			wmove(main_window, y, x);

		case ' ':
			mvaddch(y, x, space);
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

		/*int c = wgetch(main_window);
		switch(c)
		{

		}*/
		wrefresh(main_window);
		//if (input == 10)
			//break;
	}

	//int input = getstr('');


	//end cursor
	endwin();

	return 0;
}