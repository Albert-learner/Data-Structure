#include "DoublyLinkedList.h"

int List::isEmpty()
{
	return head == NULL;
}

void List::insertList(int data)
{
	Node *temp = new Node(data);
	Node *p, *q;

	if (head == NULL)
	{
		head = temp;
	}
	else if (temp->val < head->val)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
	{
		p = head;
		q = head;

		while ((p != NULL) && (p->val < temp->val))
		{
			q = p;
			p = p->next;
		}
		if (p != NULL)
		{
			temp->next = p;
			temp->prev = q;
			q->next = temp;
			p->prev = temp;
		}
		else
		{
			q->next = temp;
			temp->prev = q;
		}
	}
}

void List::deleteList(int key)
{
	Node *p, *q;

	if (head == NULL)
	{
		cout << "List is empty" << "\n";
	}
	else
	{
		if (head->val == key)
		{
			if (head->next != NULL)
			{
				p = head;
				head = head->next;
				head->prev = NULL;
				delete p;
			}
			else
			{
				head = NULL;
			}
		}
		else
		{
			p = head;
			q = head;

			while (p != NULL && p->val != key)
			{
				q = p;
				p = p->next;
			}
			if (p->next != NULL && p->val == key)
			{
				q->next = p->next;
				p->next->prev = q;
				delete p;
			}
			else if (p->next == NULL && p->val == key)
			{
				q->next = NULL;
				delete p;
			}
			else
			{
				cout << key << " is not in the list" << "\n";
			}
		}
	}
}

void List::forwardList()
{
	if (!isEmpty())
	{
		Node *p = head;
		cout << "----- Forward List ------" << "\n";
		while (p != NULL)
		{
			cout << p->val << "\n";
			p = p->next;
		}
	}
	else
	{
		cout << "List is empty" << "\n";
	}
}

void List::backwardList()
{
	if (!isEmpty())
	{
		Node *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		cout << "----- Backward List -----" << "\n";
		while (p != NULL)
		{
			cout << p->val << "\n";
			p = p->prev;
		}
	}
	else
	{
		cout << "List is empty" << "\n";
	}
}

void List::searchList(int key)
{
	if (!isEmpty())
	{
		Node *p = head;
		while (p != NULL && p->val != key)
		{
			p = p->next;
		}

		if (p != NULL)
		{
			cout << p->val << " is in the list" << "\n";
		}
		else
		{
			cout << key << " is not in the list" << "\n";
		}
	}
	else
	{
		cout << "List is empty" << "\n";
	}
}

int List::listLength()
{
	Node *p;
	int length = 0;

	p = head;

	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}

void List::locateCurrent(int N)
{
	Node *p;
	int pos = 1;

	if (head == NULL)
	{
		cout << "List is empty!" << "\n";
	}
	else if (listLength() >= N)
	{
		p = head;
		while (pos != N)
		{
			p = p->next;
			pos++;
		}
		cout << pos << "*";
		cout << p->val << "\n";
	}
	else
	{
		cout << "No such a line" << "\n";
	}
}