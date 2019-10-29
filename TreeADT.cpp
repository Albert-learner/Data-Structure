#include "Tree.h"

int Node::get_priority(char value)
{
	switch (value)
	{
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
	default:
		return 4;
		break;
	}
}

void Tree::inorder(Node *p)
{
	if (p)
	{
		inorder(p->left);
		cout << " "<<p->data<<" ";
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
		cout << " " <<p->data <<" ";
	}
}

void Tree::preorder(Node *p)
{
	if (p)
	{
		cout << " " <<p->data<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}

void Tree::insert_operand(Node *newp)
{
	if (root == NULL)
	{
		root = newp;
		return ;
	}
	else
	{
		Node *p = root;
		while (p->right != NULL)
		{
			p = p->right;
		}
		p->right = newp;
		return ;
	}
}

void Tree::insert_operator(Node *newp)
{
	if (root->get_priority(root->data) >= newp->get_priority(newp->data))
	{
		newp->left = root;
		root = newp;
	}
	else
	{
		newp->left = root->right;
		root->right = newp;
	}
}

int Tree::evalTree(Node *p)
{
	int value, left = 0, right = 0;
	if (p != NULL)
	{
		if (isdigit(p->data))
		{
			value = p->data - '0';
		}
		else
		{
			left = evalTree(p->left);
			right = evalTree(p->right);
			switch (p->data)
			{
			case '+':
				value = left + right;
				break;
			case '-':
				value = left - right;
				break;
			case '*':
				value = left * right;
				break;
			case '/':
				value = left / right;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		cout << "Empty tree" << "\n";
	}
	return value;
}

void Tree::draw(Node *p, int level)
{
	if (p != 0 && level <= 7)
	{
		draw(p->right, level + 1);
		for (int i = 1; i <= (level - 1); i++)
		{
			cout << "   ";
		}
		cout << p->data;

		if (p->left != 0 && p->right != 0)
		{
			cout << "<" << endl;
		}
		else if (p->right != 0)
		{
			cout << "/" << endl;
		}
		else if (p->left != 0)
		{
			cout << "\\" << endl;
		}
		else
		{
			cout << endl;
		}
		draw(p->left, level + 1);
	}
}

void Tree::drawInorderTree(Node *p)
{
	if (p)
	{
		cout << "(";
		drawInorderTree(p->left);
		cout << p->data;
		drawInorderTree(p->right);
		cout << ")";
	}
}

void Tree::drawPostorderTree(Node *p)
{
	if (p)
	{
		cout << "(";
		drawPostorderTree(p->left);
		drawPostorderTree(p->right);
		cout << p->data;
		cout << ")";
	}
}

void Tree::drawPreorderTree(Node *p)
{
	if (p)
	{
		cout << "(";
		cout << p->data;
		drawPreorderTree(p->left);
		drawPreorderTree(p->right);
		cout << ")";
	}
}

void Tree::drawTree(Node *p)
{
	if (p)
	{
		if (!isdigit(p->data))
		{
			cout << "(";
		}
		drawTree(p->left);
		cout << p->data;
		drawTree(p->right);
		if (!isdigit(p->data))
		{
			cout << ")";
		}
	}
}
