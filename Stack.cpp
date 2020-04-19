#include <glut.h>

#include "Stack.h"
#include "View.h"

void Stack::add(View* data)
{
	if (this->pTop != nullptr)
	{
		NodeStack* temp = this->pTop;
		while (temp->pLow != nullptr)
			temp = temp->pLow;
		temp->pLow = new NodeStack;
		temp->pLow->data = data;
		temp->pLow->pLow = nullptr;
	}
	else
	{
		this->pTop = new NodeStack;
		this->pTop->data = data;
		this->pTop->pLow = nullptr;
	}
}

void Stack::draw()
{
	NodeStack* temp = this->pTop;
	while (temp != nullptr)
	{
		temp->data->draw();
		temp = temp->pLow;
	}
}

void Stack::onMouseMoveAll(int x, int y)
{
	NodeStack* temp = this->pTop;
	while (temp != nullptr)
	{
		if (temp->data->isFocused(x, y))
			temp->data->onFocused(x, y);
		else
			temp->data->onUnfocused();

		temp = temp->pLow;
	}
}

void Stack::onMouseLeftDownAll(int x, int y)
{
	NodeStack* temp = this->pTop;
	while (temp != nullptr)
	{
		if (temp->data->isFocused(x, y))
			temp->data->onMouseLeftDown(x, y);

		temp = temp->pLow;
	}
}

void Stack::onMouseLeftUpAll(int x, int y)
{
	NodeStack* temp = this->pTop;
	while (temp != nullptr)
	{
		if (temp->data->isFocused(x, y))
			temp->data->onMouseLeftUp(x, y);

		temp = temp->pLow;
	}
}

void Stack::onClickAll(int x, int y)
{
	NodeStack* temp = this->pTop;
	while (temp != nullptr)
	{
		if (temp->data->isFocused(x, y))
			temp->data->onClick(x, y);

		temp = temp->pLow;
	}
}

void Stack::onMouseRightDownAll(int x, int y)
{
	NodeStack* temp = this->pTop;
	while (temp != nullptr)
	{
		if (temp->data->isFocused(x, y))
			temp->data->onMouseRightDown(x, y);

		temp = temp->pLow;
	}
}

void Stack::onMouseRightUpAll(int x, int y)
{
	NodeStack* temp = this->pTop;
	while (temp != nullptr)
	{
		if (temp->data->isFocused(x, y))
			temp->data->onMouseRightUp(x, y);

		temp = temp->pLow;
	}
}
