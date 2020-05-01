#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


template <class T>
class Tree
{
private:
	struct Node
	{
		T value;
		Node* left;
		Node* right;
		Node(T _value) :value(_value), left(nullptr), right(nullptr) {}
	};
	Node* root;

	void add(T, Node*&);
	void remove(T, Node*&);
	void traversal(vector<T>&, Node*);
	void getLeaf(Node*, vector<T>&);
	bool found(T, Node*);
	string TreeToString(Node*);
public:
	void dispose(Node*);
	Tree() :root(nullptr) {}
	~Tree();
	vector<T> traversal();
	void add(T);
	void remove(T);
	bool found(T);
	vector<T> getLeafList();
	operator string();
};

template<class T>
Tree<T>::~Tree()
{
	if (root) this->dispose(this->root);
}

template<class T>
void Tree<T>::dispose(Node*root)
{
	if (root)
	{
		dispose(root->left);
		dispose(root->right);
		delete root;
	}
}

template <class T>
void Tree<T>::traversal(vector<T>& top, Node* root)
{
	if (root) {
		traversal(top, root->left); // go around left subtree
		top.push_back(root->value);
		traversal(top, root->right); // go around right subtree
	}
}

template <class T>
vector<T> Tree<T>::traversal()
{
	vector<T> top;
	traversal(top, this->root);
	return top;
}

template<class T>
void Tree<T>::add(T value)
{
	if (root == nullptr)
	{
		root = new Node(value);
	}
	else
	{
		this->add(value, root);
	}
}

template<class T>
void Tree<T>::add(T value, Node*& node)
{
	if (node == nullptr)
	{
		node = new Node(value);
	}
	else if (value < node->value) this->add(value, node->left);
	else if (value > node->value) this->add(value, node->right);
	else throw "This value is already in the tree!";
}

template<class T>  
string Tree<T>::TreeToString(Node* node) // output of the tree
{
	string leftStr = (node->left == nullptr) ? "{}" : TreeToString(node->left);
	string rightStr = (node->right == nullptr) ? "{}" : TreeToString(node->right);
	string result = "{" + to_string(node->value) + ", " + leftStr + ", " + rightStr + "}";
	return result;
}

template<class T>
void Tree<T>::remove(T value)
{
	this->remove(value, this->root);
}

template<class T>
void Tree<T>::remove(T value, Node*& root) 
{
	if (root == nullptr) 
	{
		throw "Not found";
	}
	if (value > root->value) remove(value, root->right);
	else if (value < root->value) remove(value, root->left);
	else 
	{
		Node* temp = root;
		if (temp->right == nullptr && temp->left == nullptr)
		{
			root = nullptr; // if no children, no root
		}
		else if (temp->right == nullptr && temp->left != nullptr)
		{
			root = temp->left; // no right child, left child to the root
		}
		else if (temp->left == nullptr && temp->right != nullptr)
		{
			root = temp->right; // no left child, right child to the root
		}
		else
		{
			Node* maxNode = temp->left; //replace deleted item with the max value from the left subtree
			while (maxNode->right) maxNode = maxNode->right;
			temp->value = maxNode->value;
			remove(maxNode->value, temp->left);
		}
	}
}

template<class T>
bool Tree<T>::found(T value)
{
	return found(value, root);
}

template<class T>
bool Tree<T>::found(T value, Node* root)
{
	if (root == nullptr) return false;
	else if (root->value == value) return true;
	else if (value > root->value) return found(value, root->right);
	else return found(value, root->left);
}

template<class T>
vector<T> Tree<T>::getLeafList()
{
	vector<T> leafList;
	getLeaf(this->root, leafList);
	return leafList;
}

template<class T>
void Tree<T>::getLeaf(Node* root, vector<T>& leaf)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		leaf.push_back(root->value);
	}
	else
	{
		if (root->left) getLeaf(root->left, leaf);
		if (root->right) getLeaf(root->right, leaf);
	}
}

template<class T>
Tree<T>::operator string()
{
	if (root == nullptr) return "{}";
	else return this->TreeToString(this->root);
}



