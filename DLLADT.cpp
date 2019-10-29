#include "DLL.h"

bool DList::isEmpty()
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

void DList::insertList(string n, int w, int h)
{
	Node *temp = new Node();
	temp->name = n;
	temp->weight = w;
	temp->height = h;
	
	Node *p, *q;

	if (head == NULL)
	{
		head = temp;
	}
	else if (temp->name < head->name)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
	{
		p = head;
		while ((p != NULL) && !(temp->name < p->name))
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

void DList::deleteList(string key)
{
	Node *p, *q;

	if (head == NULL)
	{
		cout << "List is Empty" << "\n";
		return ;
	}
	else if (head->name == key)
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
		while ((p != NULL) && !(p->name == key))
		{
			q = p;
			p = p->next;
		}

		if (p->next != NULL && p->name == key)
		{
			q->next = p->next;
			p->next->prev = q;
			delete p;
		}
		else if (p->next == NULL && p->name == key)
		{
			q->next = NULL;
			delete p;
		}
		else
		{
			cout << "No key in DList" << "\n";
			return ;
		}
	}
}

void DList::backwardList()
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
			cout << p->name << ' ' << p->weight << ' ' << p->height << "\n";
			p = p->prev;
		}
	}
	else
	{
		cout << "List is Empty" << "\n";
	}
}

void DList::forwardList()
{
	if (!isEmpty())
	{
		Node *p = head;
		cout << "----- Forward List -----" << "\n";
		while (p != NULL)
		{
			cout << p->name << ' ' << p->weight << ' ' << p->height << "\n";
			p = p->next;
		}
	}
	else
	{
		cout << "List is Empty" << "\n";
	}
}

void DList::searchList(string key)
{
	Node *p = head;

	while ((p != NULL) && !(p->name == key)) {
		p = p->next;
	}
	if (p != NULL) 
	{
		cout << " ---- Search ----" << endl;
		cout << p->name << " " << p->weight << " " << p->height << endl;
	}
	else {
		cout << "key is not in DList" << endl;
	}
}

void DList::quit()
{
	while (head != NULL)
	{
		Node *p = head;
		head = head->next;
		delete p;
	}
}

int DList::listLength()
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

void DList::locateN(int N)
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
		cout << p->name << " " << p->weight << " " << p->height << "\n";
	}
	else
	{
		cout << "No such a line" << "\n";
	}
}