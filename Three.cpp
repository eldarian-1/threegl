#include "Three.h"

Three::Node* Three::Node::instance = nullptr;

MyType Three::getLevel()
{
	return this->level;
}

Three& Three::add(const MyType& data)
{
	if (this->pTop == nullptr)
	{
		this->pTop = new Node{ nullptr, nullptr, nullptr, data };
		this->level = 1;
	}
	else
	{
		Three::Node* temp = this->pTop;
		int level = 1;
		while (true)
		{
			++level;
			if (data < temp->data)
			{
				if (temp->pLeft == nullptr)
				{
					temp->pLeft = new Node{ temp, nullptr, nullptr, data };
					break;
				}
				else
					temp = temp->pLeft;
			}
			else if (data > temp->data)
			{
				if (temp->pRight == nullptr)
				{
					temp->pRight = new Node{ temp, nullptr, nullptr, data };
					break;
				}
				else
					temp = temp->pRight;
			}
			else if (data == temp->data)
				break;
		}
		if (level > this->level)
			this->level = level;
		int digit = 0, temp0 = data;
		while (temp0 != 0)
		{
			temp0 /= 10;
			++digit;
		}
		if (digit > this->digit)
			this->digit = digit;
	}
	return *this;
}

void Three::del(const MyType& data)
{
	Node* temp = this->pTop;
	if (temp->data == data)
	{
		this->clear();
		return;
	}
	if (temp == nullptr)
		cout << "Искомый узел не существует\n";
	else
	{
		int level = 1;
		while (true)
		{
			if (data == temp->data)
			{
				Node* pParent = temp->pParent;
				Node* pLeft = temp->pLeft;
				Node* pRight = temp->pRight;
				Node* pDel = temp;
				if (pParent->pLeft == pDel)
				{
					if ((pLeft == nullptr) && (pRight == nullptr))
					{
						pParent->pLeft = nullptr;
					}
					else if ((pLeft == nullptr) && (pRight != nullptr))
					{
						pParent->pLeft = pRight;
						pRight->pParent = pParent;
					}
					else if ((pLeft != nullptr) && (pRight == nullptr))
					{
						pParent->pLeft = pLeft;
						pLeft->pParent = pParent;
					}
					else
					{
						pParent->pLeft = pRight;
						pRight->pParent = pParent;
						temp = pRight;
						while (temp->pLeft != nullptr)
							temp = temp->pLeft;
						temp->pLeft = pLeft;
						pLeft->pParent = temp;
					}
				}
				else
				{
					if ((pLeft == nullptr) && (pRight == nullptr))
					{
						pParent->pRight = nullptr;
					}
					else if ((pLeft == nullptr) && (pRight != nullptr))
					{
						pParent->pRight = pRight;
						pRight->pParent = pParent;
					}
					else if ((pLeft != nullptr) && (pRight == nullptr))
					{
						pParent->pRight = pLeft;
						pLeft->pParent = pParent;
					}
					else
					{
						pParent->pRight = pLeft;
						pLeft->pParent = pParent;
						temp = pLeft;
						while (temp->pRight != nullptr)
							temp = temp->pRight;
						temp->pRight = pRight;
						pRight->pParent = temp;
					}
				}
				delete pDel;
				break;
			}
			else if (data < temp->data && temp->pLeft != nullptr)
				temp = temp->pLeft;
			else if (data > temp->data && temp->pRight != nullptr)
				temp = temp->pRight;
			else
			{
				cout << "Искомый узел не существует\n";
				break;
			}
		}
	}
}

void Three::clear(Node* temp)
{
	if (this->pTop == nullptr)
		return;

	if (temp == nullptr)
		temp = this->pTop;

	if (temp->pLeft != nullptr)
		this->clear(temp->pLeft);

	if (temp->pRight != nullptr)
		this->clear(temp->pRight);
	
	if (temp == this->pTop)
		this->pTop = nullptr;

	delete temp;
}

void Three::draw(int hpos, int vpos, Node* temp)
{
	if (this->pTop == nullptr)
		return;

	if (temp == nullptr)
		temp = this->pTop;

	int h_pos = SHIFT + (APP_WIDTH - 2 * SHIFT) / (pow(2, vpos - 1) + 1) * hpos;
	int v_pos = SHIFT + (APP_HEIGHT - 2 * SHIFT) / (level + 1) * vpos;
	char text[10];
	myitoa(temp->data, text, 10);

	//int a = (strlen(text) + 2) * 5;
	//int b = 20;
	int r = digit * 6 + 5;

	if (vpos != 1)
	{
		glVertex2f(h_pos, v_pos);
		glEnd();
	}

	if (temp->pLeft != nullptr)
	{
		GLfloat color[] = { 0.0, 0.0, 0.0 };
		glBegin(GL_LINES);
		glColor3fv(color);
		glLineWidth(2);
		glVertex2f(h_pos, v_pos);
		//glVertex2f(h_pos, v_pos + b);
		this->draw(hpos * 2 - 1, vpos + 1, temp->pLeft);
	}

	if (temp->pRight != nullptr)
	{
		GLfloat color[] = { 0.0, 0.0, 0.0 };
		glBegin(GL_LINES);
		glColor3fv(color);
		glLineWidth(2);
		glVertex2f(h_pos, v_pos);
		//glVertex2f(h_pos, v_pos + b);
		this->draw(hpos * 2, vpos + 1, temp->pRight);
	}

	GLfloat color[] = { 0.0, 0.0, 0.0 };
	//drawEllipse(color, a, b, h_pos, v_pos);
	drawEllipse(color, r, r, h_pos, v_pos);

	if (temp->isFocus)
	{
		color[0] = 0.9;
		color[1] = color[2] = 1.0;
	}
	else
		color[0] = color[1] = color[2] = 0.9;
	//drawEllipse(color, a - 1, b - 1, h_pos, v_pos);
	drawEllipse(color, r - 1, r - 1, h_pos, v_pos);

	color[0] = color[1] = color[2] = 0.0;
	drawText(color, text, h_pos - strlen(text) * 5, v_pos + r / 4);
}

void Three::run(int x, int y, void (Three::* func)(int, int), int hpos, int vpos, Node* temp)
{
	if (this->pTop == nullptr)
		return;

	if (temp == nullptr)
		temp = this->pTop;

	int h_pos = SHIFT + (APP_WIDTH - 2 * SHIFT) / (pow(2, vpos - 1) + 1) * hpos;
	int v_pos = SHIFT + (APP_HEIGHT - 2 * SHIFT) / (level + 1) * vpos;
	char text[15];
	myitoa(temp->data, text, 10);
	int a = (strlen(text) + 2) * 5;
	int b = 20;

	Node::instance = temp;

	if (pow(h_pos - x, 2) / pow(a, 2) + pow(v_pos - y, 2) / pow(b, 2) <= 1.0)
	{
		if (func == nullptr)
			this->onFocused();
		else
			(this->*func)(x, y);
		return;
	}
	else
		this->onUnfocused();

	if (temp->isFocus != true)
	{
		if (temp->pLeft != nullptr)
			this->run(x, y, func, hpos * 2 - 1, vpos + 1, temp->pLeft);
		if (temp->pRight != nullptr)
			this->run(x, y, func, hpos * 2, vpos + 1, temp->pRight);
	}
}


void Three::isFocused(int x, int y, void (View::*func)(int, int))
{
	this->run(x, y, (void (Three::*)(int, int))func);
}

void Three::onFocused()
{
	Node::instance->isFocus = true;
	//printf("Three: onFocused\n");
}

void Three::onUnfocused()
{
	Node::instance->isFocus = false;
	//printf("Three: onUnfocused");
}

void Three::onClick(int x, int y)
{
	//printf("Three: onClick on x: %d, y: %d\n", x, y);
	this->del(Node::instance->data);
	
}

void Three::onMouseLeftDown(int x, int y)
{
	//printf("Three: onMouseLeftDown on x: %d, y: %d\n", x, y);
}

void Three::onMouseLeftUp(int x, int y)
{
	//printf("Three: onMouseLeftUp on x: %d, y: %d\n", x, y);
}

void Three::onMouseRightDown(int x, int y)
{
	//printf("Three: onMouseRightDown on x: %d, y: %d\n", x, y);
}

void Three::onMouseRightUp(int x, int y)
{
	//printf("Three: onMouseRightUp on x: %d, y: %d\n", x, y);
}