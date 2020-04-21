#pragma once

#include "View.h"

typedef int MyType;

class Three : public View
{
private:

	struct Node
	{
		Node* pParent = nullptr;
		Node* pLeft = nullptr;
		Node* pRight = nullptr;
		MyType data = 0;
		bool isFocus = false;
	};

	static Node* instance;

	Node* pTop;
	int level;
	int digit;

	void setLevel(bool, Node* = nullptr, int = 0);
	void setDigit(bool, Node* = nullptr);

public:
	Three() : pTop(nullptr), level(0), digit(0) {};

	Three& add(const MyType&);
	void del(const MyType&);
	void clear(Node* = nullptr);

	void draw(int = 1, int = 1, Node* = nullptr);
	void run(int, int, void (Three::* func)(int, int) = nullptr, int = 1, int = 1, Node* = nullptr);

	void isFocused(int, int, void (View::*)(int, int) = nullptr);
	void onFocused();
	void onUnfocused();
	void onClick(int, int);
	void onMouseLeftDown(int, int);
	void onMouseLeftUp(int, int);
	void onMouseRightDown(int, int);
	void onMouseRightUp(int, int);
};