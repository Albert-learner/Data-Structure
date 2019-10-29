#include <stdio.h>
#include <string.h>
#include "testheader.h"

/*----------------------------------------------------------------------------------
Function name	: createList - 연결 리스트 생성 및 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	if(lp==NULL)
		return FALSE;
	lp->head = (Node*)malloc(sizeof(Node));
	if(lp->head == NULL)
		return FALSE;
	lp->tail = (Node*)malloc(sizeof(Node));
	if(lp->tail == NULL)
	{	free(lp->head);
		return FALSE;
	}

	lp->head->next=lp->tail;
	lp->tail->next=lp->tail;
	lp->size=0;
	return TRUE; // return 값을 적절히 수정하세요.
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, int data)
{
	Node *newp;
	if(lp == NULL){
		return FALSE;
	}
	newp=(Node*)malloc(sizeof(Node));
	if(newp != NULL){
		newp->data = data;
		newp->next = lp->head->next;
		lp->head->next = newp;
		++lp->size;
		return TRUE;
	}
	else{
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node 앞에 새 node 추가(정순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, int data)
{
	Node *np;   // addLast 노드
	Node *n;   // np노드 앞의 노드
	if(lp==NULL) // 거짓이라면
		return FALSE; //거짓값 반환
	np=(Node*)malloc(sizeof(Node)); //np노드 동적 할당
	if(np!=NULL){  // 참이라면
		n=lp->head; // 맨 처음인lp의 head 노드부터 확인
		while(n->next!=lp->tail){ //n노드의 주소값이 lp의 tail노드 향하지 않는다면
			n=n->next; //다음 노드로 증가
		} // n노드가 lp의 tail노드 향하면
		np->next=lp->tail;			//
		n->next=np;
		++lp->size;
		
	}
	return TRUE; // return 값을 적절히 수정하세요.

}

/*----------------------------------------------------------------------------------
Function name	: displayList - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	Node *tp;
	if(lp ==NULL){
		return;
	}

	tp = lp->head->next;
	while(tp!=lp->tail){
		printf("%d/n", tp->data);
		tp=tp->next;
	}
	/*tp = lp->head->next;
	while(tp<lp->tail){
		printf("%d/n", tp->data);
		tp=tp->next;
	}
	return;*/
}

/*----------------------------------------------------------------------------------
Function name	: searchNode - data와 일치하는 첫 번째 node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 검색할 데이터
Returns			: 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, int data)
{
	if(lp==NULL){
		return NULL;
	}

	Node *n;
	n=lp->head->next;
	while(n!=lp->tail){
		if(n->data == data){
			return n;
		}
		else{
			n=n->next;
		}
	}
	return NULL; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data와 일치하는 첫 번째 노드 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
data - 삭제할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, int data)
{
	Node *nd;
	Node *deln;
	if(lp == NULL){
		return FALSE;
	}
	deln = searchNode(lp, data);
	if(deln !=NULL){
		nd = lp->head;
		while(nd->next != deln){
			nd = nd->next;
		}
	}

	nd->next = deln->next;
	free(deln);
	--lp->size;
	return TRUE; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - 노드 정렬(오름차순)
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	Node *cp; 
	Node *tp;
	int t;
	if(lp == NULL){
		return;
	}
	cp = lp->head->next;
	while(cp->next!=lp->tail){
		tp=cp->next;
		while(tp !=lp->tail){
			if(cp->data>tp->data){
				tp->data=t;
				cp->data = tp->data;
				tp->data=t;
			}
			tp=tp->next;
		}
		cp=cp->next;
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	Node *dp; //제거 노드
	Node *cp; //현재 노드
	int data; // 제거할 순서
	if(lp==NULL) //거짓이면
		return ; //거짓값 출력
	if(lp!=NULL){ //참이면
		cp=lp->head; //현재 노드 head 노드로
		dp=cp->next;
		while(dp!=lp->tail){ //현재 노드가 lp의 tail 노드 아니면
			dp=cp->next; // dp(제거할 노드) 알려주기
			cp->next=dp->next; // cp노드의 next(*부분)을 dp노드 다음 노드의 주소값으로
			free(dp); // 노드 제거
		} // 제거하는 노드가 lp노드의 tail노드가 되면
		free(lp->head); // lp노드의 head 노드 제거
		free(lp->tail); // lp노드의 tail 노드 제거
		--lp->size; //lp의 노드 개수 줄이기
	}
	return ;
}
