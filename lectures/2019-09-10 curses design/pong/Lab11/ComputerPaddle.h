#ifndef COMPUTER_PADDLE_H
#define COMPUTER_PADDLE_H

#include "Paddle.h"
#include "Ball.h"

class ComputerPaddle : public Paddle
{
private:
	Ball *_ball_ptr = nullptr;

public:

	ComputerPaddle(Ball *ball = nullptr, int x = 0, int y = 0, int max_x = 0, int max_y = 0, int width = 2, int height = 10)
		: Paddle(x, y, max_x, max_y, width, height)
	{
		_ball_ptr = ball;
	}

	virtual void render()
	{

		if (_ball_ptr != nullptr)
		{
			//try to move towards the ball
			if (_ball_ptr->getY() > _y && _y + _height < _max_y)
			{
				_y++;
			}
			else if (_ball_ptr->getY() < _y && _y > 0)
			{
				_y--;
			}
		}

		Paddle::render();
	}
};

#endif