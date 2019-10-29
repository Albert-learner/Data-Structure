#include "BinarySearchTree.h"

Node *BST::searchBST(Node *p, int key)
{
	if (p == NULL)
		return NULL;
	else
	{
		if (key == p->data)
			return p;
		else if (key < p->data)
			p = searchBST(p->left, key);
		else if(key > p->data)
			p = searchBST(p->right, key);
	}
	return p;
}

Node *BST::insertBST(Node *p, int key)
{
	if (p == NULL)
	{
		Node *newp = new Node(key);

		if (root == NULL)
		{
			root = newp;
		}
		return newp;
	}
	else if (key < p->data)
		p->left = insertBST(p->left, key);
	else if (key > p->data)
		p->right = insertBST(p->right, key);
	return p;
}

Node *BST::find_min(Node *p)
{
	if (p->left == NULL)
		return p;
	else
		find_min(p->left);
}

Node *BST::find_max(Node *p)
{
	if (p->right == NULL)
	{
		return p;
	}
	else
	{
		find_max(p->right);
	}
}

Node *BST::deleteBST(Node *p, int key)
{
	if (p != NULL)
	{
		if (key < p->data)
			p->left = deleteBST(p->left, key);
		else if (key > p->data)
			p->right = deleteBST(p->right, key);
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
			Node *tmp = find_max(p->left);
			p->data = tmp->data;
			p->left = deleteBST(p->left, p->data);
		}
	}
	else
		cout << "Not found" << endl;
	return p;
}

void BST::drawBST(Node *p, int level)
{
	if (p != 0 && level <= 7)
	{
		drawBST(p->right, level + 1);
		for (int i = 1; i <= (level - 1); i++)
		{
			cout << "    ";
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
		drawBST(p->left, level + 1);
	}
}

void BST::traverse()
{
	cout << "----- traverse start -----"<<endl;
	inOrdetBST(root);
	cout << endl;
	postOrderBST(root);
	cout << endl;
	preOrderBST(root);
	cout << endl;
	cout << "----- traverse end -----" << endl;
}

void BST::inOrdetBST(Node *p)
{
	if (p)
	{
		inOrdetBST(p->left);
		cout << " " << p->data << " ";
		inOrdetBST(p->right);
	}
	return ;
}

void BST::postOrderBST(Node *p)
{
	if (p)
	{
		postOrderBST(p->left);
		postOrderBST(p->right);
		cout << " " << p->data << " ";
	}
	return ;
}

void BST::preOrderBST(Node *p)
{
	if (p)
	{
		cout << " " << p->data << " ";
		preOrderBST(p->left);
		preOrderBST(p->right);
	}
	return ;
}

void BST::leaf()
{
	int count = 0;
	count = leafCount(root, count);
	cout << "Leaf node count is " << count << endl;

}

int BST::leafCount(Node *p, int cnt)
{
	if (p == NULL)
	{
		cnt = 0;
	}
	else
	{
		if (p->left == NULL && p->right == NULL)
		{
			cnt++;
		}
		else
		{
			cnt = leafCount(p->left, cnt) + leafCount(p->right, cnt);
		}
	}
	return cnt;
}