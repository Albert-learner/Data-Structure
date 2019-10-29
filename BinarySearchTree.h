#pragma once
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
	friend class BST;
};

class BST
{
private:
	Node *root;

public:
	BST()
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

	Node *searchBST(Node *p, int key);
	Node *insertBST(Node *p, int key);
	Node *find_min(Node *p);
	Node *find_max(Node *p);
	Node *deleteBST(Node *p, int level);
	void drawBST(Node *p, int level);
	void traverse();
	void inOrdetBST(Node *p);
	void postOrderBST(Node *p);
	void preOrderBST(Node *p);
	void leaf();
	int leafCount(Node *p, int count);
};

