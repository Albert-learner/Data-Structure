#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	char data;
	Node *left;
	Node *right;

public:
	Node(char value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
	int get_priority(char value);
	friend class Tree;
};

class Tree
{
private:
	Node *root;

public:
	Tree()
	{
		root = NULL;
	}
	Tree(string s)
	{
		root = NULL;
		for (int i = 0; i < s.size(); i++)
		{
			Node *newp = new Node(s[i]);
			if (isdigit(s[i]))
			{
				insert_operand(newp);
			}
			else if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
			{
				insert_operand(newp);
			}
			else
			{
				insert_operator(newp);
			}
		}
	}

	void inorder(Node *p);
	void postorder(Node *p);
	void preorder(Node *p);

	void insert_operand(Node *newp);
	void insert_operator(Node *newp);
	void draw(Node *p, int level);
	void drawInorderTree(Node *p);
	void drawPostorderTree(Node *p);
	void drawPreorderTree(Node *p);
	void drawTree(Node *p);
	int evalTree(Node *p);
	
	Node *getRoot()
	{
		return root;
	}
};