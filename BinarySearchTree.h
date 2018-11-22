#ifndef _BINARYSEARCHTREE_H__
#define _BINARYSEARCHTREE_H__
#include <iostream>
#include <cstring>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
	friend class BinaryTree;
};

class BinaryTree
{
private:
	Node * root;
public:
	BinaryTree()
	{
		root = NULL;
	}
	
	void setRoot(Node *p) 
	{
		this->root = p;
		return ;
	}

	Node *getRoot()
	{
		return root;
	}

	Node *searchBSTree(Node *p, int key);
	Node *insertBSTree(Node *p, int key);
	Node *find_min(Node *p);
	Node *deleteBSTree(Node *p, int key);
	void drawBSTree(Node *p, int level);
};
#endif // !_BINARYSEARCHTREE_H__