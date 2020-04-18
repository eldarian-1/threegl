#include <glut.h>
#include <stdio.h>

#include "Button.h"
#include "AppFunc.h"

void Button::draw()
{
	drawQuad(color, x1, y1, x2, y2);

	int size = strlen(this->text);

	int x = x1 + (x2 - x1 - size * 10) / 2;
	int y = y2 - (y2 - y1 - 20) / 1.5;

	GLfloat color[] = { 0, 0, 0 };
	drawText(color, text, x, y);
}

void Button::onClick(int x, int y)
{
	printf("Button: onClick on x: %d, y: %d\n", x, y);
	this->func();
}

bool Button::isFocused(int x, int y)
{
	return (x >= this->x1 && x <= this->x2 && y >= this->y1 && y <= this->y2);
}

void Button::onFocused(int x, int y)
{
	printf("Button: onFocused on x: %d, y: %d\n", x, y);
}

void Button::onMouseLeftDown(int x, int y)
{
	printf("Button: onMouseLeftDown on x: %d, y: %d\n", x, y);
}

void Button::onMouseLeftUp(int x, int y)
{
	printf("Button: onMouseLeftUp on x: %d, y: %d\n", x, y);
}

void Button::onMouseRightDown(int x, int y)
{
	printf("Button: onMouseRightDown on x: %d, y: %d\n", x, y);
}

void Button::onMouseRightUp(int x, int y)
{
	printf("Button: onMouseRightUp on x: %d, y: %d\n", x, y);
}