#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Node
{
	char Name;
	int ID;
	string major;
	char Grade;
	Node *next;
};

class List
{
private:
	Node *head;

public:
	/*
	List ������ - ���� ����Ʈ ���� �� �ʱ�ȭ
	Parameters : ����
	Returns : ����
	*/
	List()
	{
		head = NULL;
	}

	void insert(List *lp, char name, int ID, string major, char grade);
	void displayList(List *lp);
	void searchNode(List *lp, char grade);
	void search_major(List *lp);
	List *concat(List *lp1, List *lp2);
	void sortList(List *lp);
};