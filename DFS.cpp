#include "DFS.h"


void Graph::insertGraph(int data) 
{
	Node *temp = new Node();
	temp->data = data;
	temp->link = NULL;
	Node *p, *q;

	if (root == NULL) 
	{

		temp->data = data;
		root = temp;
	}
	else if (temp->data < root->data) 
	{
		temp->link = root;
		root = temp;
	}
	else 
	{
		p = root;
		while (p != NULL && p->data < temp->data) 
		{
			q = p;
			p = p->link;
		}
		if (p != NULL) 
		{
			temp->link = p; q->link = temp;
		}
		else 
		{
			q->link = temp;
		}
	}
}

