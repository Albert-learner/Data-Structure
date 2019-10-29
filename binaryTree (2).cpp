#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "binaryTree.h"

/* -------------------------------------------------------------------------------------
함수명 : initTree - 트리 관리 구조체를 초기화 하는 함수
전달인자 : tr - Tree 구조체의 주소
리턴 값 : 없음
--------------------------------------------------------------------------------------*/
void initTree(Tree *tr)
{
	tr->root = NULL;
	tr->nodeCnt = 0;
}
/* --------------------------------------------------------------------------------------
함수명 : makeNode - 새 노드를 만들어 새 노드의 주소를 리턴하는 함수
전달인자 : data - 새 노드에 저장될 값(데이터)
left - 새 노드의 left 멤버 값
right - 새 노드의 right 멤버 값
리턴 값 : 새 노드의 주소 / 메모리 할당 실패 시 NULL pointer 
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
함수명 : addNode - 노드를 삽입하는 함수
전달인자 : tr - Tree 구조체의 주소
data - 새 노드에 저장될 데이터 저장 공간의 주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴 값 : 새 노드의 주소 / 메모리 할당 실패 시 NULL pointer
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
	 
	 else  // newNode가 root일때 덜 자주발생
	 {
		 tr->root = newNode;
		 ++tr->nodeCnt;
		 return newNode;
	 }



}
/* --------------------------------------------------------------------------------------
함수명 : inorderTraverse - 중위순회(정렬 순서로 출력)
전달인자 : np - 방문할 노드의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
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
함수명 : preorderTraverse - 전위순회
전달인자 : np - 방문할 노드의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
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
함수명 : postorderTraverse - 후위순회
전달인자 : np - 방문할 노드의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
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
함수명 : searchNode - data에 해당하는 노드 검색
전달인자 : tr - Tree 구조체의 주소
data - 검색할 데이터 저장 공간의 시작주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴 값 : 찾은 노드의 주소 / 못찾으면 NULL pointer
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
함수명 : deleteNode - data에 해당하는 노드 삭제
전달인자 : tr - Tree 구조체의 주소
data - 삭제할 데이터의 시작주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴 값 : 삭제한 노드의 parent 노드의 주소 / 못찾으면(삭제 실패 시) NULL pointer
---------------------------------------------------------------------------------------*/
Node * deleteNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *))
{

   Node *parent;  // 삭제할 노드의 부모노드
   Node *son;     // 삭제할 노드대신 자식노릇을 할 노드의 주소 저장
   Node *del;     // 삭제할 노드

   parent = del = tr->root;

   while (del != NULL) {
      if (compare(data, &del->data) == 0)  // 찾았으면!
         break;
      parent = del;
      if (compare(data, &del->data) < 0)
         del = del->left;
      else
         del = del->right;
   }
   if(del == NULL) return NULL; // 삭제 실패 시 NULL 리턴

   // 유형1 : 삭제할 노드의 오른쪽 자식이 없는 경우-삭제할 노드의 왼쪽 자식이 son역할
   if (del->right == NULL)
      son = del->left;
   // 유형2 : 삭제할 노드의 오른쪽 자식의 왼쪽 자식이 없는 경우-삭제할 노드의 오른쪽 자식이 son역할
   else if (del->right->left == NULL) {
      son = del->right;
      son->left = del->left;
   }
   // 유형3 : 그외 모든 경우-삭제한 노드의 오른쪽 서브트리에서 삭제할 데이터와 가장 가까운 값을 찾음
   else {
      Node *temp;
      temp = del->right;
      while (temp->left->left != NULL) temp = temp->left;// 삭제할 데이터와 가장 가까운 값을 찾기 위해 이동
      son = temp->left;// 삭제할 데이터와 가장 가까운 노드의 주소를 son에 저장
      temp->left = son->right;// son이 del의 자리로 올라가게 되면 기존의 son의 오른쪽 자식을 temp의 left에 붙임
      // 삭제될 노드의 왼쪽, 오른쪽 Node의 주소를 son에 저장
      son->left = del->left;
      son->right = del->right;
   }
   // 삭제될 노드 대신 자식(son) 역할을 할 노드를 위치시킴
   if (del == tr->root)
      tr->root = son;
   else if (del->data < parent->data)
      parent->left = son;
   else
      parent->right = son;

   free(del);  // 노드 삭제
   --tr->nodeCnt;
   return parent;
}


/* --------------------------------------------------------------------------------------
함수명 : destroyTree - tree 내의 모든 노드 삭제(tree 소멸)
전달인자 : tr - Tree 구조체의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
---------------------------------------------------------------------------------------*/
void destroyTree(Tree * tr, void(*print)(DataType *))
{
	postorderDelete(tr->root, print);  // 데이터 노드는 순회 하며 삭제
	tr->root = NULL;
	tr->nodeCnt = 0;
}

/* --------------------------------------------------------------------------------------
함수명 : postorderDelete - postorder(후위 순회)방식의 노드 삭제(재귀호출 함수)
전달인자 : np - 방문할 노드의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
---------------------------------------------------------------------------------------*/
void postorderDelete(Node *np, void(*print)(DataType *))
{

}
