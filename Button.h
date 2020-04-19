#pragma once

#include "View.h"

class Button : public View
{
private:
	int x1, y1, x2, y2;
	const char* text;
	void (*func)();
	bool isFocus;

public:
	Button(int _x1, int _y1, int _x2, int _y2, const char* _text, void (*_func)())
		: x1(_x1), y1(_y1), x2(_x2), y2(_y2), text(_text), func(_func), isFocus(false) {}

	void draw();
	void onClick(int, int);
	bool isFocused(int, int);
	void onFocused(int, int);
	void onUnfocused();
	void onMouseLeftDown(int, int);
	void onMouseLeftUp(int, int);
	void onMouseRightDown(int, int);
	void onMouseRightUp(int, int);

};