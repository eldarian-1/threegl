#include "App.h"
#include "Button.h"

App* App::instance = 0;

int xDown, yDown;

void displayFunc();
void reshapeFunc(int, int);
void passiveMotionFunc(int, int);
void mouseFunc(int, int, int, int);

App* App::getInstance(int* argc, char** argv, void (*button)())
{
	if (instance == 0)
		instance = new App(argc, argv, button);
	return instance;
}

App::App(int* argc, char** argv, void (*button)())
{
	this->isStarted = false;
	this->add((View*)(new Button(15, 15, 135, 45, "��������", button)))
		->add((View*)(new Button(15, 60, 135, 90, "��������", displayFunc)))
		->add(13)->add(5)->add(17)->add(15)->add(19)->add(3)->add(7)->add(1)->add(4)->add(2)->add(6)
		->add(8)->add(10)->add(9)->add(12)->add(11)->add(14)->add(16)->add(18)->add(20);

	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	int app_width = glutGet(GLUT_SCREEN_WIDTH);
	int app_height = glutGet(GLUT_SCREEN_HEIGHT);
	cout << "Screen: width = " << app_width << ", height = " << app_height << "\nLevel: " << three.getLevel() << endl;

	glutInitWindowSize(APP_WIDTH, APP_HEIGHT);
	glutInitWindowPosition((app_width - APP_WIDTH) / 2, (app_height - APP_HEIGHT * 1.3) / 2);
	glutCreateWindow("Three with OpenGL");
}

App* App::start()
{
	if (!this->isStarted)
	{
		glutDisplayFunc(displayFunc);
		glutReshapeFunc(reshapeFunc);
		glutPassiveMotionFunc(passiveMotionFunc);
		glutMouseFunc(mouseFunc);
		glutMainLoop();
		this->isStarted = true;
	}
	return this;
}

App* App::add(MyType data)
{
	this->three.add(data);
	return this;
}

App* App::add(View* view)
{
	this->stack.add(view);
	return this;
}

int App::getLevel()
{
	return this->three.getLevel();
}

App* App::draw()
{
	this->three.draw();
	this->stack.draw();
	GLfloat c[3]{ 0,0,0 };
	return this;
}

void displayFunc()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	App::getInstance()->draw();
	glutSwapBuffers();
	glFlush();
}

void reshapeFunc(int width, int height)
{
	glutReshapeWindow(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void passiveMotionFunc(int x, int y)
{
	App::getInstance()->stack.onMouseMoveAll(x, y);
	App::getInstance()->three.isNodeFocused(x, y);
	glutPostRedisplay();
}

void mouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		xDown = x;
		yDown = y;
		App::getInstance()->stack.onMouseLeftDownAll(x, y);
	}

	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (x == xDown && y == yDown)
			App::getInstance()->stack.onClickAll(x, y);
		App::getInstance()->stack.onMouseLeftUpAll(x, y);
	}

	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		App::getInstance()->stack.onMouseRightDownAll(x, y);

	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
		App::getInstance()->stack.onMouseRightUpAll(x, y);

	glutPostRedisplay();
}