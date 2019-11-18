#define PDC_DLL_BUILD 1

#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <map>
#include "TrieNode.h"
#include "Trie.h"

using namespace std;

typedef map<string, int> strInMap;
int num_cols = 0;
int num_rows = 0;
int y, x;
int _y, _x;

WINDOW* main_window = nullptr;
WINDOW* character_window = nullptr;

void check_cursor(int _y, int _x);
void countWords(istream& in, strInMap& words);
int decimaltoBinary(int num);
void set_boarder();

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
	vector<char> fileVec{};

	// Checks if file name is valid
	if (input.is_open() == false) {
		mvaddstr(y, x, "Unable to open the file!\n");
		x++;
		wmove(main_window, y, x);
		wrefresh(main_window);
	}
	vector <string> temp;
	// Reads file to a vector
	if (input.is_open() == true)
	{
		char letter;
		
		while (input.good() == true)
		{
			input >> letter;
			fileVec.push_back(letter);
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
		wmove(main_window, y, x);
		mvaddstr(y, x, "Uable to open the file!");
		x += 24;
		wmove(main_window, y, x);
		wrefresh(main_window);
	}

	//creating a vector of strings to store data from my file
	vector <string> strVec;

	//Reading the keywords file and saving it to a vector of strings
	if (input.is_open() == true)
	{
		while (input.good() == true)
		{
			string word;
			getline(input, word);
			strVec.push_back(word);
		}
	}
	//Closing the file after im done reading it
	input.close();

	//opening the keywords.txt file to read it into a vector of strings
	ifstream infile;
	infile.open("words2.txt");

	strInMap w;
	countWords(infile, w);
	//Checking to see if the file opened correctly
	if (infile.is_open() == false)
	{
		wmove(main_window, y, x);
		mvaddstr(y, x, "Unabl to open the file!");
		x += 24;
		wmove(main_window, y, x);
		wrefresh(main_window);
	}
	ofstream o;
	o.open("words2.frequency.txt");
	for (strInMap::iterator p = w.begin(); p != w.end(); p++)
	{
		o << p->first << ": " << p->second << '\n';
	}
	
	//creating a vector to put all the data into
	vector<int> tempVec;
	for (strInMap::iterator p = w.begin(); p != w.end(); p++)
	{
		tempVec.push_back(p->second);
	}

	//creating a max heap to convert to binary later

	
	vector<string> tempstr;
	//Reading the keywords file and saving it to a vector of strings
	if (infile.is_open() == true)
	{
		while (input.good() == true)
		{
			string word;
			getline(input, word);
			tempstr.push_back(word);
		}
	}
	input.close();

	//creating a trie
	Trie myTrie;
	
	//looping and adding every word from the file to my trie
	for (int i = 0; i < strVec.size(); i++)
	{
		myTrie.addWord(strVec[i]);
	}

	ofstream out_file;
	out_file.open("sample.txt");
	for (int i = 0; i < fileVec.size()-1; i++)
	{
		out_file << fileVec[i];
		mvaddch(y, x, fileVec[i]);
		x++;
	}
	

	int highlight = 1;
	vector<string> choices{};
	//Setting up the special keys.
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	scrollok(main_window, TRUE);
	
	while (1)
	{

		int input = wgetch(main_window);
		string str;
		
		if (main_window != nullptr)
		{
			switch (input)
			{
			case ' ':
				str = str.empty();
				mvaddch(y, x, ' ');
				x++;
				out_file << ' ';
			case KEY_MOUSE:
				break;
			case KEY_RESIZE:
				cbreak();
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
				if (x == 0)
					y--;
				delch();
				mvaddch(y, x, '\b');
				mvwdelch(main_window, y, x);
				wrefresh(main_window);
				//out_file.tellp();
				//out_file.seekp(-1);
				//out_file.write("", 1);
				if (y < 2)
				{
					y = 2;
				}
				break;
			case KEY_ENTER:
				y++;
				x = 0;
				break;
			case KEY_EXIT: case 27:
				exit(1);
			case ALT_0:
			
				mvaddstr(y, x,str.c_str());
				/*choices = myTrie.search(str);
				character_window = initscr();
				character_window = newwin(choices.size(), 15, y + 1, x + 1);
				wrefresh(character_window);
				box(character_window, 0, 0);
				_y = 1;
				_x = 1;

				/*wmove(character_window, _y, _x);
				for (int i = 0; i < choices.size(); i++)
				{
					mvwprintw(character_window, _y, _x, choices[i].c_str());
					_y++;
				}
				
					for (int i = 1; i < choices.size(); i++)
					{
						curs_set(FALSE);
						keypad(character_window, TRUE);
						if (_y == i)
						{
							wattron(character_window, A_REVERSE);
							mvwprintw(character_window, _y, _x, choices[i].c_str());
							wattroff(character_window, A_REVERSE);
						}
						choice = wgetch(character_window);
						switch (choice)
						{
						case KEY_UP:
							_y--;
							break;
						case KEY_DOWN:
							_y++;
							break;
						case KEY_ENTER:
							delwin(character_window);
						}
					}*/

	
			default:
				waddch(main_window, input);
				x++;
				out_file << (char)input;
				str = str + (char)input;
				break;
				}
			wrefresh(main_window);
		}
	}
	out_file.close();


	//end cursor
	endwin();

	return 0;
}

void check_cursor(int _y, int _x)
{
	if (x <= 2)
		x = 2;
	else if (y <= 2)
		y = 2;
}

void countWords(istream& in, strInMap& words)
{
	string s;
	while (in >> s)
	{
		words[s]++;
	}
}

int decimaltoBinary(int num)
{
	int binary = 0;
	int i = 1;

	while (num > 0)
	{
		binary += (num % 2) * i;
		num = num / 2;
		i *= 10;
	}
	return binary;
}

void set_boarder()
{
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