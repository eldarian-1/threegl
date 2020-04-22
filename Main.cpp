#include "App.h"

void btnAdd();
void btnDel();
void btnFind();
void btnLevel();

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");

	Control ctrl[] = {
		{15, 15, 135, 45, "Add num", btnAdd},
		{15, 60, 135, 90, "Del num", btnDel},
		{15, 105, 135, 135, "Find level", btnFind},
		{15, 150, 135, 180, "Print level", btnLevel}
	};

	App::getInstance(&argc, argv, ctrl, sizeof(ctrl)/(sizeof Control))->start();
	return 0;
}

void btnAdd()
{
	int num;
	cout << "¬ведите значение нового узла: ";
	cin >> num;
	App::getInstance()->addNum(num);
}

void btnDel()
{
	int num;
	cout << "¬ведите значение удал€емого узла: ";
	cin >> num;
	App::getInstance()->delNum(num);
}

void btnFind()
{
	int num;
	cout << "¬ведите значение искомого узла: ";
	cin >> num;
	num = App::getInstance()->findNum(num);
	cout << "”ровень данного узла: " << num << endl;
}

void btnLevel()
{
	cout << "”ровень данного дерева: " << App::getInstance()->getLevel() << endl;
}