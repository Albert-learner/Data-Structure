#include "HW2.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/*
Function name : createList - 연결 리스트 생성 밑 초기화
Parameters : lp - 리스트 관리 구조체 주소
Returns : 없음
*/
void createList(List *p)
{
	p->head = NULL;
}

/*
Function name : addFirst - head node에 node 추가(역순 저장)
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
	if (lp->head == NULL) {
		lp->head = newp;
	}
	else if (newp->Name < lp->head->Name) {
		newp->next = lp->head;
		lp->head = newp;
	}
	else
	{
		Node *cp, *bp;
		cp = lp->head;
		while ((cp != NULL) && (cp->Name <newp->Name))
		{
			bp = cp;
			cp = cp->next;
		}
		if (cp != NULL)
		{
			newp->next = cp;
			bp->next = newp;
		}
		else
			bp->next = newp;
			
	}
}
	


/*
Function name   : displayList - 리스트 내의 모든 데이터 출력
Parameters      : lp - 리스트 관리 구조체의 주소
Returns         : 없음
*/
void displayList(List *lp)
{
	Node *tp;

	if (lp == NULL) {
		cout << "빈 리스트입니다." << endl;
		return;
	}
	
	
	tp = lp->head;
	
	while (tp != NULL)
	{
		cout << tp->Name << ' ' << tp->ID << ' ' << tp->major << ' ' << tp->Grade <<'\n';
		tp = tp->next;
	}

	return;
}

/*
Function name   : searchNode - grade와 일치하는 node 검색
Parameters      : lp - 리스트 관리 구조체의 주소
				  char형 grade - 찾아야할 데이터
Returns         : 없음
*/
void searchNode(List *lp, char grade)
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
Function name   : searchNode_3 - major와 일치하는 node 검색
Parameters      : lp - 리스트 관리 구조체의 주소
				  string형 major - 찾아야할 데이터
Returns         : 없음
*/
void searchNode_3(List lp)
{

	Node *nS;
	nS = lp.head;
	while (nS != NULL)
	{
		if (nS->major=="CS")
		{
			cout << nS->Name << ' ' << nS->ID << ' ' << nS->major << ' ' << nS->Grade << '\n';
		}
		nS = nS->next;
	}
	return ;
}
