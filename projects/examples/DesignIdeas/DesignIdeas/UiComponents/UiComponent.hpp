#pragma once
#ifndef UI_COMPONENT_HPP
#define UI_COMPONENT_HPP

namespace CursesUi
{

	class UiComponent
	{
	protected:
		int _x = 0;
		int _y = 0;
		int _width = 0;
		int _height = 0;
		bool _has_focus = false;

		//Idea: perhaps make the component aware of
		//it's owner

	public:
		int getX() const
		{
			return _x;
		}

		int getY() const
		{
			return _y;
		}

		int getWidth() const
		{
			return _width;
		}

		int getHeight() const
		{
			return _height;
		}

		bool hasFocus() const
		{
			return _has_focus;
		}

		void setX(int x)
		{
			_x = x;
		}

		void setY(int y)
		{
			_y = y;
		}

		void setHeight(int h)
		{
			_height = h;
		}

		void setWidth(int w)
		{
			_width = w;
		}

		virtual void setHasFocus(bool f)
		{
			_has_focus = f;
		}
	};
}
#endif