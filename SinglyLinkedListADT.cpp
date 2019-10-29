#include "SinglyLinkedList.h"

bool List::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void List::insertNode(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	Node *p, *q;

	if (head == NULL)
	{
		head = temp;
	}
	else if (temp->data < head->data)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		p = head;
		while ((p != NULL) && (p->data < temp->data))
		{
			q = p;
			p = p->next;
		}
		if (p != NULL)
		{
			temp->next = p;
			q->next = temp;
		}
		else
		{
			q->next = temp;
		}
	}
}

void List::appendNode(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		Node *ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void List::deleteNode(int num)
{
	Node *p, *q;

	if (head == NULL)
	{
		cout << "not found" << "\n";
	}
	else
	{
		if (head->data == num)
		{
			p = head;
			head = head->next;
			delete(p);
		}
		else
		{
			p = head;
			q = head;
			while (p != NULL && p->data != num)
			{
				q = p;
				p = p->next;
			}
			if (p != NULL)
			{
				q->next = p->next;
				delete(p);
			}
			else
			{
				cout << num << "is not in the list" << "\n";
			}
		}
	}
}

void List::searchNode(int num)
{
	Node *p;

	if (head != NULL)
	{
		p = head;
		while (p != NULL && p->data != num)
		{
			p = p->next;
		}
		if (p)
		{
			cout << p->data << " is in the list." << "\n";
		}
		else
		{
			cout << num << " is not in the list." << "\n";
		}
	}
	else
	{
		cout << "List is empty" << "\n";
	}
}

void List::searchNode_pos(int cost)
{
	Node *p;
	p = head;
	for (int i = 0; i < cost; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			cout << "Not found" << "\n";
			break;
		}
		else
		{
			continue;
		}
	}
}

Node *List::invertList(Node *head)
{
	Node *middle, *trail;
	middle = NULL;

	while (head)
	{
		trail = middle;
		middle = head;
		head = head->next;
		middle->next = trail;
	}
	return middle;
}

void List::traverseList()
{
	Node *p;

	if (!isEmpty())
	{
		p = head;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << "\n";
	}
	else
	{
		cout << "List is Empty!" << "\n";
	}
}

void List::printLast()
{
	Node *p;

	if (!isEmpty())
	{
		p = head;
		while (p)
		{
			p = p->next;
			if (p->next == NULL)
			{
				cout << p->data << "\n";
				break;
			}
		}
	}
	else
	{
		cout << "List is Empty" << "\n";
	}
}

List::~List()
{
	Node *p;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}