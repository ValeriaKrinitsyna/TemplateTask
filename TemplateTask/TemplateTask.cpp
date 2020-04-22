// TemplateTask.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#define _SCL_SECURE_NO_WARNINGS 1

#include <iostream>
#include "Stack.h"


int main()
{
	setlocale(0, "Rus");
	Stack <int> myStack(5);
	// заполняем стек
	cout << "Заталкиваем элементы в стек: ";
	int ct = 0;
	while (ct++ != 5)
	{
		int temp;
		cin >> temp;
		myStack.push(temp);
	}
	myStack.printStack(); // вывод стека на экран
	cout << endl << "Удаляем два элемента из стека:" << endl;

	myStack.pop(); // удаляем элемент из стека
	myStack.pop(); // удаляем элемент из стека
	myStack.printStack(); // вывод стека на экран
	cout << endl;

	Stack <int> myStack2(5);
	cout << "Заталкиваем элементы в стек: ";
	ct = 0;
	while (ct++ != 5)
	{
		int temp;
		cin >> temp;
		myStack2.push(temp);
	}
	myStack2.printStack(); // вывод стека на экран
	cout << endl << "Новый стек:" << endl;
	myStack.merge(myStack2);
	myStack.printStack();

	system("pause");
    return 0;
}

