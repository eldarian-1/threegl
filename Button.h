#pragma once

#include "View.h"

class Button : public View
{
private:
	int x1, y1, x2, y2;
	const char* text;
	void (*func)();
	GLfloat* color;

public:
	Button(int _x1, int _y1, int _x2, int _y2, const char* _text, void (*_func)(), GLfloat* _color = nullptr)
		: x1(_x1), y1(_y1), x2(_x2), y2(_y2), text(_text), func(_func), color(_color)
	{
		if (color == nullptr)
			this->color = new GLfloat[3]{ 0.9,0.9,0.9 };
	}

	void draw();
	void onClick(int, int);
	bool isFocused(int, int);
	void onFocused(int, int);
	void onMouseLeftDown(int, int);
	void onMouseLeftUp(int, int);
	void onMouseRightDown(int, int);
	void onMouseRightUp(int, int);

};