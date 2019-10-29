#include <stdio.h>
#include <string.h>
#include "testheader.h"

/*----------------------------------------------------------------------------------
Function name	: createList - ���� ����Ʈ ���� �� �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
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
	return TRUE; // return ���� ������ �����ϼ���.
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node �ڿ� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
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
Function name	: addLast - tail node �տ� �� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, int data)
{
	Node *np;   // addLast ���
	Node *n;   // np��� ���� ���
	if(lp==NULL) // �����̶��
		return FALSE; //������ ��ȯ
	np=(Node*)malloc(sizeof(Node)); //np��� ���� �Ҵ�
	if(np!=NULL){  // ���̶��
		n=lp->head; // �� ó����lp�� head ������ Ȯ��
		while(n->next!=lp->tail){ //n����� �ּҰ��� lp�� tail��� ������ �ʴ´ٸ�
			n=n->next; //���� ���� ����
		} // n��尡 lp�� tail��� ���ϸ�
		np->next=lp->tail;			//
		n->next=np;
		++lp->size;
		
	}
	return TRUE; // return ���� ������ �����ϼ���.

}

/*----------------------------------------------------------------------------------
Function name	: displayList - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
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
Function name	: searchNode - data�� ��ġ�ϴ� ù ��° node �˻�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �˻��� ������
Returns			: ���� - �˻��� ����� �ּ� / ���� - NULL pointer
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
	return NULL; // return ���� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - ������ ������
Returns			: ���� - TRUE / ���� - FALSE
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
	return TRUE; // return ���� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - ��� ����(��������)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
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
Function name	: destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	Node *dp; //���� ���
	Node *cp; //���� ���
	int data; // ������ ����
	if(lp==NULL) //�����̸�
		return ; //������ ���
	if(lp!=NULL){ //���̸�
		cp=lp->head; //���� ��� head ����
		dp=cp->next;
		while(dp!=lp->tail){ //���� ��尡 lp�� tail ��� �ƴϸ�
			dp=cp->next; // dp(������ ���) �˷��ֱ�
			cp->next=dp->next; // cp����� next(*�κ�)�� dp��� ���� ����� �ּҰ�����
			free(dp); // ��� ����
		} // �����ϴ� ��尡 lp����� tail��尡 �Ǹ�
		free(lp->head); // lp����� head ��� ����
		free(lp->tail); // lp����� tail ��� ����
		--lp->size; //lp�� ��� ���� ���̱�
	}
	return ;
}
