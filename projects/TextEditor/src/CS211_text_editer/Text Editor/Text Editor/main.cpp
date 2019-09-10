#define PDC_DLL_BUILD 1
#include <string>
#include "curses.h"

#define WIDTH 30
#define HEIGHT 10
int startx = 0;
int starty = 0;
#include <string>

using namespace std;

int main(int argc, char ** argv)
{
	WINDOW* main_window = nullptr;
	int num_rows = 0;
	int num_cols = 0;

	//intialize screen, begin curses mode 
	main_window = initscr();

	//take up most of the screen 
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);

	// turn off echo
	noecho();
	initscr();
	cbreak();

	//nodelay(main_window, TRUE);[

	curs_set(0);
	
	wborder(main_window, '|', '|', '_', '_', '+', '+', '+', '+'); // sets border
	
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	




	string choices[3] = { "file", "edit", "tools" };
	int choice;
	int highlight = 0;
	refresh();
	wrefresh(main_window);
	keypad(main_window, true); // makes it so we can use arrow keys

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == highlight)
			{
				wattron(main_window, A_REVERSE);
				
				mvwprintw(main_window, i + 1, 1, choices[i].c_str());
				 wattroff(main_window, A_REVERSE);
			}
			
		}
		choice = wgetch(main_window);
		switch (choice)
		{
		case KEY_UP:
				highlight--;
				if (highlight == -1)
				highlight = 0;
				break;
		case KEY_DOWN:
				highlight++;
				if (highlight == 3)
					highlight = 2;

				break;
		default:
				break;
		}
		if (choice == 10)
			break;
	}

	printw("your choice was %s", choices[highlight].c_str());

	//FUN STUFF HAPPENS HERE
	//ACS_CH

	

	
	
	//mvaddstr(2, 2, "file_name"); // adds fil_name to the screen
	
	
	//Tells curses to draw
	refresh();

	//REVERT BACK TO NORMAL CONSOLE MODE
	char result = getch();
	//nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	mvaddstr(0, 0, "PRESS ANY KEY TO CONTINUE...");
	result = getch();
	endwin();

};



