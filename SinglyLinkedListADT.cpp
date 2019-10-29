#include "SinglyLinkedList.h"

/*
Function name : createList - 연결 리스트 생성 및 초기화
Parameters : lp - 리스트 관리 구조체 주소
Returns : 없음
*/
void createList(List *lp)
{
	lp->head = NULL;
}

/*
Function name : addFist - head node에 node 추가(역순 저장)
Parameters : lp - 리스트 관리 구조체 주소
			 char형 name, int형 data, string형 major, char형 grade - 추가할 데이터
Returns : 없음
*/
void addFirst(List *lp, char name, int ID, string major, char grade)
{
	Node *newp;
	newp = new Node;
	newp->Name = name;
	newp->ID = ID;
	newp->major = major;
	newp->Grade = grade;
	newp->next = NULL;

	if (lp->head == NULL)
	{
		lp->head = newp;
	}
	else if (newp->Name < lp->head->Name)
	{
		newp->next = lp->head;
		lp->head = newp;
	}
	else
	{
		Node *curp, *befp;
		curp = lp->head;
		befp = lp->head;

		while ((curp != NULL) && (curp->Name < newp->Name))
		{
			befp = curp;
			curp = curp->next;
		}

		if (curp != NULL)
		{
			newp->next = curp;
			befp->next = newp;
		}
		else
		{
			befp->next = newp;
		}
	}
}

/*
Function name : displayList - 리스트 내의 모든 데이터 출력
Parameters : lp - 리스트 관리 구조체의 주소
Returns : 없음
*/
void displayList(List *lp)
{
	Node *temp;

	if (lp == NULL)
	{
		cout << "빈 리스트입니다. " << "\n";
		return ;
	}
	else
	{
		temp = lp->head;

		while (temp != NULL)
		{
			cout << temp->Name << ' ' << temp->ID << ' ' << temp->major << ' ' << temp->Grade << '\n';
			temp = temp->next;
		}
		return ;
	}
}

/*
Function name : searchNode - grade와 일치하는 node 검색
Parameters : lp - 리스트 관리 구조체의 주소
			 char형 grade - 찾아야 할 데이터
Returns : 없음
*/
void searchNode(List *lp, char grade)
{
	if (lp == NULL)
	{
		return ;
	}
	else
	{
		Node *Snode;
		Snode = lp->head;

		while (Snode != NULL)
		{
			if (Snode->Grade == grade)
			{
				cout << Snode->Name << ' ' << Snode->ID << ' ' << Snode->major << ' ' << Snode->Grade << "\n";
			}
			Snode = Snode->next;
		}
	}
}

/*
Function name : searchNode_pos - major와 일치하는 node 검색
Parameters : lp - 리스트 관리 구조체의 주소
			 string형 major - 찾아야 할 데이터
Returns : 없음
*/
void searchNode_pos(List lp)
{
	Node *Snode;
	Snode = lp.head;

	while (Snode != NULL)
	{
		if (Snode->major == "CS")
		{
			cout << Snode->Name << ' ' << Snode->ID << ' ' << Snode->major << ' ' << Snode->Grade << "\n";
		}
		Snode = Snode->next;
	}
	return ;
}
