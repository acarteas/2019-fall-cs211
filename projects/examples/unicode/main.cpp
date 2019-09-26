#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#define ctrl(x)           ((x) & 0x1f)

void draw_centered(WINDOW* win, int max_y, int max_x, string text);

int main(void)
{
	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	//SETUP
	//initialize our window
	main_window = initscr();

	//resize our window
	resize_term(5000, 5000);
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);

	//turn keyboard echo
	noecho();

	cbreak();

	//turn on keypad input
	keypad(main_window, TRUE);

	//hide the cursor
	curs_set(FALSE);

	//MAIN PROGRAM LOGIC GOES HERE

	//pause for user input
	bool keep_going = true;

	//open unicode-compatible file w stands for "wide" or unicode 
	wofstream output_file{ "output.txt" };

	while (keep_going == true)
	{
		refresh();

		//Note: 
		wchar_t input = wgetch(main_window);

		switch (input)
		{
		case ctrl('c'):
			keep_going = false;
		default:
			mvwaddch(main_window, 0, 0, input);
			output_file << input;
		}
	}
	//end curses mode
	endwin();

	output_file.close();
}

void draw_centered(WINDOW* win, int max_y, int max_x, string text)
{
	int length = text.length();
	int left_margin = (max_x - length) / 2;
	int top_margin = (max_y - 1) / 2;
	mvwprintw(win, top_margin, left_margin, text.c_str());
}