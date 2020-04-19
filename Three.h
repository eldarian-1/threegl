#pragma once

#include "NodeThree.h"

class Three
{
private:
	NodeThree* pTop;
	int level;
	int digit;

public:
	Three() : pTop(nullptr), level(0), digit(0) {};
	Three& add(const MyType&);
	Three& del(const MyType&);
	Three& del(NodeThree*&);
	Three& clear();
	Three& draw();
	int getLevel();
	void isNodeFocused(int, int);
};