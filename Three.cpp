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
					temp->getLeft() = new NodeThree(data, temp);
					break;
				}
				else
					temp = temp->getLeft();
			}
			else if (data > temp->getData())
			{
				if (temp->getRight() == nullptr)
				{
					temp->getRight() = new NodeThree(data, temp);
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
		int digit = 0, temp = data;
		while (temp != 0)
		{
			temp /= 10;
			++digit;
		}
		if (digit > this->digit)
			this->digit = digit;
	}
	return *this;
}

Three& Three::del(const MyType& data)
{
	NodeThree* temp = this->pTop;
	if (this->pTop == nullptr)
		cout << "Искомый узел не существует\n";
	else
	{
		int level = 1;
		while (true)
		{
			if (data == temp->getData())
			{
				NodeThree* pParent = temp->getParent();
				NodeThree* pLeft = temp->getLeft();
				NodeThree* pRight = temp->getRight();
				NodeThree* pDel = temp;
				if (pParent->getLeft() == pDel)
				{
					pParent->getLeft() = pLeft;
					pLeft->getParent() = pParent;
					temp = pParent->getRight();
					while (temp->getLeft() != nullptr)
						temp = temp->getLeft();
					temp->getLeft() = pRight;
					pRight->getParent() = temp;
				}
				else
				{
					pParent->getRight() = pRight;
					pLeft->getParent() = pParent;
					temp = pParent->getLeft();
					while (temp->getRight() != nullptr)
						temp = temp->getRight();
					temp->getRight() = pLeft;
					pLeft->getParent() = temp;
				}
				break;
			}
			else if (data < temp->getData() && temp->getLeft() != nullptr)
				temp = temp->getLeft();
			else if (data > temp->getData() && temp->getRight() != nullptr)
				temp = temp->getRight();
			else
			{
				cout << "Искомый узел не существует\n";
				break;
			}
		}
	}
	return *this;
}

Three& Three::del(NodeThree*& pNode)
{
	NodeThree* temp = this->pTop;
	if (this->pTop == pNode)
		this->clear();
	else
	{
		NodeThree* pParent = temp->getParent();
		NodeThree* pLeft = temp->getLeft();
		NodeThree* pRight = temp->getRight();
		NodeThree* pDel = temp;
		if (pParent->getLeft() == pDel)
		{
			pParent->getLeft() = pLeft;
			pLeft->getParent() = pParent;
			temp = pParent->getRight();
			while (temp->getLeft() != nullptr)
				temp = temp->getLeft();
			temp->getLeft() = pRight;
			pRight->getParent() = temp;
		}
		else
		{
			pParent->getRight() = pRight;
			pLeft->getParent() = pParent;
			temp = pParent->getLeft();
			while (temp->getRight() != nullptr)
				temp = temp->getRight();
			temp->getRight() = pLeft;
			pLeft->getParent() = temp;
		}
	}
	return *this;
}

Three& Three::clear()
{
	this->pTop->clear();
	this->pTop = nullptr;
	return *this;
}

Three& Three::draw()
{
	if(this->pTop != nullptr)
		this->pTop->draw(1, 1, this->level, this->digit);
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