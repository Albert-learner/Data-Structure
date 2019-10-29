#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "binaryTree.h"

/* -------------------------------------------------------------------------------------
�Լ��� : initTree - Ʈ�� ���� ����ü�� �ʱ�ȭ �ϴ� �Լ�
�������� : tr - Tree ����ü�� �ּ�
���� �� : ����
--------------------------------------------------------------------------------------*/
void initTree(Tree *tr)
{
	tr->root = NULL;
	tr->nodeCnt = 0;
}
/* --------------------------------------------------------------------------------------
�Լ��� : makeNode - �� ��带 ����� �� ����� �ּҸ� �����ϴ� �Լ�
�������� : data - �� ��忡 ����� ��(������)
left - �� ����� left ��� ��
right - �� ����� right ��� ��
���� �� : �� ����� �ּ� / �޸� �Ҵ� ���� �� NULL pointer 
---------------------------------------------------------------------------------------*/
Node * makeNode(DataType *data, Node * left, Node *right)
{
	Node *np;
	np = (Node *)malloc(sizeof(Node));
	if (np != NULL) {
		np->data = *data;
		np->left = left;
		np->right = right;
	}
	return np;
}

/* --------------------------------------------------------------------------------------
�Լ��� : addNode - ��带 �����ϴ� �Լ�
�������� : tr - Tree ����ü�� �ּ�
data - �� ��忡 ����� ������ ���� ������ �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���� �� : �� ����� �ּ� / �޸� �Ҵ� ���� �� NULL pointer
---------------------------------------------------------------------------------------*/
Node *addNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *))
{
	Node *newNode = makeNode(data,NULL,NULL);
	Node *pp;
	Node *sp;
	if(tr==NULL)
	 {return NULL;}
	 
	if(tr->root != NULL)  
	 {
		 pp = tr->root;
		 sp = tr->root;
		while(sp!=NULL)
		{
			pp = sp;
			if(compare(data,&sp->data) == 1)
			{
				sp = sp->right;
			}
			else
			{
				sp=sp->left;
			}
			
		}
		if(compare(data,&pp->data)==1)
		{
			pp->right = newNode;
			++tr->nodeCnt;
		}
		else
		{
			pp->left = newNode;
			++tr->nodeCnt;
		}
		return newNode;
	 }
	 
	 else  // newNode�� root�϶� �� ���ֹ߻�
	 {
		 tr->root = newNode;
		 ++tr->nodeCnt;
		 return newNode;
	 }



}
/* --------------------------------------------------------------------------------------
�Լ��� : inorderTraverse - ������ȸ(���� ������ ���)
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void inorderTraverse(Node *np, void(*print)(DataType *))
{
     if(np!=NULL)
	 {
		 inorderTraverse(np->left,print);
		 print(&np->data);
		 inorderTraverse(np->right,print);
	 }
	 return;
}

/* --------------------------------------------------------------------------------------
�Լ��� : preorderTraverse - ������ȸ
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void preorderTraverse(Node *np, void(*print)(DataType *))
{
     if(np!=NULL)
	 {
		 print(&np->data);
		 preorderTraverse(np->left,print);
		 preorderTraverse(np->right,print);
	 }
	 return;
}
/* --------------------------------------------------------------------------------------
�Լ��� : postorderTraverse - ������ȸ
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void postorderTraverse(Node *np, void(*print)(DataType *))
{
     if(np!=NULL)
	 {
		 postorderTraverse(np->left,print);
		 postorderTraverse(np->right,print);
		 print(&np->data);
	 }
	 return;
}
/* --------------------------------------------------------------------------------------
�Լ��� : searchNode - data�� �ش��ϴ� ��� �˻�
�������� : tr - Tree ����ü�� �ּ�
data - �˻��� ������ ���� ������ �����ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���� �� : ã�� ����� �ּ� / ��ã���� NULL pointer
---------------------------------------------------------------------------------------*/
Node * searchNode(Tree *tr, DataType  *data, int(*compare)(DataType *, DataType *))
{
	Node *sp = tr->root;
     if(tr==NULL)
	 {return NULL;}
	 if(sp==NULL)
	 {return NULL;}

	 while(sp!=NULL){
		 if(compare(&sp->data,data) == (-1))
		 {
			 sp = sp->right;

		 }
		 else if(compare(&sp->data,data) == (1))
		 {
			 sp = sp->left;
		 }
		 else
		 {
			 return sp;  //break;
		 }
	 }
	 return sp;


}

/* --------------------------------------------------------------------------------------
�Լ��� : deleteNode - data�� �ش��ϴ� ��� ����
�������� : tr - Tree ����ü�� �ּ�
data - ������ �������� �����ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���� �� : ������ ����� parent ����� �ּ� / ��ã����(���� ���� ��) NULL pointer
---------------------------------------------------------------------------------------*/
Node * deleteNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *))
{

   Node *parent;  // ������ ����� �θ���
   Node *son;     // ������ ����� �ڽĳ븩�� �� ����� �ּ� ����
   Node *del;     // ������ ���

   parent = del = tr->root;

   while (del != NULL) {
      if (compare(data, &del->data) == 0)  // ã������!
         break;
      parent = del;
      if (compare(data, &del->data) < 0)
         del = del->left;
      else
         del = del->right;
   }
   if(del == NULL) return NULL; // ���� ���� �� NULL ����

   // ����1 : ������ ����� ������ �ڽ��� ���� ���-������ ����� ���� �ڽ��� son����
   if (del->right == NULL)
      son = del->left;
   // ����2 : ������ ����� ������ �ڽ��� ���� �ڽ��� ���� ���-������ ����� ������ �ڽ��� son����
   else if (del->right->left == NULL) {
      son = del->right;
      son->left = del->left;
   }
   // ����3 : �׿� ��� ���-������ ����� ������ ����Ʈ������ ������ �����Ϳ� ���� ����� ���� ã��
   else {
      Node *temp;
      temp = del->right;
      while (temp->left->left != NULL) temp = temp->left;// ������ �����Ϳ� ���� ����� ���� ã�� ���� �̵�
      son = temp->left;// ������ �����Ϳ� ���� ����� ����� �ּҸ� son�� ����
      temp->left = son->right;// son�� del�� �ڸ��� �ö󰡰� �Ǹ� ������ son�� ������ �ڽ��� temp�� left�� ����
      // ������ ����� ����, ������ Node�� �ּҸ� son�� ����
      son->left = del->left;
      son->right = del->right;
   }
   // ������ ��� ��� �ڽ�(son) ������ �� ��带 ��ġ��Ŵ
   if (del == tr->root)
      tr->root = son;
   else if (del->data < parent->data)
      parent->left = son;
   else
      parent->right = son;

   free(del);  // ��� ����
   --tr->nodeCnt;
   return parent;
}


/* --------------------------------------------------------------------------------------
�Լ��� : destroyTree - tree ���� ��� ��� ����(tree �Ҹ�)
�������� : tr - Tree ����ü�� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void destroyTree(Tree * tr, void(*print)(DataType *))
{
	postorderDelete(tr->root, print);  // ������ ���� ��ȸ �ϸ� ����
	tr->root = NULL;
	tr->nodeCnt = 0;
}

/* --------------------------------------------------------------------------------------
�Լ��� : postorderDelete - postorder(���� ��ȸ)����� ��� ����(���ȣ�� �Լ�)
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void postorderDelete(Node *np, void(*print)(DataType *))
{

}
