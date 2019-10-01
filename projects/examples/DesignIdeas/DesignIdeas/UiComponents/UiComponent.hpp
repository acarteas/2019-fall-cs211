#pragma once
#ifndef UI_COMPONENT_HPP
#define UI_COMPONENT_HPP

#if _WIN32
#include "../curses.h"
#else
#include <curses.h>
#endif

namespace CursesUi
{

	class UiComponent
	{
	protected:
		WINDOW* _canvas = nullptr;
		int _x = 0;
		int _y = 0;
		int _width = 0;
		int _height = 0;
		bool _has_focus = false;
		bool _needs_refresh = true;

		//Idea: perhaps make the component aware of
		//it's owner

	public:

		UiComponent(WINDOW* parent = 0, 
					int height = 0, 
					int width = 0, 
					int y = 0, 
					int x = 0)
			: _canvas(parent), 
			  _height(height),
			  _width(width),
			  _y(y),
			  _x(x)
		{
			if (parent != nullptr)
			{
				//              WINDOW, # rows, #cols, offset-y, offset-x 
				_canvas = derwin(parent, height, width, y, x);
			}
			
		}

		int getCharAtLocation(int y, int x)
		{
			return mvwinch(_canvas, y, x);
		}

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

		bool needsRefresh() const
		{
			return _needs_refresh;
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

		virtual void render() = 0;

		virtual void refresh()
		{
			if (_canvas != nullptr)
			{
				wrefresh(_canvas);
				_needs_refresh = false;
			}
		}
	};
}
#endif