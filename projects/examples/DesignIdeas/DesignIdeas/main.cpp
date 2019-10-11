#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include "UiComponents/Label.hpp"
#include "UiComponents/UiComponent.hpp"
#include "UiComponents/TextBox.hpp"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define ctrl(x)           ((x) & 0x1f)

void draw_centered(WINDOW* win, int max_y, int max_x, string text);

int main(void)
{
	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	//SETUP
	//initialize our window
	main_window = initscr();

	//resize our window
	resize_term(5000, 5000);
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);

	//turn keyboard echo
	noecho();

	cbreak();

	wclear(main_window);
	wrefresh(main_window);

	//turn on keypad input
	keypad(main_window, TRUE);

	//hide the cursor
	curs_set(FALSE);

	//MAIN PROGRAM LOGIC GOES HERE

	//pause for user input
	bool keep_going = true;
	vector<CursesUi::UiComponent*> components{};
	Interactable* active_component = nullptr;
	components.push_back(
		new CursesUi::Label{main_window, 1, 7, 0, 0, "Label 1"}
	);
	components.push_back(
		new CursesUi::Label{ main_window, 0, 5, "Label 2" }
	);
	components.push_back(
		new CursesUi::TextBox{ main_window, 40, 10, 2, 0 }
	);
	active_component = dynamic_cast<Interactable*>(components[2]);
	while (keep_going == true)
	{

		//render components
		for (auto& component : components)
		{
			//TODO: render
			if (component->needsRefresh() == true)
			{
				component->render();
				component->refresh();
			}
		}
		
		int input = wgetch(main_window);

		//Curses documentation says to use KEY_RESIZE, but you can also use
		//is_termresized.  In real life, use either/or but not both.
		if (is_termresized() == true)
		{
			resize_term(0, 0);
			getmaxyx(main_window, num_rows, num_cols);
		}
		switch (input)
		{
		case ctrl('c'):
			keep_going = false;
		case KEY_RESIZE:
			resize_term(0, 0);
			getmaxyx(main_window, num_rows, num_cols);
		}
		
		if (active_component != nullptr)
		{
			active_component->handleKeyboardInput(input);
		}
	}

	//end of program, grab screen state
	vector<vector<int>> screen_data{};
	for (int i = 0; i < num_rows; i++)
	{
		screen_data.push_back(vector<int>{});
		screen_data[i].resize(num_cols);
	}

	//grab all content from my UI components
	for (auto component : components)
	{
		for (int i = 0; i < component->getHeight(); i++)
		{
			for (int j = 0; j < component->getWidth(); j++)
			{
				screen_data[component->getY() + i][component->getX() + j] 
					= component->getCharAtLocation(i, j);
			}
		}
	}

	//end curses mode
	endwin();
}

void draw_centered(WINDOW* win, int max_y, int max_x, string text)
{
	int length = text.length();
	int left_margin = (max_x - length) / 2;
	int top_margin = (max_y - 1) / 2;
	mvwprintw(win, top_margin, left_margin, text.c_str());
}