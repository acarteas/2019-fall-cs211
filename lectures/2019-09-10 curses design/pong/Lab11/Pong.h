#ifndef PONG_H
#define PONG_H
#include "VideoGame.h"
#include "ComputerPaddle.h"
#include "Ball.h"
class Pong : public VideoGame
{
private:
	Ball _game_ball;
	Paddle _left_paddle;
	ComputerPaddle _right_paddle;

protected:
	virtual void drawPieces()
	{
		_game_ball.render();
		_left_paddle.render();
		_right_paddle.render();
		char user_input = getch();
		if (user_input != ERR)
		{
			switch (user_input)
			{
			case 'a':
				_left_paddle.moveUp();
				break;

			case 'z':
				_left_paddle.moveDown();
				break;

			}
		}

		//detect collisions
		if (_game_ball.getX() <= 0)
		{
			//check player paddle
			if (_game_ball.getY() < _left_paddle.getY())
			{
				_game_over = true;
			}
			else if (_game_ball.getY() > _left_paddle.getY() + _left_paddle.getHeight())
			{
				_game_over = true;
			}
		}

		if (_game_ball.getX() >= NUM_COLS - 1)
		{
			//check computer paddle
			if (_game_ball.getY() < _right_paddle.getY())
			{
				_game_over = true;
				_end_game_message = "Game over.  You win!";
			}
			else if (_game_ball.getY() > _right_paddle.getY() + _right_paddle.getHeight())
			{
				_game_over = true;
				_end_game_message = "Game over.  You win!";
			}
		}
	}

public:
	Pong()
	{
		_game_ball = Ball{ 0, 0, NUM_COLS, NUM_ROWS };
		_left_paddle = Paddle{0, 0, NUM_COLS, NUM_ROWS };
		_right_paddle = ComputerPaddle{ &_game_ball, NUM_COLS - 2, 0, NUM_COLS, NUM_ROWS };
	}

};

#endif