#include "App.h"

void button();

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");
	App::getInstance(&argc, argv, button)->start();
	return 0;
}

void button()
{
	int num;
	cout << "¬ведите значение: ";
	cin >> num;
	App::getInstance()->add(num);
}