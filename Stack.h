#pragma once

#include "Button.h"

struct NodeStack
{
	View* data;
	NodeStack* pLow;
};

class Stack
{
private:
	NodeStack* pTop;

public:
	Stack() : pTop(nullptr) {}
	void add(View*);
	void draw();

	void onMouseMoveAll(int, int);
	void onMouseLeftDownAll(int, int);
	void onMouseLeftUpAll(int, int);
	void onClickAll(int, int);
	void onMouseRightDownAll(int, int);
	void onMouseRightUpAll(int, int);
};
