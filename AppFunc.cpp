#include "AppFunc.h"

void drawQuad(GLfloat* color, int left, int top, int right, int bottom)
{
	glBegin(GL_QUADS);
	glColor3fv(color);
	glVertex2i(left, top);
	glVertex2i(right, top);
	glVertex2i(right, bottom);
	glVertex2i(left, bottom);
	glEnd();
}

void drawEllipse(GLfloat* color, float a, float b, float x, float y)
{
	const float step = float(2 * M_PI) / 360;

	glBegin(GL_TRIANGLE_FAN);
	glColor3fv(color);
	glVertex2f(x, y);
	for (float angle = 0; angle <= float(2 * M_PI); angle += step)
	{
		float t = (fabsf(angle - float(2 * M_PI)) < 0.00001f) ? 0.f : angle;
		const float dx = a * cosf(t);
		const float dy = b * sinf(t);
		glVertex2f((double)dx + x, (double)dy + y);
	}
	glEnd();
}

void drawText(GLfloat* color, const char* str, int x, int y)
{
	glColor3fv(color);
	for (int i = 0; str[i] != '\0'; i++)
	{
		glRasterPos2f(x + i * 10, y);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
	}
}

char* myitoa(int number, char* destination, int base)
{
	int count = 0;
	do
	{
		int digit = number % base;
		destination[count++] = (digit > 9) ? digit - 10 + 'A' : digit + '0';
	}
	while ((number /= base) != 0);
	destination[count] = '\0';
	int i;
	for (i = 0; i < count / 2; ++i)
	{
		char symbol = destination[i];
		destination[i] = destination[count - i - 1];
		destination[count - i - 1] = symbol;
	}
	return destination;
}