#ifndef PADDLE_H
#define PADDLE_H

#include "curses.h"
#include "ScreenWidget.h"

class Paddle : public ScreenWidget
{
protected:
	int _width;
	int _height;

public:
	Paddle(int x = 0, int y = 0, int max_x = 0, int max_y = 0, int width = 2, int height = 10)
		: ScreenWidget(x, y, max_x, max_y)
	{
		_width = width;
		_height = height;
	}

	int getHeight() const
	{
		return _height;
	}

	int getWidth() const
	{
		return _width;
	}

	void moveDown()
	{
		_y++;
	}

	void moveUp()
	{
		_y--;
	}

	virtual void render()
	{
		for (int i = 0; i < _height; i++)
		{
			for (int j = 0; j < _width; j++)
			{
				mvaddch(i + _y, j + _x, 219);
			}
		}
	}
};

#endif