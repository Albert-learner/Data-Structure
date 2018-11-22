#include <iostream>
#include <string>
using namespace std;

int get_priority(char value) 
{
	switch (value) {
	case '^':
		return 3;
		break;
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
		for (int j = 0; j < s.size(); j++) 
		{
			Node *n = new Node(s[j]);
			if ('0' <= s[j] && s[j] <= '9') 
			{
				insert_operand(n);
			}
			else if (('a' <= s[j] && s[j] <= 'z') || ('A' <= s[j] && s[j] <= 'Z'))
			{
				insert_operand(n);
			}
			else
				insert_operator(n);
		}
	}

	void inorder(Node *p);
	void postorder(Node *p);
	void preorder(Node *p);
	
	void insert_operand(Node *n);
	void insert_operator(Node *n);
	int evalTree(Node *p);
	Node *getRoot() 
	{
		return root;
	}
};

void Tree::inorder(Node *p) 
{
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->data;
		inorder(p->right);
	}
	return;
}

void Tree::postorder(Node *p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->data;
	}
	return;
}

void Tree::preorder(Node *p)
{
	if (p != NULL)
	{
		cout << p->data;
		preorder(p->left);
		preorder(p->right);
	}
	return;
}

void Tree::insert_operand(Node *n)
{
	if (root == NULL)
	{
		root = n;
		return;
	}
	Node *p = root;
	while (p->right != NULL)
	{
		p = p->right;
	}
	p->right = n;
	return;
}

void Tree::insert_operator(Node *n)
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

int Tree::evalTree(Node *p)
{
	int value_cost, left = 0, right = 0;
	if (p != NULL)
	{
		if (isdigit(p->data))
		{
			value_cost = p->data - '0';
		}
		else
		{
			left = evalTree(p->left);
			right = evalTree(p->right);
			switch (p->data)
			{
			case '^':
				value_cost = 1;
				for (int i = 0; i < right; i++)
				{
					value_cost *= left;
				}
			case '+':
				value_cost = left + right;
				break;
			case '-':
				value_cost = left - right;
				break;
			case '*':
				value_cost = left * right;
				break;
			case '/':
				value_cost = left / right;
				break;
			}
		}
	}
	else
		cout << "Empty tree" << endl;
	return value_cost;
}

int main()
{
	string s = "8+9-2*3";
	string s1 = "a+b*c-d";
	
	Tree t(s);
	Tree t1(s1);
	
	t.inorder(t.getRoot());
	cout << endl;
	t.postorder(t.getRoot());
	cout << endl;
	t.preorder(t.getRoot());
	cout << endl;
	cout << "--------------------------------" << endl;
	t1.preorder(t1.getRoot());
	cout << endl;
	t1.inorder(t1.getRoot());
	cout << endl;
	t1.postorder(t1.getRoot());
	cout << endl;
	
	cout << t.evalTree(t.getRoot()) << endl;
	return 0;
}
