#pragma once

class View
{
public:
	virtual void draw() = 0;
	virtual void onClick(int, int) = 0;
	virtual bool isFocused(int, int) = 0;
	virtual void onFocused(int, int) = 0;
	virtual void onMouseLeftDown(int, int) = 0;
	virtual void onMouseLeftUp(int, int) = 0;
	virtual void onMouseRightDown(int, int) = 0;
	virtual void onMouseRightUp(int, int) = 0;
};