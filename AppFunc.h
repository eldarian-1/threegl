#pragma once

#include <glut.h>
#include <iostream>
using namespace std;

#define APP_WIDTH 1280
#define APP_HEIGHT 720

#define M_PI 3.14159265358979323846

#define SHIFT 15

void drawQuad(GLfloat* color, int left, int top, int right, int bottom);

void drawLine(float, float, float, float);

void drawEllipse(GLfloat*, float, float, float, float);

void drawText(GLfloat*, const char*, int, int);

char* myitoa(int number, char* destination, int base);