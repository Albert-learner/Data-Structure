#include "HW3.h"

/*
Function name : Insert - head node에 node추가
Parameters : lp - 리스트 관리 구조체 주소,
			 char형 name, int형 data, string형 major, char형 grade - 추가할 데이터
Returns : 없음
*/
void List::insert(List *lp, char name, int ID, string major, char grade)
{
	Node *p;
	p = new Node();
	p->Name = name;
	p->ID = ID;
	p->major = major;
	p->Grade = grade;

	p->next = NULL;

	if (lp->head == NULL)
	{
		lp->head = p;
	}
	else if (p->Name < lp->head->Name)
	{
		p->next = lp->head;
		lp->head = p;
	}
	else
	{
		Node *curp, *befp;
		curp = lp->head;
		while ((curp != NULL) && (curp->Name < p->Name))
		{
			befp = curp;
			curp = curp->next;
		}
		if (curp != NULL)
		{
			p->next = curp;
			befp->next = p;
		}
		else
		{
			befp->next = p;
		}
	}
}


/*
Function name   : displayList - 리스트 내의 모든 데이터 출력
Parameters      : lp - 리스트 관리 구조체의 주소
Returns         : 없음
*/
void List::displayList(List *lp)
{
	Node *tp;

	if (lp == NULL)
	{
		cout << "List is Empty" << "\n";
		return ;
	}
	else
	{
		tp = lp->head;

		while (tp != NULL)
		{
			cout << tp->Name << ' ' << tp->ID << ' ' << tp->major << ' ' << tp->Grade << "\n";
			tp = tp->next;
		}
		return ;
	}
}


/*
Function name   : searchNode - grade와 일치하는 node 검색
Parameters      : lp - 리스트 관리 구조체의 주소
				  char형 grade - 찾아야할 데이터
Returns         : 없음
*/
void List::searchNode(List *lp, char grade)
{
	if (lp == NULL)
		return;

	Node *nS;
	nS = lp->head;
	while (nS != NULL)
	{
		if (nS->Grade == grade)
		{
			cout << nS->Name << ' ' << nS->ID << ' ' << nS->major << ' ' << nS->Grade << '\n';
		}
		nS = nS->next;
	}
}


/*
Function name : search_major - major와 일치하는 node 검색
Parameters : lp - 리스트 관리 구조체의 주소
Returns : 없음
*/
void List::search_major(List *lp)
{
	Node *Sn;
	Sn = lp->head;

	while (Sn != NULL)
	{
		if (Sn->major == "CS")
		{
			cout << Sn->Name << ' ' << Sn->ID << ' ' << Sn->major << ' ' << Sn->Grade << "\n";
			Sn = Sn->next;
		}
		else
		{
			Sn = Sn->next;
		}
	}
	return ;
}


/*
Function name : concat - 두 개의 리스트를 포인터 변수로 받아와서 하나의 리스트로 합친다.
Parameters : lp1 - 첫 번째 리스트 관리 구조체의 주소
			 lp2 - 두 번째 리스트 관리 구조체의 주소
Returns : 두 개의 리스트를 합친 관리 구조체의 주소
*/
List *List::concat(List *lp1, List *lp2)
{
	Node *temp;

	if (lp1 == NULL)
	{
		return lp2;
	}
	else
	{
		if (lp2 != NULL)
		{
			for (temp = lp1->head; temp->next != NULL; temp = temp->next);
			temp->next = lp2->head;
			return lp1;
		}
		else
		{
			return lp1;
		}
	}
}


/*
Function name : sortList - 이름을 기준으로 알파벳 순서대로 정렬시킨다. 
Parameters : lp - 리스트 관리 구조체의 주소
Returns : 없음
*/
void List::sortList(List *lp)
{
	char temp_Name, temp_Grade;
	string temp_major;
	int temp_ID;

	if (lp == NULL)
	{
		return ;
	}
	else
	{
		Node *bp = lp->head;
		Node *cp = lp->head;

		while (bp != NULL)
		{
			cp = bp->next;
			while (cp != NULL)
			{
				if (bp->Name > cp->Name)
				{
					temp_Name = cp->Name;
					temp_ID = cp->ID;
					temp_major = cp->major;
					temp_Grade = cp->Grade;

					cp->Name = bp->Name;
					cp->ID = bp->ID;
					cp->major = bp->major;
					cp->Grade = bp->Grade;

					bp->Name = temp_Name;
					bp->ID = temp_ID;
					bp->major = temp_major;
					bp->Grade = temp_Grade;

					cp = cp->next;
				}
				else
				{
					cp = cp->next;
				}
			}
			bp = bp->next;
		}
	}
	return ;
}