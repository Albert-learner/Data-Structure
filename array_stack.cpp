#include "arrayStack.h"
#include <stdio.h>
#include <malloc.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - ������ ũ���� ������ �����ϴ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  size - ������ ũ��
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp, int size)
{
	if(sp==NULL)
		return FALSE;
	sp=(Stack*)malloc(sizeof(int)*size);
	
	if(sp->stack==NULL)
		return FALSE;
	sp->top=(int)malloc(sizeof(int)*size);
	if(sp->top==NULL)
		return FALSE;
	sp->size=0;
	return TRUE;  // ���ϰ��� �������ּ���.
}
/*-----------------------------------------------------------------------------------
Function name	: isStackFull - ������ �� ���ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ �� �������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
BOOL isStackFull(Stack *sp)
{
	if(sp==NULL)
		return FALSE;
	if(sp!=NULL){
		if(sp->stack!=NULL)
			return TRUE;
		else
			return FALSE;
	}
	return FALSE;  // ���ϰ��� �������ּ���.
}
/*-----------------------------------------------------------------------------------
Function name	: isStackEmpty - ������ ������ ����ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ ������ ��������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
BOOL isStackEmpty(Stack *sp)
{
	if(sp==NULL)
		return FALSE;
	if(sp!=NULL){
		if(sp->stack!=NULL)
			return FALSE;
		else
			return TRUE;
	}
	return TRUE;  // ���ϰ��� �������ּ���.
}
/*--------------------------------------------------------------------------------------
Function name	: push - ���ÿ� ������ �ϳ��� ������
Parameters		: sp - ���ð��� ����ü�� �ּ�
inData - ���ÿ� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL push(Stack *sp, int inData)
{
	Stack *np;
	int IN;
	if(sp==NULL)
		return FALSE;
	np=(Stack*)malloc(sizeof(int)*size);
	IN=(int*)malloc(sizeof(int)*size));
	if(IN!=inData){
		return FALSE:
	else
		return inDATA;
	}
	return TRUE;  // ���ϰ��� �������ּ���.
}
/*--------------------------------------------------------------------------------------
Function name	: pop - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���ð��� ����ü�� �ּ�
popData -  ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL pop(Stack * sp, int *popData)
{
	
	return TRUE;  // ���ϰ��� �������ּ���.
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - ������ ��� ������ ���(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp)
{
	// TODO
	return;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack -  ���� �Ҹ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp)
{
	// TODO
	return;
}
