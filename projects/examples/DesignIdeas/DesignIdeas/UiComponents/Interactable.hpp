#pragma once
#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

enum class MouseClick {
	LEFT_CLICK,
	RIGHT_CLICK
};

class Interactable
{
public:
	virtual void handleKeyboardInput(wchar_t input) = 0;
	virtual void handleMouseInput(int y, int x, MouseClick click_type) = 0;
};

#endif // !INTERACTABLE_HPP
