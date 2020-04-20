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

	App(int*, char**, void (*button)());

	void draw();

public:
	static App* getInstance(int* argc = nullptr, char** argv = nullptr, void (*button)() = nullptr);

	void start();
	void add(MyType);

	friend void displayFunc();
	friend void reshapeFunc(int, int);
	friend void passiveMotionFunc(int, int);
	friend void mouseFunc(int, int, int, int);
};