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
		case 1: cout << "  ���������� �������� � ����:  " << endl;
			cin >> temp;
			if (s.push(temp) == true)
				cout << s;
			else
				cout << "���� ��������! /n /n";
			_getch();
			break;
		case 2:
			cout << " �������� �������� � �����:  " << endl;
			(s.pop() == true) ? cout << s : cout << "���� ����!\n";
			_getch();
			break;
		case 3:
			cout << " ���������� ��������: " << endl;
			cin >> test.get_value();
			s.pop_emplace(move(test.get_value()));
			break;
		case 4: cout << endl;
			cout << " �������� � ������� �����: \n" << s.head();
			cout << endl << "�������� �������� ����� ��������? ������� 'y' ";
			char ch;
			cin >> ch;
			if ((ch == 'y') || (ch == 'e'))
			{
				cout << "������� ����� ��������: ";
				cin >> s.head();
			}
			break;
		case 5: cout << endl;
			cout << " ���������� �������� �����! \n";
			s.pop_destroy();
			_getch();
			break;
		case 6: cout << endl;
			cout << " ������ �����: " << endl;
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
