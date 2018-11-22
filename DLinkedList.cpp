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

void List::insertNode(int num) //오름차순
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

void List::forwardPrint() //앞에서부터 출력
{
	Node *p;

	p = head;

	if (!head)
		cout << "빈 리스트 입니다." << endl;
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

void List::backwardPrint() //뒤에서부터 출력
{
	Node *p;

	p = head;
	if (!head)
	{
		cout << "빈 리스트입니다. " << endl;
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
		cout << "빈리스트입니다!!!" << endl;
	}
	else if (p->next == 0)
	{
		q->next = 0;
		delete p;
	}
	else if (num == 1)
	{
		p = p->next; //다음칸으로 옮겨준다
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
			cout << "범위를 벗어났습니다." << endl;
			break;
		}
	}
	cout << p->data << "를 찾았습니다.";


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
		if (strcmp(input, "1") == 0) //삽입
		{
			cout << "삽입할 데이터를 입력하세요." << endl;
			cin >> num;
			l1.insertNode(num);
		}
		else if (strcmp(input, "2") == 0) //선택삽입(후위)
		{
			cout << "몇번째를 기준으로 삽입하시겠습니까?" << endl;
			cin >> count;
			cout << "삽입할 데이터를 입력하세요." << endl;
			cin >> num;
			l1.insertAfter(num, count);
		}
		else if (strcmp(input, "3") == 0)//선택삽입(전위)
		{
			cout << "몇번째를 기준으로 삽입하시겠습니까?" << endl;
			cin >> count;
			cout << "삽입할 데이터를 입력하세요." << endl;
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
			cout << "몇번째 데이터를 삭제하시겠습니까?" << endl;
			cin >> num;
			l1.deleteNode(num);
		}
		else if (strcmp(input, "7") == 0)
		{
			cout << "몇 번째 노드를 찾으시겠습니까?" << endl;
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


