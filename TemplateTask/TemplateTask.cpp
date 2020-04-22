// TemplateTask.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
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

	system("pause");
    return 0;
}

