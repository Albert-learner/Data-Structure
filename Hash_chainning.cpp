#include <iostream>
using namespace std;

#define max_size 7

class Node
{
public:
	Node *link;
	int key;
	Node(int data)
	{
		key = data;
		link = NULL;
	}
	friend class Hash;
};

class Hash
{
private:
	Node *head;

public:
	void insertKey(int key);
	void deleteKey(int key);
	void finding(int key);
	Hash()
	{
		head = NULL;
	}
	int findKey(int key);
	int hashKey(int key)
	{
		return key % max_size;
	}
	Node *getHead()
	{
		return head;
	}
	void traverse();
};

Hash myHash[max_size];

int main()
{
	int idx, num;
	char input;
	Hash hash;

	while (1)
	{
		cout << "i. insert d. delete f. find q. quit" << endl;
		cin >> input;

		if (input == 'i')
		{
			cout << "입력할 데이터는 ? " << endl;
			cin >> num;
			idx = hash.hashKey(num);
			if (!myHash[idx].findKey(num))
			{
				myHash[idx].insertKey(num);
			}
			else
			{
				cout << "이미 존재하는 데이터입니다." << endl;
			}

			for (int i = 0; i < max_size; i++)
			{
				cout << "Htable[" << i << "]: ";
				myHash[i].traverse();
			}
		}
		else if (input == 'd')
		{
			cout << "삭제할 데이터는 ? " << endl;
			cin >> num;
			idx = hash.hashKey(num);
			myHash[idx].deleteKey(num);

			for (int i = 0; i < max_size; i++)
			{
				cout << "Htable[" << i << "]: ";
				myHash[i].traverse();
			}
		}
		else if (input == 'f')
		{
			cout << "찾을 데이터는 ? " << endl;
			cin >> num;
			idx = hash.hashKey(num);
			myHash[idx].finding(num);

			for (int i = 0; i < max_size; i++)
			{
				cout << "Htable[" << i << "]: ";
				myHash[i].traverse();
			}
		}
		else if (input == 'q')
		{
			break;
		}
		else
		{
			cout << "Bad Command!!!!!" << endl;
		}
	}

	return 0;
}

int Hash::findKey(int key)
{
	Node *p = head;

	while (p != NULL && p->key != key)
	{
		p = p->link;
	}

	if (!p)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void Hash::finding(int key)
{
	Node *p = head;

	while (p != NULL && p->key != key)
	{
		p = p->link;
	}
	if (!p)
	{
		cout << "No data!!!" << endl;
	}
	else
	{
		cout << key << "를 찾았습니다." << endl;
	}
}

void Hash::insertKey(int key)
{
	Node *tmp = new Node(key);
	Node *p;

	if (head == NULL)
	{
		head = tmp;
	}
	else
	{
		p = head;
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = tmp;
	}
}

void Hash::deleteKey(int key)
{
	Node *p, *q;

	p = head;

	if (head->key == key)
	{
		q = p;
		p = p->link;
		head = p;
		delete q;
	}
	else
	{
		while (p->key != key && p != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p->key == key)
		{
			q->link = p->link;
			delete p;
		}
		else
		{
			cout << "없는 데이터입니다." << endl;
		}
	}
}

void Hash::traverse()
{
	Node *p = head;

	while (p != NULL)
	{
		cout << p->key << " -> ";
		p = p->link;
	}
	cout << endl;
}