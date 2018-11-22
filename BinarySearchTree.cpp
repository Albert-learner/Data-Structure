#include "BinarySearchTree.h"

Node *BinaryTree::searchBSTree(Node *p, int key)
{
	if (p == NULL)
		return NULL;
	else
	{
		if (key == p->data)
			return p;
		else if (key < p->data)
			p = searchBSTree(p->left, key);
		else if (key > p->data)
			p = searchBSTree(p->right, key);
	}
	return p;
}

Node *BinaryTree::insertBSTree(Node *p, int key)
{

	if (p == NULL)
	{
		Node *n = new Node(key);
		if (root == NULL)
			root = n;
		return n;
	}
	else if (key < p->data)
		p->left = insertBSTree(p->left, key);
	else if (key > p->data)
		p->right = insertBSTree(p->right, key);
	return p;
}


Node *BinaryTree::find_min(Node *p)
{
	if (p->left == NULL)
		return p;
	else
		find_min(p->left);
}

Node *BinaryTree::deleteBSTree(Node *p, int key)
{
	if (p != NULL)
	{
		if (key < p->data)
			p->left = deleteBSTree(p->left, key);
		else if (key > p->data)
			p->right = deleteBSTree(p->right, key);
		else if ((p->left == NULL) && (p->right == NULL))
		{
			if (p == root)
			{
				root = NULL;
			}
			p = NULL;
		}
		else if (p->left == NULL)
		{
			Node *del;
			del = p;
			if (del == root)
			{
				root = p;
			}
			p = p->right;
			delete(del);
		}
		else if (p->right == NULL)
		{
			Node *del;
			del = p;
			if (del == root)
			{
				root = p;
			}
			p = p->left;
			delete(del);
		}
		else
		{
			Node *tmp=find_min(p->right);
			p->data = tmp->data;
			p->right = deleteBSTree(p->right, p->data);
		}
	}
	else
		cout << "Not found" << endl;
	return p;
}

void BinaryTree::drawBSTree(Node *p, int level)
{
	if (p != NULL && level <= 7)
	{
		drawBSTree(p->right, level + 1);
		for (int i = 1; i <= (level-1); i++)
			cout << "    ";
		cout << p->data;

		if (p->left != 0 && p->right != 0)
			cout << "<" << endl;
		else if (p->right != 0)
			cout << '/' << endl;
		else if (p->left != 0)
			cout << "\\" << endl;
		else
			cout << endl;
		drawBSTree(p->left, level + 1);
	}
}