#pragma once

#include "AppFunc.h"

typedef int MyType;

class NodeThree
{
private:
	MyType data;
	NodeThree* pParent;
	NodeThree* pLeft;
	NodeThree* pRight;
	bool isFocus;

public:
	NodeThree(MyType, NodeThree* = nullptr);
	MyType getData();
	NodeThree*& getParent();
	NodeThree*& getLeft();
	NodeThree*& getRight();
	void clear();
	void draw(int, int, int, int);
	void isFocused(int, int, int, int, int);
};