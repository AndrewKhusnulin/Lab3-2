#include "class.h"
#include "classes.cpp"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	Stack <int> s;
	int temp;
	NonCopyMove test(0);
	while (1)
	{
		system("cls");
		cout << "  Stack  " << endl;
		cout << "  -----------------------------  " << endl;
		cout << "  1. Push ";
		cout << "  2. Pop ";
		cout << "  3. Pop emplace  ";
		cout << "  4. Head ";
		cout << "  5. Pop destroy  ";
		cout << "  6. Print stack  ";
		cout << "  0. Exit    " << endl;
		cout << "  Enter your choice :  ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "  Добавление элемента в стек:  " << endl;
			cin >> temp;
			if (s.push(temp) == true)
				cout << s;
			else
				cout << "Стек заполнен! /n /n";
			_getch();
			break;
		case 2:
			cout << " Удаление элемента в стеке:  " << endl;
			(s.pop() == true) ? cout << s : cout << "Стек пуст!\n";
			_getch();
			break;
		case 3:
			cout << " Добавление элемента: " << endl;
			cin >> test.get_value();
			s.pop_emplace(move(test.get_value()));
			break;
		case 4: cout << endl;
			cout << " Значение в вершине стека: \n" << s.head();
			cout << endl << "Изменить значение этого элемента? нажмите 'y' ";
			char ch;
			cin >> ch;
			if ((ch == 'y') || (ch == 'e'))
			{
				cout << "Введите новое значение: ";
				cin >> s.head();
			}
			break;
		case 5: cout << endl;
			cout << " Разрушение верхушки стека! \n";
			s.pop_destroy();
			_getch();
			break;
		case 6: cout << endl;
			cout << " Печать стека: " << endl;
			cout << s;
			_getch();
			break;
		case 0:
			return 0;
			break;
		}
	}
	system("pause");
};
