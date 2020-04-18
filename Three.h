#pragma once

#include "NodeThree.h"

class Three
{
private:
	NodeThree* pTop;
	int level;

public:
	Three() : pTop(nullptr), level(0) {};
	Three& add(const MyType&);
	Three& draw();
	int getLevel();
	void isNodeFocused(int, int);
};