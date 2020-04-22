#pragma once

#include "View.h"

struct Control
{
	int x1, y1, x2, y2;
	const char* text;
	void (*func)();
};

class Button : public View
{
private:
	int x1, y1, x2, y2;
	const char* text;
	void (*func)();
	bool isFocus;

public:
	Button(Control btn)
		: x1(btn.x1), y1(btn.y1), x2(btn.x2), y2(btn.y2), text(btn.text), func(btn.func), isFocus(false) {}

	void draw();

	void isFocused(int, int, void (View::*)(int, int) = nullptr);
	void onFocused();
	void onUnfocused();
	void onClick(int, int);
	void onMouseLeftDown(int, int);
	void onMouseLeftUp(int, int);
	void onMouseRightDown(int, int);
	void onMouseRightUp(int, int);

};