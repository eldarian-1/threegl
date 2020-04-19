#include "Button.h"

void Button::draw()
{
	GLfloat* color = new GLfloat[3]{0.0, 0.0, 0.0};
	drawQuad(color, x1, y1, x2, y2);

	if (isFocus)
	{
		color[0] = 0.9;
		color[1] = color[2] = 1.0;
	}
	else
		color[0] = color[1] = color[2] = 0.9;
	drawQuad(color, x1+1, y1+1, x2-1, y2-1);

	int size = strlen(this->text);

	int x = x1 + (x2 - x1 - size * 10) / 2;
	int y = y2 - (y2 - y1 - 20) / 1.5;

	color[0] = color[1] = color[2] = 0.5;
	drawText(color, this->text, x, y);
}

void Button::onClick(int x, int y)
{
	//printf("Button: onClick on x: %d, y: %d\n", x, y);
	this->func();
}

bool Button::isFocused(int x, int y)
{
	return (x >= this->x1 && x <= this->x2 && y >= this->y1 && y <= this->y2);
}

void Button::onFocused(int x, int y)
{
	isFocus = true;
	//printf("Button: onFocused on x: %d, y: %d\n", x, y);
}

void Button::onUnfocused()
{
	isFocus = false;
	//printf("Button: onFocused on x: %d, y: %d\n", x, y);
}

void Button::onMouseLeftDown(int x, int y)
{
	//printf("Button: onMouseLeftDown on x: %d, y: %d\n", x, y);
}

void Button::onMouseLeftUp(int x, int y)
{
	//printf("Button: onMouseLeftUp on x: %d, y: %d\n", x, y);
}

void Button::onMouseRightDown(int x, int y)
{
	//printf("Button: onMouseRightDown on x: %d, y: %d\n", x, y);
}

void Button::onMouseRightUp(int x, int y)
{
	//printf("Button: onMouseRightUp on x: %d, y: %d\n", x, y);
}