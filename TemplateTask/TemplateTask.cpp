// TemplateTask.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "Stack.h"


int main()
{
	setlocale(0, "Rus");
	Stack <int> myStack(5);
	// ��������� ����
	cout << "����������� �������� � ����: ";
	int ct = 0;
	while (ct++ != 5)
	{
		int temp;
		cin >> temp;
		myStack.push(temp);
	}
	myStack.printStack(); // ����� ����� �� �����
	cout << endl << "������� ��� �������� �� �����:" << endl;

	myStack.pop(); // ������� ������� �� �����
	myStack.pop(); // ������� ������� �� �����
	myStack.printStack(); // ����� ����� �� �����

	system("pause");
    return 0;
}

