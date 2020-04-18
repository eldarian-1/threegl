#include "NodeThree.h"

NodeThree::NodeThree(MyType data)
{
	this->data = data;
	this->pLeft = nullptr;
	this->pRight = nullptr;
	this->isFocus = false;
}

MyType NodeThree::getData()
{
	return this->data;
}

NodeThree*& NodeThree::getLeft()
{
	return this->pLeft;
}

NodeThree*& NodeThree::getRight()
{
	return this->pRight;
}

void NodeThree::draw(int hpos, int vpos, int level)
{

	int h_pos = SHIFT + (APP_WIDTH - 2 * SHIFT) / (pow(2, vpos - 1) + 1) * hpos;
	int v_pos = SHIFT + (APP_HEIGHT - 2 * SHIFT) / (level + 1) * vpos;
	char text[10];
	myitoa(this->data, text, 10);
	int a = (strlen(text) + 2)*5;
	int b = 20;

	if (vpos != 1)
	{
		glVertex2f(h_pos, v_pos - b);
		glEnd();
	}

	GLfloat* color = new GLfloat[3]{ 0.0, 0.0, 0.0 };
	drawEllipse(color, a + 1, b + 1, h_pos, v_pos);

	if (this->isFocus)
	{
		color[0] = 0.8;
		color[1] = color[2] = 1.0;
	}
	else
		color[0] = color[1] = color[2] = 0.9;
	drawEllipse(color, a, b, h_pos, v_pos);

	color[0] = color[1] = color[2] = 0.0;
	drawText(color, text, h_pos - strlen(text)*5, v_pos+b/4);

	if (this->pLeft != nullptr)
	{
		GLfloat* color = new GLfloat[3]{ 0.0, 0.0, 0.0 };
		glBegin(GL_LINES);
		glColor3fv(color);
		glLineWidth(2);
		glVertex2f(h_pos, v_pos + b);
		this->pLeft->draw(hpos * 2 - 1, vpos + 1, level);
	}

	if (this->pRight != nullptr)
	{
		GLfloat* color = new GLfloat[3]{ 0.0, 0.0, 0.0 };
		glBegin(GL_LINES);
		glColor3fv(color);
		glLineWidth(2);
		glVertex2f(h_pos, v_pos + b);
		this->pRight->draw(hpos * 2, vpos + 1, level);
	}
}

void NodeThree::isFocused(int x, int y, int hpos, int vpos, int level)
{
	int h_pos = SHIFT + (APP_WIDTH - 2 * SHIFT) / (pow(2, vpos - 1) + 1) * hpos;
	int v_pos = SHIFT + (APP_HEIGHT - 2 * SHIFT) / (level + 1) * vpos;
	char text[10];
	myitoa(this->data, text, 10);
	int a = (strlen(text) + 2) * 5;
	int b = 20;

	if (pow(h_pos-x, 2) / pow(a, 2) + pow(v_pos-y, 2) / pow(b, 2) <= 1.0)
	{
		this->isFocus = true;
		return;
	}
	else
		this->isFocus = false;

	if (this->pLeft != nullptr)
		this->pLeft->isFocused(x, y, hpos * 2 - 1, vpos + 1, level);
	if (this->pRight != nullptr)
		this->pRight->isFocused(x, y, hpos * 2, vpos + 1, level);
}