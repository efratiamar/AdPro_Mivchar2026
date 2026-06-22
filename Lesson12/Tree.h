#pragma once
#include <iostream>
using namespace std;

template <class T>
class Tree
{
protected:
	class Node
	{
	public:
		T value;
		Node* left;
		Node* right;
		Node* father;
	public:
		Node(T val, Node* f = nullptr, Node* l = nullptr, Node* r = nullptr) 
			: value(val), father(f), left(l), right(r){};
	};

	Node* root;

private:
	void preOrder(Node* current);
	void inOrder(Node* current);
	void postOrder(Node* current);
	void clear(Node* current);
	bool isMaxHeap(Node* current);
	bool isMinHeap(Node* current);
	bool isEven(Node* current);
	bool isCond( bool (*func) (T), Node* current);




public:
	Tree() : root(nullptr) {};
	~Tree() { clear(); };

	void preOrder() { preOrder(root); };
	void inOrder() { inOrder(root); };
	void postOrder() { postOrder(root); };

	bool isEmpty() { return root == nullptr; };
	void clear() { clear(root); };

	virtual void process(T& val) { cout << val << " "; };

	virtual void add(T val) = 0; //new Node() ...
	virtual void remove(T val) = 0;
	virtual bool search(const T& val) const = 0;

	bool isHeap() { return isMaxHeap(root) || isMinHeap(root); };
	bool isEven() { return isEven(root); }

	bool isCond( bool (*func) (T) ) { return isCond(func, root); }

};

template <class T>
void Tree<T>::preOrder(Node* current)
{
	if (current)
	{
		//cout << current->value << " ";
		process(current->value);
		preOrder(current->left);
		preOrder(current->right);
	}
	//else
		//return

}

template <class T>
void Tree<T>::inOrder(Node* current)
{
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

template <class T>
void Tree<T>::postOrder(Node* current)
{
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{
		clear(current->left);
		clear(current->right);
		delete current;
	}
}

template <class T>
bool Tree<T>::isMaxHeap(Node* current)
{
	if (!current)
		return true;
	if (current->left && current->value < current->left->value ||
		current->right && current->value < current->right->value)
		return false;

	return isMaxHeap(current->left) && isMaxHeap(current->right);
}

template <class T>
bool Tree<T>::isMinHeap(Node* current)
{
	if (!current)
		return true;
	if (current->left && current->left->value < current->value ||
		current->right && current->right->value < current->value)
		return false;

	return isMinHeap(current->left) && isMinHeap(current->right);
}

template <class T>
bool Tree<T>::isEven(Node* current)
{
	if (!current)
		return true;
	if (current->value % 2 == 1)
		return false;
	
	return isEven(current->left) && isEven(current->right);

}

template <class T>
bool Tree<T>::isCond( bool (*func) (T), Node* current)
{
	if (!current)
		return true;
	if (!func(current->value))
		return false;

	return isCond(func, current->left) && isCond(func, current->right);

}


class Rational
{
public:
	int mone;
	int mechane;
};

class ReverseTree : public Tree<Rational>
{

public:
	void process(Rational& val) 
	{ 
		int t = val.mone;
		val.mone = val.mechane;
		val.mechane = t;
	}
	void reverse() { preOrder(); };
};