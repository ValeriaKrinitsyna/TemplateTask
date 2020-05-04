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
		Node* left; // pointer to node from the left subtree
		Node* right; // pointer to node from the right subtree
		Node(T _value) :value(_value), left(nullptr), right(nullptr) {}
	};
	Node* root; // pointer to the root

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
Tree<T>::~Tree() //destructor
{
	if (root) this->dispose(this->root);
}

template<class T>
void Tree<T>::dispose(Node*root) // cleans up memory
{
	if (root)
	{
		dispose(root->left); 
		dispose(root->right);
		delete root;
	}
}

template <class T>
void Tree<T>::traversal(vector<T>& top, Node* root) // walking the tree
{
	if (root) {
		traversal(top, root->left); // go around left subtree
		top.push_back(root->value); // add value to the end of vector top
		traversal(top, root->right); // go around right subtree
	}
}

template <class T>
vector<T> Tree<T>::traversal() // walking the tree from the top to root (one branch)
{
	vector<T> top;
	traversal(top, this->root);
	return top;
}

template<class T>
void Tree<T>::add(T value) // add new node to the tree
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
void Tree<T>::add(T value, Node*& node) // add new node to it's place
{
	if (node == nullptr) 
	{
		node = new Node(value);
	}
	else if (value < node->value) this->add(value, node->left); //if value is less than node, add new to the left subtree
	else if (value > node->value) this->add(value, node->right); //if value is bogger than node, add new to the right subtree
	else throw "This value is already in the tree!";
}

template<class T>  
string Tree<T>::TreeToString(Node* node) // output of the tree
{
	string leftStr = (node->left == nullptr) ? "{}" : TreeToString(node->left); //print left subtree 
	string rightStr = (node->right == nullptr) ? "{}" : TreeToString(node->right); //print right subtree
	string result = "{" + to_string(node->value) + ", " + leftStr + ", " + rightStr + "}"; //firstly, print note, then left subtree, then right subtree
	return result;
}

template<class T>
void Tree<T>::remove(T value)
{
	this->remove(value, this->root); 
}

template<class T>
void Tree<T>::remove(T value, Node*& root) //removes node from the tree
{
	if (root == nullptr) //there is no such value
	{
		throw "Not found";
	}
	if (value > root->value) remove(value, root->right); // looking for a value in the right subtree
	else if (value < root->value) remove(value, root->left); // looking for a value in the left subtree
	else 
	{
		Node* temp = root;
		if (temp->right == nullptr && temp->left == nullptr)
		{
			root = nullptr; // if no children -> no root
		}
		else if (temp->right == nullptr && temp->left != nullptr)
		{
			root = temp->left; // no right child -> left child goes to the root
		}
		else if (temp->left == nullptr && temp->right != nullptr)
		{
			root = temp->right; // no left child -> right child goes to the root
		}
		else //if the root had either right, or left child
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
bool Tree<T>::found(T value, Node* root) // looking for a value in the tree
{
	if (root == nullptr) return false; // no root, no tree
	else if (root->value == value) return true; // root==value, value is found
	else if (value > root->value) return found(value, root->right); // value>root, then we go to the right subtree
	else return found(value, root->left); // value<root, then we go to the left subtree
}

template<class T>
vector<T> Tree<T>::getLeafList()
{
	vector<T> leafList;
	getLeaf(this->root, leafList);
	return leafList;
}

template<class T>
void Tree<T>::getLeaf(Node* root, vector<T>& leaf) // looking for leaves - leaves have no children
{
	if (root->left == nullptr && root->right == nullptr) // no children
	{
		leaf.push_back(root->value); // add to the vector leafList
	}
	else // node has a child
	{
		if (root->left) getLeaf(root->left, leaf); // go down to the left
		if (root->right) getLeaf(root->right, leaf); // go down to the right
	}
}

template<class T>
Tree<T>::operator string()
{
	if (root == nullptr) return "{}"; //tree is empty
	else return this->TreeToString(this->root); //printing the tree
}



