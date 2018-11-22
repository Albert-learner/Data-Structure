#include <iostream>

using namespace std;

#define max_size 7

class Node
{
public:
	Node * link;
	int key;
	Node(int data) { key = data; link = NULL; }

	friend class Hash;
};

class Hash
{
private:
	Node * head;
public:
	void insertKey(int key);
	void deleteKey(int key);
	void finding(int key);
	Hash() { head = NULL; }
	int findKey(int key);
	int hashKey(int key) { return key % max_size; }
	Node* getHead() { return head; }
	void traverse();
};

Hash myHash[max_size];

int Hash::findKey(int key)
{
	Node *p;

	p = head;

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
	Node *p;

	p = head;

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
		cout << key << "�� ã�ҽ��ϴ�." << endl;
	}
}

void Hash::insertKey(int key)
{
	Node *temp = new Node(key);
	Node *p;

	if (head == NULL)
	{
		head = temp;

	}
	else
	{
		p = head;

		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
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
			cout << "���� �������Դϴ�" << endl;
		}
	}
}

void Hash::traverse()
{
	Node *p;

	p = head;

	while (p != NULL)
	{
		cout << p->key << " ";
		p = p->link;
	}

	cout << endl;
}





int main()
{
	int index;
	int input;
	int num;
	Hash h;
	while (1)
	{
		cout << "1.insert   2.delete   3.traverse   4.find    5.quit " << endl;
		cin >> input;


		if (input == 1)
		{
			cout << "�Է��� �����ʹ�?  " << endl;
			cin >> num;
			index = h.hashKey(num);
			if (!myHash[index].findKey(num))
				myHash[index].insertKey(num);
			else
				cout << "�̹� �����ϴ� �������Դϴ�." << endl;
		}
		else if (input == 2)
		{
			cout << "������ �����ʹ�?  " << endl;
			cin >> num;
			index = h.hashKey(num);
			myHash[index].deleteKey(num);
		}
		else if (input == 3)
		{
			for (int i = 0; i < max_size; i++)
			{
				cout << i << "��" << endl;
				myHash[i].traverse();
			}
		}
		else if (input == 4)
		{
			cout << "ã�� �����ʹ� ? " << endl;
			cin >> num;
			index = h.hashKey(num);
			myHash[index].finding(num);
		}
		else if (input == 5)
		{
			break;
		}
		else
		{
			cout << "Bad Command!!!!!!" << endl;
		}

	}


}
