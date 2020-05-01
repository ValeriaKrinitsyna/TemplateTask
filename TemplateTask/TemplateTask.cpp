// TemplateTask.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
//#define _SCL_SECURE_NO_WARNINGS 1

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
	cout << endl;

	Stack <int> myStack2(5);
	cout << "����������� �������� � ����: ";
	ct = 0;
	while (ct++ != 5)
	{
		int temp;
		cin >> temp;
		myStack2.push(temp);
	}
	myStack2.printStack(); // ����� ����� �� �����
	cout << endl << "����� ����:" << endl;
	myStack.merge(myStack2);
	myStack.printStack();

	system("pause");
    return 0;
}

