#pragma once
#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
#include "UiComponent.hpp"
#include "Interactable.hpp"
#include <string>
using std::string;

namespace CursesUi
{
	class TextBox : public UiComponent, public Interactable
	{
	protected:
		string _text;

	public:

		//Note: curses does things backwards.  Keep
		//with that standard
		TextBox(WINDOW* parent = 0,
			int height = 0,
			int width = 0,
			int y = 0,
			int x = 0,
			string text = "")
			: UiComponent(parent, height, width, y, x),
			_text(text)
		{
		}

		TextBox(WINDOW* parent = 0,
			int y = 0,
			int x = 0,
			string text = "")
			: UiComponent(parent, 1, text.length(), y, x),
			_text(text)
		{
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

		virtual void render()
		{
		}

		virtual void handleKeyboardInput(wchar_t input)
		{
			waddch(_canvas, input);
			_needs_refresh = true;
		}

		virtual void handleMouseInput(int y, int x, MouseClick click_type)
		{
			if (click_type == MouseClick::LEFT_CLICK)
			{
				wmove(_canvas, y, x);
			}
		}
	};
}

#endif