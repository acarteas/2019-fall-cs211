#pragma once
#ifndef LABEL_HPP
#define LABEL_HPP
#include "UiComponent.hpp"
#include <string>
using std::string;

namespace CursesUi
{
	class Label : public UiComponent
	{
	protected:
		string _text;

	public:

		//Note: curses does things backwards.  Keep
		//with that standard
		Label(int y = 0, int x = 0, string text = "")
		{
			_y = y;
			_x = x;
			_text = text;
		}

		Label(string text)
		{
			_text = text;
		}

		string getText() const
		{
			return _text;
		}

		string& getText()
		{
			return _text;
		}

		void setText(const string& text)
		{
			_text = text;
		}
	};
}

#endif