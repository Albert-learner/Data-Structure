#include "listStack.h"
#include <stdio.h>
#include <malloc.h>
/*--------------------------------------------------------------------------------------
Function name	: createStack - ��ũ�帮��Ʈ�� �����Ǵ� ���� ���� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
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
   	return TRUE;  // ���ϰ��� �������ּ���
}
/*--------------------------------------------------------------------------------------
Function name	: isStackEmpty() - ������ ����ִ°� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
BOOL isStackEmpty(const Stack *sp)
{
	if(sp==NULL)
		return FALSE;

	if(sp->head->next==sp->tail)
		return TRUE;
	else
		return FALSE;
   	return TRUE;  // ���ϰ��� �������ּ���
}
/*--------------------------------------------------------------------------------------
Function name	: push() - ���ÿ� ������ �ϳ��� ������
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  pushData  - ���ÿ� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
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
   	return TRUE;  // ���ϰ��� �������ּ���
}
/*--------------------------------------------------------------------------------------
Function name	: pop() - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���ð��� ����ü�� �ּ�
popData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
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
   	return TRUE;  // ���ϰ��� �������ּ���
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - ������ ��� ������ ���(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
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
Function name	: destroyStack() - ���� �Ҹ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
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
