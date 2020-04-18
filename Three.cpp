#include "Three.h"

Three& Three::add(const MyType& data)
{
	NodeThree* temp = this->pTop;
	if (this->pTop == nullptr)
	{
		this->pTop = new NodeThree(data);
		this->level = 1;
	}
	else
	{
		int level = 1;
		while (true)
		{
			++level;
			if (data < temp->getData())
			{
				if (temp->getLeft() == nullptr)
				{
					temp->getLeft() = new NodeThree(data);
					break;
				}
				else
					temp = temp->getLeft();
			}
			else if (data > temp->getData())
			{
				if (temp->getRight() == nullptr)
				{
					temp->getRight() = new NodeThree(data);
					break;
				}
				else
					temp = temp->getRight();
			}
			else if (data == temp->getData())
			{
				break;
			}
		}
		if (level > this->level)
			this->level = level;
	}
	return *this;
}

Three& Three::draw()
{
	if(this->pTop != nullptr)
		this->pTop->draw(1, 1, this->level);
	return *this;
}

int Three::getLevel()
{
	return this->level;
}

void Three::isNodeFocused(int x, int y)
{
	if (this->pTop != nullptr)
		this->pTop->isFocused(x, y, 1, 1, this->level);
}