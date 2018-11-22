#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_STACK_SIZE = 50;

class Stack
{
	int top;
	char data[MAX_STACK_SIZE];
public:
	Stack()
	{
		top = -1;
	}
	bool isEMpty()
	{
		return top == -1;
	}
	bool isFull()
	{
		return top == MAX_STACK_SIZE - 1;
	}
	void push(char e)
	{
		if (isFull())
			return ;
		
		data[++top] = e;
	}
	char pop()
	{
		if (isEMpty())
			exit(1);

		return data[top--];
	}
	char peek()
	{
		if (isEMpty())
			exit(1);

		return data[top];
	}
	void display()
	{
		if (isEMpty())
			return ;

		for (int i = 0; i < top + 1; i++)
		{
			cout << data[i] << ' ';
		}
		cout << endl;
	}
};

int get_priority(char v)
{
	switch (v)
	{
	case '*':
	case '/':
		return 2;
		break;
	case '+':
	case '-':
		return 1;
		break;
	default:
		return 4;
		break;
	}
}

class Node
{
public:
	char data;
	int prio;
	Node *left;
	Node *right;
	Node(char v)
	{
		data = v;
		left = NULL;
		right = NULL;
	}
	friend class Tree;
};

class Tree
{
private:
	Node * root;
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
			Node *n = new Node(s[i]);
			if ('0'<=s[i] && s[i]<='9')
				Insert_Operand(n);
			else
				Insert_Operator(n);
		}
	}
	void inorder(Node *p);
	void postorder(Node *p);
	void preorder(Node *p);

	void Insert_Operand(Node *n);
	void Insert_Operator(Node *n);
	int evalTree(Node *p);
	Node *getRoot()
	{
		return root;
	}
};

void Tree::inorder(Node *p)
{
	if (p)
	{
		inorder(p->left);
		cout << p->data;
		inorder(p->right);
	}
	return ;
}

void Tree::postorder(Node *p)
{
	if (p)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->data;
	}
	return ;
}

void Tree::preorder(Node *p)
{
	if (p)
	{
		cout << p->data;
		preorder(p->left);
		preorder(p->right);
	}
}

void Tree::Insert_Operand(Node *n)
{
	Node *p = root;
	if (root == NULL)
	{
		root->data = p->data;
	}
	while (p->right != NULL)
	{
		p = p->right;
	}

}

void Tree::Insert_Operator(Node *n)
{
	if (get_priority(root->data) >= get_priority(n->data))
	{
		n->left = root;
		root = n;
	}
	else
	{
		n->left = root->right;
		root->right = n;
	}
}

string postorder(string s)
{
	
}

int Tree::evalTree(Node *p)
{
	int value_cost, left = 0, right = 0;
	if (p != NULL)
	{
		value_cost = p->data - '0';
	}
	else
	{
		left = evalTree(p->left);
		right = evalTree(p->right);
	}
}

int main()
{

	return 0;
}