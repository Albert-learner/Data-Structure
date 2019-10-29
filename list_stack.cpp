#include "listStack.h"
#include <stdio.h>
#include <malloc.h>
/*--------------------------------------------------------------------------------------
Function name	: createStack - 링크드리스트로 관리되는 스택 생성 함수
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
--------------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp)
{
	if(sp==NULL)
		return FALSE;
	sp->head=(Snode*)calloc(1,sizeof(Snode));
	if(sp->head==NULL)
		return FALSE;
	sp->tail=(Snode*)calloc(1,sizeof(Snode));
	if(sp->tail==NULL){
		free(sp->head);
		return FALSE;
	}

	sp->head->next=sp->tail;
	sp->tail->next=sp->tail;
   	return TRUE;  // 리턴값은 수정해주세요
}
/*--------------------------------------------------------------------------------------
Function name	: isStackEmpty() - 스택이 비어있는가 검사
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 완전히 비어있으면 TRUE 리턴, 비어있지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL isStackEmpty(const Stack *sp)
{
	if(sp==NULL)
		return FALSE;

	if(sp->head->next==sp->tail)
		return TRUE;
	else
		return FALSE;
   	return TRUE;  // 리턴값은 수정해주세요
}
/*--------------------------------------------------------------------------------------
Function name	: push() - 스택에 데이터 하나를 저장함
Parameters		: sp - 스택관리 구조체의 주소
				  pushData  - 스택에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL push(Stack *sp, int pushData)
{
	Snode *p;
	if(sp==NULL)
		return FALSE;
	p=(Snode*)calloc(1,sizeof(Snode));
	if(p==NULL)
		return FALSE;
	else{
		p->next=sp->head->next;
		sp->head->next=p;
		p->data=pushData;
		return TRUE;
	}
   	return TRUE;  // 리턴값은 수정해주세요
}
/*--------------------------------------------------------------------------------------
Function name	: pop() - 스택에서 데이터 하나를 꺼냄
Parameters		: sp - 스택관리 구조체의 주소
popData - 꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL pop(Stack *sp, int *popData)
{
	Snode *cur;
	if(sp==NULL)
		return FALSE;
	if(isStackEmpty(sp)==TRUE)
		return FALSE;
	else
		*popData=sp->head->next->data;
		cur=sp->head->next;
		sp->head->next=sp->head->next->next;
		free(cur);
		return TRUE;
   	return TRUE;  // 리턴값은 수정해주세요
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - 스택의 모든 데이터 출력(pop하면 나오는 순서대로 출력)
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printStack(const Stack *sp)
{
	Snode *cur;
	if(sp==NULL)
		return ;

	if(isStackEmpty(sp)==TRUE){
		printf("Stack is empty!/n");
		return ;
	}
	cur=sp->head->next;
	while(cur!=sp->tail)
	{
		printf("%5d/n", cur->data);
		cur=cur->next;
	}
	printf("/n");
	return;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack() - 스택 소멸 함수
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp)
{
	Snode *c;
	if(sp==NULL)
		return ;
	while(sp->head->next!=sp->tail)
	{
		c=sp->head->next;
		sp->head->next=sp->head->next->next;
		free(c);
	}
	free(sp->head);
	free(sp->tail); 
	sp->head=sp->tail=NULL;
	return;
}
