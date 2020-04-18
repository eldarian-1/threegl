#pragma once

#include "AppFunc.h"

typedef int MyType;

class NodeThree
{
private:
	MyType data;
	NodeThree* pLeft;
	NodeThree* pRight;
	bool isFocus;

public:
	NodeThree(MyType);
	MyType getData();
	NodeThree*& getLeft();
	NodeThree*& getRight();
	void draw(int, int, int);
	void isFocused(int, int, int, int, int);
};