// BinaryTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	Tree<int> BinaryTree;
	vector<int> v = BinaryTree.traversal();
	BinaryTree.add(15);
	BinaryTree.add(2);
	BinaryTree.add(3);
	BinaryTree.add(20);
	BinaryTree.add(21);
	cout << "Binary tree:" << endl << (string)BinaryTree << endl << endl;

	BinaryTree.remove(3);
	cout <<"Remove 3.\nBinary tree:\n"<< (string)BinaryTree << endl << endl;

	vector<int> top = BinaryTree.traversal();
	cout << "Tree traversal:\n";
	for (int i = 0; i < top.size(); i++) cout << top[i] << "\t";
	cout << endl << endl;

	vector<int> leaves = BinaryTree.getLeafList();
	cout << "Leaves:\n";
	for (int i = 0; i < leaves.size(); i++) cout << leaves[i] << "\t";
	cout << endl << endl;

	cout << "Search:\n";	
	if (BinaryTree.found(20)) cout << "Value 20 is found" << endl << endl;

	system("pause");
    return 0;
}

