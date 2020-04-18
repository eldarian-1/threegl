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
	App* draw();

public:
	static App* getInstance(int* argc = nullptr, char** argv = nullptr, void (*button)() = nullptr);

	App* start();
	App* add(View*);
	App* add(MyType);
	int getLevel();

	friend void displayFunc();
	friend void reshapeFunc(int, int);
	friend void passiveMotionFunc(int, int);
	friend void mouseFunc(int, int, int, int);
};

