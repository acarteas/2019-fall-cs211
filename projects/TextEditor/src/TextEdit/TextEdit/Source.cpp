#define PDC_DLL_BUILD 1

#include "curses.h"
#include "panel.h"
#include "curspriv.h"

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
	cbreak();
	getyx(main_window, y, x);
	keypad(stdscr, TRUE);

	while (1)
	{
		int input = getch();

		switch (input)
		{
		case KEY_UP:
			y--;
			wmove(main_window, y, x); 
			//wrefresh(main_window);
			break;
		case KEY_DOWN:
			y++;
			wmove(main_window, y, x);
			//wrefresh(main_window);
			break;
		case KEY_LEFT:
			x--;
			wmove(main_window, y, x);
			//wrefresh(main_window);
			break;
		case KEY_RIGHT:
			x++;
			wmove(main_window, y, x);
			//wrefresh(main_window);
			break;
		case KEY_ENTER:
			y++;
			wmove(main_window, y, x);
			break;
		}

		wrefresh(main_window);
	}

	//end cursor
	endwin();

	return 0;
}