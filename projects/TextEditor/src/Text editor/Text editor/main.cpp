#define PDC_DLL_BUILD 1
#include "curses.h"
#include <string>
using namespace std;


int main(void)
{
	WINDOW* main_window = nullptr;
	int num_rows = 0;
	int num_cols = 0;

	// initialize screen, begin curses mode
	main_window = initscr();

	//take up most of screen
	getmaxyx(main_window, num_rows, num_cols); 
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);

	//tuen key echo off
	noecho();
	//nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	curs_set(0);

	//Fun here
	for (int i = 0; i < num_cols; i++)
	{
		mvaddch(0, i, 219);
	}
	for (int i = 0; i < num_rows;i++)
	{
		//left colum
		mvaddch(i, 0, 219);
		//right colum
		mvaddch(i, num_cols - 1, 219);
	}
	//tels curs to draw
	refresh();
	char result = getch();


	//revert to normal mode
	nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	mvaddstr(0, 0, "Press any key to continue..");
	char result = getch();
	endwin();



}