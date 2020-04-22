#define _SCL_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Stack
{
private:
	T *stackPtr; // указатель на стек
	int size; // размер стека
	const size_t max_size = 10;
	T top = 0; // вершина стека
public:
	Stack(int sz = 10);// по умолчанию размер стека равен 10 элементам
	~Stack(); // деструктор
	bool push(const T); // поместить элемент в стек
	T pop(); // удалить из стека элемент
	bool empty() const;
	void merge(Stack &src);
	void reserve(int new_size);
	void printStack();
};

// конструктор
template <typename T>
Stack<T>::Stack(int s)
{
	size = s > 0 ? s : 10;   // инициализировать размер стека
	stackPtr = new T[size]; // выделить память под стек
}

// деструктор
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // удаляем стек
}

// элемент функция класса  Stack для помещения элемента в стек
// возвращаемое значение: true - операция успешно завершена, false - элемент в стек не добавлен
template <typename T>
bool Stack<T>::push(const T value)
{
	if (top == size) // стек полон
	{
		cout << "Stack overflow" << endl;
		return false; 
	}
	stackPtr[top] = value; // помещаем элемент в стек
	top++;
	return true; // успешное выполнение операции
}

// элемент функция класса  Stack для удаления элемента из стек
// возвращаемое значение: true - операция успешно завершена, false - стек пуст
template <typename T>
T Stack<T>::pop()
{
	if (top == 0) //cout << "Stack is empty" << endl;
		throw std::out_of_range("Stack is empty");
	return stackPtr[--top]; // удаляем элемент из стека
}

// вывод стека на экран
template <typename T>
void Stack<T>::printStack() //вывод стека в столбец
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

template <typename T>
bool Stack<T>::empty() const
{
	return top == 0;
}

template <typename T> 
void Stack<T>::reserve(int new_size) //функция для увеличения размера стека
{
	if (new_size <= size)
		return;

	T *data = new T[new_size];
	std::move(stackPtr, stackPtr + top, data);
	delete[] stackPtr;
	size = new_size;
	stackPtr = data;
}

template <typename T>
void Stack<T>::merge(Stack &src)
{
	reserve(top + src.top);
	for (int i = 0; i < src.top; ++i) //чтобы второй стек не переворачивался при соединении
		push(src.stackPtr[i]);

	src.top = 0;
}

