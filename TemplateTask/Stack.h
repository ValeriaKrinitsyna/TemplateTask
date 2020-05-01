//#define _SCL_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Stack
{
private:
	T *stackPtr; // ��������� �� ����
	int size; // ������ �����
	const size_t max_size = 10;
	T top = 0; // ������� �����
public:
	Stack(int sz = 10);// �� ��������� ������ ����� ����� 10 ���������
	~Stack(); // ����������
	bool push(const T); // ��������� ������� � ����
	T pop(); // ������� �� ����� �������
	bool empty() const;
	void merge(Stack &src);
	void reserve(int new_size);
	void printStack();
};

// �����������
template <typename T>
Stack<T>::Stack(int s)
{
	size = s > 0 ? s : 10;   // ���������������� ������ �����
	stackPtr = new T[size]; // �������� ������ ��� ����
}

// ����������
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ������� ������  Stack ��� ��������� �������� � ����
// ������������ ��������: true - �������� ������� ���������, false - ������� � ���� �� ��������
template <typename T>
bool Stack<T>::push(const T value)
{
	if (top == size) // ���� �����
	{
		cout << "Stack overflow" << endl;
		return false; 
	}
	stackPtr[top] = value; // �������� ������� � ����
	top++;
	return true; // �������� ���������� ��������
}

// ������� ������� ������  Stack ��� �������� �������� �� ����
// ������������ ��������: true - �������� ������� ���������, false - ���� ����
template <typename T>
T Stack<T>::pop()
{
	if (top == 0) //cout << "Stack is empty" << endl;
		throw std::out_of_range("Stack is empty");
	return stackPtr[--top]; // ������� ������� �� �����
}

// ����� ����� �� �����
template <typename T>
void Stack<T>::printStack() //����� ����� � �������
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
void Stack<T>::reserve(int new_size) //������� ��� ���������� ������� �����
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
	for (int i = 0; i < src.top; ++i) //����� ������ ���� �� ��������������� ��� ����������
		push(src.stackPtr[i]);

	src.top = 0;
}

