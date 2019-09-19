
#define PDC_DLL_BUILD 1
#include <fstream>
#include "curses.h"
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

	


	initscr();
	noecho();
	keypad(stdscr, TRUE);


	// Main terminal
	WINDOW* win = stdscr;

	// Terminal dimensions
	int term_rows = getmaxy(win);
	int term_cols = getmaxx(win);

	// Main window dimensions

	int mHeight = term_rows - 6;
	int mWidth = term_cols - 3;
	int mStart_y = 3;
	int mStart_x = 0;

	// Top window dimensions
	int tHeight = 3;
	int tWidth = term_cols;
	int tStart_y = 0;
	int tStart_x = 0;

	// Bottom window dimensions
	int bHeight = 3;
	int bWidth = term_cols;
	int bStart_y = term_rows - 3;
	int bStart_x = 0;

	// Right side window dimensions

	int rsHeight = term_rows - 4;
	int rsWidth = 3;
	int rsStart_y = 2;
	int rsStart_x = term_cols - 3;

	// Window creations
	WINDOW* mWin = newwin(mHeight, mWidth, mStart_y, mStart_x);
	WINDOW* topWin = newwin(tHeight, tWidth, tStart_y, tStart_x); // Top window
	WINDOW* botWin = newwin(bHeight, bWidth, bStart_y, bStart_x); // Bottom window
	WINDOW* rsWin = newwin(rsHeight, rsWidth, rsStart_y, rsStart_x); // Right side window


	refresh();

	// Creates box for each window
	box(topWin, 0, 0);
	box(botWin, 0, 0);
	box(rsWin, 0, 0);


	// Printing border text
	//mvwprintw(win, 10, 10,"yesh");
	mvwprintw(topWin, 1, term_cols / 2 - 14, "|File|	|Edit|	|Save|");
	mvwprintw(botWin, 1, term_cols / 2 - 5, "Word Count:");
	mvwprintw(botWin, 1, term_cols - 17, " |'F8' to quit|");



	// Refreshing windows
	wrefresh(topWin);
	wrefresh(botWin);
	wrefresh(rsWin);

	
	
	// Loads specified file from command line in to a vector
	ifstream input (argv[1]);
	vector<string> file{};

	// Checks if file name is valid
	if (input.is_open() == false) {
		mvwprintw(mWin, 10, 10, "Invalid file name, could not open");
		wrefresh(mWin);
	}

	// Reads file to a vector
	if (input.is_open() == true) {
	
		/*mvwprintw(mWin, 10, 10, "input is open");
		wrefresh(mWin);*/
		
		while (input.good() == true) {
			string line;
			getline(input, line);
			file.push_back(line);

		}
	}

	// Displays  contents of vector in main window
	int x_pos = 0;
	int y_pos = 0;
	for (int i = 0; i < term_rows - 8 ; i++) {
		
		mvwaddstr(mWin, y_pos, x_pos, file[i].c_str());
		
		y_pos += 1;

		wrefresh(mWin);
	}
	

	
	int key_x_pos = 1; // Position of writing
	int key_y_pos = 1; // Position of writing
	
	int ch;
	ch = wgetch(mWin);

	// Writes user input to screen
	while (ch != KEY_F(8)) {
		
		// Checks if enter has been pressed and starts new line
		if (ch == 10) {
			key_y_pos += 1;
			key_x_pos = 0;
		
		}

		// Checks if line has reached edge of terminal and starts a new line
		if (key_x_pos == term_cols - 3) {
			key_y_pos += 1;
			key_x_pos = 1;
		}

		// Prints typed char and updates for next position
		mvwprintw(mWin, key_y_pos, key_x_pos, "%c", ch);
		key_x_pos += 1;
		wrefresh(mWin);
		
		ch = wgetch(mWin);
	}
	

	endwin();


	return 0;

}

