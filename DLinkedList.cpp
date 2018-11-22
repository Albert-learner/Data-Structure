#include <iostream>
#include <cstring>

using namespace std;

class Node
{
private:
	int data;
	Node *next;
	Node *pre;
	Node(int value) { data = value; next = 0; pre = 0; };

	friend class List;
};
class List
{
private:
	Node * head;
public:
	List() { head = 0; };
	~List();
	void insertNode(int num);
	void insertAfter(int num, int count);
	void insertBefore(int num, int count);
	void deleteNode(int num);
	void searchList(int num);
	void forwardPrint();
	void backwardPrint();

};

void List::insertNode(int num) //��������
{
	Node *temp = new Node(num);
	Node *p, *q;


	if (!head)
	{
		head = temp;
	}
	else if ((temp->data) < (head->data))
	{
		temp->next = head;
		head->pre = temp;
		head = temp;
	}
	else
	{
		p = head;
		q = head;

		while ((p != 0) && ((p->data) < (temp->data)))
		{
			q = p;
			p = p->next;
		}
		if (p != 0)
		{
			q->next = temp;
			temp->pre = q;
			temp->next = p;
			p->pre = temp;
		}
		else
		{
			q->next = temp;
			temp->pre = q;
		}
	}
}

void List::insertAfter(int num, int count)
{
	Node *temp = new Node(num);
	Node *p, *q;

	p = head;
	q = head;
	for (int i = 0; i < count; i++)
	{
		q = p;
		p = p->next;
	}
	if (p == 0)
	{
		q->next = temp;
		temp->pre = q;
	}
	else
	{
		q->next = temp;
		temp->pre = q;
		temp->next = p;
		p->pre = temp;

	}
}

void List::insertBefore(int num, int count)
{
	Node *temp = new Node(num);
	Node *p, *q;

	p = head;
	q = head;
	for (int i = 0; i < count - 1; i++)
	{
		q = p;
		p = p->next;
	}
	if (p == 0)
	{
		q->next = temp;
		temp->pre = q;
	}
	else
	{
		q->next = temp;
		temp->pre = q;
		temp->next = p;
		p->pre = temp;

	}
}

void List::forwardPrint() //�տ������� ���
{
	Node *p;

	p = head;

	if (!head)
		cout << "�� ����Ʈ �Դϴ�." << endl;
	else
	{
		while (p != 0)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}

	cout << endl;
}

void List::backwardPrint() //�ڿ������� ���
{
	Node *p;

	p = head;
	if (!head)
	{
		cout << "�� ����Ʈ�Դϴ�. " << endl;
	}
	else
	{
		while ((p->next) != 0)
			p = p->next;


		while (p != 0)
		{
			cout << p->data << " ";
			p = p->pre;
		}
		cout << endl;
	}
}


void List::deleteNode(int num)
{
	Node *p, *q;

	p = head;
	q = head;

	for (int i = 0; i < num - 1; i++)
	{
		q = p;
		p = p->next;
	}
	if (head == 0)
	{
		cout << "�󸮽�Ʈ�Դϴ�!!!" << endl;
	}
	else if (p->next == 0)
	{
		q->next = 0;
		delete p;
	}
	else if (num == 1)
	{
		p = p->next; //����ĭ���� �Ű��ش�
		p->pre = NULL;
		head = p;
		delete q;
	}
	else {
		q->next = p->next;
		(p->next)->pre = q;
	}


}

void List::searchList(int num)
{
	Node *p;

	p = head;

	for (int i = 0; i < num - 1; i++)
	{
		p = p->next;
		if (p == 0)
		{
			cout << "������ ������ϴ�." << endl;
			break;
		}
	}
	cout << p->data << "�� ã�ҽ��ϴ�.";


}



int main()
{
	List l1;
	char input[10];
	int num;
	int count;

	while (1)
	{
		cout << "1.Insert 2.InsertAfter 3.insetBefore 4.ForwardPrint 5.BackwardPrint 6.Delete 7.searchList" << endl;
		cin >> input;
		if (strcmp(input, "1") == 0) //����
		{
			cout << "������ �����͸� �Է��ϼ���." << endl;
			cin >> num;
			l1.insertNode(num);
		}
		else if (strcmp(input, "2") == 0) //���û���(����)
		{
			cout << "���°�� �������� �����Ͻðڽ��ϱ�?" << endl;
			cin >> count;
			cout << "������ �����͸� �Է��ϼ���." << endl;
			cin >> num;
			l1.insertAfter(num, count);
		}
		else if (strcmp(input, "3") == 0)//���û���(����)
		{
			cout << "���°�� �������� �����Ͻðڽ��ϱ�?" << endl;
			cin >> count;
			cout << "������ �����͸� �Է��ϼ���." << endl;
			cin >> num;
			l1.insertBefore(num, count);
		}
		else if (strcmp(input, "4") == 0) //forward
		{
			l1.forwardPrint();
		}
		else if (strcmp(input, "5") == 0) //backward
		{
			l1.backwardPrint();
		}
		else if (strcmp(input, "6") == 0) //delete
		{
			cout << "���° �����͸� �����Ͻðڽ��ϱ�?" << endl;
			cin >> num;
			l1.deleteNode(num);
		}
		else if (strcmp(input, "7") == 0)
		{
			cout << "�� ��° ��带 ã���ðڽ��ϱ�?" << endl;
			cin >> num;
			l1.searchList(num);
		}
	}
}

List::~List()
{
	Node *p, *q;

	p = head;
	q = head;

	while (p != 0)
	{
		q = p;
		p = p->next;
		delete q;
	}

}


