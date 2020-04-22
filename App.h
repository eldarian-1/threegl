#pragma once

#include "Three.h"
#include "Stack.h"

class App
{
private:
	static App* instance;

	Three three;
	Stack stack;
	bool isStarted;

	App(int*, char**, Control*, int);

	void draw();

public:
	static App* getInstance(int* = nullptr, char** = nullptr, Control* = nullptr, int = 0);

	void start();

	void addNum(MyType);
	void delNum(MyType);
	int findNum(MyType);
	int getLevel();

	friend void displayFunc();
	friend void reshapeFunc(int, int);
	friend void passiveMotionFunc(int, int);
	friend void mouseFunc(int, int, int, int);
};