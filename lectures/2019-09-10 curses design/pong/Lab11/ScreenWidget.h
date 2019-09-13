#ifndef SCREEN_WIDGET_H
#define SCREEN_WIDGET_H

class ScreenWidget
{
protected:
	int _x;
	int _y;
	int _max_x;
	int _max_y;

public:
	ScreenWidget(int x = 0, int y = 0, int max_x = 0, int max_y = 0)
	{
		_x = x;
		_y = y;
		_max_x = max_x;
		_max_y = max_y;
	}

	int getX() const
	{
		return _x;
	}

	int getY() const
	{
		return _y;
	}

	virtual void render() = 0;
};

#endif