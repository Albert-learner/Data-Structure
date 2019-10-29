#include "SinglyLinkedList.h"

/*
Function name : createList - ���� ����Ʈ ���� �� �ʱ�ȭ
Parameters : lp - ����Ʈ ���� ����ü �ּ�
Returns : ����
*/
void createList(List *lp)
{
	lp->head = NULL;
}

/*
Function name : addFist - head node�� node �߰�(���� ����)
Parameters : lp - ����Ʈ ���� ����ü �ּ�
			 char�� name, int�� data, string�� major, char�� grade - �߰��� ������
Returns : ����
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
Function name : displayList - ����Ʈ ���� ��� ������ ���
Parameters : lp - ����Ʈ ���� ����ü�� �ּ�
Returns : ����
*/
void displayList(List *lp)
{
	Node *temp;

	if (lp == NULL)
	{
		cout << "�� ����Ʈ�Դϴ�. " << "\n";
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
Function name : searchNode - grade�� ��ġ�ϴ� node �˻�
Parameters : lp - ����Ʈ ���� ����ü�� �ּ�
			 char�� grade - ã�ƾ� �� ������
Returns : ����
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
Function name : searchNode_pos - major�� ��ġ�ϴ� node �˻�
Parameters : lp - ����Ʈ ���� ����ü�� �ּ�
			 string�� major - ã�ƾ� �� ������
Returns : ����
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
