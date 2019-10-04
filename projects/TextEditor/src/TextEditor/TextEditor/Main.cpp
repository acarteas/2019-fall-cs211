
#define PDC_DLL_BUILD 1
#include <fstream>
#include "curses.h"
#include <string>
#include <vector>

using namespace std;


void drawText(WINDOW* win, vector<char> &vect, const int term_rows, const int term_cols, int start); // Displays  contents of vector in main window and get length
void get_curs_pos(WINDOW* get, WINDOW* write, int rows); // Writes cursor's y and x position

int main(int argc, char* argv[]) {

	


	initscr();
	noecho();
	keypad(stdscr, TRUE);




	// Main terminal
	WINDOW* win = stdscr;

	// Terminal dimensions
	const int term_rows = getmaxy(win);
	const int term_cols = getmaxx(win);

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

	// Arrow key usage 
	keypad(mWin, TRUE);
	keypad(topWin, TRUE);
	keypad(botWin, TRUE);
	keypad(rsWin, TRUE);

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
	ofstream output;
	input >> noskipws;
	vector<char> fyle{};

	// Checks if file name is valid
	if (input.is_open() == false) {
		mvwprintw(mWin, 10, 10, "Invalid file name, could not open");
		wrefresh(mWin);
	}

	// Reads file to a vector
	if (input.is_open() == true) {
		
		while (input.good() == true) {
			char letter;
			input >> letter;
			fyle.push_back(letter);

		}
	}





	
	
	int start = 0;
	int fyle_rows = fyle.size() / 114; // Fle rows
	int row_num = 1; // Starting row num

	mvwprintw(botWin, 1, 16, "%d", fyle_rows);
	mvwprintw(botWin, 1, 1, "Number of rows:");
	get_curs_pos(mWin, botWin, row_num);
	
	drawText(mWin, fyle, term_rows, term_cols, start); // Draws text to screen

	int vect_pos = -1; // Position of cursor in vector
	int key_x_pos = 0; // Position of writing
	int key_y_pos = 0; // Position of writing
	
	// Cursor position and key grab
	int curs_x_pos = 0;
	int curs_y_pos = 0;
	
	int key;
	key = wgetch(mWin);
	
	while (key != KEY_F(8)) {

		// Experimental

		mvwprintw(botWin, 1, 47, "%d", vect_pos);
		wrefresh(botWin);
























		wmove(mWin, curs_y_pos, curs_x_pos); // Write new position of cursor
		get_curs_pos(mWin, botWin, row_num); // Write coordinates of cursor in bottom window
		wrefresh(mWin); // Refreshes main window
		
		key = wgetch(mWin);

		// If key is valid input
		if (key >= 32
			&& key <= 126 
			|| key == 10
			|| key == 8) {
			
			// Checks if enter has been pressed and starts new line
			if (key == 10) {
				curs_y_pos += 1;
				curs_x_pos = 0;
				vect_pos += 115;
				continue;
			}

				// Checks if backspace was entered
				if (key == 8) {
					if (curs_x_pos == 0 && curs_y_pos > 0) {
						curs_y_pos--;
						curs_x_pos = term_cols - 4;
					}
						if (curs_x_pos > 0) {
							curs_x_pos--;
							mvwaddch(mWin, curs_y_pos, curs_x_pos, 32);
						}
					continue;
				}
			
		// Prints typed char and updates for next position
		mvwprintw(mWin, curs_y_pos, curs_x_pos, "%c", key);
		curs_x_pos++;
		vect_pos++;
		
			output.open ("Edited.txt");
			fyle[vect_pos] = key;
			for (int i = 0; i < fyle.size(); i++) {
				output << fyle[i];

			}
			output.close();
		}
		
		// Movement of cursor with arrow keys
		switch (key) {
		case KEY_UP:
			if (curs_y_pos == 0 && start > 0) {
				start -= term_cols - 4;
				drawText(mWin, fyle, term_rows, term_cols, start);
				row_num--;
			}
			if (curs_y_pos > 0) {
				curs_y_pos--;
				vect_pos -= 116;
				row_num--;
			}
			break;
		case KEY_DOWN:
			if (curs_y_pos == term_rows - 7 && row_num < fyle_rows) {
				start += term_cols - 4;
				vect_pos += 116;
				curs_y_pos = term_rows - 7;
				drawText(mWin, fyle, term_rows, term_cols, start);
				row_num++;
			}
			if (curs_y_pos < term_rows - 7) {
				curs_y_pos++;
				vect_pos += 116;
				row_num++;
			}
			break;
		case KEY_RIGHT:
			if (curs_x_pos < term_cols - 4) {
				curs_x_pos++;
				vect_pos++;
			}
			break;
		case KEY_LEFT:
			if (curs_x_pos > 0) {
				curs_x_pos--;
				vect_pos--;
			}
			break;
		
		default:
			break;
		}
		
	}
	endwin();

return 0;

}



void drawText(WINDOW* win, vector<char>& vect, const int term_rows, const int term_cols, int start) {
	
	int x = 0;
	int y = 0;
	int file_pos = start;
	int file_end = (term_cols - 4) * (term_rows - 6) + file_pos - 2;

	if (file_pos < vect.size()) {

		for (file_pos; file_pos < file_end; file_pos++) {

			// Word wraps when text reaches edge
			if (x == term_cols - 4) {
				y++;
				x = 0;
			}

			// If all is normal print char and advance 1 position
			if (file_pos < vect.size() && file_pos >= 0) {
				mvwaddch(win, y, x, vect[file_pos]);
				x++;
			
			}
			
			// Print blank char
			else {
				mvwaddch(win, y, x, 32);
				x++;
			}

		}

	}
	wrefresh(win);
}

void get_curs_pos(WINDOW* get, WINDOW* write, int rows) {
	
	int cursor_x_pos;
	int cursor_y_pos;
	getyx(get, cursor_y_pos, cursor_x_pos);

	// X position
	mvwprintw(write, 1, 22, "X:"); 
	mvwprintw(write, 1, 24, "%d", cursor_x_pos);

	// Y position
	mvwprintw(write, 1, 27, "Y:");
	mvwprintw(write, 1, 29, "%d", cursor_y_pos);

	// Row number
	mvwprintw(write, 1, 32, "Row:");
	mvwprintw(write, 1, 36, "%d", rows);
	

	wrefresh(write);

	//Blank spaces
	mvwaddch(write, 1, 25, 32);
	mvwaddch(write, 1, 26, 32);
	mvwaddch(write, 1, 30, 32);
	mvwaddch(write, 1, 37, 32);

}

