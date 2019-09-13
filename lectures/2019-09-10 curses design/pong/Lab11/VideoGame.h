#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H

#include "curses.h"
#include <Windows.h>
#include <string>
using namespace std;
class VideoGame
{
private:
	void clearScreen()
	{
		wclear(_game_window);
	}

protected:
	bool _game_over = false;
	const int NUM_ROWS = 50;
	const int NUM_COLS = 100;

	//be sure to update this message based on win condition
	string _end_game_message = "Game over. You lose...";
	virtual void drawPieces() = 0;
	WINDOW *_game_window = nullptr;
	
public:

	VideoGame()
	{
		//start curses mode
		_game_window = initscr();
		resize_term(NUM_ROWS, NUM_COLS);
		nodelay(_game_window, TRUE);

		noecho();
		cbreak();

		//hide cursor
		curs_set(FALSE);
	}

	~VideoGame()
	{
		//end curses mode
		endwin();
	}

	void playGame()
	{
		while (_game_over == false)
		{
			DWORD start = GetTickCount();

			clearScreen();
			drawPieces();
			refresh();
			
			//ensures good frame rate
			for (DWORD end = GetTickCount(); end - start < 5; end = GetTickCount())
			{
				//sleep
			}
		}

		nodelay(_game_window, FALSE);
		mvaddstr(49, 0, _end_game_message.c_str());
		char result = getch();
	}
};

#endif