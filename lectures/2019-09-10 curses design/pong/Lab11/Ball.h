#ifndef BALL_H
#define BALL_H

#include "curses.h"
#include "ScreenWidget.h"
#include "RandomNumberGenerator.h"

class Ball : public ScreenWidget
{
private:
	char _representation = '*';
	RandomNumberGenerator _rng;
	int _x_speed = 1;
	bool _move_x_positive = true;
	int _y_speed = 1;
	bool _move_y_positive = true;
	int _x_speed_counter = 0;
	int _y_speed_counter = 0;

public:
	Ball(int x = 0, int y = 0, int max_x = 0, int max_y = 0)
		: ScreenWidget(x, y, max_x, max_y)
	{
		//randomly set x and y speeds
		_x_speed = _rng.getInt(1, 3);
		_y_speed = _rng.getInt(1, 3);
	}

	virtual void render()
	{
		//did we reach a bounds?  If so, switch directions and speed
		if (_x >= _max_x - 1)
		{
			_move_x_positive = false;
			_x_speed = _rng.getInt(1, 3);
			_y_speed = _rng.getInt(1, 3);
		}
		else if (_x <= 0)
		{
			_move_x_positive = true;
			_x_speed = _rng.getInt(1, 3);
			_y_speed = _rng.getInt(1, 3);
		}

		if (_y >= _max_y - 1)
		{
			_move_y_positive = false;
			_x_speed = _rng.getInt(1, 3);
			_y_speed = _rng.getInt(1, 3);
		}
		else if (_y <= 0)
		{
			_move_y_positive = true;
			_x_speed = _rng.getInt(1, 3);
			_y_speed = _rng.getInt(1, 3);
		}

		//is it time to move?
		if (_x_speed_counter > _x_speed)
		{
			_x = _move_x_positive ? _x + 1 : _x - 1;
			_x_speed_counter = 0;
		}
		else
		{
			_x_speed_counter++;
		}
		if (_y_speed_counter > _y_speed)
		{
			_y = _move_y_positive ? _y + 1 : _y - 1;
			_y_speed_counter = 0;
		}
		else
		{
			_y_speed_counter++;
		}

		//finally, render ourselves
		mvaddch(_y, _x, _representation);

	}
};

#endif